#include "Extras.h"

bool FileExists(std::string path)
{
	std::ifstream my_file(path);
	if (my_file)
	{
		return true;
	}
	return false;
}

bool FileDelete(std::string path) 
{
	if (remove(path.c_str()) != 0)
	{
		char buff[128];
		wsprintf(buff, "Cannot delete file %s \nPlease remove manually!",path.c_str());
		MessageBoxA(NULL,buff, "ERROR", MB_OK);
		return true;
	}
	else 
	{
		return false;
	}

}

std::string capital(std::string name)
{

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = toupper(name[i]);
	}

	return name;

}

std::string xorIT(std::string what)
{
	for (int i = 0; i < what.length(); i++)
	{
		what[i] = what[i] ^ XOR_KEY;
	}
	return what;
}

std::wstring s2ws(const std::string& str)
{
	typedef std::codecvt_utf8<wchar_t> convert_typeX;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

std::string ws2s(const std::wstring& wstr)
{
	typedef std::codecvt_utf8<wchar_t> convert_typeX;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

bool WriteAccountData(std::string user, std::string password, bool createFlag)
{
		std::ofstream File(STORE_ACCOUNT);
		if (File.is_open())
		{
			File << xorIT(user);
			File << " ";
			File << xorIT(password);
			File.close();
		}
	char buff[120];
	wsprintf(buff,"Writing Data: %s %s",user.c_str(),password.c_str());
	MessageBoxA(NULL, buff, "OK", MB_OK);

	return true;
}


std::vector<std::string> ReadAccountData()
{
	std::string line;
	if (FileExists(STORE_ACCOUNT) == true)
	{
		std::ifstream File(STORE_ACCOUNT);
		if (File.is_open())
		{
			//There's only one LINE !^^
			std::getline(File, line);
			File.close();
		}
	}
	return SplitString(line);
}


std::vector<std::string> SplitString(std::string input)
{
	std::string buf;
	std::stringstream ss(input); 

	std::vector<std::string> tokens; 

	while (ss >> buf)
		tokens.push_back(buf);

	char buff[120];
	wsprintf(buff, "Read Data: %s %s", tokens[0].c_str(), tokens[1].c_str());
	MessageBoxA(NULL, buff, "OK", MB_OK);

	return tokens;
}
