run:
	g++ -c init.cpp
	g++ -c util.cpp
	g++ -c write.cpp
	g++ -c zpm.cpp
	g++ zpm.o init.o util.o write.o -lboost_system -lboost_filesystem -o zpm
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
