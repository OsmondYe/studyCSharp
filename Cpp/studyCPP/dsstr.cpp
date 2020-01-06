#include "pch.h"
// this is string common algo

// my strchr
char* oye_strchr(const char* string, char ch) {

	while ( *string && *string!=ch ){		
		++string;
	}
	if (*string == ch) {
		return (char*)string;
	}
	return (NULL);
}

// my last occurrence of ch in str
char* oye_strrchr(const char* str, char ch) {
	const char* begin = str;
	// move str to end
	while (*str++);

	// search toward front
	while (--str != begin && *str != ch);	

	return (*str) == ch ? (char*)str : NULL;
}
// search str2 in str1
char* oye_strstr(const char* str1, const char* str2) {

	char* cp = (char*)str1;
	char *s1, *s2;			// alarm char* s1,s2  XXXXXX s2 is char , not char*

	if (!*str2) {
		return (char*)str1;
	}

	//scan whole str1
	while (*cp)
	{
		s1 = cp;
		s2 = (char*)str2;

		// each pos in str1, check sutstr , 
		while (*s1 && *s2 && !(*s2 - *s1)) {
			s1++, s2++;
		}

		if (!*s2) {
			return cp;
		}
		
		cp++;
	}

	return NULL;

}

TEST(DSStr, Count) {
	char str[] = "hello world";

	cout << oye_strchr(str, 'w') << endl;
	cout << oye_strrchr(str, 'w') << endl;
	// SEH exception	
	//cout << oye_strstr(str, "worlddgdf") << endl;
}


/*Longest Substring Without Repeating Characters
Input: "abcabcbb"
Output: 3

Input: "bbbbb"
Output: 1

Input: "pwwkew"
Output: 3
-------------
using dp, exsit optimize value
	-dp[i],  longest must incldue s[i];
	-dp[i] ? dp[i-1]
		- char(dp[i]) never counted,
			dp[i]=dp[i-1]+1;
		- char(dp[i]) has counted in  previous count
			d= dist(i - dp[i]) 


*/

int lswrc(std::string& s) {
	// sanity check
	if (s.empty()) return 0;
	if (s.size() == 1) return 1;
	
	//
	vector<int> assist(256, -1);
	vector<int> dp(s.size(), -1);
	//
	dp[0] = 1;
	assist[s[0]] = 0;

	for (int i = 1; i < s.size(); ++i) {
		if (assist[s[i]] == -1) {
			//s[i] that is never count in
			dp[i] = dp[i - 1] + 1;
		}
		else {
			int dist = i -  assist[ s[i]];
			if (dist > dp[i - 1]) {
				dp[i] = dp[i - 1] + 1;
			}
			else if (dist == dp[i - 1]) {
				dp[i] = dp[i - 1];// like: abcda, 
			}
			else {
				// disp < dp[i-1]
				dp[i] = dist;	// like: abdcd dp[end()-1]=2;  cd
			}
		}
		assist[s[i]] = i;
	}

	// return max(dp);
	return *std::max_element(dp.begin(), dp.end());

}

TEST(DSStr, LSWRC) {
	cout << "longest substr without repeating chars" << endl;


	string s{ "abc" };
	EXPECT_EQ(3, lswrc(s));

	s = "aaa";
	EXPECT_EQ(1, lswrc(s));

	s = "abcda";
	EXPECT_EQ(4, lswrc(s));

	s = "pwwkew";
	EXPECT_EQ(3, lswrc(s));

	s = "abcabcbb";
	EXPECT_EQ(3, lswrc(s));

	s = "dvdf";
	EXPECT_EQ(3, lswrc(s));

	s = "ohvhjdml";
	EXPECT_EQ(6, lswrc(s));

	int i = 10;
	while (i--)
	{
		auto v = aux::getRandom_LowerAlpha(30);
		aux::output(v);
		aux::println(lswrc(v));
	}

}