run:
	g++ zpm.cpp -lboost_system -lboost_filesystem -o zpm

clean:
	rm -rf z_modules
	rm -rf CMakeLists.txt
	rm -rf zpm
	rm -rf main.cpp

res:
	make clean
	make run
	./zpm init
	./zpm get route_z
