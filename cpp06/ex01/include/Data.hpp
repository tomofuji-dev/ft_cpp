#ifndef DATA_HPP
#define DATA_HPP
#include <stdint.h>
# include <iostream>

class Data {

public:

	Data();
	~Data();
	uintptr_t	getValue() const;

private:

	int value_;
	
	Data(const Data& src);
	Data&	operator=(const Data& rhs);

};

std::ostream& operator<<(std::ostream& stream, const Data& value);

#endif
