#include "extended_array.h"
#include <cassert>

void test_checksum_type_valid()
{
	ExtArray<int> intArr{ 0, 1, 0 };
	try {
		int sum = intArr.checkSum();
		std::cout << "int checkSum returned " << sum << std::endl;
	}
	catch (...) {
		assert(false && "checkSum threw exception for int type");
	}

	ExtArray<bool> boolArr{ true, false, true };
	try {
		int sum = boolArr.checkSum();
		std::cout << "bool checkSum returned " << sum << std::endl;
	}
	catch (...) {
		assert(false && "checkSum threw exception for bool type");
	}

	std::cout << "Test checkSum type valid. OK" << std::endl;
}

void test_checksum_type_invalid()
{
	ExtArray<double> doubleArr{ 1.0, 2.0 };
	try {
		doubleArr.checkSum();
		assert(false && "checkSum should throw bad_typeid for double");
	}
	catch (const std::bad_typeid& e) {
		std::cout << "Caught expected bad_typeid: " << e.what() << std::endl;
	}
	catch (...) {
		assert(false && "checkSum threw unexpected exception for double");
	}

	std::cout << "Test checkSum type invalid. OK" << std::endl;
}

void test_checksum_content_valid()
{
	ExtArray<int> arr{ 0, 1, 1, 0, 1 };
	try {
		int sum = arr.checkSum();
		assert(sum == 3);
	}
	catch (...) {
		assert(false && "checkSum threw exception for valid content");
	}

	ExtArray<int> empty(0);
	try {
		assert(empty.checkSum() == 0);
	}
	catch (...) {
		assert(false);
	}

	std::cout << "Test checkSum content valid. OK" << std::endl;
}

void test_checksum_content_invalid()
{
	ExtArray<int> arr{ 0, 1, 2, 1 };
	try {
		arr.checkSum();
		assert(false && "checkSum should throw logic_error for value 2");
	}
	catch (const std::logic_error& e) {
		std::cout << "Caught expected logic_error: " << e.what() << std::endl;
	}
	catch (...) {
		assert(false && "checkSum threw unexpected exception for invalid content");
	}

	std::cout << "Test checkSum content invalid. OK" << std::endl;
}

void test_checksum_result()
{
	ExtArray<int> arr1{ 1, 0, 1, 1 };
	assert(arr1.checkSum() == 3);

	ExtArray<bool> arr2{ true, false, true, false, true };
	assert(arr2.checkSum() == 3);

	std::cout << "Test checkSum result. OK" << std::endl;
}