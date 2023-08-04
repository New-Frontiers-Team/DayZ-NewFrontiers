:: Start test client with mods and connect to server
@echo off

IF "%1"=="-debug" (
    set "filePatching=-filePatching"
) ELSE (
    set "filePatching="
)

start /D "%DAYZ_FOLDER%" DayZDiag_x64.exe "-mod=P:\@CF;%DAYZ_FOLDER%\!Workshop\@Community-Online-Tools;P:\@NewFrontiers;P:\@NewFrontiersBases;P:\@NewFrontiersKillFeed" %filePatching% -connect=127.0.0.1 -port=2302
