#include "include/JustTest.hpp"

#include "gmock/gmock.h"

using namespace testing;

TEST(JustTest, AddTest)
{
	JustTest jt;
	int result = jt.Add(3, 5);

	ASSERT_THAT(result, Eq(8));
}