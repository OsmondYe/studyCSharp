#include "pch.h"

#include<limits>

// numeric_limits 

// ��������ȷ����ͬ�������͵���ֵ���½�����

TEST(Limits, Basic) {

	cout << numeric_limits<int>::max();
	cout << numeric_limits<int>::min();

}