pushd "%~dp0"

::Link mod folder to DayZ Source
mklink /J "P:\NewFrontiers" "..\@core\src"

:: Link source to DayZ Game folder
mklink /J "%DAYZ_FOLDER%\NewFrontiers" "..\@core\src"

:: Prepare build folder
mklink /J "P:\@NewFrontiers" "..\@core\build"

:: Build
call "build.bat"

popd
