#!/bin/bash
set -ev

# --< TL4 >--

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
CCA="$CCW --pedantic -Wno-unused"
if [ $CC == "clang" ]; then
  CCA="$CCA -Wno-self-assign"
fi

rm -rf $DIR/.test/TL4
mkdir -p $DIR/.test/TL4
pushd $DIR/.test/TL4


# compile tl3-compiler
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../../TL3/tl3-compiler.c ../../TL2/lumi.2.c -I../../TL2 -o ./tl3-compiler

# test tl4-compiler C files
mkdir global expression syntax-tree statement
cp ../../TL4/*.3.lm .
cp ../../TL4/global/*.3.lm global
cp ../../TL4/expression/*.3.lm expression
cp ../../TL4/syntax-tree/*.3.lm syntax-tree
cp ../../TL4/statement/*.3.lm statement
./tl3-compiler tl4-compiler.3.lm global/argument.3.lm global/common.3.lm \
  global/file-io.3.lm global/global.3.lm global/list.3.lm global/map.3.lm \
  global/type-instance.3.lm expression/base-type.3.lm expression/call.3.lm \
  expression/constant.3.lm expression/container.3.lm \
  expression/expression.3.lm expression/initialize.3.lm expression/slice.3.lm \
  expression/symbol.3.lm syntax-tree/block.3.lm syntax-tree/branch.3.lm \
  syntax-tree/code.3.lm syntax-tree/code-flow.3.lm syntax-tree/node.3.lm \
  syntax-tree/root.3.lm statement/enum.3.lm statement/error.3.lm \
  statement/for.3.lm statement/function.3.lm statement/native.3.lm \
  statement/test.3.lm statement/type.3.lm statement/variable.3.lm
diff ../../TL4/global global
diff ../../TL4/expression expression
diff ../../TL4/syntax-tree syntax-tree
diff ../../TL4/statement statement
diff ../../TL4/tl4-compiler.c tl4-compiler.c

# compile tl4-compiler
pushd ..
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../TL4/tl4-compiler.c ../TL3/lumi.3.c -I../TL3 -I../TL4 -o TL4/tl4-compiler
popd

# run tl4-compiler unit-tests
mkdir tests
cp ../../TL4/tests/*.lm tests
cp ../../TL4/tests/*.expected.c tests
./tl3-compiler global/*.3.lm expression/*.3.lm syntax-tree/*.3.lm \
  statement/*.3.lm tests/*.3.lm tl4-compiler.3.lm
if [ $CC == "gcc" ]; then
  COVERAGE="-coverage -O0"
else
  COVERAGE=
fi
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  $COVERAGE tl4-compiler.c ../../TL3/lumi.3.c -I. -I../../TL3 \
  -o tl4-compiler-tests
TEST_DIR=tests/ ./tl4-compiler-tests
diff tests/code-header.actual.c tests/code-header.expected.c
diff tests/expression-tests.actual.c tests/expression-tests.expected.c
diff tests/syntax-tree-tests.actual.c tests/syntax-tree-tests.expected.c
if [ ! -z "$COVERAGE" ]; then
  gcov tl4-compiler.c > gcov.log
fi

# run tl4-compiler single-file integration test
./tl4-compiler tests/integration-actual-single.c tests/integration-test0.4.lm
diff ../../TL4/tests/integration-expected-single.c \
  tests/integration-actual-single.c
$CCA tests/integration-actual-single.c ../../TL4/lumi.4.c -I../../TL4 \
  -o test-tl4-single
./test-tl4-single > tests/integration-single-output.txt
diff ../../TL4/tests/integration-single-output.txt \
  tests/integration-single-output.txt

# run tl4-compiler multiple-file integration test
./tl4-compiler -t covered tests/integration-actual-multiple.c \
  tests/integration-test0.4.lm tests/integration-test1.4.lm \
  tests/integration-test2.4.lm
diff ../../TL4/tests/integration-expected-multiple.c \
  tests/integration-actual-multiple.c
$CCA tests/integration-actual-multiple.c ../../TL4/lumi.4.c \
  ../../TL4/tests/integration-external.c -I../../TL4 -o test-tl4-multiple
./test-tl4-multiple -xml > tests/integration-multiple-output.txt
mkdir cover-tl4-tests
mv cobertura.xml cover-tl4-tests
diff ../../TL4/tests/integration-multiple-output.txt \
  tests/integration-multiple-output.txt
diff ../../TL4/tests/expected-cobertura.xml cover-tl4-tests/cobertura.xml

# run tl4-compiler coverage fail integration test
./tl4-compiler -t integration tests/integration-actual-uncovered.c \
  tests/integration-test0.4.lm tests/integration-test1.4.lm \
  tests/integration-test2.4.lm
diff ../../TL4/tests/integration-expected-uncovered.c \
  tests/integration-actual-uncovered.c
$CCA tests/integration-actual-uncovered.c ../../TL4/lumi.4.c \
  ../../TL4/tests/integration-external.c -I../../TL4 -o test-tl4-uncovered
! ./test-tl4-uncovered > tests/integration-uncovered-output.txt
diff ../../TL4/tests/integration-uncovered-output.txt \
  tests/integration-uncovered-output.txt

# run tl4-compiler error integration test
./tl4-compiler -t error tests/integration-actual-error.c \
  tests/integration-error-test.4.lm
diff ../../TL4/tests/integration-expected-error.c \
  tests/integration-actual-error.c
$CCA tests/integration-actual-error.c ../../TL4/lumi.4.c -I../../TL4 \
  -o test-tl4-error
! ./test-tl4-error > tests/integration-error-output.txt
diff ../../TL4/tests/integration-error-output.txt \
  tests/integration-error-output.txt
  
# TL4 teardown
popd
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf $DIR/.test/TL4
fi


# TL4 tests passed
