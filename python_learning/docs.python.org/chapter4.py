#!/usr/bin/python2.7
# -*- coding: UTF-8 -*-

# 4.1 (if statements)

def Test4_1():
    x = int(raw_input("Plearse enter an interger: "))
    if x < 0 :
        x = 0
        print 'Negative changed to zero'
    elif x == 0:
        print 'Zero'
    elif x == 0:
        print 'Single'
    else:
        print 'More'

# 4.2 (for StateMents)
def Test4_2():
    words = ['cat','window','defenestrate']
    for word in words:
        print word,len(word)

    for word in words[:]:
        if(len(word)>6):
            words.insert(0,word)

    print words


# 4.3 (The range Function)
def Test4_3():
    print range(10)
    print range(5,10)
    print range(1,10,3)
    print range(-10,-100,-30)
    a = ['Mary','had','a','little','lamb']
    for i in range(len(a)):
        print i, a[i]

# 4.4 (break and continue Statements, and else clauses on Loops)
def Test4_4():
    for n in range(2,18):
        for x in range(2,n):
            if n%x == 0:
                print n, 'equals ', n , '*', x
                break
        else:
            print n, 'is primer'

    for num in range(2,10):
        if num % 2 == 0:
            print 'Found an even number', num
            continue
        print 'Found a num', num


# 4.6 (define Functions)
def Test4_6(n):
    '''Print a Fibonacci series up to n'''
    result = []
    a, b = 0,1
    while a < n:
        result.append(a)
        #print a,
        a, b = b, a+b
    return result

#print Test4_6(2000)


# 4.7 Defining Functions:
def ask_ok(prompt , retries = 4, complaint = 'Yes or No,please'):
    while True:
        ok = raw_input(prompt)
        if ok in ('y','ye','yes'):
            return True
        if ok in ('n','no','nop','nope'):
            return False
        retries = retries - 1
        if retries < 0 :
            raise IOError('refuseink user')
        print complaint

#print(ask_ok('Do you really want to quit? '))

def Test4_7_1():
    i = 5
    def f(arg=i):
        print arg

    i = 6
    f()

    def f2(a, L=None):
        if L is None:
            L = []
        L.append(a)
        return L

    print f2(1)
    print f2(2)
    print f2(3)


def parrot(voltage, state = 'a stiff', action = 'voom', type= 'Norwegian Bule'):
    print "-- This parrot wouldn't", action
    print "if you put", voltage ,"volts through it."
    print "-- Lovely plumage , the", type
    print "-- It's", state, "i"

#parrot(1000)

def cheeseshop(kind, *args, **keywords):
    print "-- Do you have any", kind, "?"
    print "-- I'm sorry, we're all out, " , kind
    for arg in args:
        print arg

    print "-" * 40
    keys = sorted(keywords.keys())
    for kw in keys:
        print kw,":", keywords[kw]

cheeseshop("Limburger", "It's very runny, sir",
           "It's really very, VERY runny, sir",
           shopkeeper='Michael Palin',
           client="John Clees",
           sketch='Cheese Shop Sketch'
           )

def Test4_7_1():
    args = [3,6]
    print range(*args)

#Test4_7_1()

def Test4_7_2():
    """测试的类
    No, really,it doesn't do anything
    :return:
    """

#d = {"voltage":"four mllion", "state":"bleedin", "action":"room"}
#parrot(**d)
print Test4_7_2.__doc__