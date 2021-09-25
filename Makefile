# Game
game :
	mkdir -p obj 
	mkdir -p bin
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/error_handling.c -o obj/error_handling.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/event.c -o obj/event.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/game_window.c -o obj/game_window.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/garbage_collector.c -o obj/garbage_collector.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/keyboard_management.c -o obj/keyboard_management.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/level.c -o obj/level.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/level_menu.c -o obj/level_menu.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/main.c -o obj/main.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/menu.c -o obj/menu.o
	gcc.exe -Wall -g -I"C:\Program Files\CodeBlocks\MinGW\include" -c C:/Users/Hayk/Desktop/LabyTrap/src/mouse_management.c -o obj/mouse_management.o
	gcc.exe -L"C:\Program Files\CodeBlocks\MinGW\lib" -o bin/LabyTrap.exe obj/error_handling.o obj/event.o obj/game_window.o obj/garbage_collector.o obj/keyboard_management.o obj/level.o obj/level_menu.o obj/main.o obj/menu.o obj/mouse_management.o   -lallegro-5.0.10-monolith-mt-debug

# Command options
dist :
	$(ARCHIVE) include src Makefile Doxyfile assets 

docs :
	doxygen

clean :
	rm -rf obj/ 
	rm -rf bin/
	rm -rf *.tar.xz 
	rm -rf docs/