#include <string>
#include <stdexcept>
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};
class Baseball {
public:
	Baseball(const std::string& question) :question(question) {}
	GuessResult guess(const std::string& guessNumber){
		assertIllegalArgument(guessNumber);
		return { true, 3, 0 };
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
};