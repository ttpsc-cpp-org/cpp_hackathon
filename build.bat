@echo off

set THIS_DIR=%cd%
set BUILD_DIR=%THIS_DIR%\build\win
set INSTALL_DIR=%THIS_DIR%\build\win-install

pushd %BUILD_DIR%

cmake ^
    --build . ^
    --config Debug
if %errorlevel% neq 0 goto onerror

cmake ^
    --build . ^
    --config Release
if %errorlevel% neq 0 goto onerror

cmake ^
    --build . ^
    --config Debug ^
    --target unit_tests
if %errorlevel% neq 0 goto onerror

cmake ^
    --build . ^
    --config Release ^
    --target unit_tests
if %errorlevel% neq 0 goto onerror

cmake ^
    --build . ^
    --config Release ^
    --target install
if %errorlevel% neq 0 goto onerror

cmake ^
    --install .
if %errorlevel% neq 0 goto onerror

popd

pushd %INSTALL_DIR%

echo ### Test run ###
PWServerExe.exe
echo ### Test run finished ###

popd

echo ### SUCCESS ###
exit /B 0

:onerror

popd

echo ### FAILED ###
exit /B 1
