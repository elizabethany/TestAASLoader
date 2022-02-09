#include <vector>
#include <iostream>
#include "aas.hpp"

char* getFilePath()
{
	char* filePath = new char[150];
	std::cin.getline(filePath, 150);

	return filePath;
}

// Make string copy of file path, change extension from .baas to .aas (the format for plain text AAS files), and add it to the output folder path
std::string getOutputPath(
	const char* aasFilePath
)
{
	std::string fileName(aasFilePath);
	const std::string extension = ".baas";
	size_t startPoint = fileName.find(extension);
	size_t endPoint = extension.length();
	fileName.replace(startPoint, endPoint, ".aas");

	auto filePath = "Plain Text AAS/" + fileName;

	return filePath;
}

int main(
	int argc,
	char** argv
)
{
	// New aas struct
	idAAS2File myFile;
	char* tempFile;

	if (argv[1] != NULL) // Get .baas file path from drag & drop and load AAS into struct
	{
		tempFile = argv[1];
	}
	else // Get .baas file path from console input and load AAS into struct
	{
		std::cout << ".BAAS file path: ";
		tempFile = getFilePath();
	}

	const char* aasFileName = tempFile;

	load_aas(&myFile, aasFileName);

	std::cout << "\nAAS file loaded";

	// Use input AAS file name to create output file name
	auto outputPath = getOutputPath(aasFileName); // bfg_division.baas_monster128;aas

	// Write AAS to output file
	write_aas(&myFile, outputPath);
	std::cout << "\nPress Enter or close this window . . .";
	std::cin.get();

	return 0;
}