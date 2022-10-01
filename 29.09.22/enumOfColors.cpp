#include <iostream>

#include <map>

#include <string>


enum class Color { Red, Green, Blue, White, Black, Purple, Yellow, Pink, Orange };

std::map<Color, std::string> m = { 
	{Color::Red, "Red"}, 
	{Color::Green, "Green"}, 
	{Color::Blue, "Blue"}, 
	{Color::White, "White"}, 
	{Color::Black, "Black"}, 
	{Color::Purple, "Purple"} , 
	{Color::Yellow, "Yellow"}, 
	{Color::Pink, "Pink"}, 
	{Color::Orange, "Orange"} 
};  

std::ostream& operator<<(std::ostream& out, const Color c) {
	out << "Color::" << m[c] << std::endl;
	return out;
}

std::string toString(Color x) {
	return m[x];
}

Color toEnum(std::string s) {
	for (const auto& [key, value] : m) {
		if (s == value) {
			return key;
		}
	}
}

int main() {
	std::cout << toString(Color::Pink) << std::endl;
	std::cout << toEnum("Orange");
	return 0;
}
