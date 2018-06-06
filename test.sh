#!/bin/bash
set -ev

# --< Setup >--
if [ -z $CC ]; then
  CC=gcc
fi
CCW="$CC --std=c89 -Wall -Werror"
CCA="$CCW --pedantic -Wno-unused-label"
rm -rf .test
mkdir .test
cp *.lm .test
cp TL*/*.lm .test
cd .test


# --< TL0 >--

# compile tl0-compiler
$CCW ../TL0/tl0-compiler.c ../TL0/tl0-file.c ../TL0/tl0-string.c -o tl0-compiler

# test tl0-compiler on tl0-compiler
./tl0-compiler tl0-compiler.0.lm tl0-compiler.c
diff ../TL0/tl0-compiler.c tl0-compiler.c

# test tl0-compiler on tl1-compiler files
./tl0-compiler tl1-compiler.0.lm tl1-compiler.c
diff ../TL1/tl1-compiler.c tl1-compiler.c


# --< TL1 >--

# compile tl1-compiler
$CCW ../TL1/tl1-compiler.c ../TL0/tl0-file.c ../TL0/tl0-string.c -I../TL0 \
  -o tl1-compiler

# test tl1-compiler on tl2-compiler files
./tl1-compiler tl2-compiler.1.lm tl2-compiler.c
diff ../TL2/tl2-compiler.c tl2-compiler.c


# --< TL2 >--

# compile tl2-compiler
$CCW -Wno-parentheses ../TL2/tl2-compiler.c ../TL1/lumi.1.c -I../TL1 \
  -o tl2-compiler

# test tl2-compiler on tl3-compiler files
./tl2-compiler common.2.lm map.2.lm global.2.lm exp.2.lm st-node.2.lm \
  flow.2.lm args.2.lm func.2.lm member.2.lm call.2.lm operand.2.lm dec.2.lm \
  type.2.lm test.2.lm tl3-compiler.2.lm
diff ../TL3/common.c common.c
diff ../TL3/map.c map.c
diff ../TL3/global.c global.c
diff ../TL3/exp.c exp.c
diff ../TL3/st-node.c st-node.c
diff ../TL3/flow.c flow.c
diff ../TL3/args.c args.c
diff ../TL3/func.c func.c
diff ../TL3/member.c member.c
diff ../TL3/call.c call.c
diff ../TL3/operand.c operand.c
diff ../TL3/dec.c dec.c
diff ../TL3/type.c type.c
diff ../TL3/test.c test.c
diff ../TL3/tl3-compiler.c tl3-compiler.c


# --< TL3 >--

# compile tl3-compiler
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../TL3/tl3-compiler.c ../TL2/lumi.2.c -I../TL2 -o tl3-compiler

# test tl3-compiler on tl4-compiler files
mkdir global expression syntax-tree statement
cp ../TL4/global/*.3.lm global
cp ../TL4/expression/*.3.lm expression
cp ../TL4/syntax-tree/*.3.lm syntax-tree
cp ../TL4/statement/*.3.lm statement
./tl3-compiler tl4-compiler.3.lm global/*.3.lm expression/*.3.lm \
  syntax-tree/*.3.lm statement/*.3.lm
diff ../TL4/global global
diff ../TL4/expression expression
diff ../TL4/syntax-tree syntax-tree
diff ../TL4/statement statement
diff ../TL4/tl4-compiler.c tl4-compiler.c


# --< TL4 >--

# compile tl4-compiler
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../TL4/tl4-compiler.c ../TL3/lumi.3.c -I../TL3 -I../TL4 -o tl4-compiler

# run tl4-compiler unit-tests
mkdir tests
cp ../TL4/tests/*.3.lm tests
cp ../TL4/tests/*.4.lm tests
cp ../TL4/tests/*.expected.c tests
./tl3-compiler global/*.3.lm expression/*.3.lm syntax-tree/*.3.lm \
  statement/*.3.lm tests/*.3.lm tl4-compiler.3.lm
if [ $CC == "gcc" ]; then
  COVERAGE="-coverage -O0"
else
  COVERAGE=
fi
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  $COVERAGE tl4-compiler.c ../TL3/lumi.3.c -I. -I../TL3 -o tl4-compiler-tests
TEST_DIR=tests/ ./tl4-compiler-tests
diff tests/code-header.actual.c tests/code-header.expected.c
diff tests/expression-tests.actual.c tests/expression-tests.expected.c
diff tests/syntax-tree-tests.actual.c tests/syntax-tree-tests.expected.c
if [ ! -z "$COVERAGE" ]; then
  gcov tl4-compiler.c > gcov.log
fi

# run tl4-compiler single-file integration test
./tl4-compiler tests/integration-actual-single.c tests/integration-test0.4.lm
diff ../TL4/tests/integration-expected-single.c \
  tests/integration-actual-single.c
$CCA tests/integration-actual-single.c ../TL4/lumi.4.c -I../TL4 \
  -o test-tl4-single
./test-tl4-single > tests/integration-single-output.txt
diff ../TL4/tests/integration-single-output.txt \
  tests/integration-single-output.txt

# run tl4-compiler multiple-file integration test
./tl4-compiler -t covered tests/integration-actual-multiple.c \
  tests/integration-test0.4.lm tests/integration-test1.4.lm \
  tests/integration-test2.4.lm
diff ../TL4/tests/integration-expected-multiple.c \
  tests/integration-actual-multiple.c
$CCA tests/integration-actual-multiple.c ../TL4/lumi.4.c \
  ../TL4/tests/integration-external.c -I../TL4 -o test-tl4-multiple
./test-tl4-multiple -xml > tests/integration-multiple-output.txt
mkdir cover-tl4-tests
mv cobertura.xml cover-tl4-tests
diff ../TL4/tests/integration-multiple-output.txt \
  tests/integration-multiple-output.txt
diff ../TL4/tests/expected-cobertura.xml cover-tl4-tests/cobertura.xml

# run tl4-compiler coverage fail integration test
./tl4-compiler -t integration tests/integration-actual-uncovered.c \
  tests/integration-test0.4.lm tests/integration-test1.4.lm \
  tests/integration-test2.4.lm
diff ../TL4/tests/integration-expected-uncovered.c \
  tests/integration-actual-uncovered.c
$CCA tests/integration-actual-uncovered.c ../TL4/lumi.4.c \
  ../TL4/tests/integration-external.c -I../TL4 -o test-tl4-uncovered
! ./test-tl4-uncovered > tests/integration-uncovered-output.txt
diff ../TL4/tests/integration-uncovered-output.txt \
  tests/integration-uncovered-output.txt

# run tl4-compiler error integration test
./tl4-compiler -t error tests/integration-actual-error.c \
  tests/integration-error-test.4.lm
diff ../TL4/tests/integration-expected-error.c tests/integration-actual-error.c
$CCA tests/integration-actual-error.c ../TL4/lumi.4.c -I../TL4 -o test-tl4-error
! ./test-tl4-error > tests/integration-error-output.txt
diff ../TL4/tests/integration-error-output.txt \
  tests/integration-error-output.txt

# test tl4-compiler on tl5-compiler files
mkdir TL5
cp -r ../TL5/*/ TL5
cp ../TL5/*.4.lm TL5
./tl4-compiler tl5-compiler.c TL5/tl5-compiler.4.lm TL5/*/*.4.lm
diff ../TL5/tl5-compiler.c tl5-compiler.c


# --< TL5 >--

# compile tl5-compiler
$CC ../TL5/tl5-compiler.c ../TL4/lumi.4.c -I../TL4 -o tl5-compiler


# --< lumi command >--

# test tl4-compiler on lumi command files
./tl4-compiler lumi.c lumi.4.lm
diff ../lumi.c lumi.c

# compile lumi command
$CCA ../lumi.c ../TL4/lumi.4.c -I../TL4 -o lumi

# run lumi command tests
./tl4-compiler -t lumi lumi-tests.c lumi.4.lm lumi-tests.4.lm
$CCA lumi-tests.c ../TL4/lumi.4.c -I../TL4 -o lumi-tests
./lumi-tests -xml
mkdir cover-lumi-tests
mv cobertura.xml cover-lumi-tests

# run lumi command on TL4 integration tests
PATH="$PATH:." LUMIPATH=".." ./lumi tests/integration-test0.4.lm \
  -o test-lumi-single
diff ../TL4/tests/integration-expected-single.c test-lumi-single.c
./test-lumi-single > lumi-integration-single-output.txt
diff ../TL4/tests/integration-single-output.txt \
  lumi-integration-single-output.txt
PATH="$PATH:." LUMIPATH=".." ./lumi -t covered tests/integration-test0.4.lm \
  tests/integration-test1.4.lm tests/integration-test2.4.lm -e \
  ../TL4/tests/integration-external.c -o test-lumi-multiple
diff ../TL4/tests/integration-expected-multiple.c test-lumi-multiple.c
./test-lumi-multiple > lumi-integration-multiple-output.txt
diff ../TL4/tests/integration-multiple-output.txt \
  lumi-integration-multiple-output.txt


# --< Standard Libraries >--

# run standard-libraries unit-tests
mkdir standard-libraries
cp ../standard-libraries/*.3.lm standard-libraries
cp ../standard-libraries/tests/*.3.lm standard-libraries
./tl3-compiler standard-libraries/*.3.lm
$CCW -Wno-unused-variable -Wno-missing-braces \
  standard-libraries/standard-libraries-tests.c ../TL3/lumi.3.c -I. -I../TL3 \
  -o standard-libraries-tests
./standard-libraries-tests


# --< Documentation >--

# compile examples
cp ../docs/*.lm .
./tl4-compiler hello-world.c hello-world.4.lm
$CCA hello-world.c ../TL4/lumi.4.c -I../TL4 -o hello-world
./tl4-compiler hello-world-test.c hello-world.4.lm hello-world-test.4.lm \
  -t hello-world
$CCA hello-world-test.c ../TL4/lumi.4.c -I../TL4 -o hello-world-test
./tl4-compiler examples.c examples.4.lm
$CCA examples.c ../TL4/lumi.4.c -I../TL4 -o run-examples

# run examples
./hello-world
./hello-world-test
./run-examples

# --< Teardown >--
cd ..
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf .test
fi


# All tests passed
