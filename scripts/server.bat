:: Start test server with mods
@echo off

IF "%1"=="-debug" (
    set "filePatching=-filePatching"
) ELSE (
    set "filePatching="
)

start /D "%DAYZ_FOLDER%" DayZDiag_x64.exe "-mod=P:\@CF;%DAYZ_FOLDER%\!Workshop\@Community-Online-Tools;P:\@NewFrontiers;P:\@NewFrontiersBases;P:\@NewFrontiersKillFeed" %filePatching% -server -config=serverDZ.cfg
