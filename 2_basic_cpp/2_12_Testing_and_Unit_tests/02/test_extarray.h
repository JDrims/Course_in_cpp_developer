#include "extended_array.h"
#include <cassert>

void test_mean_range_valid()
{
	ExtArray<int> arr{1, 2, 3, 4, 5};

	assert(static_cast<double>(arr.mean(0, 5)) == 3.0);
	assert(static_cast<double>(arr.mean(1, 4)) == 3.0);
	assert(static_cast<double>(arr.mean(2, 3)) == 3.0);
	assert(static_cast<double>(arr.mean(0, 1)) == 1.0);

	std::cout << "Test mean range valid. OK" << std::endl;
}

void test_mean_range_invalid()
{
	ExtArray<int> arr{ 10, 20, 30 };

	try
	{
		arr.mean(2, 1);
		assert(false);

		std::cout << "Test mean range valid. OK" << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Test mean range invalid argument: " << e.what() << ". OK" << std::endl;
	}

	try
	{
		arr.mean(3, 4);
		assert(false);

		std::cout << "Test mean range valid. OK" << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Test mean range invalid argument: " << e.what() << ". OK" << std::endl;
	}

	try {
		arr.mean(1, 4);
		assert(false);

		std::cout << "Test mean range valid. OK" << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "Test mean range invalid argument: " << e.what() << ". OK" << std::endl;
	}

	try {
		arr.mean(1, 1);
		assert(false);

		std::cout << "Test mean range valid. OK" << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "Test mean range invalid argument: " << e.what() << ". OK" << std::endl;
	}

	std::cout << "Test mean range invalid. OK" << std::endl;
}