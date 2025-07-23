#include <string>
#include <stdexcept>
class Baseball {
public:
	void guess(const std::string& string){
		if (string.length() != 3)
			throw std::length_error("Must be three letters.");
		for (auto ch : string) {
			if (ch < '0' || ch > '9')
				throw std::invalid_argument("Must be number.");
		}
	}
};