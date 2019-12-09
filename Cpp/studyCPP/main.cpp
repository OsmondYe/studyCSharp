// studyCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"


/*
container_hearders:
	vector 
	deque
	forward_list		:  single linked list
	list				:  double linked list
	-----
	map set
	unordered_map/set
	-----
	queue/ stack		:	adapter
	-----
	array				:  fixed dimenstion array
	bitset				:  bool array
*/

int main(int argc, wchar_t** argv)
{
	srand(time(NULL));

	testing::InitGoogleTest(&argc, argv);

	// filter *,?,-,:
	//	 aaa.*:bbb.*:ccc.*		->  only test aaa,bbb, ccc
	//	 aaa.*-aaa.version		->  test all all but except aaa.version
	//testing::FLAGS_gtest_filter = "Windows.RegOperation2";
	//testing::FLAGS_gtest_filter = "*Container.*:Algorithm.*:Syntax.*";
	//testing::FLAGS_gtest_filter = "Concurrency.MustJoinOrDetach";
	//testing::FLAGS_gtest_filter = "Container.*";

	//testing::FLAGS_gtest_filter = "Idiom.*:Syntax.*:Container.*:Concurrency.*";
	testing::FLAGS_gtest_filter = "Syntax.*";
	testing::FLAGS_gtest_filter = "Stream.*";
	testing::FLAGS_gtest_filter = "Regex.*";
	testing::FLAGS_gtest_filter = "String.*";
	testing::FLAGS_gtest_filter = "Random.*";
	testing::FLAGS_gtest_filter = "Algorithm.*";
	testing::FLAGS_gtest_filter = "DSBase.Perm";
	testing::FLAGS_gtest_filter = "DSBase.*";
	testing::FLAGS_gtest_filter = "DSLinear.*";
	

	return RUN_ALL_TESTS();

}

