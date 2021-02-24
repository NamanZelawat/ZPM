#include<bits/stdc++.h>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;
using namespace std;

class Info_file_handler
{
	public:
		Document *document;
		StringBuffer *buf;
		PrettyWriter<StringBuffer> *writer;
		Document::AllocatorType *allocator;
		Value *temp;

		void init();
		void edit_value(char dep[]);
		void add_value(string name,string type,string value = "$");
		void write();
		vector<string> get_array_string(string name);
		int get_int(string name);
		string get_string(string name);
		vector<string> dependency_provider();
};