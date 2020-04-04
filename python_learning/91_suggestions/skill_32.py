#!/usr/bin/python2.7
# -*- coding=utf-8 -*-

def appendlist(newiterm, oldlist = []):
    oldlist.append(newiterm)
    return oldlist

print appendlist(1)
print appendlist('a')

