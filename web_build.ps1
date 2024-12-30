cmake -S . -B build -G Ninja -DPLATFORM=Web "-DCMAKE_TOOLCHAIN_FILE=D:/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"
cmake --build build