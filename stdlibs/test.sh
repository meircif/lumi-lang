#!/bin/bash
set -ev

# --< Standard Libraries >--

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do
  DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
MYDIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null && pwd )"
DIR="$( cd -P "$( dirname "$MYDIR" )" >/dev/null && pwd )"

if [ -z $CC ]; then
  CC=gcc
fi
CCA="$CC --std=c89 -Werror -Wall -Wno-unused-variable --pedantic \
  -Wno-unused-label"
if [ $CC == "gcc" ]; then
  CCA="$CCA -Wno-unused-but-set-variable"
else
  CCA="$CCA -Wno-self-assign"
fi

rm -rf $DIR/.test/stdlibs
mkdir -p $DIR/.test/stdlibs
pushd $DIR/.test


# compile tl5-compiler
$CCA ../TL5/tl5-compiler.c ../TL4/lumi.4.c -I../TL4 -o stdlibs/tl5-compiler


# run stdlibs unit-tests
stdlibs/tl5-compiler -t math stdlibs/math-tests.c ../stdlibs/math.5.lm \
  ../stdlibs/tests/math-tests.5.lm
$CCA stdlibs/math-tests.c -o stdlibs/math-tests
stdlibs/math-tests -xml
mkdir stdlibs/cover-math-tests
mv cobertura.xml stdlibs/cover-math-tests

stdlibs/tl5-compiler -t ds stdlibs/ds-tests.c ../stdlibs/list.5.lm \
  ../stdlibs/tests/ds-tests.5.lm
$CCA stdlibs/ds-tests.c -o stdlibs/ds-tests
stdlibs/ds-tests -xml
mkdir stdlibs/cover-ds-tests
mv cobertura.xml stdlibs/cover-ds-tests

stdlibs/tl5-compiler -t time stdlibs/time-tests.c ../stdlibs/time.5.lm \
  ../stdlibs/tests/time-tests.5.lm
$CCA stdlibs/time-tests.c -I../stdlibs/tests -o stdlibs/time-tests
stdlibs/time-tests -xml
mkdir stdlibs/cover-time-tests
mv cobertura.xml stdlibs/cover-time-tests

# Run os stdlib tests
stdlibs/tl5-compiler -t os stdlibs/os-tests.c ../stdlibs/os.5.lm \
  ../stdlibs/tests/os-test.5.lm ../stdlibs/list.5.lm 
$CCA stdlibs/os-tests.c -I../stdlibs/tests -o stdlibs/os-tests
stdlibs/os-tests -xml
mkdir stdlibs/cover-os-tests
mv cobertura.xml stdlibs/cover-os-tests


# Standard Libraries teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf stdlibs
fi
popd


# Standard Libraries tests passed
