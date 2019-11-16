#!/usr/bin/python2.7
# -*- coding=utf-8 -*-

def Test7_1():
    s = 'Hello, world'
    print str(s)
    print repr(s)
    print str(1.0/7.0)
    x = 10 * 3.25
    y = 200*200
    s = 'The value of x is' + repr(x) + ', and y is ' + repr(y) + '...'
    print s
    hello = 'hello, world\n'
    hellos = repr(hello)
    print hellos

    print repr((x,y,('spam','eggs')))


def Test7_2():
    for x in range(1,11):
        print repr(x).rjust(2), repr(x*x).rjust(3), repr(x*x*x).rjust(4)

def Test7_3():
    for x in range(1,11):
        print '{0:2d} {1:3d} {2:4d}'.format(x,x*x,x*x*x)

def Test7_4():
    print '12'.zfill(5)
    print '-3.14'.zfill(7)
    print '3.14159265359'.zfill(5)

def Test7_5():
    print 'We are the {} who say "{}!"'.format('knights',"hi")
    print 'the story of {0},{1} and {other}.'.format('Bill','Manfred',other='Gerog')

    import math
    print 'The value of PI is approximately {}.'.format(math.pi)
    print 'The value of PI is appromimately {!r}'.format(math.pi)
    print 'The value of PI is appromimately {0:.3f}.'.format(math.pi)

    table = {'Sjoerd':4127, 'Jack':4098, 'Dcab':7678}
    for name, phone in table.iteritems():
        print '{0:10} ==> {1:10d}'.format(name,phone)

    print ('Jack:{0[Jack]:d}; Sjoerd:{0[Sjoerd]:d}; Dcab:{0[Dcab]:d}').format(table)

def Test7_6():
    import math
    print 'The value of PI is approximately %5.3f.' % math.pi

def Test7_8():
    #f = open('./test.html','wr')
    #print f.readline()
    #print f.readline()
    #f.write('This is a test\n')
    with open('./test.html','r') as f:
        read_data = f.read()

def Test7_9():
    import json
    print json.dumps([1,'simple','list'])

Test7_9()
