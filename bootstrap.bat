
@echo OFF
conan config install ./conan
conan install . -pr MinGW --build=missing
pip install gcovr