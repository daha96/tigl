REM cmake --build . --config Release --target all
cmake --build . -j 12 --config Debug --target all
REM if errorlevel 1 exit 1
