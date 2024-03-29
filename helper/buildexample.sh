#! /bin/bash

rm -rf build
cmake -B build
cmake --build build -j8
build/unit_test
cmake --build build --target coverage
cmake --build build --target clang-format
