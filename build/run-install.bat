rem call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
cmake --build . -j 12 --target install --config Release
REM if errorlevel 1 exit 1
xcopy /yhiev install\share\tigl3\python\tigl3 C:\Users\Daniel\anaconda3\envs\pacs_3\Lib\site-packages\tigl3
xcopy /y install\bin\tigl3.dll C:\Users\Daniel\anaconda3\envs\pacs_3\Library\bin
REM if errorlevel 1 exit 1
