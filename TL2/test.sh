#!/bin/bash
set -ev

# --< TL2 >--

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
CC0="$CC --std=c89 -Werror"
CCW="$CC0 -Wall"

rm -rf $DIR/.test/TL2
mkdir -p $DIR/.test/TL2
pushd $DIR/.test

# compile tl1-compiler
$CC0 ../TL1/tl1-compiler.c ../TL0/tl0-file.c ../TL0/tl0-string.c -I../TL0 \
  -o TL2/tl1-compiler

# test tl2-compiler C file
TL2/tl1-compiler ../TL2/tl2-compiler.1.lm TL2/tl2-compiler.c
diff ../TL2/tl2-compiler.c TL2/tl2-compiler.c

# compile tl2-compiler
$CCW -Wno-parentheses ../TL2/tl2-compiler.c ../TL1/lumi.1.c -I../TL1 \
  -o TL2/tl2-compiler
  

# TL2 teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf TL2
fi
popd


# TL2 tests passed
