#include <iostream>
#include "baseball.cpp"
#include "gmock/gmock.h"

TEST(BaseballGame, ThrowExceptionInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(std::string("12")), std::length_error);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}