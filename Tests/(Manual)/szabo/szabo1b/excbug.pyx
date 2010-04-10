def iowrap(f):
  try:
    return f()
  except IOError, e:
    return e
