:: Setup mod folders to development

@echo off
pushd "%~dp0"

:: Link mod folder to DayZ Source
mklink /J "P:\NewFrontiers" "..\@core\src"
mklink /J "P:\NewFrontiersBases" "..\@bases\src"
mklink /J "P:\NewFrontiersKillFeed" "..\@killfeed\src"

:: Link source to DayZ Game folder
mklink /J "%DAYZ_FOLDER%\NewFrontiers" "..\@core\src"
mklink /J "%DAYZ_FOLDER%\NewFrontiersBases" "..\@bases\src"
mklink /J "%DAYZ_FOLDER%\NewFrontiersKillFeed" "..\@killfeed\src"

:: Prepare build folder
mklink /J "P:\@NewFrontiers" "..\@core\build"
mklink /J "P:\@NewFrontiersBases" "..\@bases\build"
mklink /J "P:\@NewFrontiersKillFeed" "..\@killfeed\build"
mklink /J "P:\@CF" "%DAYZ_FOLDER%\!Workshop\@CF"

:: Build
call "build.bat"

popd
