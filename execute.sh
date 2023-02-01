#!/bin/bash

# build
cc \
    -ftest-coverage -fprofile-arcs \
    gilded-rose-test.c src/gilded-rose.c -o gilded-rose-test > /dev/null

# run & test
./gilded-rose-test | ./verify.sh -t gilded-rose

# clean
rm gilded-rose-test

# coverage
gcov gilded-rose.c

# clean coverage
rm gilded-rose.gc*
rm gilded-rose-test.gc*