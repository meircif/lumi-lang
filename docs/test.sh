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
CCA="$CC --std=c89 -Werror -Wall -Wno-unused -Wno-self-assign -Wno-long-long
  --pedantic"

rm -rf $DIR/.test/docs
mkdir -p $DIR/.test/docs
pushd $DIR/.test


# compile tl5-compiler
$CCA ../TL5/tl5-compiler.c ../TL4/lumi.4.c -I../TL4 -o docs/tl5-compiler

# compile examples
docs/tl5-compiler docs/hello-world.c ../docs/hello-world.5.lm
$CCA docs/hello-world.c -o docs/hello-world
docs/tl5-compiler docs/hello-world-test.c ../docs/hello-world.5.lm \
  ../docs/hello-world-test.5.lm -t hello-world
$CCA docs/hello-world-test.c -o docs/hello-world-test
docs/tl5-compiler docs/examples.c ../docs/examples.5.lm
$CCA docs/examples.c -o docs/run-examples

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
