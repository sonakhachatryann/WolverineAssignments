#include <iostream>
void memcpy(void* src, void* dest, size_t size) {
	int i = 0;
	while (size != 0) {
		*((char *)dest + i) = *(char *)src;
		++i;
		src = static_cast<char *>(src) + 1;
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
