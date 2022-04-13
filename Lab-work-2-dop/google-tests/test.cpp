#include "pch.h"
#include "../Lab-work-2-dop/Functions.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
using namespace func;
TEST(UniqLetters, isuniq) {
	

	EXPECT_EQ(func::isUnique_let("wwgvegh4y", 'y'), 0);

	EXPECT_EQ(func::isUnique_let("wwgvegh4y", 'g'), 0);

	EXPECT_EQ(func::isUnique_let("ed2drt.yortleo234ap", 'r'), 0);
}


TEST(UniqLetters, getUniqLetters) {

	char first[] = ".lldf456f6hfcoocopla"; //uniq = ldfhcopa
	char second[] = "";
	char third[] = "";


	//первый тест
	char* first_uniq = get_unique_letters(first);
	char first_uniq_manual[] = "ldfhcopa";
	int i = 0, j = 0;
	while (first_uniq[i] != 0)
	{
		EXPECT_EQ(first_uniq[i], first_uniq_manual[i]);
		i++;

	}
	//---------------


}
