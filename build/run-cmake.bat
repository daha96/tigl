REM call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
cmake -G "Ninja" ^
 -DTIGL_VIEWER=OFF ^
 -DTIGL_BINDINGS_PYTHON_INTERNAL=ON ^
 -DTIGL_CONCAT_GENERATED_FILES=ON ^
 -DCMAKE_INSTALL_PREFIX=install ^
 -DTIGL_BUILD_TESTS=ON ^
 ..
REM if errorlevel 1 exit 1