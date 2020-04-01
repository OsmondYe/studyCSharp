#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <shellapi.h>
#include <combaseapi.h>

#include <Tlhelp32.h>  // for CreateToolhelp32Snapshot

// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <tchar.h>
// c++
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>


// I always like springf, fsprintf
#pragma comment(lib,"legacy_stdio_definitions.lib")
#endif //PCH_H


using namespace std;

//
//here are my utils;
//

// hook and inject
void inject_dll(int pid, const string& dll_path);
void inject_dll(const string& pname, const string& dll_path);

// shell api
void lookup_english_word_in_browser(const std::string& word);

void shell_api_test();

// network api
void query_address_by_name(const string& name);
void query_host_name();