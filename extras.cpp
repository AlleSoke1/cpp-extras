#include "Extras.h"
#include <afxwin.h>
#include <fstream>
#include <codecvt>

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
