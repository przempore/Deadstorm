@echo off

if not exist bin mkdir bin
cd bin
cmake ..
msbuild Deadstorm.sln