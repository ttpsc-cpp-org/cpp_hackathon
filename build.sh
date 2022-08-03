#!/bin/bash

THIS_DIR=$(pwd)

BUILD_DIR=build/linux
INSTALL_DIR=build/linux-install

rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

rm -rf ${INSTALL_DIR}
mkdir -p ${INSTALL_DIR}

conan install \
    -g cmake_find_package \
    --output-folder=${BUILD_DIR} \
    ${THIS_DIR}

pushd ${BUILD_DIR}

cmake ${THIS_DIR}

popd

#rm -rf 
#mkdir -p build
