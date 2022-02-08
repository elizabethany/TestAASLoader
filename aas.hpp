#pragma once
#include "idlib.hpp"

struct idAAS2Settings {
	using type_t = unsigned;
	//offset 0 , size 4
	idAAS2Settings::type_t type;
	//offset 4 , size 64
	idArray < char , 64 > fileExtensionAAS;
	//offset 68 , size 64
	idArray < char , 64 > groupName;
	//offset 132 , size 64
	idArray < char , 64 > explicitGroupName;
	//offset 196 , size 64
	idArray < char , 64 > exclusionGroupName;
	//offset 260 , size 1
	bool canWriteAreaBModel;
	//offset 264 , size 24
	idBounds boundingBox;
	//offset 288 , size 4
	int primitiveModeBrush;
	//offset 292 , size 4
	int primitiveModeModel;
	//offset 296 , size 12
	idVec3 gravityDir;
	//offset 308 , size 4
	float gravityValue;
	//offset 312 , size 4
	float maxStepHeight;
	//offset 316 , size 4
	float maxBarrierHeight;
	//offset 320 , size 4
	float maxWaterJumpHeight;
	//offset 324 , size 4
	float maxFallHeight;
	//offset 328 , size 4
	float maxLedgeGrabHeight;
	//offset 332 , size 4
	float minFloorCos;
	//offset 336 , size 4
	float minHighCeiling;
	//offset 340 , size 4
	float groundSpeed;
	//offset 344 , size 4
	float waterSpeed;
	//offset 348 , size 4
	float ladderSpeed;
	//offset 352 , size 4
	float wallCornerEdgeRadius;
	//offset 356 , size 4
	float ledgeCornerEdgeRadius;
	//offset 360 , size 4
	float obstaclePVSRadius;
	//offset 364 , size 4
	float wallCornerReachabilityBackoff;
	//offset 368 , size 4
	float highQualityReachabilityBackoff;
	//offset 372 , size 4
	float maxDistBetweenWalkReachabilities;
	//offset 376 , size 4
	float maxDistBetweenLedgeReachabilities;
	//offset 380 , size 1
	bool useRageStyleCoverGeneration;
	//offset 381 , size 1
	bool generateCover;
	//offset 382 , size 1
	bool createBouncePadTraversals;
	//offset 383 , size 1
	bool createTeleporterTraversals;
	//offset 384 , size 1
	bool createDoorTraversals;
	//offset 385 , size 1
	bool createLedgeGrabTraversals;
	//offset 388 , size 4
	float minCrouchingCoverHeight;
	//offset 392 , size 4
	float minStandingCoverHeight;
	//offset 396 , size 4
	float crouchingFireHeight;
	//offset 400 , size 4
	float standingFireHeight;
	//offset 404 , size 4
	float minWallWidth;
	//offset 408 , size 4
	float maxWallWidth;
	//offset 412 , size 4
	float minDoorWidth;
	//offset 416 , size 4
	float maxDoorWidth;
	//offset 420 , size 4
	float coverCornerDistance;
	//offset 424 , size 4
	float coverWallDistance;
	//offset 428 , size 4
	float chokePointWidth;
	//offset 432 , size 4
	int tt_barrierJump;
	//offset 436 , size 4
	int tt_waterJump;
	//offset 440 , size 4
	int tt_startWalkOffLedge;
	//offset 444 , size 4
	int tt_ledgeGrab;
	//offset 448 , size 4
	int tt_startLadderClimb;
	
};

struct idAAS2File_bspTree_t {
	 //offset 0 , size 12
	idVec3 floorNormal;//offset 12 , size 4
	int headNode;//offset 16 , size 4
	int firstArea;//offset 20 , size 4
	int lastArea; 
 };
struct aas2Edge_t {
	 //offset 0 , size 8
	int vertexNum[2];//offset 8 , size 4
	int flags; 
 };
struct aas2Reachability_t {
	//offset 0 , size 4
	unsigned int travelFlags;
	//offset 4 , size 2
	unsigned short travelTime;
	//offset 6 , size 2
	unsigned short fromAreaNum;
	//offset 8 , size 2
	unsigned short toAreaNum;
	//offset 10 , size 2
	unsigned short reservationID;
	//offset 12 , size 6
	short start[3];
	//offset 18 , size 6
	short end[3];
	//offset 24 , size 4
	int reservationExpireTime;
	//offset 28 , size 4
	unsigned int areaTTOfsAndNumber;
	//offset 32 , size 4
	int next;
	//offset 36 , size 4
	int  rev_next;
	
};

struct aas2Area_t {
	//offset 0 , size 4
	unsigned int travelFlags;
	//offset 4 , size 2
	unsigned short flags;
	//offset 6 , size 2
	short numEdges;
	//offset 8 , size 4
	int firstEdge;
	//offset 12 , size 2
	short cluster;
	//offset 14 , size 2
	unsigned short clusterAreaNum;
	//offset 16 , size 4
	unsigned int obstaclePVSOffset;
	//offset 20 , size 4
	int reach;
	//offset 24 , size 4
	int rev_reach;
	//offset 28 , size 2
	unsigned short firstChokePoint;
	//offset 30 , size 2
	short numChokePoints;
	//offset 32 , size 2
	unsigned short firstCover;
	//offset 34 , size 2
	unsigned short numCover;
	//offset 36 , size 2
	short firstTraversal;
	//offset 38 , size 2
	unsigned short numTraversals;
	//offset 40 , size 2
	unsigned short firstHintNode;
	//offset 42 , size 2
	unsigned short numHintNodes;
	
};
struct aas2AreaBounds_t {
	//offset 0 , size 6
	short min[3];
	//offset 6 , size 6
	short max[3];
	
};


struct aas2Node_t {
	//offset 0 , size 4
	unsigned int planeNum;
	//offset 4 , size 4
	unsigned int flags;
	//offset 8 , size 8
	int children[2];
	
};
struct aas2Portal_t {
	//offset 0 , size 2
	unsigned short areaNum;
	//offset 2 , size 4
	short clusters[2];
	//offset 6 , size 4
	unsigned short clusterAreaNum[2];
	//offset 10 , size 2
	unsigned short maxAreaTravelTime;
	
};
struct aas2Cluster_t {
	//offset 0 , size 4
	int numAreas;
	//offset 4 , size 4
	int numReachableAreas;
	//offset 8 , size 4
	int numPortals;
	//offset 12 , size 4
	int firstPortal;
	
};
struct aas2Name_t {
	//offset 0 , size 128
	char name[128];
	//offset 128 , size 4
	int index;
	
};
struct aas2AnimName_t {
	//offset 0 , size 128
	char name[128];
	
};
struct aas2DependencyName_t {
	//offset 0 , size 128
	char name[128];
	
};
struct aas2InteractionEntityName_t {
	//offset 0 , size 128
	char name[128];
	
};
struct aas2Cover_t {
	//offset 0 , size 12
	idVec3 origin;
	//offset 12 , size 12
	idVec3 dir;
	//offset 24 , size 4
	float radius;
	//offset 28 , size 2
	short idleAnimIndex;
	//offset 30 , size 2
	short areaNum;
	//offset 32 , size 2
	short flags;
	//offset 34 , size 2
	unsigned short padding;
	//offset 36 , size 4
	int numTouching;
	//offset 40 , size 4
	int firstTouching;
	//offset 44 , size 4
	int aiTypes;
	//offset 48 , size 4
	int reservedBy;
	//offset 52 , size 4
	int usableTime;
	
};
struct aas2Traversal_t {
	//offset 0 , size 12
	idVec3 startPoint;
	//offset 12 , size 12
	idVec3 endPoint;
	//offset 24 , size 6
	idQuantizedVec3 orientationFwd;
	//offset 30 , size 6
	idQuantizedVec3 extrusionFwd;
	//offset 36 , size 2
	short animIndex;
	//offset 38 , size 2
	short extrusionDistance;
	//offset 40 , size 4
	int reachabilityIndex;
	//offset 44 , size 2
	short dependencyIndex;
	//offset 46 , size 2
	short interactionEntIndex;
	//offset 48 , size 4
	unsigned int flags;
	//offset 52 , size 2
	short startAreaNum;
	//offset 54 , size 2
	short endAreaNum;
	//offset 56 , size 2
	unsigned short travelTimeScale;
	//offset 58 , size 2
	unsigned short padding;
	
};
struct aas2HintNode_t {
	//offset 0 , size 12
	idVec3 origin;
	//offset 12 , size 2
	short areaNum;
	//offset 14 , size 2
	short radius;
	//offset 16 , size 1
	unsigned char hintType;
	//offset 17 , size 1
	unsigned char orientation;
	//offset 18 , size 1
	unsigned char dirFlags;
	//offset 19 , size 1
	unsigned char grouping;
	//offset 20 , size 4
	int hintData;
	
};
struct aas2ChokePoint_t {
	//offset 0 , size 24
	idVec3 points[2];
	//offset 24 , size 4
	unsigned short rooms[2];
	
};
struct aas2Room_t {
	//offset 0 , size 2
	unsigned short firstChokePoint;
	//offset 2 , size 2
	unsigned short numChokePoints;
	//offset 4 , size 2
	unsigned short firstCover;
	//offset 6 , size 2
	unsigned short numCover;
	
};
struct aas2Trace_t {
	//offset 0 , size 4
	int flags;
	//offset 4 , size 4
	int travelFlags;
	//offset 8 , size 4
	int maxAreas;
	//offset 12 , size 4
	int getOutOfSolid;
	//offset 16 , size 4
	float fraction;
	//offset 20 , size 12
	idVec3 endpos;
	//offset 32 , size 4
	int planeNum;
	//offset 36 , size 4
	int lastAreaNum;
	//offset 40 , size 4
	int blockingAreaNum;
	//offset 44 , size 4
	int numAreas;
	//offset 48 , size 8
	int* areas;
	//offset 56 , size 8
	idVec3* points;
	
};
struct aas2TraceHeight_t {
	//offset 0 , size 4
	int maxPoints;
	//offset 4 , size 4
	int numPoints;
	//offset 8 , size 8
	idVec3* points;
	
};
struct aas2EdgeCrossed_t {
	//offset 0 , size 4
	int toAreaNum;
	//offset 4 , size 4
	int edgeNum;
	//offset 8 , size 12
	idVec3 edgePoint;
	
};
struct aas2TraceFloor_t {
	//offset 0 , size 4
	float fraction;
	//offset 4 , size 12
	idVec3 endpos;
	//offset 16 , size 4
	int lastAreaNum;
	//offset 20 , size 20
	aas2EdgeCrossed_t firstEdge;
	//offset 40 , size 20
	aas2EdgeCrossed_t lastEdge;
	//offset 60 , size 4
	int maxAreas;
	//offset 64 , size 4
	int numAreas;
	//offset 68 , size 4
	int maxReachIndices;
	//offset 72 , size 4
	int numReachIndices;
	//offset 80 , size 8
	int* areas;
	//offset 88 , size 8
	int* reachIndices;
	
};

struct idAAS2File {
	//offset 52 , size 4
	unsigned int crc;
	//offset 56 , size 4
	unsigned int timestamp;
	//offset 64 , size 24
	std::vector<int> visitedAreas;
	//offset 88 , size 452
	idAAS2Settings settings;
	//offset 540 , size 4
	int majorVersion;
	//offset 544 , size 4
	int minorVersion;
	//offset 548 , size 4
	int firstFakeVertex;
	//offset 552 , size 4
	int firstFakeEdge;
	//offset 556 , size 4
	int firstFakeEdgeIndex;
	//offset 560 , size 4
	int firstFakeArea;
	//offset 568 , size 24
	std::vector<idAAS2File_bspTree_t> trees;
	//offset 592 , size 24
	std::vector<idPlane> planes;
	//offset 616 , size 24
	std::vector<idVec3> vertices;
	//offset 640 , size 24
	std::vector<aas2Edge_t> edges;
	//offset 664 , size 24
	std::vector<int> edgeIndex;
	//offset 688 , size 24
	std::vector < aas2Reachability_t> reachabilities;
	//offset 712 , size 24
	std::vector < aas2Area_t  > areas;
	//offset 736 , size 24
	std::vector < aas2Node_t > nodes;
	//offset 760 , size 24
	std::vector < aas2Portal_t > portals;
	//offset 784 , size 24
	std::vector < int > portalIndex;
	//offset 808 , size 24
	std::vector < aas2Cluster_t > clusters;
	//offset 832 , size 24
	std::vector < unsigned char > obstaclePVS;
	//offset 856 , size 24
	std::vector < aas2Name_t > reachabilityNames;
	//offset 880 , size 24
	std::vector < aas2AnimName_t > animNames;
	//offset 904 , size 24
	std::vector < aas2DependencyName_t > dependencyNames;
	//offset 928 , size 24
	std::vector < aas2InteractionEntityName_t > interactionEntityNames;
	//offset 952 , size 24
	std::vector < aas2Cover_t > cover;
	//offset 976 , size 24
	std::vector < int > areaCoverIndex;
	//offset 1000 , size 24
	std::vector < int > touchingCoverIndex;
	//offset 1024 , size 24
	std::vector < aas2ChokePoint_t > chokePoints;
	//offset 1048 , size 24
	std::vector < aas2Traversal_t > traversalPoints;
	//offset 1072 , size 24
	std::vector < aas2HintNode_t > hintNodes;
	//offset 1096 , size 24
	std::vector < aas2AreaBounds_t > areaBounds;
	//offset 1120 , size 1
	bool allocatedOnGlobalHeap;
	
};


bool load_aas(idAAS2File* out_aas, const char* filepath);
void idAAS2File_EndianSwap(idAAS2File *result);

bool write_aas(idAAS2File* aasFile, const char* tofile);
