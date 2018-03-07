#!/bin/bash
set -ev

# --< Setup >--
if [ -z $CC ]; then
  CC=gcc
fi
CCW="$CC --std=c89 -Wall -Werror"
rm -rf .test
mkdir .test
cp *.mr .test
cp MR*/*.mr .test
cd .test


# --< MR0 >--

# compile mr0-compiler
$CCW ../MR0/mr0-compiler.c ../MR0/mr0-file.c ../MR0/mr0-string.c -o mr0-compiler

# test mr0-compiler on mr0-compiler
./mr0-compiler mr0-compiler.0.mr mr0-compiler.c
diff ../MR0/mr0-compiler.c mr0-compiler.c

# test mr0-compiler on mr1-compiler files
./mr0-compiler mr1-compiler.0.mr mr1-compiler.c
diff ../MR1/mr1-compiler.c mr1-compiler.c


# --< MR1 >--

# compile mr1-compiler
$CCW ../MR1/mr1-compiler.c ../MR0/mr0-file.c ../MR0/mr0-string.c -I../MR0 \
  -o mr1-compiler
  
# test mr1-compiler on mr2-compiler files
./mr1-compiler mr2-compiler.1.mr mr2-compiler.c
diff ../MR2/mr2-compiler.c mr2-compiler.c


# --< MR2 >--

# compile mr2-compiler
$CCW -Wno-parentheses ../MR2/mr2-compiler.c ../MR1/mr.1.c -I../MR1 \
  -o mr2-compiler
  
# test mr2-compiler on mr3-compiler files
./mr2-compiler common.2.mr map.2.mr global.2.mr exp.2.mr st-node.2.mr \
  flow.2.mr args.2.mr func.2.mr member.2.mr call.2.mr operand.2.mr dec.2.mr \
  type.2.mr test.2.mr mr3-compiler.2.mr
diff ../MR3/common.c common.c
diff ../MR3/map.c map.c
diff ../MR3/global.c global.c
diff ../MR3/exp.c exp.c
diff ../MR3/st-node.c st-node.c
diff ../MR3/flow.c flow.c
diff ../MR3/args.c args.c
diff ../MR3/func.c func.c
diff ../MR3/member.c member.c
diff ../MR3/call.c call.c
diff ../MR3/operand.c operand.c
diff ../MR3/dec.c dec.c
diff ../MR3/type.c type.c
diff ../MR3/test.c test.c
diff ../MR3/mr3-compiler.c mr3-compiler.c


# --< MR3 >--

# compile mr3-compiler
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../MR3/mr3-compiler.c ../MR2/mr.2.c -I../MR2 -o mr3-compiler

# test mr3-compiler on mr4-compiler files
mkdir global expression syntax-tree statement
cp ../MR4/global/*.3.mr global
cp ../MR4/expression/*.3.mr expression
cp ../MR4/syntax-tree/*.3.mr syntax-tree
cp ../MR4/statement/*.3.mr statement
./mr3-compiler global/*.3.mr expression/*.3.mr syntax-tree/*.3.mr \
  statement/*.3.mr mr4-compiler.3.mr
diff ../MR4/global global
diff ../MR4/expression expression
diff ../MR4/syntax-tree syntax-tree
diff ../MR4/statement statement
diff ../MR4/mr4-compiler.c mr4-compiler.c


# --< MR4 >--

# compile mr4-compiler
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../MR4/mr4-compiler.c ../MR3/mr.3.c -I../MR3 -I../MR4 -o mr4-compiler

# run mr4-compiler unit-tests
mkdir tests
cp ../MR4/tests/*.3.mr tests
cp ../MR4/tests/*.4.mr tests
cp ../MR4/tests/*.expected.c tests
./mr3-compiler global/*.3.mr expression/*.3.mr syntax-tree/*.3.mr \
  statement/*.3.mr tests/*.3.mr mr4-compiler.3.mr
if [ $CC == "gcc" ]; then
  COVERAGE="-coverage -O0"
else
  COVERAGE=
fi
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  $COVERAGE mr4-compiler.c ../MR3/mr.3.c -I. -I../MR3 -o mr4-compiler-tests
TEST_DIR=tests/ ./mr4-compiler-tests
diff tests/code-header.actual.c tests/code-header.expected.c
diff tests/expression-tests.actual.c tests/expression-tests.expected.c
diff tests/syntax-tree-tests.actual.c tests/syntax-tree-tests.expected.c
if [ ! -z "$COVERAGE" ]; then
  gcov mr4-compiler.c > gcov.log
fi

# run mr4-compiler single-file integration test
./mr4-compiler tests/integration-actual-single.c tests/integration-test0.4.mr
diff ../MR4/tests/integration-expected-single.c \
  tests/integration-actual-single.c
$CCW -Wno-unused-label --pedantic tests/integration-actual-single.c \
  ../MR4/mr.4.c -I../MR4 -o  test-mr4-single
./test-mr4-single > tests/integration-single-output.txt
diff ../MR4/tests/integration-single-output.txt \
  tests/integration-single-output.txt

# run mr4-compiler multiple-file integration test
./mr4-compiler -t covered tests/integration-actual-multiple.c \
  tests/integration-test0.4.mr tests/integration-test1.4.mr \
  tests/integration-test2.4.mr
diff ../MR4/tests/integration-expected-multiple.c \
  tests/integration-actual-multiple.c
$CCW -Wno-unused-label --pedantic tests/integration-actual-multiple.c \
  ../MR4/mr.4.c ../MR4/tests/integration-external.c -I../MR4 -o \
  test-mr4-multiple
./test-mr4-multiple -xml > tests/integration-multiple-output.txt
diff ../MR4/tests/integration-multiple-output.txt \
  tests/integration-multiple-output.txt
diff ../MR4/tests/expected-cobertura.xml cobertura.xml
if [ -z "$COVERAGE" ]; then
  rm cobertura.xml
fi

# run mr4-compiler coverage fail integration test
./mr4-compiler -t integration tests/integration-actual-uncovered.c \
  tests/integration-test0.4.mr tests/integration-test1.4.mr \
  tests/integration-test2.4.mr
diff ../MR4/tests/integration-expected-uncovered.c \
  tests/integration-actual-uncovered.c
$CCW -Wno-unused-label --pedantic tests/integration-actual-uncovered.c \
  ../MR4/mr.4.c ../MR4/tests/integration-external.c -I../MR4 -o \
  test-mr4-uncovered
! ./test-mr4-uncovered > tests/integration-uncovered-output.txt
diff ../MR4/tests/integration-uncovered-output.txt \
  tests/integration-uncovered-output.txt

# run mr4-compiler error integration test
./mr4-compiler -t error tests/integration-actual-error.c \
  tests/integration-error-test.4.mr
diff ../MR4/tests/integration-expected-error.c tests/integration-actual-error.c
$CCW -Wno-unused-label --pedantic tests/integration-actual-error.c \
  ../MR4/mr.4.c -I../MR4 -o  test-mr4-error
! ./test-mr4-error > tests/integration-error-output.txt
diff ../MR4/tests/integration-error-output.txt \
  tests/integration-error-output.txt


# --< MRB >--

# test mr3-compiler on mrb files
./mr3-compiler mrb.3.mr
diff ../mrb.c mrb.c

# compile mrb
$CCW ../mrb.c ../MR3/mr.3.c -I. -I../MR3 -o mrb


# --< Standard Libraries >--

# run standard-libraries unit-tests
mkdir standard-libraries
cp ../standard-libraries/*.3.mr standard-libraries
cp ../standard-libraries/tests/*.3.mr standard-libraries
./mr3-compiler standard-libraries/*.3.mr
$CCW -Wno-unused-variable -Wno-missing-braces \
  standard-libraries/standard-libraries-tests.c ../MR3/mr.3.c -I. -I../MR3 \
  -o standard-libraries-tests
./standard-libraries-tests


# --< Teardown >--
cd ..
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf .test
fi


# All tests passed
