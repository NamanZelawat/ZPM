#include "resource.h"
#include "init.h"
#include "util.h"
#include "write.h"

char URL[100] = "git clone https://github.com/NamanZelawat/";

int main(int argc,char *argv[])
{ 	
	if(argc < 2)
	{
		cout<<"Please specify a command for ex :- init, get ...\n";
		return 0;
	}
	if(strcmp(argv[1],"init") == 0)
	{
		make_project_file();
		make_list_file();
		make_z_modules();
	 	make_build_file_modules();
	 	make_build_file_project();
	 	fill_dependencies();
	 	write_build_modules();
	 	write_build_project();
	}
	else if(strcmp(argv[1],"get") == 0)
	{
		if(argc < 3)
		{
			cout<<"Please specify a repo name for ex :- route_z, glad ...\n";
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
		write_build_project();
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