#include <iostream>
void memcpy(char* src, char* dest, int size) {
	int i = 0;
	while (size != 0) {
		dest[i] = *src;
		++i;
		++src;
		--size;
	}
	return;
}
int main() {
	char arr[] = "hello";
	char arr2[6];
	memcpy(arr, arr2, 6);
	std::cout << arr2;
	return 0;
}
