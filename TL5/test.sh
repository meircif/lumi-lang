#!/bin/bash
set -ev

# --< TL5 >--

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
CCW="$CC --std=c89 -Werror -Wall -Wno-unused -Wno-missing-braces"
CCA="$CCW -Wno-self-assign -Wno-long-long
  -Wno-tautological-constant-out-of-range-compare --pedantic"
if ! which valgrind > /dev/null || [[ $CC == *32* ]] || [[ $CC == *arm* ]]; then
  SKIP_VALGRIND="y"
fi

rm -rf $DIR/.test/TL5
mkdir -p $DIR/.test/TL5
pushd $DIR/.test


# compile tl4-compiler
$CCW -Wno-typedef-redefinition ../TL4/tl4-compiler.c ../TL3/lumi.3.c \
  -I../TL3 -I../TL4 -o TL5/tl4-compiler

# test generated tl5-compiler sources
TL5/tl4-compiler TL5/string-generator.c ../TL5/string-generator.4.lm
$CCA TL5/string-generator.c ../TL4/lumi.4.c -I../TL4 -o TL5/string-generator
TL5/string-generator ../TL5/lumi.5.c TL5/header-string.4.lm
diff ../TL5/global/header-string.4.lm TL5/header-string.4.lm

# test tl5-compiler C file
cp -r ../TL5 TL5/
pushd TL5
./tl4-compiler tl5-compiler.c TL5/tl5-compiler.4.lm \
  TL5/expression/assign.4.lm TL5/expression/base-type.4.lm \
  TL5/expression/call.4.lm TL5/expression/constant.4.lm \
  TL5/expression/container.4.lm TL5/expression/expression.4.lm \
  TL5/expression/field.4.lm TL5/expression/initialize.4.lm \
  TL5/expression/operator.4.lm TL5/expression/slice.4.lm \
  TL5/expression/symbol.4.lm TL5/expression/wrap.4.lm TL5/global/argument.4.lm \
  TL5/global/common.4.lm TL5/global/compiler.4.lm TL5/global/file-io.4.lm \
  TL5/global/header-string.4.lm TL5/global/int-range.4.lm \
  TL5/global/list.4.lm TL5/global/map.4.lm TL5/global/memory.4.lm \
  TL5/global/type-instance.4.lm TL5/statement/enum.4.lm \
  TL5/statement/error.4.lm TL5/statement/for.4.lm TL5/statement/function.4.lm \
  TL5/statement/native.4.lm TL5/statement/test.4.lm TL5/statement/type.4.lm \
  TL5/statement/variable.4.lm TL5/syntax-tree/block.4.lm \
  TL5/syntax-tree/branch.4.lm TL5/syntax-tree/code.4.lm \
  TL5/syntax-tree/flow.4.lm TL5/syntax-tree/node.4.lm TL5/syntax-tree/root.4.lm
popd
diff ../TL5/tl5-compiler.c TL5/tl5-compiler.c

# compile tl5-compiler
$CCA ../TL5/tl5-compiler.c ../TL4/lumi.4.c -I../TL4 -o TL5/tl5-compiler

# run tl5-compiler unit-tests
TL5/tl4-compiler -t tl5-compiler TL5/tl5-compiler-tests.c \
  ../TL5/tl5-compiler.4.lm ../TL5/*/*.4.lm ../TL5/tests/ut/*.4.lm
$CCA TL5/tl5-compiler-tests.c ../TL4/lumi.4.c -I../TL4 -o \
  TL5/tl5-compiler-tests
cp -r ../TL5/tests/ut TL5/
TEST_DIR=TL5/ut/ TL5/tl5-compiler-tests -xml
mv cobertura.xml TL5/ut/
diff TL5/ut/actual.c TL5/ut/expected.c

# run tl5-compiler single-file integration test
cp -r ../TL5/tests TL5/
TL5/tl5-compiler TL5/test-single.c TL5/tests/integration/test0.5.lm
$CCA TL5/test-single.c -o TL5/test-single
TL5/test-single > TL5/test-single-output.txt
diff TL5/tests/integration/single-output.txt TL5/test-single-output.txt
if [ -z $SKIP_VALGRIND ]; then
  valgrind -q --leak-check=full --error-exitcode=1 TL5/test-single > /dev/null
fi

# run tl5-compiler multiple-file integration test
TL5/tl5-compiler -t covered TL5/test-multiple.c \
  TL5/tests/integration/test0.5.lm TL5/tests/integration/test1.5.lm \
  TL5/tests/integration/test2.5.lm
$CCA TL5/test-multiple.c TL5/tests/integration/external.c \
  -ITL5/tests/integration -o TL5/test-multiple
TL5/test-multiple -xml > TL5/test-multiple-output.txt
mkdir TL5/cover-tests
mv cobertura.xml TL5/cover-tests/
diff TL5/tests/integration/multiple-output.txt TL5/test-multiple-output.txt
diff TL5/tests/integration/expected-cobertura.xml TL5/cover-tests/cobertura.xml
if [ -z $SKIP_VALGRIND ]; then
  valgrind -q --leak-check=full --error-exitcode=1 TL5/test-multiple > /dev/null
fi

# run tl5-compiler coverage fail integration test
TL5/tl5-compiler -t integration TL5/test-uncovered.c \
  TL5/tests/integration/test0.5.lm TL5/tests/integration/test1.5.lm \
  TL5/tests/integration/test2.5.lm
$CCA TL5/test-uncovered.c TL5/tests/integration/external.c \
  -ITL5/tests/integration -o TL5/test-uncovered
! TL5/test-uncovered > TL5/test-uncovered-output.txt
diff TL5/tests/integration/uncovered-output.txt TL5/test-uncovered-output.txt

# run tl5-compiler error integration test
TL5/tl5-compiler -t error TL5/test-error.c TL5/tests/integration/error-test.5.lm
$CCA TL5/test-error.c -o TL5/test-error
! TL5/test-error > TL5/test-error-output.txt
diff TL5/tests/integration/error-output.txt TL5/test-error-output.txt


# TL5 teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf TL5
fi
popd


# TL5 tests passed
