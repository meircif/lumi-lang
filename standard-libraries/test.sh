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
CCW="$CC --std=c89 -Werror -Wall -Wno-unused-variable -Wno-missing-braces"

rm -rf $DIR/.test/standard-libraries
mkdir -p $DIR/.test/standard-libraries
pushd $DIR/.test


# compile tl3-compiler
$CCW -Wno-typedef-redefinition ../TL3/tl3-compiler.c ../TL2/lumi.2.c -I../TL2 \
  -o standard-libraries/tl3-compiler


# run standard-libraries unit-tests
cp ../standard-libraries/*.3.lm standard-libraries/
cp ../standard-libraries/tests/*.3.lm standard-libraries/
standard-libraries/tl3-compiler standard-libraries/*.3.lm
$CCW standard-libraries/standard-libraries-tests.c ../TL3/lumi.3.c -I. \
  -I../TL3 -o standard-libraries/standard-libraries-tests
standard-libraries/standard-libraries-tests


# Standard Libraries teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf standard-libraries
fi
popd


# Standard Libraries tests passed
