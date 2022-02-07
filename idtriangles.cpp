#include "idlib.hpp"
#include "raw_loader.hpp"
#include "idtriangles.hpp"

/*

  a2->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)a2, &a1->numVerts, 4uLL);
  v4->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v4, &v5->numIndexes, 4uLL);
  v4->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v4, &v5->vertexMask, 4uLL);
  v5->cpuVertexMask = v5->vertexMask;
  v4->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v4, &v5->vsb, 40uLL);
 
*/
void load_id_triangles(idTriangles& into, raw_loader_t& r) {
	into.numVerts = r.rd<unsigned>();
	into.numIndexes = r.rd<unsigned>();
	into.vertexMask = r.rd<unsigned>();
	into.cpuVertexMask = into.vertexMask;
	r.read_n_into<float>(&into.vsb, sizeof(idVertexScaleAndBias)/sizeof(float));

}