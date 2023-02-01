#!/bin/bash

echo --- build ---
rm test-gilded-rose
clang-12 \
    -fexperimental-new-pass-manager \
    -fpass-plugin=/usr/lib/mull-ir-frontend-12 \
    -g \
    gilded-rose-test.c src/gilded-rose.c \
    -o test-gilded-rose;
echo ""

echo --- mutation test run ---
mull-runner-12 \
    ./test-gilded-rose \
    -ide-reporter-show-killed \
    --workers=1 \
    --test-program=bash -- -c './test-gilded-rose | ./verify.sh -t gilded-rose -d true';
echo ""
