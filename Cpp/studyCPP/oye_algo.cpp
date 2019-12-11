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