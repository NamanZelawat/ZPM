#include<bits/stdc++.h>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;
using namespace std;

class Info_handler
{
	public:
		Document *document;
		StringBuffer *buf;
		ofstream *fout; 
		PrettyWriter<StringBuffer> *writer;
		Document::AllocatorType *allocator;
		Value *temp;

		void edit_value();
		void add_value(string name,string type,string value);
		void write();
		Info_handler();
		~Info_handler();
};