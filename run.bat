
@echo off
chcp 65001 > nul

cd /d "%~dp0"

"x64\Debug\graph.exe"
pause