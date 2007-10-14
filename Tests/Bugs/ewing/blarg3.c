void glColor4fv(float *v) {
}

void (*h)(float *v);

void f(void) {
	h = glColor4fv;
}
