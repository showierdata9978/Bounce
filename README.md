# BouncyBoxes

A small c++ and raylib project.


## Building

```bash

# Setting up raylib (from https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#build-raylib-using-cmake)
git clone https://github.com/raysan5/raylib.git raylib
cd raylib/
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=ON ..
make
sudo make install

cd ../.. # leaving raylib

cmake -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ -S . -B ./build -G "Unix Makefiles"
cd build
make
```

### Running from src

```bash
# assuming project root

cd build/bounce/

./bounce 64
```

