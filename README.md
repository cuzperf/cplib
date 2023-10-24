# cplib: C++ library for Programming Contest

[![Code Coverage](https://github.com/cuzperf/cplib/actions/workflows/test.yml/badge.svg)](https://github.com/cuzperf/cplib/actions/workflows/test.yml) [![codecov](https://codecov.io/gh/cuzperf/cplib/graph/badge.svg?token=ZNPDQ55RDU)](https://codecov.io/gh/cuzperf/cplib)

> Please run `python prepare.py` first !!!

运行上述命令后，`git commit` 会被 hook:
- 自动（增量构建）一次项目（确保不出现低级错误）
- 按照 `.clang-format` 提供的代码规范运行 clang-format

## 里程碑 (milestone)

- [x] cmake 构建
- [x] googletest 支持
- [x] clang-format 支持
- [x] git commit 被 hook 强制 clang-format
- [x] github ci/cd 支持
- [x] 代码覆盖率支持，并用 [codecov](https://codecov.io/) 展示
- [ ] 完成整个 cplib 的迁移并优化

## Ubuntu Helper

- run `sudo apt install cmake lcov`
- run `helper/clang-format15.sh` to install clang-format-15
- run `helper/buildexample.sh` to run this project
