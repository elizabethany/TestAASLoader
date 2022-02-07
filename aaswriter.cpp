#include <vector>
#include "aas.hpp"

void write_aas(idAAS2File* outdata, const char* tofile) {
	FILE* f = nullptr;
	fopen_s(&f, tofile, "a");
	fputs("test", f);
	fclose(f);
}