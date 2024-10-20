@echo off

cd ../bin

echo building project
cmake --build . target -- game

pause