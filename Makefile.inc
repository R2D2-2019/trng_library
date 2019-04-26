#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

SEARCH  += $(trng)/code/headers
SEARCH  += $(trng)/code/src

# source files in this library
SOURCES += $(wildcard $(trng)/code/src/*.cpp)

# header files in this library
HEADERS += $(wildcard $(trng)/code/headers/*.hpp)
