:: Run server and client on debug mode
@echo off
pushd "%~dp0"

call server.bat -debug
timeout 10 > NUL
call client.bat -debug

popd
