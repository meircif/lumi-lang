#!/bin/bash
set -ev

# --< TL0 >--

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

rm -rf $DIR/.test/TL0
mkdir -p $DIR/.test/TL0
pushd $DIR/.test


# compile tl0-compiler
$CC0 ../TL0/tl0-compiler.c ../TL0/tl0-file.c ../TL0/tl0-string.c -o \
  TL0/tl0-compiler

# test tl0-compiler on tl0-compiler
TL0/tl0-compiler ../TL0/tl0-compiler.0.lm TL0/tl0-compiler.c
diff ../TL0/tl0-compiler.c TL0/tl0-compiler.c


# TL0 teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf TL0
fi
popd


# TL0 tests passed
