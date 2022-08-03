#!/bin/bash

set -e
set -x

THIS_DIR=$(pwd)

BUILD_DIR=${THIS_DIR}/build/linux

pushd ${BUILD_DIR}

cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    ${THIS_DIR}

cmake \
    --build .

cmake \
    --build . \
    --target unit_tests

popd
