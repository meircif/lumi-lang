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
CCA="$CC --std=c89 -Werror -Wall -Wno-unused -Wno-self-assign --pedantic"

rm -rf $DIR/.test/stdlib
mkdir -p $DIR/.test/stdlib
pushd $DIR/.test


# compile tl5-compiler
$CCA ../TL5/tl5-compiler.c ../TL4/lumi.4.c -I../TL4 -o stdlib/tl5-compiler


# run stdlib unit-tests
stdlib/tl5-compiler -t math stdlib/math-tests.c ../stdlib/math.5.lm \
  ../stdlib/tests/math-tests.5.lm
$CCA stdlib/math-tests.c -o stdlib/math-tests
stdlib/math-tests -xml
mkdir stdlib/cover-math-tests
mv cobertura.xml stdlib/cover-math-tests

stdlib/tl5-compiler -t ds stdlib/ds-tests.c ../stdlib/list.5.lm \
   ../stdlib/dict.5.lm ../stdlib/tests/list-tests.5.lm  \
   ../stdlib/tests/dict-tests.5.lm
$CCA stdlib/ds-tests.c -o stdlib/ds-tests
stdlib/ds-tests -xml
mkdir stdlib/cover-ds-tests
mv cobertura.xml stdlib/cover-ds-tests

stdlib/tl5-compiler -t time stdlib/time-tests.c ../stdlib/time.5.lm \
  ../stdlib/tests/time-tests.5.lm
$CCA stdlib/time-tests.c -I../stdlib/tests -o stdlib/time-tests
stdlib/time-tests -xml
mkdir stdlib/cover-time-tests
mv cobertura.xml stdlib/cover-time-tests

stdlib/tl5-compiler -t os stdlib/os-tests.c ../stdlib/os.5.lm \
  ../stdlib/tests/os-test.5.lm ../stdlib/list.5.lm
$CCA stdlib/os-tests.c -I../stdlib/tests -o stdlib/os-tests
stdlib/os-tests -xml
mkdir stdlib/cover-os-tests
mv cobertura.xml stdlib/cover-os-tests


# Standard Libraries teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf stdlib
fi
popd


# Standard Libraries tests passed
