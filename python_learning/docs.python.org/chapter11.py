#!/usr/bin/python2.7
# -*- coding: utf-8 -*-
import os
import time

def Test_1():
    import repr
    print repr.repr(set('supercalifragilisticexpialidocious'))

    import pprint
    t = [[[['black', 'cyan'], 'white', ['green', 'red']], [['magenta','yellow'], 'blue']]]
    pprint.pprint(t)

    import textwrap
    doc = """ The wrap() method is just like fill() except that it returns
    a list of strings instead of one big string with newlines to separate
    the wrapped lines."""

    print textwrap.fill(doc, width=40)


def Test_2():
    from string import Template
    t = Template('${village}folk send $$10 to $cause.')
    print t.substitute(village='nottingham', cause='the ditch fund')

def Test_3():
    import struct
    data = open('./test.zip','rb').read()

    start = 0
    for i in range(3):  # show the first 3 file headers
        start += 14
        fields = struct.unpack('<IIIHH', data[start:start + 16])
        crc32, comp_size, uncomp_size, filenamesize, extra_size = fields

        start += 16
        filename = data[start:start + filenamesize]
        start += filenamesize
        extra = data[start:start + extra_size]
        print filename, hex(crc32), comp_size, uncomp_size

        start += extra_size + comp_size  # skip to the next header

def Test_4():
    import threading, zipfile
    class AsyncZip(threading.Thread):
        def __init__(self,infile, outfile):
            threading.Thread.__init__(self)
            self._infile = infile
            self._outfile = outfile

        def run(self):
            f = zipfile.ZipFile(self._outfile, 'w', zipfile.ZIP_DEFLATED)
            f.write(self._infile)
            f.close()
            print 'Finished background zip of :', self._infile

    background = AsyncZip('./test.html','./test_2.zip')
    background.start()
    background.join()

def Test_5():
    from array import array
    a = array('H', [4000,10,700,22222])
    print sum(a)

    print a[1:2]

    from collections import deque
    d = deque(["task1","task2","task3"])
    d.append("task4")

    print "Handing", d.popleft()

    import bisect
    scores = [(100,'perl'),(200,'tcl'),(400,'lua'),(500,'python')]
    bisect.insort(scores,(300,'ruby'))

    print scores

    from heapq import heapify, heappop, heappush
    data = [1,3,5,7,9,2,4,6,8,0]
    heapify(data)
    print data

    heappush(data, -5)
    print data

    [ heappop(data) for i in range(3)]
    print data


def Test_6():
    from decimal import Decimal
    x = Decimal('0.70') * Decimal('1.05')
    print x

    y = x.quantize(Decimal('0.1'))
    print y

    print round(.70 * 1.05,2)


Test_6()