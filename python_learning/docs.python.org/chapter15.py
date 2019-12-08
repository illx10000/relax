#!/usr/bin/python2.7
# -*- coding: utf-8 -*-

def Test_1():
    import os
    filename = os.environ.get('PYTHONSTARTUP')
    if filename and os.path.isfile(filename):
        with open(filename) as fobj:
            startup_file = fobj.read()
        exec(startup_file)

def Test_2():
    import site
    print site.getusersitepackages()

Test_2()