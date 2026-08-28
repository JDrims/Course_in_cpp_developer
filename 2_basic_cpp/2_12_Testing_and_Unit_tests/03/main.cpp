#include "test_extarray.h"

int main()
{
	test_checksum_type_valid();
	test_checksum_type_invalid();
	test_checksum_content_valid();
	test_checksum_content_invalid();
	test_checksum_result();

	return 0;
}