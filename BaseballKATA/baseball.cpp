#include <string>
#include <stdexcept>
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};
class Baseball {
public:
	Baseball(const std::string& question) :question(question), result{ false,0,0 } {}
	GuessResult guess(const std::string& guessNumber){
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
			return { true, 3, 0 };
		result = {};
		for (auto ch : guessNumber) {
			if (question.find(ch) == std::string::npos)
				result.balls++;
			else
				result.strikes++;
		}
		return result;
	}

	int getStrikes() {
		return result.strikes;
	}

	int getBalls() {
		return result.balls;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw std::length_error("Must be three letters.");
		for (auto ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw std::invalid_argument("Must be number.");
		}
		if (isDuplicateNumber(guessNumber))
			throw std::invalid_argument("Must not have the same number.");
	}
	bool isDuplicateNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

private:
	std::string question;
	GuessResult result;
};