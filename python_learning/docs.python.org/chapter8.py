#!/usr/bin/python2.7
# -*- coding=utf-8 -*-

import os
import sys

def Test8_1():
    while True:
        try:
            x = int(raw_input("input a number:"))
            break
        except ValueError:
            print "Oops! That was no valid number. Try again"


def Test8_2():
    import sys

    try:
        f = open('test.html')
        s = f.readline()
        i = int(s.strip())

    except IOError as e:
        print "IO error({0}):{1}".format(e.errno,e.strerror)
    except ValueError:
        print "Could not convert data into a interger"
    except:
        print "unexpected error:", sys.exc_info()[0]
        raise

def Test8_3():
    for arg in sys.argv[1:]:
        try:
            f = open(arg,'r')
        except IOError:
            print 'cant opend', arg
        else :
            print arg, ' has ', len(f.readline()), 'lines'
            f.close()


def Test8_4():
    try:
        raise Exception('spam','eggs')
    except Exception as inst:
        print type(inst)
        print inst.args
        print inst
        x, y = inst.args
        print 'x = ', x
        print 'y = ', y


class MyError(Exception):
    def __init__(self,value):
        self.value = value

    def __str__(self):
        return repr(self.value)


def Test8_5():
    try:
        raise MyError(2*2)
    except MyError as e:
        print 'my execption occured. value:', e.value

def Test8_6():
    try:
        raise KeyboardInterrupt
    finally:
        print 'Goodbye, world'

Test8_6()