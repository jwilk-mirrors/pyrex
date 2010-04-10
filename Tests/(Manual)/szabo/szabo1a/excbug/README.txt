How to reproduce the bug
~~~~~~~~~~~~~~~~~~~~~~~~
Requirements:

* a Unix system (tested on Linux)
* possibly PC architecture (tested on i386)
* Python 2.6 (tested with Stackless Python 2.6.4) installed as python2.6
* Pyrex version 0.9.8.5 installed for Python 2.6
* development tools (gcc) and libraries

Installation once the requirements are met:

  $ pyrexc excbug.pyx
  $ python2.6 setup.py build
  $ sudo python2.6 setup.py install

To see the bug, run this in a separate terminal window,

  $ python2.6 server1.py

, and keep it running. Then run this in another terminal window:

  $ python2.6 client.py

The client makes 300 SSL requests to the server. The bug causes the server
to die (usually with a Segmentation fault or Aborted) or hang after a few
(between 3 and 20) requests. The bug can be reproduced with Pyrex, but it
always works with Cython.

Sorry for not being able to create a smaller example code. I couldn't
reproduce the bug with anything simpler.
