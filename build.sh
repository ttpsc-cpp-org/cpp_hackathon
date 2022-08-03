#!/bin/bash

set -e
set -x

THIS_DIR=$(pwd)

BUILD_DIR=${THIS_DIR}/build/linux

#rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

pushd ${BUILD_DIR}

conan install \
    --generator cmake_find_package_multi \
    --settings build_type=Debug \
    --settings compiler.runtime=MDd \
    --build missing \
    ${THIS_DIR}

conan install \
    --generator cmake_find_package_multi \
    --settings build_type=Release \
    --build missing \
    ${THIS_DIR}

#    -DCMAKE_BUILD_TYPE=Debug \
cmake \
    ${THIS_DIR}

cmake \
    --build . \
    --config Debug

popd
