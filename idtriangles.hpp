#pragma once

#include "idlib.hpp"

struct idVertexScaleAndBias {
	//offset 0 , size 12
	idVec3 xyzScale;
	//offset 12 , size 12
	idVec3 xyzBias;
	//offset 24 , size 8
	idVec2 stScale;
	//offset 32 , size 8
	idVec2 stBias;
	
};

struct idDrawVert {
	//offset 0 , size 12
	idVec3 xyz;
	//offset 12 , size 8
	idVec2 st;
	//offset 20 , size 4
	unsigned char normal[4] ;
	//offset 24 , size 4
	unsigned char tangent[4];
	//offset 28 , size 4
	unsigned char color[4];
	//offset 32 , size 8
	idVec2 vmtrTC;
	//offset 40 , size 8
	unsigned short vmtrSB[4];
	
};
struct idDrawVertSmall {
	//offset 0 , size 6
	unsigned short xyz[3];
	//offset 6 , size 4
	unsigned short st[2];
	//offset 10 , size 4
	unsigned char normal[4];
	//offset 14 , size 4
	unsigned char tangent[4];
	//offset 18 , size 4
	unsigned char color[4];
	//offset 22 , size 8
	idVec2 vmtrTC;
	//offset 30 , size 8
	unsigned short vmtrSB[4];
	
};
using primtiveType_t = int;
using bufferUsageType_t = int;
struct idBufferObject {
	//offset 0 , size 4
	int size;
	//offset 4 , size 4
	int offsetInOtherBuffer;
	//offset 8 , size 8
	void* apiObject;
	
};

struct idVertexBuffer {
	idBufferObject base;
	char unknown[64];
	bufferUsageType_t usage;
};
struct idIndexBuffer {
	idBufferObject base;
	char unknown[64];
	bufferUsageType_t usage;
};
static_assert(sizeof(idIndexBuffer) == 88);
struct idTriangles {
	//offset 0 , size 24
	idBounds bounds;
	//offset 24 , size 1
	bool generateNormals;
	//offset 28 , size 4
	primtiveType_t primitiveType;
	//offset 32 , size 4
	int numIndexes;
	//offset 36 , size 4
	int numVerts;
	//offset 40 , size 4
	int detailOffset;
	//offset 44 , size 1
	bool allowGpuHosting;
	//offset 48 , size 40
	idVertexScaleAndBias vsb;
	//offset 88 , size 16
	idVec4 virtualMapping;
	//offset 104 , size 4
	unsigned int cpuVertexMask;
	//offset 112 , size 8
	idDrawVert* verts;
	//offset 120 , size 8
	idDrawVertSmall* vertsSmall;
	//offset 128 , size 8
	unsigned short* indexes;
	//offset 136 , size 4
	unsigned int vertexMask;
	//offset 144 , size 88
	idVertexBuffer vertexBuffer;
	//offset 232 , size 88
	idIndexBuffer indexBuffer;
	//offset 320 , size 1
	bool directFileMap;
	

};

void load_id_triangles(idTriangles& into, raw_loader_t& r);
