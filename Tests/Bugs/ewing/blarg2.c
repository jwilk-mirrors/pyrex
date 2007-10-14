struct __pyx_obj_6ewing6_C {
  struct __pyx_vtabstruct_6ewing6_C *__pyx_vtab;
};

struct __pyx_vtabstruct_6ewing6_C {
  void ((*a)(struct __pyx_obj_6ewing6_C *));
};

struct __pyx_obj_6ewing6_D {
  struct __pyx_obj_6ewing6_C __pyx_base;
};

/*typedef struct __pyx_obj_6ewing6_E EEE;*/

struct __pyx_vtabstruct_6ewing6_D {
  struct __pyx_vtabstruct_6ewing6_C __pyx_base;
  void ((*_render)(struct __pyx_obj_6ewing6_D *, struct __pyx_obj_6ewing6_E *));
};

struct __pyx_obj_6ewing6_E {
};

void f(void) {
  struct __pyx_obj_6ewing6_D *__pyx_v_d;
  struct __pyx_obj_6ewing6_E *__pyx_v_e;
	((struct __pyx_vtabstruct_6ewing6_D *)__pyx_v_d->__pyx_base.__pyx_vtab)->_render(__pyx_v_d, __pyx_v_e);
}
