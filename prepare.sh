#!/bin/bash

set -e
set -x

THIS_DIR=$(pwd)
BUILD_DIR=${THIS_DIR}/build/linux
CMAKE_GENERATOR="Ninja"

rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

pushd ${BUILD_DIR}

conan install \
    --generator cmake_find_package \
    --settings build_type=Debug \
    --build missing \
    ${THIS_DIR}

cmake \
    -G "${CMAKE_GENERATOR}" \
    -DCMAKE_BUILD_TYPE=Debug \
    ${THIS_DIR}

popd