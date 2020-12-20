
#include <gtest/gtest.h>

TEST(gtest_mtDequeLib_test1, test_Sample){
ASSERT_TRUE(true);
}


int main (int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
