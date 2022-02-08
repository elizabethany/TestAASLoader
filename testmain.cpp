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

	/*
	const auto& temp = myFile.areas[3];
	std::cout << "\ntravelFlags " << temp.travelFlags;
	std::cout << "\nflags " << temp.flags;
	std::cout << "\nnumEdges " << temp.numEdges;
	std::cout << "\nfirstEdge " << temp.firstEdge;
	std::cout << "\ncluster " << temp.cluster;
	std::cout << "\nclusterAreaNum " << temp.clusterAreaNum;
	std::cout << "\nobstaclePVSOffset " << temp.obstaclePVSOffset;
	std::cout << "\nreach " << temp.reach;
	std::cout << "\nrev_reach " << temp.rev_reach;
	std::cout << "\nfirstChokePoint " << temp.firstChokePoint;
	std::cout << "\nnumChokePoints " << temp.numChokePoints;
	std::cout << "\nfirstCover " << temp.firstCover;
	std::cout << "\nnumCover " << temp.numCover;
	std::cout << "\nfirstTraversal " << temp.firstTraversal;
	std::cout << "\nnumTraversals " << temp.numTraversals;
	std::cout << "\nfirstHintNode " << temp.firstHintNode;
	std::cout << "\nnumHintNodes " << temp.numHintNodes;
	*/

	std::cout << "\nOutput file path: ";
	//const char* outputPath = getFilePath(); // test.txt
	const char* outputPath = "test.txt";
	write_aas(&myFile, outputPath);

	//std::cin.get();

	return 0;
}