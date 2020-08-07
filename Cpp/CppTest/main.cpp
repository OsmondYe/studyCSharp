// CppTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest/gtest.h>


using namespace std;

class GlobalEnvironment : public testing::Environment {
	virtual void SetUp() {
		wcout << L"OsmondTest:Global Setup" << endl;
	}

	// Override this to define how to tear down the environment.
	virtual void TearDown() {
		wcout << L"OsmondTest:Global Teardown" << endl;
	}
};


// find a way to init gdi+
ULONG_PTR gdiplusToken;
Gdiplus::GdiplusStartupInput gdipulsInput;
void init_gdi_plus() {
	Gdiplus::GdiplusStartup(&gdiplusToken,&gdipulsInput,NULL);
}

int main(int argc, wchar_t** argv) {
	testing::InitGoogleTest(&argc, argv);
	

	init_gdi_plus();

	// filter *,?,-,:
	//	 aaa.*:bbb.*:ccc.*		->  only test aaa,bbb, ccc
	//	 aaa.*-aaa.version		->  test all all but except aaa.version
	//testing::FLAGS_gtest_filter = "Windows.*";
	//testing::FLAGS_gtest_filter = "MadchookTest.SkyDRMViewer";
	//testing::FLAGS_gtest_filter = "ATL.*";
	//testing::FLAGS_gtest_filter = "Openssl.BoostBeast";
	//testing::FLAGS_gtest_filter = "BoostAsio.*";
	//testing::FLAGS_gtest_filter = "MadchookTest.InjectMsPhoto";
	testing::FLAGS_gtest_filter = "Utils.Process";
	testing::FLAGS_gtest_filter = "Win32.*";
	testing::FLAGS_gtest_filter = "User32.*";
	testing::FLAGS_gtest_filter = "User32.PrinterRelated";
	testing::FLAGS_gtest_filter = "Shell32.*";
	testing::FLAGS_gtest_filter = "Utils.Str";
	testing::FLAGS_gtest_filter = "Windows.FReplaceFile";
	




	return RUN_ALL_TESTS();
}





