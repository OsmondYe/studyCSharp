// RmcSDKWrapperTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, wchar_t** argv)
{
	testing::InitGoogleTest(&argc, argv);

	// filter *,?,-,:
	//	 aaa.*:bbb.*:ccc.*		->  only test aaa,bbb, ccc
	//	 aaa.*-aaa.version		->  test all all but except aaa.version
	//testing::FLAGS_gtest_filter = "Windows.*";
	//testing::FLAGS_gtest_filter = "MadchookTest.*";
	testing::FLAGS_gtest_filter = "RMCSKDWrapperTest.*";
	//testing::FLAGS_gtest_filter = "RMCSKDWrapperTest.UserProtectFile";
	//testing::FLAGS_gtest_filter = "RMCSKDTest.*";
	//testing::FLAGS_gtest_filter = "Utils.*";
	//testing::FLAGS_gtest_filter = "Openssl.BoostBeast";
	//testing::FLAGS_gtest_filter = "CppLanguage.*";
	//testing::FLAGS_gtest_filter = "BoostAsio.*";

	return RUN_ALL_TESTS();
}

