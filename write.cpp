#include "write.h"

void write_build_modules()
{
	std::ofstream fout; 

	fout.open("z_modules/CMakeLists.txt");

	// for(int i = 0;i<dependencies.size();i++)
	// {
	// 	fout << "add_subdirectory(" + dependencies[i].string() + ")" << endl;
	// }

	fout.close();
}

void write_build_project()
{
	std::ofstream fout; 

	char total[100];

	// cout<<"Writing project name\n";
	// cout<<project_name<<endl;

	strcpy(total,"project(");
	//strcat(total,project_name);
	strcat(total," C CXX)");

	fout.open("CMakeLists.txt");

	fout << "cmake_minimum_required(VERSION 2.8)" << endl;
	fout << total << endl;
	fout << "add_subdirectory(z_modules)" <<endl;

	total[0] = '\0';
	strcpy(total,"add_executable(");
	//strcat(total,project_name);
	strcat(total," main.cpp)");

	fout << total << endl;

	fout.close();
}

void add_dependencies()
{
	char total[100];
	std::ofstream fout; 
	fout.open("CMakeLists.txt",ios::app);
	// for(int i = 0;i<dependencies.size();i++)
	// {
	// 	total[0] = '\0';
	// 	strcpy(total,"target_link_libraries(");
	// 	strcat(total,project_name);
	// 	strcat(total," ");
	// 	strcat(total,dependencies[i].string().c_str());
	// 	strcat(total,")");
	// 	fout << total << endl;
	// }
	fout.close();
}