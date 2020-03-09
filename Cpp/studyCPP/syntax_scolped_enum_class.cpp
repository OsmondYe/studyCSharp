#include "pch.h"

//c11
enum class Color : std::uint32_t {  // : std::uint32_t give enum a fixed,explicit value type
	red,
	white,
	black
};

//c++ old

enum MyColor {
	MyRed,
	MyWhite
};



TEST(Syntax, ScopedEnum) {

	Color c = Color::black;
	cout << (int)c << endl;
	// psedo-key-word red will not be leak into global 
	Color red = Color::red;
	cout << (int)red << endl;
	cout << (int)MyRed << endl;  // MyRed is the elem in enum MyColor
	int MyRed = 12;
	cout << MyRed << endl;       // but now MyRed is a int var
}



// ��չ�� enum
enum class Salutation : char {
	mr,
	ms,
	co,
	none
};

TEST(Syntax, ScoptedEnumeration) {
	Salutation s = Salutation::mr;
	s = Salutation::ms;
	s = (Salutation)12;
}