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

rm -rf $DIR/.test/standard-libraries
mkdir -p $DIR/.test/standard-libraries
pushd $DIR/.test


# compile tl4-compiler
$CCW -Wno-missing-braces -Wno-typedef-redefinition ../TL4/tl4-compiler.c \
  ../TL3/lumi.3.c -I../TL3 -I../TL4 -o standard-libraries/tl4-compiler


# run standard-libraries unit-tests
standard-libraries/tl4-compiler standard-libraries/math-tests.c \
  ../standard-libraries/math.4.lm ../standard-libraries/iterator.4.lm \
  ../standard-libraries/tests/math-tests.4.lm -t math
$CCA standard-libraries/math-tests.c ../TL4/lumi.4.c -I../TL4 \
  -o standard-libraries/math-tests
standard-libraries/math-tests -xml
mkdir standard-libraries/cover-math-tests
mv cobertura.xml standard-libraries/cover-math-tests
standard-libraries/tl4-compiler standard-libraries/ds-tests.c \
  ../standard-libraries/list.4.lm ../standard-libraries/iterator.4.lm \
  ../standard-libraries/tests/ds-tests.4.lm -t ds
$CCA standard-libraries/ds-tests.c ../TL4/lumi.4.c -I../TL4 \
  -o standard-libraries/ds-tests
standard-libraries/ds-tests -xml
mkdir standard-libraries/cover-ds-tests
mv cobertura.xml standard-libraries/cover-ds-tests


# Standard Libraries teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf standard-libraries
fi
popd


# Standard Libraries tests passed
