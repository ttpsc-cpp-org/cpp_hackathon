@echo off

set THIS_DIR=%cd%
set BUILD_DIR=%THIS_DIR%\build\win
set INSTALL_DIR=%THIS_DIR%\build\win-install

rmdir /S /Q %BUILD_DIR%
rmdir /S /Q %INSTALL_DIR%
mkdir %BUILD_DIR%
mkdir %INSTALL_DIR%

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
    -DCMAKE_INSTALL_PREFIX=%INSTALL_DIR% ^
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
