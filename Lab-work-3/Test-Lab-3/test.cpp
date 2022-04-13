#include "pch.h"
#include "../Lab-work-3/Functions.h"


using namespace mywork;

TEST(ZeroOutInteger, zeroFirstElement) {
	int mass[] = { 135, 23466, 23, 1515, 535 };
	int copy[] = { 23466, 23, 1515, 535, 0 };

	zeroOut2(mass, 5, 0); // 1 element zeroOut
	int i = 0;
	while (i < 5)
	{
		EXPECT_EQ(mass[i], copy[i]);
		i++;
	}





}

TEST(ZeroOutInteger, zeroElement) {

	int mass[] = { 135, 23466, 23, 1515, 535 };
	int copy[] = { 135, 23466, 1515, 535, 0 };

	zeroOut2(mass, 5, 2); //2 element zeroOut
	int i = 0;
	while (i < 5)
	{
		EXPECT_EQ(mass[i], copy[i]);
		i++;
	}
}

TEST(ZeroOutInteger, zeroLastElement) {
	int mass[] = { 135, 23466, 23, 1515, 535 };
	int copy[] = { 135, 23466, 23, 1515, 0 };

	zeroOut2(mass, 5, 4); //4 element zeroOut
	int i = 0;
	while (i < 5)
	{
		EXPECT_EQ(mass[i], copy[i]);
		i++;
	}


}












