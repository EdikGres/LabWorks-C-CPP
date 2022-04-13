#include "pch.h"
#include "../Lab-work-3-dop/MyLibForLab.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
using namespace mylab;
TEST(MyLibTests, reverseMassTest) {

	int mass[5] = { 1, 2, 3, 4, 5 };

	reverseMass(mass, 5);
	int i = 0, j = 5;
	while (i < 5)
	{
		ASSERT_EQ(mass[i], j);
		j--;
		i++;
	}

}
TEST(MyLibTests, reverseMass2Test) {

	int mass[5] = { 1, 2, 3, 4, 5 };

	reverseMass2(mass, 5);
	int i = 0, j = 5;
	while (i < 5)
	{
		ASSERT_EQ(mass[i], j);
		j--;
		i++;
	}

}