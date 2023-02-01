#!/bin/bash

# build
cc gilded-rose-test.c src/gilded-rose.c -o gilded-rose-test

# run
./gilded-rose-test

# clean
rm gilded-rose-test
