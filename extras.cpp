#include <afxwin.h>
#include "stdafx.h"

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

	return tokens;
}

std::vector<std::string> &SplitStringDelim(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}



void FS_CheckUpgrade()
{
#if API_VER == 1
	if (FileExists("Resource00.pak") == true)
	{
		system("rename Resource00.pak Reborn00.sk; 		rename Resource01.pak Reborn01.sk;		rename Resource02.pak Reborn02.sk;		rename Resource03.pak Reborn03.sk;		rename Resource04.pak Reborn04.sk;		rename Resource05.pak Reborn05.sk;		rename Resource06.pak Reborn06.sk;		rename Resource07.pak Reborn07.sk;		rename Resource08.pak Reborn08.sk;		rename Resource09.pak Reborn09.sk;		rename Resource10.pak Reborn10.sk;		rename Resource11.pak Reborn11.sk;		del / F *.dll;		del DragonNest.exe;		del DragLauncher.exe; ");
		Sleep(2000);
		if (FileExists("Reborn00.sk") == true)
		{
			MessageBox(NULL, "File Structure upgrade complete!", "OK", MB_ICONHAND);
		}
	}
#endif
}
