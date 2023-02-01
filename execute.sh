#!/bin/bash

# build
cc \
    gilded-rose-test.c -o gilded-rose-test > /dev/null

# run
./gilded-rose-test

# clean
rm gilded-rose-test
