#include<bits/stdc++.h>
#include "Build_file_handler.h"
#include "Info_file_handler.h"
#include "Z_modules_handler.h"

using namespace std;

string project_name;

path path_z_modules("z_modules");
path path_build_modules_file("z_modules/CMakeLists.txt");
path path_build_project_file("CMakeLists.txt");
path path_info_file("zpm.info");
path path_project_file("main.cpp");

Z_modules_handler z_modules;

Build_file_handler build_modules_file;
Build_file_handler build_project_file;
Build_file_handler info_file;
Build_file_handler project_file;

Info_file_handler info_file_hand;

int main(int argc,char *argv[])
{
	z_modules.init(path_z_modules);

 	build_modules_file.init(path_build_modules_file);
 	build_project_file.init(path_build_project_file);
 	info_file.init(path_info_file,"{}");
 	project_file.init(path_project_file);

 	info_file_hand.init();

 	project_name = info_file_hand.get_string("name");
 	if(project_name == "~")
 	{
 		cout<<"Give project name : ";
 		cin>>project_name;
 		build_project_file.add_project(project_name);
 	}

	if(argc == 2 && strcmp(argv[1],"init") == 0)
	{
	 	info_file_hand.add_value("name","string",project_name);
	 	info_file_hand.write();

	 	info_file_hand.add_value("dependencies","array");
	 	info_file_hand.write();
	}
	else if(argc == 3 && strcmp(argv[1],"get") == 0)
	{
		z_modules.get_module(string(argv[2],argv[2]+strlen(argv[2])));
		info_file_hand.edit_value(argv[2]);
		build_modules_file.add_subdir(string(argv[2],argv[2]+strlen(argv[2])));
		build_project_file.add_linker(project_name,string(argv[2],argv[2]+strlen(argv[2])));
	}
	else if(argc == 2 && strcmp(argv[1],"dep") == 0)
	{
		vector<string> dep = info_file_hand.dependency_provider();
		for(int i = 0;i<dep.size();i++)
		{
			cout<<dep[i]<<" ";
		}
		cout<<"\n";	
	}
}