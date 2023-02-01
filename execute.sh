#!/bin/bash

# build
cc \
    gilded-rose-test.c src/gilded-rose.c -o gilded-rose-test > /dev/null

# run & test
./gilded-rose-test | ./verify.sh -t gilded-rose

# clean
rm gilded-rose-test
