#!/bin/bash
set -ev

# setup
if [ -z $CC ]; then
  CC=gcc
fi
CCW="$CC --std=c89 -Wall -Werror"
rm -rf .test
mkdir .test
cp *.mr .test
cp MR*/*.mr .test
cd .test

# MR0
$CCW ../MR0/mr0-compiler.c ../MR0/mr0-file.c ../MR0/mr0-string.c -o mr0-compiler
./mr0-compiler mr0-compiler.0.mr mr0-compiler.c
diff ../MR0/mr0-compiler.c mr0-compiler.c
./mr0-compiler mr1-compiler.0.mr mr1-compiler.c
diff ../MR1/mr1-compiler.c mr1-compiler.c

# MR1
$CCW ../MR1/mr1-compiler.c ../MR0/mr0-file.c ../MR0/mr0-string.c -I../MR0 \
  -o mr1-compiler
./mr1-compiler mr2-compiler.1.mr mr2-compiler.c
diff ../MR2/mr2-compiler.c mr2-compiler.c

# MR2
$CCW -Wno-parentheses ../MR2/mr2-compiler.c ../MR1/mr.1.c -I../MR1 \
  -o mr2-compiler
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

# MR3
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../MR3/mr3-compiler.c ../MR2/mr.2.c -I../MR2 -o mr3-compiler
mkdir global expression syntax-tree
cp ../MR4/global/*.3.mr global
cp ../MR4/expression/*.3.mr expression
cp ../MR4/syntax-tree/*.3.mr syntax-tree
./mr3-compiler global/*.3.mr expression/*.3.mr syntax-tree/*.3.mr \
  mr4-compiler.3.mr
diff ../MR4/global global
diff ../MR4/expression expression
diff ../MR4/syntax-tree syntax-tree
diff ../MR4/mr4-compiler.c mr4-compiler.c

# MR4
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  ../MR4/mr4-compiler.c ../MR3/mr.3.c -I../MR3 -I../MR4 -o mr4-compiler
mkdir tests
cp ../MR4/tests/*.3.mr tests
./mr3-compiler global/*.3.mr expression/*.3.mr syntax-tree/*.3.mr \
  tests/*.3.mr mr4-compiler.3.mr
$CCW -Wno-unused-variable -Wno-missing-braces -Wno-typedef-redefinition \
  mr4-compiler.c ../MR3/mr.3.c -I. -I../MR3 -o mr4-compiler-tests
./mr4-compiler-tests
./mr4-compiler tests/integration-actual-single.c \
  ../MR4/tests/integration-test1.4.mr
diff ../MR4/tests/integration-expected-single.c \
  tests/integration-actual-single.c

# MRB
./mr3-compiler mrb.3.mr
diff ../mrb.c mrb.c
$CCW ../mrb.c ../MR3/mr.3.c -I. -I../MR3 -o mrb

# teardown
cd ..
rm -rf .test
