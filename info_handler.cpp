#include "info_handler.h"

void Info_handler::edit_value()
{

}

void Info_handler::add_value(string name,string type,string value = "$")
{
	// if(type == "int")
	// {
	// 	temp.SetInt(stoi(value));
	// 	document.AddMember(name, temp, allocator);
	// }
	// else if(type == "float")
	// {
	// 	temp.SetFloat(stof(value));
	// 	document.AddMember(name, temp, allocator);
	// }
	// else if(type == "string")
	// {
	// 	temp.SetString(value, value.size()+1, document.GetAllocator());
	// 	document.AddMember(name, temp, allocator);
	// }
	// else if(type == "array")
	// {
	// 	temp.SetArray();
	// 	document.AddMember(name, temp, allocator);
	// }
	// else if(type == "object")
	// {
	// 	temp.SetObject();
	// 	document.AddMember(name, temp, allocator);
	// }
}

void Info_handler::write()
{
	*(fout) << buf->GetString() << endl;
}

Info_handler::Info_handler()
{
	document = new Document;
	buf = new StringBuffer;
	fout = new ofstream;
	writer = new PrettyWriter<StringBuffer>(*buf);
	allocator = new Document::AllocatorType;
	allocator = &(document->GetAllocator());
	temp = new Value();
	fout->open("zpm.info");
	document->Parse({});
	document->Accept(*writer);
	this->write();
}

Info_handler::~Info_handler()
{
	fout->close();
}