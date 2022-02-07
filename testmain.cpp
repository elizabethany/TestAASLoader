#include <vector>
#include <iostream>
#include "aas.hpp"

char* getFilePath()
{
	char* filePath = new char[150];
	std::cin.getline(filePath, 150);

	return filePath;
}

int main() {

	idAAS2File myFile{};

	std::cout << ".BAAS file path: ";
	const char* aasFilePath = getFilePath();
	load_aas(&myFile, aasFilePath);

	std::cout << "Output file path: ";
	const char* outputPath = getFilePath();
	write_aas(&myFile, outputPath);

	return 0;

}