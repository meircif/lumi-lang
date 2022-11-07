import sys
import ctypes

testlib = ctypes.cdll.LoadLibrary(sys.argv[1])

assert testlib.inc(12) == 13

testlib.get_string.restype = ctypes.c_char_p
assert testlib.get_string() == b"a constant string"

# assert `test` function is not exported
try:
    testlib.test
except AttributeError:
    pass

assert testlib.test_all() == 1
