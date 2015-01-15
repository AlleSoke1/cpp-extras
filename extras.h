#ifndef EXTRAS_H
#define EXTRAS_H
#pragma once
#include <iostream>
#include <vector>
#include <afxwin.h>
#include <codecvt>
#include <fstream>
#include <string>
#include <sstream>

#define STORE_ACCOUNT "./Data.sky"
#define XOR_KEY 0xFF

bool FileExists(std::string path);
bool FileDelete(std::string path);
std::string capital(std::string name);
std::string xorIT(std::string what);
std::wstring s2ws(const std::string& str);
std::string ws2s(const std::wstring& wstr);
bool WriteAccountData(std::string user, std::string password, bool createFlag);
std::vector<std::string> ReadAccountData();
std::vector<std::string> SplitString (std::string input);

#endif
