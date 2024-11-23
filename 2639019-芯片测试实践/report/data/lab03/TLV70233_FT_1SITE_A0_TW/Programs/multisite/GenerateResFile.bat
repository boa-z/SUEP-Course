::*************************
::GenerateResFile ver 1.1
::*************************
::-------------------------------------------------------------------
::this version checks if PinmapCleaner is present and, in this case,
::executes it for all pinmap files in the working directory to
::tidy-up pinmap numbering (start numbering from 0 and proceed 
::in sequence with no holes
::-------------------------------------------------------------------
@echo off
del maplist.txt
del log.txt
dir /b *.map > maplist.txt
if EXIST PinmapCleaner.exe for /F "tokens=1" %%i in (maplist.txt) do PinmapCleaner.exe %%i
for /F "tokens=1" %%i in (maplist.txt) do GeneratePinResFile %%i >> log.txt
@echo "GenerateResFile ver 1.1"
for /F "tokens=1" %%i in (maplist.txt) do echo - %%i
