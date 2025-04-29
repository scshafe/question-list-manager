#!/usr/bin/env python

# Not my own script. Found in comments on a beagleboard discussion page:
# https://forum.beagleboard.org/t/cloning-the-root-filesystem-for-cross-compiling/29828/3

import sys
import os

# Take a sysroot directory and turn all the abolute symlinks and turn them into
# relative ones such that the sysroot is usable within another system.

# if len(sys.argv) != 2:
#     print("Usage is " + sys.argv[0] + "<directory>")
#     sys.exit(1)

# topdir1 = sys.argv[1]
# topdir1 = os.path.abspath(topdir1)

topdir = os.environ['BBB_CROSS_SYSROOT']

# print(topdir1)
print(topdir)

def handlelink(filep, subdir):
    link = os.readlink(filep)
    if link[0] != "/":
        return
    if link.startswith(topdir):
        return
    #print("Replacing %s with %s for %s" % (link, topdir+link, filep))
    print("Replacing %s with %s for %s" % (link, os.path.relpath(topdir+link, subdir), filep))
    os.unlink(filep)
    os.symlink(os.path.relpath(topdir+link, subdir), filep)

for subdir, dirs, files in os.walk(topdir):
    for f in files:
        filep = os.path.join(subdir, f)
        if os.path.islink(filep):
            #print("Considering %s" % filep)
            handlelink(filep, subdir)
