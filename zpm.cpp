#include<bits/stdc++.h>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

path modules("z_modules");
path buildModulesFile("z_modules/CMakeLists.txt");
path buildProjectFile("CMakeLists.txt");

int check;
std::vector<path> dependencies;	
char URL[100] = "git clone https://github.com/NamanZelawat/";

void make_z_modules()
{
	if(exists(modules))
 	{
 		cout<<"z_modules already exists naughty :).\n";
 	}   
 	else
 	{
 		cout<<"Creating z_modules ...\n";
 		check = system("mkdir z_modules");
 		if(!check)
 		{
 			cout<<"Done\n";
 		}
 		else
 		{
 			cout<<"Some error occured in creating z_modules retry\n";
 			exit(1);
 		}
 	}
}

void make_build_file_modules()
{
	if(exists(buildModulesFile))
 	{
 		cout<<"Build modules file already exists naughty :).\n";
 	}   
 	else
 	{
 		cout<<"Creating build file for modules ...\n";
 		check = system("touch z_modules/CMakeLists.txt");
		if(!check)
		{
			cout<<"Done\n";
		}
		else
		{
			cout<<"Some error occured in creating build file for modules retry\n";
			exit(1);
		}
 	}
}

void make_build_file_project()
{
	if(exists(buildProjectFile))
 	{
 		cout<<"Build project file already exists naughty :).\n";
 	}   
 	else
 	{
 		cout<<"Creating build file for project ...\n";
 		check = system("touch CMakeLists.txt");
		if(!check)
		{
			cout<<"Done\n";
		}
		else
		{
			cout<<"Some error occured in creating build file retry\n";
			exit(1);
		}
 	}
}

void fill_dependencies()
{
	for (auto&& x : directory_iterator(modules))
	{
		if(is_directory(x.path()))
    	{
			dependencies.push_back(x.path().filename());
		}
	}
}

void print_dependencies()
{
	for (auto&& x : directory_iterator(modules))
	{
		if(is_directory(x.path().filename()))
    	{
			cout<<x.path().filename()<<endl;
		}
	}	
}

void write_build_modules()
{
	std::ofstream fout; 

	fout.open("z_modules/CMakeLists.txt");

	string subdirs = "";

	for(int i = 0;i<dependencies.size();i++)
	{
		subdirs += dependencies[i].string();
		subdirs += " ";
	}

	fout << "cmake_minimum_required(VERSION 2.8)" << endl; 
	fout << "add_subdirectory(" + subdirs + ")" << endl;
}



int main(int argc,char *argv[])
{ 	
	if(argc < 2)
	{
		cout<<"Please specify a command for ex :- init, get ...\n";
		return 0;
	}
	if(strcmp(argv[1],"init") == 0)
	{
		system("touch main.cpp");
		make_z_modules();
	 	make_build_file_modules();
	 	make_build_file_project();
	 	fill_dependencies();
	 	write_build_modules();
	}
	else if(strcmp(argv[1],"get") == 0)
	{
		if(argc < 3)
		{
			cout<<"Please specify a repo name for ex :- route_z ...\n";
			return 0;
		}
		char total[100];
		strcpy(total,URL);
		strcat(total,argv[2]);
		system(total);
		char mov[100];
		strcpy(mov,"mv ");
		strcat(mov,argv[2]);
		strcat(mov," ");
		strcat(mov,"z_modules/");
		system(mov);
		fill_dependencies();
		write_build_modules();
	}
	else if(strcmp(argv[1],"dep") == 0)
	{
		print_dependencies();
	}
	else
	{
		cout<<"Error in command no such command found\n";	
	}
}