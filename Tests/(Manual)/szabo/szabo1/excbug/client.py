import socket
import ssl

for i in xrange(300):
  print '.',
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  ss = ssl.SSLSocket(sock)
  ss.connect(('127.0.0.1', 44433))
  ss.sendall('foo')
  ss.close()
print 'Client finished OK.'
