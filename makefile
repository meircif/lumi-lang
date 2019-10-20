ifeq ($(CC),)
CC=gcc
endif

COMPILERS=$(foreach n,0 1 2 3 4 5,tl$(n)-compiler)
EXECUTABLES=lumi $(COMPILERS)

.PHONY: install uninstall all clean cp-bin

install: | cp-bin clean

uninstall:
		rm -f $(addprefix /usr/local/bin/,$(EXECUTABLES))

clean:
		rm -f $(EXECUTABLES)

cp-bin: all
		sudo install $(EXECUTABLES) /usr/local/bin/

all: $(EXECUTABLES)

lumi:
		$(CC) lumi-command/lumi.c TL4/lumi.4.c -ITL4 -o lumi

tl0-compiler:
		$(CC) TL0/tl0-compiler.c TL0/tl0-file.c TL0/tl0-string.c -o tl0-compiler

tl1-compiler:
		$(CC) TL1/tl1-compiler.c TL0/tl0-file.c TL0/tl0-string.c -ITL0 -o tl1-compiler

tl2-compiler:
		$(CC) TL2/tl2-compiler.c TL1/lumi.1.c -ITL1 -o tl2-compiler

tl3-compiler:
		$(CC) TL3/tl3-compiler.c TL2/lumi.2.c -ITL2 -o tl3-compiler

tl4-compiler:
		$(CC) TL4/tl4-compiler.c TL3/lumi.3.c -ITL3 -ITL4 -I. -o tl4-compiler

tl5-compiler:
		$(CC) TL5/tl5-compiler.c TL4/lumi.4.c -ITL4 -o tl5-compiler
