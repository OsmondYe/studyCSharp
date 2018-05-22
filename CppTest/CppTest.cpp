// CppTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "sdkwrapper.h"
#include <string>
#include <iostream>
#include <fstream>



using namespace std;
void binary_to_ascii(unsigned int value) {
	unsigned int quotient;
	quotient = value / 10;
	if (quotient != 0)
	{
		binary_to_ascii(quotient);
	}
	putchar(value % 10 + '0');
}



void testRMCSDK_wrapper();

int main()
{
	
	testRMCSDK_wrapper();

	return 0;
}



