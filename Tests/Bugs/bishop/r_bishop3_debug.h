void bugrit(char *name, PyTypeObject *t) {
	printf("bugrit: %s: 0x%p\n", name, t);
	printf("tp_traverse = 0x%p\n", t->tp_traverse);
	printf("tp_clear = 0x%p\n", t->tp_clear);
}
