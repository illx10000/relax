#!/usr/bin/python2.7
# -*- coding: UTF-8 -*-

def Test_1():
    class MyClass:
        """A simple example class"""
        i = 123456

        def f(self):
            return 'hello world'

        def __init__(self):
            self.data = []

def Test_2():
    class Complex:
        def __init__(self,realpart, imagepart):
            self.r = realpart
            self.i = imagepart

    x = Complex(3.0,-4.5)
    print x.r, x.i
    x.counter = 1

    while x.counter < 10:
        x.counter = x.counter * 2
    print x.counter

def Test_3():
    class Tinstance():
        print "hello,world"

def Test_4():
    class Dog:
        kind='canine'
        def __init__(self,name):
            self.name = name

    d = Dog('Fido')
    e = Dog('Buddy')
    print d.kind
    print e.kind
    print d.name
    print e.name


def Test_5():
    class Dog:
        tricks = []
        def __init__(self,name):
            self.name = name

        def add_trick(self, trick):
            self.tricks.append(trick)

    d = Dog('Fido')
    e = Dog('Buddy')
    d.add_trick('roll')
    e.add_trick('play')

    print d.tricks

def Test_6():
    class Dog:
        def __init__(self, name):
            self.name = name
            self.tricks = []

        def add_trick(self, trick):
            self.tricks.append(trick)

    d = Dog('Fido')
    e = Dog('Buddy')
    d.add_trick('roll')
    e.add_trick('play')

    print d.tricks

Test_6()




