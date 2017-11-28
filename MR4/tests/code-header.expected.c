
typedef struct Test Test;
typedef struct Ta Ta;
typedef struct Ta_Dynamic Ta_Dynamic;
typedef struct Tb Tb;
typedef struct Tb_Dynamic Tb_Dynamic;
typedef struct Tc Tc;
typedef struct Tc_Dynamic Tc_Dynamic;
struct Test {
  Int num;
  Returncode (*fun)(void);
};
struct Ta {
  Test _base;
  Int numa;
};
struct Ta_Dynamic {
  Returncode (*dyn)(Ta** self, Ta_Dynamic* self_Dynamic);
};
struct Tb {
  Ta _base;
  Int numb;
};
struct Tb_Dynamic {
  Ta_Dynamic _base;
};
struct Tc {
  Tb _base;
  Int numc;
};
struct Tc_Dynamic {
  Tb_Dynamic _base;
};
Returncode Test_new(Test** self, Int num);
Returncode Test_meth(Test** self);
Returncode Ta_metha(Ta** self, Ta_Dynamic* self_Dynamic);
Returncode Ta_dyn(Ta** self, Ta_Dynamic* self_Dynamic);
Returncode Tb_methb(Tb** self, Tb_Dynamic* self_Dynamic);
Returncode Tb_dyn(Tb** self, Tb_Dynamic* self_Dynamic);
Returncode Tc_methc(Tc** self, Tc_Dynamic* self_Dynamic);
Returncode Tc_dyn(Tc** self, Tc_Dynamic* self_Dynamic);
Ta_Dynamic Ta_dynamic = {Ta_dyn};
Tb_Dynamic Tb_dynamic = {{(Func)Tb_dyn}};
Tc_Dynamic Tc_dynamic = {{{(Func)Tc_dyn}}};
Returncode fun0(void);
Returncode fun1(Int x, String** s, String** o);
Returncode fun2(String*** s, Int* x);
Returncode fun3(Int x, String*** s);
Returncode fun4(Int x);
Returncode fun5(Int x, Int* y);
Returncode fun6(Int x, Int y, Int* n, Int* m);
Returncode fun7(Tb*** tb, Tb_Dynamic** tb_Dynamic);
Returncode mock(Int i, Char c, Bool b, String** str, Array** arr, File** fobj, Test** t, Ta** ta, Ta_Dynamic* ta_Dynamic, Tb** tb, Tb_Dynamic* tb_Dynamic, Tc** tc, Tc_Dynamic* tc_Dynamic, String*** so, Int* io);
Returncode Test_new(Test** self, Int num) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Test_meth(Test** self) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Ta_metha(Ta** self, Ta_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Ta_dyn(Ta** self, Ta_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Tb_methb(Tb** self, Tb_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Tb_dyn(Tb** self, Tb_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Tc_methc(Tc** self, Tc_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Tc_dyn(Tc** self, Tc_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun0(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun1(Int x, String** s, String** o) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun2(String*** s, Int* x) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun3(Int x, String*** s) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun4(Int x) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun5(Int x, Int* y) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun6(Int x, Int y, Int* n, Int* m) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun7(Tb*** tb, Tb_Dynamic** tb_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode mock(Int i, Char c, Bool b, String** str, Array** arr, File** fobj, Test** t, Ta** ta, Ta_Dynamic* ta_Dynamic, Tb** tb, Tb_Dynamic* tb_Dynamic, Tc** tc, Tc_Dynamic* tc_Dynamic, String*** so, Int* io) {
  Returncode MR_err = OK;
  