#include<bits/stdc++.h>
#include <boost/filesystem.hpp>
#include "rapidjson/document.h"

using namespace std;
using namespace rapidjson;
using namespace boost::filesystem;

class Z_modules_handler
{
	public:
		void get_module(string name);
		void init(path name);
};
