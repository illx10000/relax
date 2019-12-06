#!/usr/bin/python2.7
# -*- coding: utf-8 -*-
import os
import time

def Test_1():
    print os.getcwd()
    print os.chdir('/Users/luoxi/Desktop/python/unit_test')
    print os.system('mkdir today')

    dir(os)
    print help(time)

def Test_2():
    import glob
    print glob.glob('*.py')
    print help(glob)

def Test_3():
    import sys
    print sys.argv

def Test_4():
    import sys
    sys.stderr.write('Warning, log file not found starting a new one\n')

def Test_5():
    import re
    print re.findall(r'\bf[a-z]*', 'which foot or hand fell fastest')
    print re.sub(r'(\b[a-z]+) \1', r'\1', 'cat in the the hat')
    #print help(re)
    print 'tea for too'.replace('too', 'two')

def Test_6():
    import math
    print math.cos(math.pi*2)
    import random
    print random.choice(['apple','pear','banana'])
    print random.sample(xrange(1000),10)
    print random.random()
    print random.randrange(10)
    print help(random)


def Test_7():
    import urllib2
    for line in urllib2.urlopen("https://docs.python.org/2/tutorial/stdlib.html"):
        print line


def Test_8():
    from datetime import date
    now = date.today()
    print now
    print now.strftime("%m-%d-%y. %d %b %Y is a %A on the %d day of %B.")

    birthday = date(1994,2,27)
    age = now - birthday
    print age.days

def Test_9():
    import zlib
    s = 'witch witch which has which witches wrist watch'
    print len(s)

    t = zlib.compress(s)
    print len(t)

    print zlib.decompress(t)

    print zlib.crc32(t)

def Test_10():
    from timeit import Timer
    print Timer('t=a;a=b;b=t','a=1;b=2').timeit()

def Test_11():
    import doctest

    def arerage(values):
        return sum(values,0.0)/len(values)

    import unittest
    class TestStatistcalFunctions(unittest.TestCase):
        def test_average(self):
            self.assertEqual(arerage([20,30,70]),40.0)
            self.assertEqual(round(arerage([1,5,7]),1),4.3)

            with self.assertRaises(ZeroDivisionError):
                arerage([])
            with self.assertRaises(TypeError):
                arerage(20,30,70)

    print unittest.main()


Test_11()
