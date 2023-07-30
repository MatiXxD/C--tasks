#include <iostream>

template <class type>
void swaps(type& var1, type& var2) {

	type temp = var2;
	var2 = var1;
	var1 = temp;

}

int main() {

	int var1 = 1, var2 = 2; std::cout << "Int:\n";
	std::cout << "Before: " << var1 << ' ' << var2 << std::endl;
	swaps(var1, var2);
	std::cout << "After: " << var1 << ' ' << var2 << std::endl;

	float var1f = 1.1, var2f = 2.2; std::cout << "\nFloat:\n";
	std::cout << "Before: " << var1f << ' ' << var2f << std::endl;
	swaps(var1f, var2f);
	std::cout << "After: " << var1f << ' ' << var2f << std::endl;

	char var1c = 11, var2c = 22; std::cout << "\Char:\n";
	std::cout << "Before: " << static_cast<int>(var1c) << ' ' << static_cast<int>(var2c) << std::endl;
	swaps(var1c, var2c);
	std::cout << "After: " << static_cast<int>(var1c) << ' ' << static_cast<int>(var2c) << std::endl;

	return 0;

}
