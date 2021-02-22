#include "init.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;

int check;
std::vector<path> dependencies;	
char temp[10];

path modules("z_modules");
path buildModulesFile("z_modules/CMakeLists.txt");
path buildProjectFile("CMakeLists.txt");
path infoFile("zpm.info");
path projectFile("main.cpp");

void make_project_file()
{
	cout<<"Give project name : ";
 	cin>>temp;

	if(exists(projectFile))
 	{
 		cout<<"Project file already exists naughty :).\n";
 	}   
 	else
 	{
 		cout<<"Creating Project file ...\n";
 		check = system("touch main.cpp");
 		if(!check)
 		{
 			cout<<"Done\n";
 		}
 		else
 		{
 			cout<<"Some error occured in creating project file retry\n";
 			exit(1);
 		}
 	}
}

void make_list_file()
{
	if(exists(infoFile))
 	{
 		cout<<"Info file already exists naughty :).\n";
 	}   
 	else
 	{
 		cout<<"Creating Info file ...\n";
 		check = system("touch zpm.info");
 		if(!check)
 		{
 			cout<<"Done\n";
 		}
 		else
 		{
 			cout<<"Some error occured in creating zpm.info retry\n";
 			exit(1);
 		}
 	}

 	char json[3] = "{}";
	Document document;
	document.Parse(json);

 	Value project_name;

	project_name.SetString(temp, strlen(temp), document.GetAllocator());

	document.AddMember("name",project_name, document.GetAllocator());
	StringBuffer buf;
	PrettyWriter<StringBuffer> writer(buf);
	document.Accept(writer);

	std::ofstream fout; 

	fout.open("zpm.info");
	fout << buf.GetString() << endl;
	fout.close();
}

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