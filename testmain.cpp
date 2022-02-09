#include <vector>
#include <iostream>
#include "aas.hpp"

static const std::string extension = ".baas";
static const std::string slash = "\\";

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
	// Create string copy of char* input file path
	std::string fileName(aasFilePath);

	// Remove everything before file name, if applicable
	if (fileName.find(slash) != std::string::npos)
	{
		std::size_t lastSlash = fileName.find_last_of(slash);
		fileName.erase(0, lastSlash);
	}

	// Change extension from .baas to .aas
	size_t startPoint = fileName.find(extension);
	size_t endPoint = extension.length();
	fileName.replace(startPoint, endPoint, ".aas");

	// Append name of output folder to start
	auto filePath = "Plain Text AAS/" + fileName;

	return filePath;
}

int main(
	int argc,
	char** argv
)
{
	// New AAS struct
	idAAS2File myFile;
	char* tempFile;

	if (argv[1] != NULL && argc > 0) // Get .baas file path from drag & drop/command line
	{
		tempFile = argv[1];
		if (std::string(tempFile).find(extension) == std::string::npos)
		{
			std::cout << "\nInvalid AAS file\nPress Enter or close this window . . .";
			std::cin.get();
			return 0;
		}
	}
	else // Get .baas file path from console input
	{
		std::cout << ".BAAS file path: ";
		tempFile = getFilePath();
		while (std::string(tempFile).find(extension) == std::string::npos)
		{
			std::cout << "\nInvalid AAS file, please try again\n\n.BAAS file path: ";
			tempFile = getFilePath();
		}
	}

	// Make const char* copy
	const char* aasFileName = tempFile;

	// Load AAS into struct
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