#include <iostream>
#include "baseball.cpp"
#include "gmock/gmock.h"
class BaseballFixture : public testing::Test {
public:
	Baseball game;
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
}
int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}