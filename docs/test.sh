#!/bin/bash
set -ev

# --< Documentation >--

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
CCW="$CC --std=c89 -Werror -Wall"
CCA="$CCW --pedantic -Wno-unused-label"
if [ $CC == "gcc" ]; then
  CCA="$CCA -Wno-unused-but-set-variable"
else
  CCA="$CCA -Wno-self-assign"
fi

rm -rf $DIR/.test/docs
mkdir -p $DIR/.test/docs
pushd $DIR/.test


# compile tl4-compiler
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../TL4/tl4-compiler.c ../TL3/lumi.3.c -I../TL3 -I../TL4 -o docs/tl4-compiler

# compile examples
docs/tl4-compiler docs/hello-world.c ../docs/hello-world.4.lm
$CCA docs/hello-world.c ../TL4/lumi.4.c -I../TL4 -o docs/hello-world
docs/tl4-compiler docs/hello-world-test.c ../docs/hello-world.4.lm \
  ../docs/hello-world-test.4.lm -t hello-world
$CCA docs/hello-world-test.c ../TL4/lumi.4.c -I../TL4 -o docs/hello-world-test
docs/tl4-compiler docs/examples.c ../docs/examples.4.lm
$CCA docs/examples.c ../TL4/lumi.4.c -I../TL4 -o docs/run-examples

# run examples
docs/hello-world
docs/hello-world-test
docs/run-examples

# run sphinx with spell checker
sphinx-build -W -b spelling ../docs docs/spelling


# Documentation teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf docs
fi
popd


# Documentation tests passed
