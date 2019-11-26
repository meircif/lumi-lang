#!/bin/bash
set -ev

# --< lumi command >--

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
CCA="$CCW --pedantic -Wno-unused-label -Wno-overlength-strings"
if [ $CC == "gcc" ]; then
  CCA="$CCA -Wno-unused-but-set-variable"
else
  CCA="$CCA -Wno-self-assign"
fi

rm -rf $DIR/.test/lumi
mkdir -p $DIR/.test/lumi
pushd $DIR/.test


# compile tl4-compiler
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../TL4/tl4-compiler.c ../TL3/lumi.3.c -I../TL3 -I../TL4 -o lumi/tl4-compiler

# test lumi command C file
cp -r ../lumi-command lumi/
pushd lumi
./tl4-compiler lumi.c lumi-command/lumi.4.lm
popd
diff $MYDIR/lumi.c lumi/lumi.c

# compile lumi command
$CCA $MYDIR/lumi.c ../TL4/lumi.4.c -I../TL4 -o lumi/lumi

# run lumi command tests
lumi/tl4-compiler -t lumi lumi/lumi-tests.c $MYDIR/lumi.4.lm \
  $MYDIR/lumi-tests.4.lm
$CCA lumi/lumi-tests.c ../TL4/lumi.4.c -I../TL4 -o lumi/lumi-tests
lumi/lumi-tests -xml
mv cobertura.xml lumi/

# run lumi command on TL4 integration tests
cp -r ../TL4/tests lumi/
pushd lumi
PATH="$PATH:$DIR/.test/lumi" LUMIPATH="$DIR/" ./lumi \
  tests/integration-test0.4.lm -o test-single
diff ../../TL4/tests/integration-expected-single.c test-single.c
./test-single > single-output.txt
diff ../../TL4/tests/integration-single-output.txt single-output.txt
PATH="$PATH:$DIR/.test/lumi" LUMIPATH="$DIR/" ./lumi -t covered \
  tests/integration-test0.4.lm tests/integration-test1.4.lm \
  tests/integration-test2.4.lm -e tests/integration-external.c -o test-multiple
diff ../../TL4/tests/integration-expected-multiple.c test-multiple.c
./test-multiple > multiple-output.txt
diff ../../TL4/tests/integration-multiple-output.txt multiple-output.txt
popd
  

# lumi command teardown
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf lumi
fi
popd


# lumi command tests passed
