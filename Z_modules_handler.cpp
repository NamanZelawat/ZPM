#include "Z_modules_handler.h"

void Z_modules_handler::init(path name)
{
	int check;
 	if(!exists(name))
 	{
 		cout<<"Creating "<<name.string()<<" folder ...\n";
 		string cmd = "mkdir " + name.string();
 		check = system(cmd.c_str());
 		if(!check)
 		{
 			cout<<"Done\n";
 		}
 		else
 		{
 			cout<<"Some error occured in creating folder retry\n";
 			exit(1);
 		}
 	}
}

void Z_modules_handler::get_module(string name)
{
	char URL[100] = "git clone https://github.com/NamanZelawat/";
	char total[100];
	strcpy(total,URL);
	strcat(total,name.c_str());
	system(total);
	char mov[100];
	strcpy(mov,"mv ");
	strcat(mov,name.c_str());
	strcat(mov," ");
	strcat(mov,"z_modules/");
	system(mov);
}