# cplib: C++ library for Programming Contest

![github license](https://img.shields.io/github/license/cuzperf/cplib) [![Code Coverage](https://github.com/cuzperf/cplib/actions/workflows/test.yml/badge.svg)](https://github.com/cuzperf/cplib/actions/workflows/test.yml) [![codecov](https://codecov.io/gh/cuzperf/cplib/graph/badge.svg?token=ZNPDQ55RDU)](https://codecov.io/gh/cuzperf/cplib) [![codedocs](https://codedocs.xyz/cuzperf/cplib.svg)](https://codedocs.xyz/cuzperf/cplib/)

> Please run `python prepare.py` first !!!

运行上述命令后，`git commit` 会被 hook:
- 自动（增量）构建一次项目（确保不出现低级错误）
- 按照 `.clang-format` 提供的代码规范运行 clang-format，统一代码风格

> 项目进度见 #3

## Ubuntu Helper

- run `sudo apt install cmake lcov`
- run `helper/clang-format15.sh` to install clang-format-15
- run `helper/buildexample.sh` to run this project
