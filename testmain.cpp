#include <vector>
#include <iostream>
#include "aas.hpp"

int main(int argc, const char** argv) {
	
	idAAS2File myfile{};
	load_aas(&myfile, argv[1]);

	return 0;

}