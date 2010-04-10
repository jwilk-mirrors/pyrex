# by pts@fazekas.hu at Sun Feb 14 21:02:26 CET 2010

# This doesn't matter much, we'll get a segfault anyway.
#import gc
#gc.disable()

import errno
import os
import os.path
import select
import socket
import ssl
import sys

import excbug

def iowrap(f):
  try:
    return excbug.iowrap(f)
  except IOError, e:
    return e

def iowrap2(f):
  try:
    return f()
  except IOError, e:
    return e

class sockwrapper(object):
  def __init__(self, sock):
    self.sock = sock
  _sock = property(lambda self: self.sock)

def handle_bug_eagain(fd, iswrite):
    p = select.poll()
    if iswrite:
        p.register(fd, select.POLLOUT)
    else:
        p.register(fd, select.POLLIN)
    p.poll()

def hrecv(sslsock, buflen):
    while 1:
        #print "hrecv"
        e = excbug.iowrap(sslsock._sslobj.read)
        if not isinstance(e, IOError):
            return e
        assert isinstance(e, ssl.SSLError)
        if e.args[0] == ssl.SSL_ERROR_WANT_READ:
            handle_bug_eagain(sslsock.fileno(), 0)
        elif e.args[0] == ssl.SSL_ERROR_WANT_WRITE:
            handle_bug_eagain(sslsock.fileno(), 1)
        else:
            assert 0

def faccept(sslsock, sockwrapper):
    while True:
        print "faccept", sys.exc_info()
        e = excbug.iowrap(sslsock._sock.accept)
        print ".......", sys.exc_info()
        if e is not None and not isinstance(e, IOError):
            break
        assert e is None or e.errno == errno.EAGAIN
        handle_bug_eagain(sslsock.fileno(), 0)
    asock, addr = e
    asslsock = bugsub(
        sockwrapper(asock),
        keyfile=sslsock.keyfile,
        certfile=sslsock.certfile,
        server_side=True,
        cert_reqs=sslsock.cert_reqs,
        ssl_version=sslsock.ssl_version,
        ca_certs=sslsock.ca_certs,
        do_handshake_on_connect=False,
        suppress_ragged_eofs=sslsock.suppress_ragged_eofs)
    if sslsock.do_handshake_on_connect:
        asslsock.sslsock.do_handshake_on_connect = True
        while 1:
            try:
                asslsock.sslsock._sslobj.do_handshake()
                break
            except ssl.SSLError, e:
                if e.errno == ssl.SSL_ERROR_WANT_READ:
                    handle_bug_eagain(asslsock.sslsock.fileno(), 0)
                elif e.errno == ssl.SSL_ERROR_WANT_WRITE:
                    handle_bug_eagain(asslsock.sslsock.fileno(), 1)
                else:
                    raise
    return (asslsock, addr)


class bugsub(object):
    def __init__(self, *args, **kwargs):
        self.sslsock = ssl.SSLSocket(*args, **kwargs)
        self.sslsock.setblocking(False)  # Having blocking prevents segfault.

class Foo(object):
  def __del__(self):
    try:
      assert 0
    except:
      pass

def HandleRequestSock(csslsock):
  f = Foo()
  hrecv(csslsock.sslsock, 1)
  csslsock.sslsock.close()

if __name__ == '__main__':
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
  sock.bind(('127.0.0.1', 44433))
  sock.listen(128)
  sslsock = ssl.SSLSocket(
      sock,
      certfile=os.path.join(os.path.dirname(__file__), 'ssl_cert.pem'),
      keyfile=os.path.join(os.path.dirname(__file__), 'ssl_key.pem'))
  sslsock.setblocking(False)
  while True:
    csslsock, addr = faccept(sslsock, sockwrapper)
    HandleRequestSock(csslsock)
