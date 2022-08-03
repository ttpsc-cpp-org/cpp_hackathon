@echo off

set THIS_DIR=%cd%
set BUILD_DIR=%THIS_DIR%\build\win

rmdir /S /Q %BUILD_DIR%
mkdir %BUILD_DIR%

pushd %BUILD_DIR%

conan install ^
    --generator cmake_find_package_multi ^
    --settings build_type=Debug ^
    --settings compiler.runtime=MDd ^
    --build missing ^
    %THIS_DIR%
if %errorlevel% neq 0 goto onerror

conan install ^
    --generator cmake_find_package_multi ^
    --settings build_type=Release ^
    --build missing ^
    %THIS_DIR%
if %errorlevel% neq 0 goto onerror

cmake ^
    %THIS_DIR%
if %errorlevel% neq 0 goto onerror

start .

popd

echo ### SUCCESS ###
exit /B 0

:onerror

popd

echo ### FAILED ###
exit /B 1
