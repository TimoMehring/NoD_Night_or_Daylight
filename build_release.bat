@echo off
cd /d %~dp0

if not exist release mkdir release
if not exist release\NoD_v1.0.0 mkdir release\NoD_v1.0.0

g++ -std=c++17 -O2 src/main.cpp src/graphics.cpp src/daytime.cpp src/audio.cpp -o release\NoD_v1.0.0\NoD.exe -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows

if %errorlevel% neq 0 (
    echo.
    echo Release Build fehlgeschlagen.
    pause
    exit /b %errorlevel%
)

echo.
echo Release Build erfolgreich.
echo Datei: release\NoD_v1.0.0\NoD.exe
pause