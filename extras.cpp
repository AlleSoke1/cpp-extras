#include "Extras.h"
#include <afxwin.h>
#include <fstream>


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
