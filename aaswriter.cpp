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
	//output << "\n\n" << aasFile->crc;
	
	output << "\n\n" << 0;

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

	// Write areas (17 items in struct, 13 items in both txt .aas, not sure what order to write them in)
	output << "\nareas " << aasFile->areas.size() << " {";
	int areaIndex = 0;
	for (const auto& currentArea : aasFile->areas)
	{
		// Reference code from D3BFG aas writer
		// areas[i].flags, areas[i].contents, areas[i].firstFace, areas[i].numFaces, areas[i].cluster, areas[i].clusterAreaNum, num )
		output << "\n	" << areaIndex << " ( " << currentArea.flags << " " << currentArea.travelFlags << " " << currentArea.numEdges << " " << currentArea.firstEdge << " " << currentArea.cluster << " " << currentArea.clusterAreaNum << " " << currentArea.obstaclePVSOffset << " " << currentArea.firstCover << " " << currentArea.firstChokePoint << " " << currentArea.numChokePoints << " " << currentArea.firstTraversal << " " << currentArea.numTraversals << " " << 0 << " )";
		areaIndex++;
	}
	output << "\n}";

	// Write nodes
	output << "\nnodes " << aasFile->nodes.size() << " {";
	int nodeIndex = 0;
	for (const auto& currentNode : aasFile->nodes)
	{
		output << "\n	" << nodeIndex << " ( " << currentNode.planeNum << " " << currentNode.flags << " " << currentNode.children[0] << " " << currentNode.children[1] << " )";
		nodeIndex++;
	}
	output << "\n}";

	// Write portals (6 items struct, 5 items in both txt .aas
	// maxAreaTravelTime was dropped, but reference shows all zero values, so maybe it won't matter
	// maxAreaTravelTime does not apepar in D3BFG writer
	output << "\nportals " << aasFile->portals.size() << " {";
	int portalIndex = 0;
	for (const auto& currentPortal : aasFile->portals)
	{
		output << "\n	" << portalIndex << " ( " << currentPortal.areaNum << " " << currentPortal.clusters[0] << " " << currentPortal.clusters[1] << " " << currentPortal.clusterAreaNum[0] << " " << currentPortal.clusterAreaNum[1] << " )";
		portalIndex++;
	}
	output << "\n}";

	// Write portalIndex (no portalIndex exists in txt .aas as reference)
	output << "\nportalIndex " << aasFile->portalIndex.size() << " {";
	int portalIndexIndex = 0;
	for (const auto& currentPortalIndex : aasFile->portalIndex)
	{
		output << "\n	" << portalIndexIndex << " ( " << currentPortalIndex << " )";
		portalIndexIndex++;
	}
	output << "\n}";

	// Write clusters
	output << "\nclusters " << aasFile->clusters.size() << " {";
	int clusterIndex = 0;
	for (const auto& currentCluster : aasFile->clusters)
	{
		// D3BFG writer writes firstPortal before numPortals
		output << "\n	" << clusterIndex << " ( " << currentCluster.numAreas << " " << currentCluster.numReachableAreas << " " << currentCluster.firstPortal << " " << currentCluster.numPortals << " )";
		clusterIndex++;
	}
	output << "\n}";

	// Write obstaclePVS
	output << "\nobstaclePVS " << aasFile->obstaclePVS.size() << " {";
	int obstaclePVSIndex = 0;
	for (const auto& currentObstaclePVS : aasFile->obstaclePVS)
	{
		// No obstaclePVS in D3BFG writer; is casting to int even the correct way?
		output << "\n	" << obstaclePVSIndex << " ( " << static_cast<int>(currentObstaclePVS) << " )";
		obstaclePVSIndex++;
	}
	output << "\n}";

	// Write reachNames
	output << "\nreachNames " << aasFile->reachabilityNames.size() << " {";
	int reachabilityNameIndex = 0;
	for (const auto& currentReachabilityName : aasFile->reachabilityNames)
	{
		// No reachabilityNames in D3BFG writer
		output << "\n	" << reachabilityNameIndex << " ( " << currentReachabilityName.name << " " << currentReachabilityName.index << " )";
		reachabilityNameIndex++;
	}
	output << "\n}";

	// Write animNames
	output << "\nanimNames " << aasFile->animNames.size() << " {";
	for (const auto& currentAnimName : aasFile->animNames)
	{
		// No reachabilityNames in D3BFG writer
		output << "\n\"" << currentAnimName.name << "\"";
	}
	output << "\n}";

	// Write dependencyNames
	output << "\ndependencyNames " << aasFile->dependencyNames.size() << " {";
	for (const auto& currentDependencyName : aasFile->dependencyNames)
	{
		// No dependencyNames in D3BFG writer
		output << "\n\"" << currentDependencyName.name << "\"";
	}
	output << "\n}";

	// Write interactionEntityNames
	output << "\ninteractionEntityNames " << aasFile->interactionEntityNames.size() << " {";
	for (const auto& currentInteractionEntityNames : aasFile->interactionEntityNames)
	{
		// No interactionEntityNames in D3BFG writer
		output << "\n\"" << currentInteractionEntityNames.name << "\"";
	}
	output << "\n}";

	// Write cover
	output << "\ncover " << aasFile->cover.size() << " {";
	int coverIndex = 0;
	for (const auto& currentCover : aasFile->cover)
	{
		// No cover in D3BFG writer
		output << "\n	" << coverIndex << " ( " << currentCover.origin.x << " " << currentCover.origin.y << " " << currentCover.origin.z << " " << currentCover.dir.x << " " << currentCover.dir.y << " " << currentCover.dir.z << " " << currentCover.radius << " " << currentCover.idleAnimIndex << " " << currentCover.padding << " " << currentCover.flags << " " << currentCover.firstTouching << " " << currentCover.numTouching << " " << currentCover.aiTypes << " )";
		coverIndex++;
	}
	output << "\n}";

	// Write areaCoverIndex
	output << "\nareaCoverIndex " << aasFile->areaCoverIndex.size() << " {";
	int areaCoverIndexIndex = 0;
	for (const auto& currentAreaCoverIndex : aasFile->areaCoverIndex)
	{
		// No areaCoverIndex in D3BFG writer
		output << "\n	" << areaCoverIndexIndex << " ( " << currentAreaCoverIndex << " )";
		areaCoverIndexIndex++;
	}
	output << "\n}";

	// Write touchingCoverIndex
	output << "\ntouchingCoverIndex " << aasFile->touchingCoverIndex.size() << " {";
	int touchingCoverIndexIndex = 0;
	for (const auto& currentTouchingCoverIndex : aasFile->touchingCoverIndex)
	{
		// No touchingCoverIndex in D3BFG writer
		output << "\n	" << touchingCoverIndexIndex << " ( " << currentTouchingCoverIndex << " )";
		touchingCoverIndexIndex++;
	}
	output << "\n}";

	// Write traversalPoints
	output << "\ntraversalPoints " << aasFile->traversalPoints.size() << " {";
	int traversalPointIndex = 0;
	for (const auto& currentTraversalPoint : aasFile->traversalPoints)
	{
		// No traversalPoints in D3BFG writer

		// Open brace
		output << "\n	" << traversalPointIndex << " ( ";

		// startPoint, endPoint, orientationFwd, and extrusionFwd
		output << currentTraversalPoint.startPoint.x << " " << currentTraversalPoint.startPoint.y << " " << currentTraversalPoint.startPoint.z << " " << currentTraversalPoint.endPoint.x << " " << currentTraversalPoint.endPoint.y << " " << currentTraversalPoint.endPoint.z << " " << currentTraversalPoint.orientationFwd.x << " " << currentTraversalPoint.orientationFwd.y << " " << currentTraversalPoint.orientationFwd.z << " " << currentTraversalPoint.extrusionFwd.x << " " << currentTraversalPoint.extrusionFwd.y << " " << currentTraversalPoint.extrusionFwd.z << " ";

		output << currentTraversalPoint.padding << " ";

		// travelTimeScale, animIndex, flags, dependencyIndex, and interactionEntIndex
		output << currentTraversalPoint.travelTimeScale << " " << currentTraversalPoint.animIndex << " " << currentTraversalPoint.flags << " " << currentTraversalPoint.dependencyIndex << " " << currentTraversalPoint.interactionEntIndex;

		// Closing brace
		output << " )";

		traversalPointIndex++;
	}
	output << "\n}";

	output.close();

	return true;
}