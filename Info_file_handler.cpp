#include "Info_file_handler.h"
	
vector<string> Info_file_handler::dependency_provider()
{
	vector<string> res;
	for(int i = 0;i<(*document)["dependencies"].Size();i++)
	{
		res.push_back((*document)["dependencies"][i].GetString());
	}
	return res;
}

vector<string> Info_file_handler::get_array_string(string name)
{
	
}

int Info_file_handler::get_int(string name)
{
	
}

string Info_file_handler::get_string(string name)
{
	string ret = "~";
	if((*document).HasMember(name.c_str()))
	{
		ret = (*document)[name.c_str()].GetString();
	}
	return ret;
}

void Info_file_handler::edit_value(char dep[])
{
	(*document)["dependencies"].PushBack(Value().SetString(dep,strlen(dep)), *allocator);
	this->write();
}

void Info_file_handler::add_value(string name,string type,string value)
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

void Info_file_handler::write()
{
	std::ofstream fout; 
	fout.open("zpm.info");
	StringBuffer buf;
	writer = new PrettyWriter<StringBuffer>(buf);
	document->Accept(*writer);
	fout << buf.GetString() << endl;
	fout.close();
}

void Info_file_handler::init()
{
	std::ifstream fout; 
	fout.open("zpm.info");
	stringstream info;
	info << fout.rdbuf();
	fout.close();

	document = new Document;
	buf = new StringBuffer;
	allocator = new Document::AllocatorType;
	allocator = &(document->GetAllocator());
	temp = new Value();
	document->Parse(info.str().c_str(),info.str().size());
	this->write();
}

