@echo off

start cmake -B build -G "Ninja"

pushd build
start cmake --build .
popd
