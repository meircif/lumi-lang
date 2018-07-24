#!/bin/bash
set -ev

# --< TL3 >--

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

rm -rf $DIR/.test/TL3
mkdir -p $DIR/.test/TL3
pushd $DIR/.test


# compile tl2-compiler
$CCW -Wno-parentheses ../TL2/tl2-compiler.c ../TL1/lumi.1.c -I../TL1 \
  -o TL3/tl2-compiler

# test tl3-compiler C files
cp ../TL3/*.2.lm TL3/
pushd TL3
./tl2-compiler common.2.lm map.2.lm global.2.lm exp.2.lm st-node.2.lm \
  flow.2.lm args.2.lm func.2.lm member.2.lm call.2.lm operand.2.lm dec.2.lm \
  type.2.lm test.2.lm tl3-compiler.2.lm
diff ../../TL3/common.c common.c
diff ../../TL3/map.c map.c
diff ../../TL3/global.c global.c
diff ../../TL3/exp.c exp.c
diff ../../TL3/st-node.c st-node.c
diff ../../TL3/flow.c flow.c
diff ../../TL3/args.c args.c
diff ../../TL3/func.c func.c
diff ../../TL3/member.c member.c
diff ../../TL3/call.c call.c
diff ../../TL3/operand.c operand.c
diff ../../TL3/dec.c dec.c
diff ../../TL3/type.c type.c
diff ../../TL3/test.c test.c
diff ../../TL3/tl3-compiler.c tl3-compiler.c
popd

# compile tl3-compiler
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../TL3/tl3-compiler.c ../TL2/lumi.2.c -I../TL2 -o TL3/tl3-compiler


# TL3 teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf TL3
fi
popd


# TL3 tests passed
