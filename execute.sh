#!/bin/bash

# jenny

# ./jenny -n2 -s5 4 6 6 | grep -v Could | (echo const int jenny[][3] = {; sed -f indices-jenny.sed;echo }\;;) > jenny.h

# build
cc \
    -ftest-coverage -fprofile-arcs \
    void-fn-test.c src/globals.cpp -o void-fn-test > /dev/null

# run & test
./void-fn-test | ./verify.sh -t void-fn

# clean
rm void-fn-test

# coverage
# gcov -b globals.c

# clean coverage
rm void-fn-test*.gc*
