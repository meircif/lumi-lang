#!/bin/bash
set -ev

# --< TL1 >--

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

rm -rf $DIR/.test/TL1
mkdir -p $DIR/.test/TL1
pushd $DIR/.test


# compile tl0-compiler
$CC0 ../TL0/tl0-compiler.c ../TL0/tl0-file.c ../TL0/tl0-string.c -o \
  TL1/tl0-compiler

# test tl1-compiler C file
TL1/tl0-compiler ../TL1/tl1-compiler.0.lm TL1/tl1-compiler.c
diff ../TL1/tl1-compiler.c TL1/tl1-compiler.c

# compile tl1-compiler
$CC0 ../TL1/tl1-compiler.c ../TL0/tl0-file.c ../TL0/tl0-string.c -I../TL0 \
  -o TL1/tl1-compiler
  

# TL1 teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf TL1
fi
popd


# TL1 tests passed
