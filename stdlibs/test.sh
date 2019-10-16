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
CCW="$CC --std=c89 -Werror -Wall -Wno-unused-variable"
CCA="$CCW --pedantic -Wno-unused-label"
if [ $CC == "gcc" ]; then
  CCA="$CCA -Wno-unused-but-set-variable"
else
  CCA="$CCA -Wno-self-assign"
fi

rm -rf $DIR/.test/stdlibs
mkdir -p $DIR/.test/stdlibs
pushd $DIR/.test


# compile tl4-compiler
$CCW -Wno-missing-braces -Wno-typedef-redefinition ../TL4/tl4-compiler.c \
  ../TL3/lumi.3.c -I../TL3 -I../TL4 -o stdlibs/tl4-compiler


# compile tl5-compiler
$CCA -Wno-overlength-strings ../TL5/tl5-compiler.c ../TL4/lumi.4.c \
  -I../TL4 -o stdlibs/tl5-compiler


# run stdlibs unit-tests
stdlibs/tl4-compiler stdlibs/math-tests.c ../stdlibs/math.4.lm \
  ../stdlibs/iterator.4.lm ../stdlibs/tests/math-tests.4.lm -t math
$CCA stdlibs/math-tests.c ../TL4/lumi.4.c -I../TL4 -o stdlibs/math-tests
stdlibs/math-tests -xml
mkdir stdlibs/cover-math-tests
mv cobertura.xml stdlibs/cover-math-tests

stdlibs/tl4-compiler stdlibs/ds-tests.c ../stdlibs/list.4.lm \
  ../stdlibs/iterator.4.lm ../stdlibs/tests/ds-tests.4.lm -t ds
$CCA stdlibs/ds-tests.c ../TL4/lumi.4.c -I../TL4 -o stdlibs/ds-tests
stdlibs/ds-tests -xml
mkdir stdlibs/cover-ds-tests
mv cobertura.xml stdlibs/cover-ds-tests

stdlibs/tl5-compiler stdlibs/time-tests.c ../stdlibs/time.5.lm \
  ../stdlibs/tests/time-tests.5.lm -t time
$CCA stdlibs/time-tests.c -I../stdlibs/tests -o stdlibs/time-tests
stdlibs/time-tests -xml
mkdir stdlibs/cover-time-tests
mv cobertura.xml stdlibs/cover-time-tests


# Standard Libraries teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf stdlibs
fi
popd


# Standard Libraries tests passed
