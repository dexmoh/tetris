# Script to quickly build and run the project on windows.

$BUILD_DIR = "build"
$PROJECT_NAME = "tetris"
$EXE_NAME = "tetris.exe"

cmake -B $BUILD_DIR
cmake --build $BUILD_DIR
& "./$BUILD_DIR/$PROJECT_NAME/$EXE_NAME"
