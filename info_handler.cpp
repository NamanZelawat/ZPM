#include "info_handler.h"

void Info_handler::edit_value()
{

}

void Info_handler::add_value(string name,string type,string value = "$")
{
	if(type == "int")
	{
		Value nm(name.c_str(),*allocator);
		temp->SetInt(stoi(value));
		document->AddMember(nm, *temp, *allocator);
	}
	else if(type == "float")
	{
		Value nm(name.c_str(),*allocator);
		temp->SetFloat(stof(value));
		document->AddMember(nm, *temp, *allocator);
	}
	else if(type == "string")
	{
		Value nm(name.c_str(),*allocator);
		temp->SetString(value.c_str(), *allocator);
		document->AddMember(nm, *temp, *allocator);
	}
	else if(type == "array")
	{
		Value nm(name.c_str(),*allocator);
		temp->SetArray();
		document->AddMember(nm, *temp, *allocator);
	}
	else if(type == "object")
	{
		Value nm(name.c_str(),*allocator);
		temp->SetObject();
		document->AddMember(nm, *temp, *allocator);
	}
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