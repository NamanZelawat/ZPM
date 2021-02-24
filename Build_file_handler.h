#include<bits/stdc++.h>
#include <boost/filesystem.hpp>
#include "rapidjson/document.h"

using namespace std;
using namespace rapidjson;
using namespace boost::filesystem;
 
class Build_file_handler
{
	string name;
	public:
		void init(path name,string def = "");
		void add_subdir(string subdir);
		void add_project(string project_name);
		void add_linker(string project_name,string link_name);
};
