rem
call ..\makedefs.bat
rem
%mcpp% configs/foxstation.epp > foxstation.edl ^
 -I ..\..\openeaagles\include\openeaagles ^
 -I ..\shared\data ^
 -DFONT_PATH="\"../shared/data/fonts/\"" ^
 -DTEXTURES_PATH="\"../shared/data/textures/\""
