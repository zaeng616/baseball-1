#include <iostream>
#include "baseball.cpp"
#include "gmock/gmock.h"
class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(std::string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (std::exception e) {}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnFailResultTwoStrikesOneBall) {
	GuessResult result = game.guess("103");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(1, result.balls);
	EXPECT_EQ(2, game.getStrikes());
}

TEST_F(BaseballFixture, ReturnFailResultOneStrikeTwoBalls) {
	GuessResult result = game.guess("109");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
	EXPECT_EQ(2, game.getBalls());
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}