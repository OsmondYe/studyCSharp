#include "pch.h"

int main(int argc, wchar_t** argv)
{
	srand(time(NULL));	// give a randome seed

	testing::InitGoogleTest(&argc, argv);

	// filter *,?,-,:
	//	 aaa.*:bbb.*:ccc.*		->  only test aaa,bbb, ccc
	//	 aaa.*-aaa.version		->  test all all but except aaa.version
	//testing::FLAGS_gtest_filter = "Windows.RegOperation2";
	//testing::FLAGS_gtest_filter = "*Container.*:Algorithm.*:Syntax.*";
	//testing::FLAGS_gtest_filter = "Concurrency.MustJoinOrDetach";

	//testing::FLAGS_gtest_filter = "Idiom.*:Syntax.*:Container.*:Concurrency.*";
	testing::FLAGS_gtest_filter = "Stream.*";
	testing::FLAGS_gtest_filter = "Regex.*";
	testing::FLAGS_gtest_filter = "Random.*";
	testing::FLAGS_gtest_filter = "Algorithm.*";
	testing::FLAGS_gtest_filter = "DSBase.Perm";
	testing::FLAGS_gtest_filter = "String.ReplaceAll";
	testing::FLAGS_gtest_filter = "Idiom.MacroParam";
	testing::FLAGS_gtest_filter = "Sort.Merge";
	testing::FLAGS_gtest_filter = "Concurrency.Mutex";
	testing::FLAGS_gtest_filter = "String.IEqual";
	testing::FLAGS_gtest_filter = "Chrono.*";
	testing::FLAGS_gtest_filter = "Set.*";
	testing::FLAGS_gtest_filter = "OyeAlgo.Fibonacci";
	testing::FLAGS_gtest_filter = "Sort.Quick";
	testing::FLAGS_gtest_filter = "DSLinear.MAX_SUB_ARRAY";
	testing::FLAGS_gtest_filter = "DSLinear.Vector_Remove_duplicate_Elem";
	testing::FLAGS_gtest_filter = "Map.Hash";
	testing::FLAGS_gtest_filter = "Memory.SmartPtr_Array";
	testing::FLAGS_gtest_filter = "AlgoLinear.LeetCode*";
	testing::FLAGS_gtest_filter = "AlgoHash.LeetCode";
	testing::FLAGS_gtest_filter = "AlgoStr.LeetCode";
	testing::FLAGS_gtest_filter = "AlgoTree.LeetCode";
	testing::FLAGS_gtest_filter = "Template.*";
	testing::FLAGS_gtest_filter = "Iterator.*";
	testing::FLAGS_gtest_filter = "Syntax.*";
	

	return RUN_ALL_TESTS();

}

