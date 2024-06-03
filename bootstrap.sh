#/bin/sh
apt-get update
apt-get install -y python3 python3-pip cmake ninja-build
pip install gcovr "conan==1.64.1"
conan config install ./conan
