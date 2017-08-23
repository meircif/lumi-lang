
Type(TestStruct) {
  Access(3) Int num
  Access(1) String text
}

TestStruct.Function(set)(Access(0) Int x, Access(1) String s) {
  Variable(self).Member(num) = Variable(x)
  Variable(self).Member(text) = Variable(s)
}

TestStruct.Function(get)()->(Access(0) Int x, Access(1) String s) {
  Variable(x) = Variable(self).Member(num)
  Variable(s) = Variable(self).Member(text)
}


Access(3) Int global-int

Access(3) Int CONSTANT-INT (Int(23))

Access(1) String global-string

Access(1) String CONSTANT-STRING (String("a constant string"))

Function(test-func)() {
  Variable(sys).Member(print)(Access(1) String("I am test func"))
}

Function(test-func)(Access(0) Int num, Access(1) String text)->(Access(0) Int out-num, Access(1) String out-text) {
  Variable(out-num) = Variable(num)
  Variable(out-text) = Variable(text)
}
