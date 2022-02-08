#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "aas.hpp"

#define AAS_FILEID "ZIONAAS"
#define AAS_FILEVERSION "3.20"

// https://github.com/id-Software/DOOM-3-BFG/blob/master/neo/aas/AASFile.cpp idAASFileLocal::Write

bool write_aas(idAAS2File* aasFile, const char* tofile) {
	
	// Open or create the output file at given path
	std::fstream output(tofile, std::fstream::out | std::fstream::trunc);

	// aas field and version
	output << AAS_FILEID << " " << AAS_FILEVERSION;

	// crc
	output << "\n\n" << aasFile->crc;

	// firstFake stuffs
	output << "\n\nfirstFakeVertex " << aasFile->firstFakeVertex;
	output << "\nfirstFakeEdge " << aasFile->firstFakeEdge;
	output << "\nfirstFakeEdgeIndex " << aasFile->firstFakeEdge;
	output << "\nfirstFakeArea " << aasFile->firstFakeArea;

	// Write settings
	output << "\n\nsettings {";
	output << "\n	type = " << aasFile->settings.type;
	output << "\n	fileExtensionAAS = \"" << aasFile->settings.fileExtensionAAS.ptr << "\"";
	output << "\n	groupName = \"" << aasFile->settings.groupName.ptr << "\"";
	output << "\n	explicitGroupName = \"" << aasFile->settings.explicitGroupName.ptr << "\"";
	//output << "\n	exclusionGroupName = \"" << aasFile->settings.exclusionGroupName.ptr << "\"";
	output << "\n	bbox = (" << aasFile->settings.boundingBox.b[0].x << " " << aasFile->settings.boundingBox.b[0].y << " " << aasFile->settings.boundingBox.b[0].z << ")";
	output << "-(" << aasFile->settings.boundingBox.b[1].x << " " << aasFile->settings.boundingBox.b[1].y << " " << aasFile->settings.boundingBox.b[1].z << ")";
	output << "\n	primitiveModeBrush = " << aasFile->settings.primitiveModeBrush;
	output << "\n	primitiveModeModel = " << aasFile->settings.primitiveModeModel;
	output << "\n	gravity = (" << aasFile->settings.gravityDir.x << " " << aasFile->settings.gravityDir.y << " " << aasFile->settings.gravityDir.z << ")";
	output << "\n	maxStepHeight = " << aasFile->settings.maxStepHeight;
	output << "\n	maxBarrierHeight = " << aasFile->settings.maxBarrierHeight;
	output << "\n	maxWaterJumpHeight = " << aasFile->settings.maxWaterJumpHeight;
	output << "\n	maxFallHeight = " << aasFile->settings.maxFallHeight;
	output << "\n	maxLedgeGrabHeight = " << aasFile->settings.maxLedgeGrabHeight;
	output << "\n	minFloorCos = " << aasFile->settings.minFloorCos;
	output << "\n	minHighCeiling = " << aasFile->settings.minHighCeiling;
	output << "\n	groundSpeed = " << aasFile->settings.groundSpeed;
	output << "\n	waterSpeed = " << aasFile->settings.waterSpeed;
	output << "\n	ladderSpeed = " << aasFile->settings.ladderSpeed;
	output << "\n	wallCornerEdgeRadius = " << aasFile->settings.wallCornerEdgeRadius;
	output << "\n	ledgeCornerEdgeRadius = " << aasFile->settings.ledgeCornerEdgeRadius;
	output << "\n	obstaclePVSRadius = " << aasFile->settings.obstaclePVSRadius;
	output << "\n	wallCornerReachabilityBackoff = " << aasFile->settings.wallCornerReachabilityBackoff;
	output << "\n	highQualityReachabilityBackoff = " << aasFile->settings.highQualityReachabilityBackoff;
	output << "\n	maxDistBetweenWalkReachabilities = " << aasFile->settings.maxDistBetweenWalkReachabilities;
	output << "\n	maxDistBetweenLedgeReachabilities = " << aasFile->settings.maxDistBetweenLedgeReachabilities;
	output << "\n	useRageStyleCoverGeneration = " << aasFile->settings.useRageStyleCoverGeneration;
	output << "\n	generateCover = " << aasFile->settings.generateCover;
	output << "\n	createBouncePadTraversals = " << aasFile->settings.createBouncePadTraversals;
	output << "\n	createTeleporterTraversals = " << aasFile->settings.createTeleporterTraversals;
	output << "\n	createDoorTraversals = " << aasFile->settings.createDoorTraversals;
	output << "\n	createLedgeGrabTraversals = " << aasFile->settings.createLedgeGrabTraversals;
	output << "\n	minCrouchingCoverHeight = " << aasFile->settings.minCrouchingCoverHeight;
	output << "\n	minStandingCoverHeight = " << aasFile->settings.minStandingCoverHeight;
	output << "\n	minWallWidth = " << aasFile->settings.minWallWidth;
	output << "\n	maxWallWidth = " << aasFile->settings.maxWallWidth;
	output << "\n	coverCornerDistance = " << aasFile->settings.coverCornerDistance;
	output << "\n	coverWallDistance = " << aasFile->settings.coverWallDistance;
	output << "\n	crouchingFireHeight = " << aasFile->settings.crouchingFireHeight;
	output << "\n	standingFireHeight = " << aasFile->settings.standingFireHeight;
	output << "\n	chokePointWidth = " << aasFile->settings.chokePointWidth;
	output << "\n	tt_barrierJump = " << aasFile->settings.tt_barrierJump;
	output << "\n	tt_waterJump = " << aasFile->settings.tt_waterJump;
	output << "\n	tt_startWalkOffLedge = " << aasFile->settings.tt_startWalkOffLedge;
	output << "\n	tt_ledgeGrab = " << aasFile->settings.tt_ledgeGrab;
	output << "\n	tt_startLadderClimb = " << aasFile->settings.tt_startLadderClimb;
	output << "\n}";

	// Write planes
	output << "\nplanes " << aasFile->planes.size() << " {";
	int planeIndex = 0;
	for (const auto& currentPlane : aasFile->planes)
	{
		output << "\n	" << planeIndex << " ( " << currentPlane.a << " " << currentPlane.b << " " << currentPlane.c << " " << currentPlane.d << " )";
		planeIndex++;
	}
	output << "\n}";

	// Write vertices
	output << "\nvertices " << aasFile->vertices.size() << " {";
	int vertexIndex = 0;
	for (const auto& currentVertex : aasFile->vertices)
	{
		output << "\n	" << vertexIndex << " ( " << currentVertex.x << " " << currentVertex.y << " " << currentVertex.z << " )";
		vertexIndex++;
	}
	output << "\n}";

	// Write edges
	output << "\nedges " << aasFile->edges.size() << " {";
	int edgeIndex = 0;
	for (const auto& currentEdge : aasFile->edges)
	{
		output << "\n	" << edgeIndex << " ( " << currentEdge.vertexNum[0] << " " << currentEdge.vertexNum[1] << " " << currentEdge.flags << " )";
		edgeIndex++;
	}
	output << "\n}";

	// Write edgeIndex
	output << "\nedgeIndex " << aasFile->edgeIndex.size() << " {";
	int edgeIndexIndex = 0;
	for (const auto& currentEdgeIndex : aasFile->edgeIndex)
	{
		output << "\n	" << edgeIndexIndex << " ( " << currentEdgeIndex << " )";
		edgeIndexIndex++;
	}
	output << "\n}";

	// Write reachabilities
	output << "\nreachabilities " << aasFile->reachabilities.size() << " {";
	int reachabilityIndex = 0;
	for (const auto& currentReachability : aasFile->reachabilities)
	{
		// Open first brace
		output << "\n	" << reachabilityIndex << " ( ";

		// stuff
		output << currentReachability.travelFlags << " " << currentReachability.travelTime << " " << currentReachability.fromAreaNum << " " << currentReachability.toAreaNum;
		
		// start
		output << " (" << currentReachability.start[0] << " " << currentReachability.start[1] << " " << currentReachability.start[2] << ")";
		
		// end
		output << " (" << currentReachability.end[0] << " " << currentReachability.end[1] << " " << currentReachability.end[2] << ")";

		// Close first brace
		output << " )";

		reachabilityIndex++;
	}
	output << "\n}";

	output.close();

	return true;
}