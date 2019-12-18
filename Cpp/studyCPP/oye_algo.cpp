#include "pch.h"


// my strchr
char* oye_strchr(const char* string, char ch) {

	while ( *string && *string!=ch ){		// c����str��\0��β���Ǹ��ö���,����ֱ����ѭ���ж� (*string) Ϊ0, ѭ������
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

		// each pos in str1, check sutstr , �������������,��ô while���� *s2==NULL
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

TEST(OyeAlgo, Count) {

	char str[] = "hello world";

	cout << oye_strchr(str, 'w') << endl;
	cout << oye_strrchr(str, 'w') << endl;
	cout << oye_strstr(str, "worlddgdf") << endl;			// cout<<NULL ����һ������


}

static int c_fib = 0;
unsigned long long fibonacci(int n) {
	++c_fib;
	if (n == 0) return 0;
	if (n == 1)  return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}


TEST(OyeAlgo, Fibonacci) {
	int count=40;
	/*
		用Divide and Conqure来解决
			把问题划分为子问题，最小的子问题解已知，本质上就是一个树， 从上到下来处理
	*/
	for (int i = 3; i < count; i++) {
		int fib_num = i;
		c_fib = 0;
		cout << "fib_num:" << fib_num << "\tresult:" << fibonacci(fib_num) << "\tc_fib:" << c_fib << endl;
	}

	/*
		用Dynamic Programming来解决， 智商层面的优越感，油然而生
			根据DC得来的灵感， 如果从下到上来思考问题的解，不就常数时间搞定了

	*/
	vector<int> fn(count, 0);
	fn[0] = 0;
	fn[1] = 1;
	c_fib = 0;
	for (int i = 2; i < count; i++) {
		fn[i] = fn[i - 1] + fn[i - 2];
		cout << "fib_num:" << i << "\tresult:" << fn[i] << "\tc_fib:" << ++c_fib << endl;
	}

}