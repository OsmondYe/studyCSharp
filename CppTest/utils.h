#pragma once

namespace win {
	bool is_file_exist(const char* file);
	bool is_file_exist(const wchar_t* file);

	bool is_dir_exist(const char* dir);
	bool is_dir_exist(const wchar_t* dir);

	bool is_path_exist(const char* dir);
	bool is_path_exist(const wchar_t* dir);

	HANDLE get_process(const wchar_t* process_name);
	HANDLE get_process(int process_id);

};
