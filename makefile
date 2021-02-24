run:
	g++ -c Build_file_handler.cpp
	g++ -c Info_file_handler.cpp
	g++ -c Z_modules_handler.cpp
	g++ -c z.cpp
	g++ z.o Build_file_handler.o Info_file_handler.o Z_modules_handler.o -lboost_system -lboost_filesystem -o zpm
	rm -rf *.o;

clean:
	rm -rf z_modules
	rm -rf CMakeLists.txt
	rm -rf zpm
	rm -rf main.cpp
	rm -rf *.o
	rm -rf zpm.info

res:
	make clean
	make run
	./zpm init
	./zpm get route_z
