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
		if not exist bin\game\Debug\SDL2_ttf.dll (
			copy %SDL2_ttf%\lib\x86\SDL2_ttf.dll bin\game\Debug\
			)
		if not exist bin\game\Debug\libfreetype-6.dll (
			copy %SDL2_ttf%\lib\x86\libfreetype-6.dll bin\game\Debug\
			)
		if not exist bin\game\Debug\zlib1.dll (
			copy %SDL2_ttf%\lib\x86\zlib1.dll bin\game\Debug\
			)
		if not exist bin\game\Debug\libjpeg-9.dll (
			copy %SDL2_image%\lib\x86\libjpeg-9.dll bin\game\Debug\
			)
		if not exist bin\game\Debug\libpng16-16.dll (
			copy %SDL2_image%\lib\x86\libpng16-16.dll bin\game\Debug\
			)
		if not exist bin\game\Debug\assets (
			mkdir bin\game\Debug\assets
			xcopy bin\game\assets bin\game\Debug\assets /e /i /s /y /v
			)
		cd bin\game\Debug
		Deadstorm.exe
		cd ..\..\..
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