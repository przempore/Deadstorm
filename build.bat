@echo off

if "%1" == "-b" (
  if not exist bin mkdir bin
  cd bin
  cmake ..
  cd ..
  msbuild bin/Deadstorm.sln
	)

if "%1" == "-d" (
	rmdir /s /q bin
	)