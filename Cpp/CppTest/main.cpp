// CppTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;




int main(int argc, wchar_t** argv) {
	testing::InitGoogleTest(&argc, argv);
	

	// filter *,?,-,:
	//	 aaa.*:bbb.*:ccc.*		->  only test aaa,bbb, ccc
	//	 aaa.*-aaa.version		->  test all all but except aaa.version
	//testing::FLAGS_gtest_filter = "Windows.*";
	testing::FLAGS_gtest_filter = "Win32.*";
	testing::FLAGS_gtest_filter = "User32.*";
	testing::FLAGS_gtest_filter = "User32.PrinterRelated";
	testing::FLAGS_gtest_filter = "Shell32.*";
	testing::FLAGS_gtest_filter = "Windows.FClearFolder";
	testing::FLAGS_gtest_filter = "Utils.Str";
	testing::FLAGS_gtest_filter = "Win32.InterlockedXXX";
	testing::FLAGS_gtest_filter = "Win32.Thread_Multi";
	testing::FLAGS_gtest_filter = "Process.Enum";
	testing::FLAGS_gtest_filter = "Process.AdjustDebugRights";
	testing::FLAGS_gtest_filter = "gdi.ScreenCapture";
	

	return RUN_ALL_TESTS();
}





