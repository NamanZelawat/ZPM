#include "Build_file_handler.h"

void Build_file_handler::init(path name,string def)
{
 	if(!exists(name))
 	{
 		cout<<"Creating "<<name.string()<<" file ...\n";
 		string cmd = "touch " + name.string();
 		int check = system(cmd.c_str());
 		if(!check)
 		{
 			cout<<"Done\n";
 		}
 		else
 		{
 			cout<<"Some error occured in creating file retry\n";
 			exit(1);
 		}

 		std::ofstream fout; 
		fout.open(name.string());
		fout << def << endl;
 	}
 	this->name = name.string();
}

void Build_file_handler::add_subdir(string subdir)
{
	cout<<"Writing "<<subdir<<" to "<<name<<endl;
	std::ofstream fout; 
	fout.open(name,ios::app);
	fout << "add_subdirectory(" + subdir + ")" << endl;
	fout.close();
}

void Build_file_handler::add_project(string project_name)
{
	std::ofstream fout; 
	fout.open(name,ios::app);
	fout << "project("<<project_name<<" C CXX)"<< endl;
	fout << "add_subdirectory(z_modules)" << endl;
	fout << "add_executable("+ project_name +" main.cpp)" << endl;
	fout.close();
}

void Build_file_handler::add_linker(string project_name,string link_name)
{
	std::ofstream fout; 
	fout.open(name,ios::app);
	fout << "target_link_libraries(" << project_name << " " << link_name << ")" << endl;
	fout.close();
}



