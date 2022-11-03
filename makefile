CC?=gcc
BUILDDIR?=.build
INSTALLDIR?=/usr/local/bin/

EXECUTABLES=lumi $(foreach n,0 1 2 3 4 5,tl$(n)-compiler)
EXECUTABLE_PATHS=$(addprefix $(BUILDDIR)/,$(EXECUTABLES))

.PHONY: install uninstall all clean cp-bin stdlib-tests tl5-integration \
	tl5-integration-output

install: | cp-bin clean

uninstall:
	rm -f $(addprefix $(INSTALLDIR),$(EXECUTABLES))

clean:
	rm -f $(EXECUTABLE_PATHS)

cp-bin: all
	sudo install $(EXECUTABLE_PATHS) $(INSTALLDIR)

all: $(EXECUTABLES)

build-dir:
	mkdir -p $(BUILDDIR)

lumi: build-dir
	$(CC) lumi-command/lumi.c TL4/lumi.4.c -ITL4 -o $(BUILDDIR)/lumi

tl0-compiler: build-dir
	$(CC) TL0/tl0-compiler.c TL0/tl0-file.c TL0/tl0-string.c -o \
	$(BUILDDIR)/tl0-compiler

tl1-compiler: build-dir
	$(CC) TL1/tl1-compiler.c TL0/tl0-file.c TL0/tl0-string.c -ITL0 -o \
		$(BUILDDIR)/tl1-compiler

tl2-compiler: build-dir
	$(CC) TL2/tl2-compiler.c TL1/lumi.1.c -ITL1 -o $(BUILDDIR)/tl2-compiler

tl3-compiler: build-dir
	$(CC) TL3/tl3-compiler.c TL2/lumi.2.c -ITL2 -o $(BUILDDIR)/tl3-compiler

tl4-compiler: build-dir
	$(CC) TL4/tl4-compiler.c TL3/lumi.3.c -ITL3 -ITL4 -I. -o \
		$(BUILDDIR)/tl4-compiler

tl5-compiler: build-dir
	$(CC) TL5/tl5-compiler.c TL4/lumi.4.c -ITL4 -o $(BUILDDIR)/tl5-compiler

lumi.c:
	lumi -c lumi-command/lumi.4.lm

lumi-tests: build-dir
	lumi -t lumi lumi-command/lumi.4.lm lumi-command/lumi-tests.4.lm -o \
		$(BUILDDIR)/lumi-tests -r

lumi-install: lumi.c lumi
	sudo install $(BUILDDIR)/lumi $(INSTALLDIR)
	rm -f $(BUILDDIR)/lumi

docs-tests: build-dir
	lumi docs/hello-world.5.lm -o $(BUILDDIR)/hello-world -r
	lumi -t hello-world docs/hello-world.5.lm docs/hello-world-test.5.lm -o \
		$(BUILDDIR)/hello-world-test -r
	lumi docs/examples.5.lm -o $(BUILDDIR)/examples -r

math-tests: build-dir
	lumi -t math stdlib/math.5.lm stdlib/tests/math-tests.5.lm -o \
		$(BUILDDIR)/math-tests -r

ds-tests: build-dir
	lumi -t ds stdlib/list.5.lm stdlib/dict.5.lm stdlib/tests/list-tests.5.lm \
		stdlib/tests/dict-tests.5.lm -o $(BUILDDIR)/ds-tests -r

time-tests: build-dir
	lumi -t time stdlib/time.5.lm stdlib/tests/time-tests.5.lm -e --std=c89 \
		-e -Istdlib/tests -o $(BUILDDIR)/time-tests -r

os-tests: build-dir
	lumi -t os stdlib/os.5.lm stdlib/tests/os-tests.5.lm stdlib/list.5.lm \
		-e -Istdlib/tests -o $(BUILDDIR)/os-tests -r

zlib-tests: build-dir
	lumi -t zlib stdlib/zlib.5.lm stdlib/tests/zlib-tests.5.lm \
		-e -Istdlib/tests -o $(BUILDDIR)/zlib-tests -r

stdlib-tests: | math-tests ds-tests time-tests os-tests zlib-tests

tl0-compiler.c:
	lumi -c TL0/tl0-compiler.0.lm

tl1-compiler.c:
	lumi -c TL1/tl1-compiler.0.lm

tl2-compiler.c:
	lumi -c TL2/tl2-compiler.1.lm

tl3-compiler.c:
	cd TL3 && lumi -c common.2.lm map.2.lm global.2.lm exp.2.lm st-node.2.lm \
		flow.2.lm args.2.lm func.2.lm member.2.lm call.2.lm operand.2.lm dec.2.lm \
		type.2.lm test.2.lm tl3-compiler.2.lm

tl4-compiler.c:
	cd TL4 && lumi -c tl4-compiler.3.lm global/*.3.lm expression/*.3.lm \
		syntax-tree/*.3.lm statement/*.3.lm

tl4-install: tl4-compiler.c tl4-compiler
	sudo install $(BUILDDIR)/tl4-compiler $(INSTALLDIR)
	rm -f $(BUILDDIR)/tl4-compiler

tl4-tests: build-dir
	cd TL4 && tl3-compiler global/*.3.lm expression/*.3.lm  \
		syntax-tree/*.3.lm statement/*.3.lm tests/*.3.lm tl4-compiler.3.lm
	cd TL4 && $(CC) -g tl4-compiler.c ../TL3/lumi.3.c -I. -I../TL3 \
		-o ../$(BUILDDIR)/tl4-compiler-tests
	TEST_DIR=TL4/tests/ $(BUILDDIR)/tl4-compiler-tests

tl5-compiler.c: build-dir
	lumi TL5/string-generator.4.lm -o $(BUILDDIR)/string-generator
	$(BUILDDIR)/string-generator TL5/lumi.5.c TL5/global/header-string.4.lm
	lumi -c TL5/tl5-compiler.4.lm TL5/*/*.4.lm

tl5-install: tl5-compiler.c tl5-compiler
	sudo install $(BUILDDIR)/tl5-compiler $(INSTALLDIR)
	rm -f $(BUILDDIR)/tl5-compiler

tl5-ut: build-dir
	lumi -t tl5-compiler TL5/tl5-compiler.4.lm TL5/*/*.4.lm TL5/tests/ut/*.4.lm \
		-o $(BUILDDIR)/tl5-compiler-tests -r -ra TL5/tests/ut/

tl5-run-ut: build-dir
	$(BUILDDIR)/tl5-compiler-tests TL5/tests/ut/

tl5-run-ut-trace: build-dir
	$(BUILDDIR)/tl5-compiler-tests TL5/tests/ut/ --trace

tl5-single-test: build-dir
	lumi TL5/tests/integration/test0.5.lm -o $(BUILDDIR)/single -r

tl5-single-test-output: build-dir
	lumi TL5/tests/integration/test0.5.lm -o $(BUILDDIR)/single -r > \
		TL5/tests/integration/single-output.txt

tl5-lib-test: build-dir
	lumi -l integration TL5/tests/integration/test0.5.lm \
	-o $(BUILDDIR)/libtest.so
	python TL5/tests/integration/test-lib.py $(BUILDDIR)/libtest.so

tl5-multiple-test: build-dir
	lumi -t covered TL5/tests/integration/test*.5.lm -e \
		TL5/tests/integration/external.c -e -ITL5/tests/integration -o \
		$(BUILDDIR)/multiple -r

tl5-multiple-test-output: build-dir
	lumi -t covered TL5/tests/integration/test*.5.lm -e \
		TL5/tests/integration/external.c -e -ITL5/tests/integration -o \
		$(BUILDDIR)/multiple -r -ra -xml > \
		TL5/tests/integration/multiple-output.txt
	mv cobertura.xml TL5/tests/integration/expected-cobertura.xml

tl5-uncovered-test: build-dir
	! lumi -t integration TL5/tests/integration/test*.5.lm -e \
		TL5/tests/integration/external.c -e -ITL5/tests/integration -o \
		$(BUILDDIR)/uncovered -r

tl5-uncovered-test-output: build-dir
	! lumi -t integration TL5/tests/integration/test*.5.lm -e \
		TL5/tests/integration/external.c -e -ITL5/tests/integration -o \
		$(BUILDDIR)/uncovered -r > TL5/tests/integration/uncovered-output.txt

tl5-error-test: build-dir
	! lumi -t error TL5/tests/integration/error-test.5.lm -o $(BUILDDIR)/error -r

tl5-error-test-output: build-dir
	! lumi -t error TL5/tests/integration/error-test.5.lm -o $(BUILDDIR)/error \
		-r > TL5/tests/integration/error-output.txt

tl5-integration: | tl5-single-test tl5-multiple-test tl5-uncovered-test \
	tl5-error-test

tl5-integration-output: | tl5-single-test-output tl5-multiple-test-output \
	tl5-uncovered-test-output tl5-error-test-output
