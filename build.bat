@echo off

if "%1" == "-b" (
   	call :build
   	goto eof
	)

if "%1" == "-d" (
	call :remove
	goto eof
	)

if "%1" == "-r" (
	if exist bin\game\Debug\Deadstorm.exe (
		if not exist bin\game\Debug\SDL2.dll (
			copy %SDL2%\lib\x86\SDL2.dll bin\game\Debug\
			)
		if not exist bin\game\Debug\SDL2_image.dll (
			copy %SDL2_image%\lib\x86\SDL2_image.dll bin\game\Debug\
			)
		bin\game\Debug\Deadstorm.exe
		goto eof
		
		)
    echo "Can't run without build before."
	goto eof
	)

if "%1" == "-rb" (
	call :remove
   	call :build
   	goto eof
	)
if "%1" == "-t" (
	if exist bin\test\Debug\runUnitTests.exe (
		if not exist bin\test\Debug\SDL2.dll (
			copy %SDL2%\lib\x86\SDL2.dll bin\test\Debug\
			)
		if not exist bin\test\Debug\SDL2_image.dll (
			copy %SDL2_image%\lib\x86\SDL2_image.dll bin\test\Debug\
			)
		bin\test\Debug\runUnitTests.exe
		goto eof
		
		)
	)

if "%1" == "" (
	goto :noArgs
	)

:build
if not exist bin mkdir bin
cd bin
cmake ..
cd ..
msbuild bin/Deadstorm.sln
exit /B 0

:remove
rmdir /s /q bin
exit /B 0

:noArgs
echo "-b 	build"
echo "-d 	delete"
echo "-r 	run"
echo "-rb 	rebuild"
goto eof


:eof