#include <iostream>

void memset(char* str, char ch, int size) {
	while (size != 0) {
		*str = ch;
		++str;
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
