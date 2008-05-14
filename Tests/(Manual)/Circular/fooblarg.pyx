from foo cimport Foo
from blarg cimport Blarg

cdef Foo eff
cdef Blarg bee

eff = Foo()
eff.name = "Henry"

bee = Blarg()
bee.name = "Algernon"

eff.b = bee
bee.f = eff

eff.report()
bee.report()
