:: Build PBO using Addon Builder
@echo off

start /D "%DAYZ_TOOLS%\Bin\AddonBuilder" cmd /k AddonBuilder.exe "P:\NewFrontiers" "P:\@NewFrontiers\addons" -packonly -clear
start /D "%DAYZ_TOOLS%\Bin\AddonBuilder" cmd /k AddonBuilder.exe "P:\NewFrontiersBases" "P:\@NewFrontiersBases\addons" -packonly -clear
start /D "%DAYZ_TOOLS%\Bin\AddonBuilder" cmd /k AddonBuilder.exe "P:\NewFrontiersQuests" "P:\@NewFrontiersQuests\addons" -packonly -clear
start /D "%DAYZ_TOOLS%\Bin\AddonBuilder" cmd /k AddonBuilder.exe "P:\NewFrontiersKillFeed" "P:\@NewFrontiersKillFeed\addons" -packonly -clear
