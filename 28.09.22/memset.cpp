#include <iostream>

void memset(void* str, char ch, size_t size) {
	while (size != 0) {
		*(char *)str = ch;
		str = static_cast<char *>(str) +1;
		--size;
	}
	return;
}

int main() {	
	char arr[4];
	memset(arr, 'a', 4);
	for (int i = 0; i < 4; ++i) {
		std::cout << arr[i];
	}
	std::cout << std::endl;
	return 0;
}
