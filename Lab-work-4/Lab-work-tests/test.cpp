#include "pch.h"
#include "../Lab-work-4/MyLibForLab.h"

using namespace mylab;

TEST(IsNumberTests, isnumberWork) {
	char first = 'a'; // 0
	char second = '6'; // 1
	char third = '/'; // 0
	char fourth = '-'; // 0
	char fifth = '0'; // 1

	ASSERT_EQ(isNumber(first), 0);
	ASSERT_EQ(isNumber(second), 1);
	ASSERT_EQ(isNumber(third), 0);
	ASSERT_EQ(isNumber(fourth), 0);
	ASSERT_EQ(isNumber(fifth), 1);
}

TEST(MakeIntegerTests, makeInt) {
	char first[] = "awergy123"; //0 т.к. с первого числа из массива
	char second[] = "dwrigwg"; // 0
	char third[] = "-1413we"; //-1413

	ASSERT_EQ(makeInteger(first), 0);
	ASSERT_EQ(makeInteger(second), 0);
	ASSERT_EQ(makeInteger(third), -1413);
}
TEST(MyStrlenTests, getlen) {
	char firt[] = "ergyg23jf"; // 10
	char second[4] = "123"; // 4

	ASSERT_EQ(my_strlen(firt), 9);
	ASSERT_EQ(my_strlen(second), 3);
}

TEST() {
	char first[] = "lol123.gw45 rguy 401 kr 863"; // 123 45 401 863
	int mass[4];
	int len = 4;


}