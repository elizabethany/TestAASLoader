#pragma once
#include "idlib.hpp"
struct idAAS2Settings {
	//offset 0 , size 4
   //type of file--dictates brush contents flags to be considered
	int type;
	//offset 8 , size 40
		//file extension to use when saving the output files - this is really the type name of the AAS and should be unique for each aas def
	idStr fileExtensionAAS;
	//offset 48 , size 40
		//the name of editor groups to pull primitives from. Only primitives included in these groups are even considered for inclusion in the AAS build. Brushes in these groups may still be excluded if their clip flags do not match those requires for the AAS type_t.
	idStr groupName;
	//offset 88 , size 40
	idStr explicitGroupName;
	//offset 128 , size 24
		//-----------------------  Collision Settings -----------------------
	idBounds boundingBox;
	//offset 152 , size 4
	int primitiveModeBrush;
	//offset 156 , size 4
	int primitiveModePatch;
	//offset 160 , size 4
	int primitiveModeModel;
	//offset 164 , size 12
		//-----------------------  Physics Settings -----------------------
	idVec3 gravityDir;
	//offset 176 , size 4
	float gravityValue;
	//offset 180 , size 4
	float maxStepHeight;
	//offset 184 , size 4
	float maxBarrierHeight;
	//offset 188 , size 4
	float maxWaterJumpHeight;
	//offset 192 , size 4
	float maxFallHeight;
	//offset 196 , size 4
	float minFloorCos;
	//offset 200 , size 4
	float minHighCeiling;
	//offset 204 , size 4
		//in units per second
	float groundSpeed;
	//offset 208 , size 4
		//in units per second
	float waterSpeed;
	//offset 212 , size 4
		//in units per second
	float ladderSpeed;
	//offset 216 , size 4
		//-----------------------  Navigation Settings -----------------------
	float wallCornerEdgeRadius;
	//offset 220 , size 4
	float ledgeCornerEdgeRadius;
	//offset 224 , size 4
	float obstaclePVSRadius;
	//offset 228 , size 4
		//-----------------------  Spacial Analysis Settings ----------------------- minimum height of CrouchingCover
	float minCrouchingCoverHeight;
	//offset 232 , size 4
		//minimum height of StandingCover
	float minStandingCoverHeight;
	//offset 236 , size 4
		//height above floor to look for fire while crouching
	float crouchingFireHeight;
	//offset 240 , size 4
		//height above floor to look for fire while standing
	float standingFireHeight;
	//offset 244 , size 4
		//minimum width of a wall (used for DoorwayDetection)
	float minWallWidth;
	//offset 248 , size 4
		//maximum width of a wall (used for DoorwayDetection)
	float maxWallWidth;
	//offset 252 , size 4
		//minimum width of a doorway
	float minDoorWidth;
	//offset 256 , size 4
		//maximum width of a doorway
	float maxDoorWidth;
	//offset 260 , size 4
		//when in cover, the edge of the AI's bounding box should be this far behind the corner
	float coverCornerDistance;
	//offset 264 , size 4
		//when in cover, the edge of the AI's bounding box should be this far from the wall
	float coverWallDistance;
	//offset 268 , size 4
		//maximum distance between edges that will be considered a ChokePoint
	float chokePointWidth;
	//offset 272 , size 4
		//-----------------------  Fixed Travel Times -----------------------
	int tt_barrierJump;
	//offset 276 , size 4
	int tt_waterJump;
	//offset 280 , size 4
	int tt_startWalkOffLedge;
	//offset 284 , size 4
	int tt_startLadderClimb;
};
struct idAAS2File_bspTree_t {
	//offset 0 , size 12
	idVec3 floorNormal;
	//offset 12 , size 4
	int headNode;
	//offset 16 , size 4
	int firstArea;
	//offset 20 , size 4
	int lastArea;
};
struct aas2Edge_t {
	//offset 0 , size 8
	int vertexNum[2];//offset 8 , size 4
	int flags;
};

struct aas2Reachability_t {
	//offset 0 , size 4
   //type of travel required to get to the area
	unsigned int travelFlags;
	//offset 4 , size 2
		//travel time of the inter area movement
	unsigned short travelTime;
	//offset 6 , size 2
		//number of area the reachability starts
	unsigned short fromAreaNum;
	//offset 8 , size 2
		//number of area the reachability leads to
	unsigned short toAreaNum;
	//offset 10 , size 2
		//unused
	unsigned short padding;
	//offset 12 , size 6
		//start point of inter area movement
	short start[3];
	//offset 18 , size 6
		//end point of inter area movement
	short end[3];
	//offset 24 , size 4
		//travel times in fromAreaNum from reachabilities that lead towards this area to this  reachability, and the reachability number
	unsigned int areaTTOfsAndNumber;
	//offset 28 , size 2
		//next reachability in list
	short next;
	//offset 30 , size 2
		//next reachability in reversed list
	short rev_next;
};
struct aas2Area_t {
	//offset 0 , size 4
   //travel flags for traveling through this area
	unsigned int travelFlags;
	//offset 4 , size 2
		//several area flags
	unsigned short flags;
	//offset 6 , size 2
		//number of edges in the boundary of the face
	short numEdges;
	//offset 8 , size 4
		//first edge in the edge index
	int firstEdge;
	//offset 12 , size 2
		//the area's cluster--if negative, it's a portal
	short cluster;
	//offset 14 , size 2
		//number of the area in the cluster
	unsigned short clusterAreaNum;
	//offset 16 , size 4
		//offset into obstacle PVS
	unsigned int obstaclePVSOffset;
	//offset 20 , size 2
		//reachabilities that start from this area
	short reach;
	//offset 22 , size 2
		//reachabilities that lead to this area
	short rev_reach;
	//offset 24 , size 2
	unsigned short firstChokePoint;
	//offset 26 , size 2
		//room number if negative
	short numChokePoints;
	//offset 28 , size 2
		//first index in the cover index list
	unsigned short firstCover;
	//offset 30 , size 2
		//number of cover in the area
	unsigned short numCover;
	//offset 32 , size 2
		//first index in the traversal list
	unsigned short firstTraversal;
	//offset 34 , size 2
		//number of traversals out of the area
	unsigned short numTraversals;
	//offset 36 , size 2
		//first index int the search node list
	unsigned short firstHintNode;
	//offset 38 , size 2
		//number of search nodes in the area
	unsigned short numHintNodes;
};
struct aas2Node_t {
	//offset 0 , size 4
   //plane number that splits the subspace at this node
	unsigned int planeNum;
	//offset 4 , size 4
		//node flags
	unsigned int flags;
	//offset 8 , size 8
		//child nodes, zero is solid, negative is -(area number)
	int children[2];
};
struct aas2Portal_t {
	//offset 0 , size 2
   //area number that is the actual portal
	unsigned short areaNum;
	//offset 2 , size 4
		//cluster number at the front and back of the portal
	short clusters[2];
	//offset 6 , size 4
		//portal area number in the front and back cluster
	unsigned short clusterAreaNum[2];
	//offset 10 , size 2
		//maximum travel time through the portal area
	unsigned short maxAreaTravelTime;
};
struct aas2Cluster_t {
	//offset 0 , size 4
   //number of areas in the cluster
	int numAreas;
	//offset 4 , size 4
		//number of areas with reachabilities
	int numReachableAreas;
	//offset 8 , size 4
		//number of cluster portals
	int numPortals;
	//offset 12 , size 4
		//first cluster portal in the index
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
   //position of the cover
	idVec3 origin;
	//offset 12 , size 12
		//direction the cover is facing
	idVec3 dir;
	//offset 24 , size 2
		//area this cover point is in
	short areaNum;
	//offset 26 , size 2
		//flags indicating cover point attributes
	short flags;
	//offset 28 , size 4
		//number of other cover points intersecting this one
	int numTouching;
	//offset 32 , size 4
		//first intersecting CoverPoint index in touchingCoverIndex
	int firstTouching;
	//offset 36 , size 4
		//spawnId of the entity that has this cover reserved
	int reservedBy;
	//offset 40 , size 4
		//clientGame->GetGameMs() must be > than this to use this cover
	int usableTime;
};
struct aas2ChokePoint_t {
	//offset 0 , size 24
	idVec3 points[2];
	//offset 24 , size 4
	unsigned short rooms[2];

};

struct aas2Traversal_t {
	//offset 0 , size 12
   //12
	idVec3 startPoint;
	//offset 12 , size 12
		//24
	idVec3 endPoint;
	//offset 24 , size 6
		//30
	idQuantizedVec3 orientationFwd;
	//offset 30 , size 6
		//36
	idQuantizedVec3 extrusionFwd;
	//offset 36 , size 2
		//38
	short animIndex;
	//offset 38 , size 2
		//40
	short reachabilityIndex;
	//offset 40 , size 2
		//42
	short dependencyIndex;
	//offset 42 , size 2
		//44
	short interactionEntIndex;
	//offset 44 , size 2
		//46
	short extrusionDistance;
	//offset 46 , size 2
		//48
	short startAreaNum;
	//offset 48 , size 2
		//50
	short endAreaNum;
	//offset 50 , size 2
		//52
	unsigned short padding;
	//offset 52 , size 4
		/// AASMERGE: reference back to reachability and get flags from there? 56
	unsigned int flags;
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
struct aas2AreaBounds_t {
	//offset 0 , size 6
	short min[3];
	//offset 6 , size 6
	short max[3];
	
};


#define		TAG_AAS		229292
struct idAAS2File {
	//offset 64 , size 4
	unsigned int crc;
	//offset 68 , size 4
	unsigned int timestamp;
	//offset 72 , size 24
	idList < int, TAG_AAS, false > visitedAreas;
	//offset 96 , size 288
	idAAS2Settings settings;
	//offset 384 , size 4
	int major;
	//offset 388 , size 4
	int minor;
	//offset 392 , size 24
	idList < idAAS2File_bspTree_t, TAG_AAS, false > trees;
	//offset 416 , size 24
	idList < idPlane, TAG_AAS, false  > planes;
	//offset 440 , size 24
	idList < idVec3, TAG_AAS, false  > vertices;
	//offset 464 , size 24
	idList < aas2Edge_t, TAG_AAS, false  > edges;
	//offset 488 , size 24
	idList < int, TAG_AAS, false> edgeIndex;
	//offset 512 , size 24
	idList < aas2Reachability_t, TAG_AAS, false> reachabilities;
	//offset 536 , size 24
	idList < aas2Area_t, TAG_AAS, false> areas;
	//offset 560 , size 24
	idList < aas2Node_t, TAG_AAS, false> nodes;
	//offset 584 , size 24
	idList < aas2Portal_t, TAG_AAS, false> portals;
	//offset 608 , size 24
	idList < int, TAG_AAS, false> portalIndex;
	//offset 632 , size 24
	idList < aas2Cluster_t, TAG_AAS, false> clusters;
	//offset 656 , size 24
	idList < unsigned char, TAG_AAS, false> obstaclePVS;
	//offset 680 , size 24
	idList < aas2Name_t, TAG_AAS, false> reachabilityNames;
	//offset 704 , size 24
			//table of animation for animated traversals
	idList < aas2AnimName_t, TAG_AAS, false> animNames;
	//offset 728 , size 24
		//table of dependency nodes for animated traversals
	idList < aas2DependencyName_t, TAG_AAS, false> dependencyNames;
	//offset 752 , size 24
		//table of dependency nodes for animated traversals
	idList < aas2InteractionEntityName_t, TAG_AAS, false> interactionEntityNames;
	//offset 776 , size 24
		//CoverPoints
	idList < aas2Cover_t, TAG_AAS, false> cover;
	//offset 800 , size 24
		//CoverPoint-list indices in each area
	idList < int, TAG_AAS, false> areaCoverIndex;
	//offset 824 , size 24
		//intersecting CoverPoint-list indices
	idList < int, TAG_AAS, false> touchingCoverIndex;
	//offset 848 , size 24
		//choke points
	idList < aas2ChokePoint_t, TAG_AAS, false> chokePoints;
	//offset 872 , size 24
		//traversal points
	idList < aas2Traversal_t, TAG_AAS, false> traversalPoints;
	//offset 896 , size 24
		//extensible hint node structure
	idList < aas2HintNode_t, TAG_AAS, false> hintNodes;
	//offset 920 , size 24
	idList < aas2AreaBounds_t, TAG_AAS, false> areaBounds;
};
