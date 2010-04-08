struct Foo {
	Foo();
	int i;
	virtual ~Foo();
	virtual int blarg();
};

struct Blarg {
	Blarg(int, float);
	Blarg(int, char *);
	int j;
	virtual ~Blarg();
};

struct SubFoo : Foo, Blarg {
	int k;
	virtual void zax();
};

struct Zax {
};
