#/bin/sh
if command -v apt-get >/dev/null 2>&1; then
    apt-get update
    apt-get install -y python3 python3-pip cmake ninja-build python3-venv
fi

python3 -m venv venv
. venv/bin/activate
pip install gcovr "conan==1.64.1"
conan config install ./conan
