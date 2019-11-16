#!/usr/bin/python2.7
# -*- coding: UTF-8 -*-

def Test5_1():
    a = [66.25, 333, 333, 1, 1234.5]
    print a.count(333), a.count(66.25), a.count('x')

    a.insert(0,-1)
    a.append(333)
    print a

    print a.index(333)
    a.remove(333)
    print a

    a.reverse()
    print a

    a.sort()
    print a

    a.pop()
    print a


def Test5_1_1():
    stack = [3,4,5]
    stack.append(6)
    stack.append(7)
    print stack

    stack.pop()
    print stack

    print stack.pop()
    print stack.pop()
    print stack


def Test5_1_2():
    from collections import deque
    queue = deque(['Reic','John','Michael'])
    queue.append('Terry')
    queue.append('Gtaham')
    print queue.popleft()
    print queue.popleft()
    print queue

def Test5_1_3():
    def f_1(x):
        return x % 3 == 0 or x % 5 == 0
    print filter(f_1, range(2,25))

    def cube(x):
        return x**3
    print map(cube, range(1,10))

    def add(x,y):
        return x+y
    print reduce(add, range(0,10))

def Test5_1_4():
    squares = []
    for x in range(1,10):
        squares.append(x ** 2)
    #print squares

    squares = [x*2 for x in range(1,10)]
    #print squares

    pair = [(x,y) for x in [1,2,3] for y in [3,2,4] if x != y]
    #print pair

    vec = [-4,-2,0,2,4]
    print [ v*2 for v in vec]
    print [x for x in vec if x >= 0]
    print [abs(x) for x in vec]
    freshfruit = ['  banana', '  loganberry ', 'passion fruit  ']
    print [weapon.strip() for weapon in freshfruit]

    vec = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print [num for x in vec for num in x]

    from math import pi
    print [str(round(pi,i)) for i in range(100,105)]


def Test5_1_4_1():
    matrix = [
        [1,2,3,4],
        [5,6,7,8],
        [9,10,11,12],
    ]

    print [[row[i] for row in matrix] for i in range(4)]
    #print matrix

def Test5_2():
    a = [-1,1,66.25,333,333,1234.5]
    del a[0]
    print a

    del a[2:4]
    print a

    del a[:]
    print a

def Test5_3():
    t = 12345,54321, 'hello'
    print t[0]
    print t
    u = t,(1,2,3,4,5)
    print u

    empty = ()
    singleton = 'hello'
    print len(empty)
    print len(singleton)
    print singleton

def Test5_4():
    basket = ['apple','orange', 'apple', 'pear', 'orange', 'banana']
    fruit = set(basket)
    print fruit
    print 'orange' in fruit
    print 'ssss' in fruit

    a = set('abracadabra')
    b = set('alacazam')

    print a-b
    print a|b
    print a&b
    print a^b
    print (a|b)-(a&b)

    x = { k for k in 'abracadabra' if k not in 'abc'}
    print x

def Test5_5():
    tel = {'jack':4098, 'sape': 4139}
    tel['guido'] = 4127

    print tel
    print tel['jack']
    del  tel['sape']
    tel['irv'] = 4127
    print tel

    print tel.keys()
    print 'guido' in tel

    ra = dict([('sape',4139),('guido',4127),('jack',4098)])
    print ra

    t  = { x:x**2 for x in range(2,8,2) }
    print t


def Test5_6():
    #for i,v in enumerate(['tic','tac','toe']):
    #    print i,v

    questions = ['name', 'quest', 'favorite color']
    answers = ['lancelot', 'the holy grail', 'blue']
    for q, a in zip(questions, answers):
        print 'What is your {0}?  It is {1}.'.format(q, a)

    for i in reversed(xrange(1,10,2)):
        print i

    basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']
    for f in sorted(set(basket)):
        print f

    knights = {'gallahad':'the pure', 'robin':'the brave'}
    for k , v in knights.iteritems():
        print k, v


def Test5_7():
    string1, string2, string3 = '', 'Trondheim', 'Hammer Dance'
    non_null = string1 or string2 or string3
    print non_null


def Test5_8():
    print (1,2,3) < (1,2,4)


#Test5_1()
#Test5_1_1()
#Test5_1_2()
#Test5_1_3()
#Test5_1_4()
#Test5_1_4_1()
#Test5_2()
#Test5_3()
#Test5_4()
#Test5_5()
#Test5_6()
#Test5_7()
Test5_8()