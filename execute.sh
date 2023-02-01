#!/bin/bash

# jenny

./jenny -n2 -s5 4 6 6 | grep -v Could | (echo const int jenny[][3] = {; sed -f indices-jenny.sed;echo }\;;) > jenny.h

# build
cc \
    -ftest-coverage -fprofile-arcs \
    gilded-rose-test.c src/gilded-rose.c -o gilded-rose-test > /dev/null

# run & test
./gilded-rose-test | ./verify.sh -t gilded-rose

# clean
rm gilded-rose-test

# coverage
gcov -b gilded-rose.c

# clean coverage
rm gilded-rose.gc*
rm gilded-rose-test.gc*
