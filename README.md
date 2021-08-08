    GENERAL INFORMATION
#
      VERSI0NING

Versioning in my git repository goes like this : 

#
      USE OF THE ALLEGRO 5 LIBRARY

        INSTALLATION

- For CodeBlocks : 
        https://www.allegro.cc/files/ ->
        MinGW 4.7.0 / allegro-5.0.10-mingw-4.7.0.zip.

- For Visual Studio : 
        https://www.allegro.cc/files/ ->
        MSVC 11 / allegro-5.0.10-msvc-11.0.zip

- Easy installation : 
        Allegro 5 available in the "files" branch for CodeBlock and Visual Studio

        POSITIONING OF DLL

- Solution 1 : 
        Copy the DLL to the executable directory.

- Solution 2 : 
        Copy the DLL to the appropriate system folder 
        (C:\Windows\SysWOW64 -> 64 bit or C:\Windows\System32 -> 32 bit).

- Solution 3 : 
        Use a static library.

        CONFIGURATION

- For CodeBlocks : 

        Menu Project -> Project build options -> Search directories (for debug and release) -> compiler
        (add include) -> Linker (add lib)

        Menu Project -> Project build options -> Linker settings (Debug) -> add 
        allegro-5.0.10-monolith-mt-debug -> Linker settings (Release) -> add 
        allegro-5.0.10-monolith-mt

- For Visual Studio :
        

#

