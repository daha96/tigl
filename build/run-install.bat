cmake --build . -j 12 --target install --config Release
REM if errorlevel 1 exit 1
xcopy /y install\share\tigl3\python\tigl3\** C:\Users\Daniel\anaconda3\envs\pacs_3\Lib\site-packages\tigl3
REM if errorlevel 1 exit 1
