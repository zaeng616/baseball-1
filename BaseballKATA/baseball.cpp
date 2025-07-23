#include <string>
#include <stdexcept>
class Baseball {
public:
	void guess(const std::string& string){
		throw std::length_error("Must be three letters.");
	}
};