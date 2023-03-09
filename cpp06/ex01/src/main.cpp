#include "Data.hpp"
#include "Serialize.hpp"

void print_data(Data* data) {
	std::cout << data << ": " << data->getValue() << std::endl;
}

int main() {
	Data data;
	print_data(&data);
	uintptr_t serialized = serialize(&data);
	std::cout << "serialized: " << serialized << std::endl;
	Data* re_data = deserialize(serialized);
	print_data(re_data);
}

__attribute__((destructor))
void destructor() {
	system("leaks -q exe");
}
