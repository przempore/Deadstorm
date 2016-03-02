@echo off
set DeadstormBuilded

if "%1" == "-b" (
   	call :build
   	set DeadstormBuilded=1
   	goto eof
	)

if "%1" == "-d" (
	call :remove
	goto eof
	)

if "%1" == "-r" (
	if %DeadstormBuilded%  == 1 (
		if not exist bin\game\Debug\SDL2.dll (
			copy %SDL2%\lib\x86\SDL2.dll C:\Users\przemo\Repository\Deadstorm\bin\game\Debug\
			)
		if not exist C:\Users\przemo\Repository\Deadstorm\bin\game\Debug\SDL2_image.dll (
			copy %SDL2_image%\lib\x86\SDL2_image.dll C:\Users\przemo\Repository\Deadstorm\bin\game\Debug\
			)
		bin\game\Debug\Deadstorm.exe
		goto eof
		
		)
	echo "Can't run without build."
	goto eof
	)

if "%1" == "-rb" (
	call :remove
   	call :build
   	goto eof
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
set DeadstormBuilded=0
exit /B 0

:noArgs
echo "-b 	build"
echo "-d 	delete"
echo "-r 	run"
echo "-rb 	rebuild"
goto eof


:eof