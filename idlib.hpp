#pragma once

struct idStr
{
  int len;
  char *data;
  int allocedAndFlag;
  char baseBuffer[20];
};

template<typename T, unsigned tag, bool stat>
struct idList {
	T* list;
	int num;
	int size;
	short granularity;
	unsigned char memTag;
	unsigned char listStatic;
};

struct idListVoid {
	void* list;
	int num;
	int size;
	short granularity;
	unsigned char memTag;
	unsigned char listStatic;
};

template<typename T, unsigned b, unsigned tg>
struct idBlockAlloc {
	struct element_t {
		using met = element_t;
		T* data;
		//offset 0 , size 8
		met* next;
		//offset 0 , size 32
		unsigned char buffer[(((sizeof(T))>(sizeof(met*))?(sizeof(T)):(sizeof(met*)))+(16-1))&~(16-1)];
	};
	struct idBlock {
		//offset 0 , size 512
		element_t elements[b];
		//offset 512 , size 8
		struct idBlock* next;
		//offset 520 , size 8
		element_t* free;
		//offset 528 , size 4
		int freeCount;
		
	};
	//offset 0 , size 8
	idBlock* blocks;
	//offset 8 , size 8
	element_t* free;
	//offset 16 , size 4
	int total;
	//offset 20 , size 4
	int active;
	//offset 24 , size 1
	bool allowAllocs;
	//offset 25 , size 1
	bool clearAllocs;
	
};
struct idHeapArrayVoid {
	//offset 0 , size 8
	unsigned char* buffer;
	//offset 8 , size 4
	unsigned int num;
	//offset 12 , size 1
	bool bufferOwnedByObject;
};

template<typename T>
struct idHeapArray {
	//offset 0 , size 8
	T* buffer;
	//offset 8 , size 4
	unsigned int num;
	//offset 12 , size 1
	bool bufferOwnedByObject;
};

template<unsigned N>
struct idStrDynStatic {
	idStr str;
	char buffer[N];
};

template<typename T1, typename T2>
struct idPair {
	T1 first;
	T2 second;
};

template<typename T, unsigned N> 
struct idArray {
	T ptr[N];
};
template<typename T>
struct idRange{
	//offset 0 , size 4
	T minRange;
	//offset 4 , size 4
	T maxRange;
	
};

template<typename T, unsigned N, bool st, unsigned tag>
struct idStaticList : public idList<T, tag, st> {
	T staticList[N];
};


template<typename T, typename TT, T vm>
using idTypesafeTime = T;
struct idAngles {
	 //offset 0 , size 4
	float pitch;//offset 4 , size 4
	float yaw;//offset 8 , size 4
	float roll; 
 };
struct idPolar3 {
	 //offset 0 , size 4
	float radius;//offset 4 , size 4
	float theta;//offset 8 , size 4
	float phi; 
 };
struct idVec3 {
	 //offset 0 , size 4
	float x;//offset 4 , size 4
	float y;//offset 8 , size 4
	float z; 
 };
struct idMat3 {
	 //offset 0 , size 36
	idVec3 mat[3]; 
 };
struct idVec4 {
	 //offset 0 , size 4
	float x;//offset 4 , size 4
	float y;//offset 8 , size 4
	float z;//offset 12 , size 4
	float w; 
 };
struct idVec1 {
	 //offset 0 , size 4
	float x; 
 };
struct idVec2 {
	 //offset 0 , size 4
	float x;//offset 4 , size 4
	float y; 
 };

struct idVec5 {
	 //offset 0 , size 4
	float x;//offset 4 , size 4
	float y;//offset 8 , size 4
	float z;//offset 12 , size 4
	float s;//offset 16 , size 4
	float t; 
 };
struct idVec6 {
	 //offset 0 , size 24
	float p[6]; 
 };
struct idQuantizedVec3 {
	 //offset 0 , size 2
	short x;//offset 2 , size 2
	short y;//offset 4 , size 2
	short z; 
 };
struct idQuantizedVec3Mag {
	 //offset 0 , size 2
	short x;//offset 2 , size 2
	short y;//offset 4 , size 2
	short z;//offset 6 , size 2
	unsigned short len; 
 };
struct idVec2i {
	 //offset 0 , size 4
	int x;//offset 4 , size 4
	int y; 
 };
struct idVec3i {
	 //offset 0 , size 4
	int x;//offset 4 , size 4
	int y;//offset 8 , size 4
	int z; 
 };
struct idVecX {
	 //offset 0 , size 4
	int size;//offset 4 , size 4
	int alloced;//offset 8 , size 8
	float* p; 
 };
struct idQuat {
	 //offset 0 , size 4
	float x;//offset 4 , size 4
	float y;//offset 8 , size 4
	float z;//offset 12 , size 4
	float w; 
 };
struct idCQuat {
	 //offset 0 , size 4
	float x;//offset 4 , size 4
	float y;//offset 8 , size 4
	float z; 
 };
struct idRotation {
	 //offset 0 , size 12
	idVec3 origin;//offset 12 , size 12
	idVec3 vec;//offset 24 , size 4
	float angle;//offset 28 , size 36
	idMat3 axis;//offset 64 , size 1
	bool axisValid; 
 };
struct idMat4 {
	 //offset 0 , size 64
	idVec4 mat[4]; 
 };
struct idMat2 {
	 //offset 0 , size 16
	idVec2 mat[2]; 
 };
struct idMat5 {
	 //offset 0 , size 100
	idVec5 mat[5]; 
 };
struct idMat6 {
	 //offset 0 , size 144
	idVec6 mat[6]; 
 };
struct idMatX {
	 //offset 0 , size 4
	int numRows;//offset 4 , size 4
	int numColumns;//offset 8 , size 4
	int alloced;char pad12[4];//offset 16 , size 8
	float* mat; 
 };
struct idBounds {
	 //offset 0 , size 24
	idVec3 b[2]; 
 };
struct idPlane {
	 //offset 0 , size 4
	float a;//offset 4 , size 4
	float b;//offset 8 , size 4
	float c;//offset 12 , size 4
	float d; 
 };
struct idMat3x4 {
	 //offset 0 , size 48
	float mat[12]; 
 };
struct idSinCos {
	 //offset 0 , size 4
	float sin;//offset 4 , size 4
	float cos; 
 };
struct idPluecker {
	 //offset 0 , size 24
	float p[6]; 
 };
struct idSpatialVec {
	 //offset 0 , size 2
	short size;//offset 2 , size 2
	short allocated;char pad4[4];//offset 8 , size 8
	float* p; 
 };
struct idSpatialMat {
	 //offset 0 , size 4
	int numRows;//offset 4 , size 4
	int numColumns;//offset 8 , size 4
	int allocatedRows;char pad12[4];//offset 16 , size 8
	float* mat; 
 };
struct idPolynomial {
	 //offset 0 , size 4
	int degree;//offset 4 , size 4
	int allocated;//offset 8 , size 8
	float* coefficient; 
 };
struct idLCP {
	 char pad0[8];//offset 8 , size 4
	int maxIterations; 
 };
struct idParametricDecay {
	 //offset 0 , size 4
	float delta;//offset 4 , size 4
	float linear;//offset 8 , size 4
	float t0;//offset 12 , size 4
	float tdelta;//offset 16 , size 4
	float lambda; 
 };
struct idSphere {
	 //offset 0 , size 12
	idVec3 origin;//offset 12 , size 4
	float radius; 
 };
struct idRenderMatrix {
	 //offset 0 , size 64
	float m[16]; 
 };
struct idBoundsShort {
	 //offset 0 , size 12
	short b[2][3]; 
 };
struct idBounds2D {
	 //offset 0 , size 16
	idVec2 bounds[2]; 
 };
struct idBox {
	 //offset 0 , size 12
	idVec3 center;//offset 12 , size 12
	idVec3 extents;//offset 24 , size 36
	idMat3 axis; 
 };
struct idCylinder {
	 //offset 0 , size 12
	idVec3 origin;//offset 12 , size 4
	float halfHeight;//offset 16 , size 4
	float radius; 
 };
struct idCone {
	 //offset 0 , size 24
	idVec3 endPoints[2];//offset 24 , size 8
	float radii[2]; 
 };
struct idCapsule {
	 //offset 0 , size 24
	idVec3 endPoints[2];//offset 24 , size 4
	float radius; 
 };

