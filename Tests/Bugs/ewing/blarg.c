/*typedef struct foo Foo;*/

void g(struct foo *x) {
}

void f(void) {
	void (*h)(struct foo *);
	h = g;
}
