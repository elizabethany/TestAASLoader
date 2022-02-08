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

	idAAS2File myFile;

	std::cout << ".BAAS file path: ";
	//const char* aasFilePath = getFilePath(); // intro.baas_monster48;aas
	const char* aasFilePath = "bfg_division.baas_monster128;aas";
	load_aas(&myFile, aasFilePath);

	std::cout << "Output file path: ";
	//const char* outputPath = getFilePath(); // test.txt
	const char* outputPath = "test.txt";
	write_aas(&myFile, outputPath);

	return 0;
}