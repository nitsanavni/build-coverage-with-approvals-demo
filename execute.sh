#!/bin/bash

# jenny

# ./jenny -n2 -s5 4 6 6 | grep -v Could | (echo const int jenny[][3] = {; sed -f indices-jenny.sed;echo }\;;) > jenny.h

# build
cc \
    -ftest-coverage -fprofile-arcs \
    void-fn-test.c src/globals.c src/sample.c src/constants.c -o void-fn-test

# run & test
./void-fn-test | ./verify.sh -t void-fn

# clean
rm void-fn-test

# coverage
gcov -b void-fn-test-sample.c

# clean coverage
rm void-fn-test*.gc*
