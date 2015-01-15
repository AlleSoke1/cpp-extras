#ifndef EXTRAS_H
#define EXTRAS_H
#pragma once
#include <iostream>

#define STORE_ACCOUNT "./Data.sky"
#define XOR_KEY 0x55

bool FileExists(std::string path);
bool FileDelete(std::string path);
std::string capital(std::string name);
std::string xorIT(std::string what);
std::wstring s2ws(const std::string& str);
std::string ws2s(const std::wstring& wstr);
#endif
