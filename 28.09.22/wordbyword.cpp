#include <iostream>
#include <fstream>

int main() {
	std::ifstream fin("myfile.txt");
	std::fstream fout;
	char ch;
	fout.open("yourfile.txt", std::ios::out);
	fin.seekg(0, std::ios::beg);
	while (fin) {
		fin.get(ch);
		while (ch != ' ' && ch != ',' && ch != '\n') {
			fout << ch;
			fin.get(ch);
			if (ch == ' ' || ch == ',' || ch == '\n') {
				fout << std::endl;
				break;
			}
		} 
	}
	fin.close();
	fout.close();
	return 0;
}
