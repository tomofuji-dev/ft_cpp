#include "Data.hpp"
#include <cstdlib>
#include <ctime>

Data::Data() : value_(0) {
	srand(time(NULL));
	value_ = rand();
}

Data::~Data() {}

uintptr_t	Data::getValue() const {
	return value_;
}

std::ostream& operator<<(std::ostream& stream, const Data& value) {
	stream << value.getValue();
	return stream;
}
