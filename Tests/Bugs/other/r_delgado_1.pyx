cdef class eggs:

  def __dealloc__(self):
    pass

  def eat(self):
    raise RuntimeError("I don't like that")

