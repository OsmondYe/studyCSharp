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

int main(int argc, wchar_t** argv) {
	testing::InitGoogleTest(&argc, argv);


	int a = 12;
	int b = sizeof(a);

	DWORD64 c = 0x0123456789ABCDEF;

	
	// filter *,?,-,:
	//	 aaa.*:bbb.*:ccc.*		->  only test aaa,bbb, ccc
	//	 aaa.*-aaa.version		->  test all all but except aaa.version
	//testing::FLAGS_gtest_filter = "Windows.RegOperation2";
	testing::FLAGS_gtest_filter = "MadchookTest.ScreenCapture";
	//testing::FLAGS_gtest_filter = "RMCSKDWrapperTest.*";
	//testing::FLAGS_gtest_filter = "RMCSKDWrapperTest.UserProtectFile";
	//testing::FLAGS_gtest_filter = "RMCSKDTest.*";
	//testing::FLAGS_gtest_filter = "Utils.*";
	//testing::FLAGS_gtest_filter = "Openssl.BoostBeast";
	//testing::FLAGS_gtest_filter = "CppLanguage.CppBasicStringStudy";
	//testing::FLAGS_gtest_filter = "BoostAsio.*";


	return RUN_ALL_TESTS();
}





