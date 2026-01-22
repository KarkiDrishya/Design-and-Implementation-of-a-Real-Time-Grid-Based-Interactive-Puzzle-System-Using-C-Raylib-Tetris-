:: Here we compile multiple files and running build.bat automatically runs MADLADS.exe too
::EVerytime we run this build.bat g++ will recompile all the files and overwrite MADLADS.exe 
:: echo off prevents displaying of commands as they run
@echo off 


g++ grid.cpp main.cpp -I C:/raylib/include -L C:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm -o Tetris.exe

:: Here we check if the Compilation was successful or not
::So since MADLADS.exe is overwriiten each time this if else loop just checks
::if MADLADS.exe was created successfully or not
::NOTE - use  start cmd /k MADLADS.exe If you want the game to open in a new window and instead of /k use /c if u want the new window to auto close
IF EXIST Tetris.exe (
    :: Play mp3 asynchronously with Windows Media Player
    @REM start "" "C:\Program Files\Windows Media Player\wmplayer.exe" /play /close "C:\Users\USER\Documents\College\Classes\MADSLADS\MADSLADS\Chill Music.mp3"
    echo NOW TETRIS.... 
    start cmd /c Tetris.exe



        
) ELSE (
    :: Displays message if some error occured and MADLADS Wasent created
    echo ERROR OCCURED
)
::echo. creates a new line 
::pause ensures the window remains open and also says press any key to continue for exitting the game
echo.

