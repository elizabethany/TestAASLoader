/*
	Loader for aas2
*/
#include <vector>
#include <iostream>
#include "aas.hpp"

#include "raw_loader.hpp"

#include <cassert>

static void __fastcall idAAS2File__FlagNoPushAreas(idAAS2File *result);


static bool read_impl(idAAS2File* f, raw_loader_t& r);

bool load_aas(idAAS2File* out_aas, const char* filepath) {
	
	FILE* f = nullptr;
	fopen_s(&f, filepath, "rb");
	if (!f)
    {
        std::cout << "Invalid .baas file path\nPress Enter to continue . . .";
        std::cin;
        return false;
	}

	fseek(f, 0, SEEK_END);
	size_t sz = ftell(f);

	fseek(f, 0, SEEK_SET);

	char* buff = (char*) malloc(sz);

	fread(buff, 1, sz, f);

	fclose(f);

	raw_loader_t rr{buff};

	return read_impl(out_aas, rr);
}

/*
__int64 __fastcall idAAS2Settings::ReadFromFileBinary(idAAS2Settings *this, idFile *a2, idStr *a3)
{
  idFile *v3; // x20
  idAAS2Settings *v4; // x19
  char v5; // w9
  char v6; // w10
  char v7; // w11
  __int64 (__fastcall *v8)(idFile_Memory *__hidden, void *, unsigned __int64); // x8
  unsigned int v9; // w8
  idFileMemoryVftbl *v10; // x9
  unsigned int v11; // w10
  unsigned int v12; // w8
  idFileMemoryVftbl *v13; // x9
  unsigned int v14; // w10
  unsigned int v15; // w8
  idFileMemoryVftbl *v16; // x9
  unsigned int v17; // w10
  char v18; // w9
  char v19; // w10
  char v20; // w11
  char v21; // w9
  char v22; // w10
  char v23; // w11
  char v24; // w9
  char v25; // w10
  char v26; // w11
  char v27; // w9
  char v28; // w10
  char v29; // w11
  char v30; // w9
  char v31; // w10
  char v32; // w11
  char v33; // w9
  char v34; // w10
  char v35; // w11
  char v36; // w9
  char v37; // w10
  char v38; // w11
  char v39; // w9
  char v40; // w10
  char v41; // w11
  char v42; // w9
  char v43; // w10
  char v44; // w11
  char v45; // w9
  char v46; // w10
  char v47; // w11
  char v48; // w9
  char v49; // w10
  char v50; // w11
  char v51; // w9
  char v52; // w10
  char v53; // w11
  char v54; // w9
  char v55; // w10
  char v56; // w11
  char v57; // w9
  char v58; // w10
  char v59; // w11
  char v60; // w9
  char v61; // w10
  char v62; // w11
  char v63; // w9
  char v64; // w10
  char v65; // w11
  char v66; // w9
  char v67; // w10
  char v68; // w11
  char v69; // w9
  char v70; // w10
  char v71; // w11
  char v72; // w9
  char v73; // w10
  char v74; // w11
  char v75; // w9
  char v76; // w10
  char v77; // w11
  char v78; // w9
  char v79; // w10
  char v80; // w11
  char v81; // w9
  char v82; // w10
  char v83; // w11
  char v84; // w9
  char v85; // w10
  char v86; // w11
  char v87; // w9
  char v88; // w10
  char v89; // w11
  char v90; // w9
  char v91; // w10
  char v92; // w11
  char v93; // w9
  char v94; // w10
  char v95; // w11
  char v96; // w9
  char v97; // w10
  char v98; // w11
  char v99; // w9
  char v100; // w10
  char v101; // w11
  char v102; // w9
  char v103; // w10
  char v104; // w11
  char v105; // w9
  char v106; // w10
  char v107; // w11
  char v108; // w9
  char v109; // w10
  char v110; // w11
  char v111; // w9
  char v112; // w10
  char v113; // w11
  char v114; // w9
  char v115; // w10
  char v116; // w11
  char v117; // w9
  char v118; // w10
  char v119; // w11
  char v120; // w9
  char v121; // w10
  char v122; // w11
  char v123; // w9
  char v124; // w10
  char v125; // w11
  char v126; // w9
  char v127; // w10
  char v128; // w11
  char v129; // w9
  char v130; // w10
  char v131; // w11
  __int64 result; // x0
  char v133; // w9
  char v134; // w10
  char v135; // w11
  unsigned int v136; // [xsp+Ch] [xbp-14h]

  v3 = a2;
  v4 = this;
  a2->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)a2, this, 4uLL);
  v5 = v4->type[0];
  v6 = v4->type[2];
  v7 = v4->type[1];
  v4->type[0] = v4->type[3];
  v4->type[3] = v5;
  v4->type[1] = v6;
  v4->type[2] = v7;
  v8 = v3->vftbl->_ZN13idFile_Memory4ReadEPvm;
  v136 = 0;
  v8((idFile_Memory *)v3, &v136, 4uLL);
  v9 = v136;
  v10 = v3->vftbl;
  v11 = v136 >> 24;
  HIBYTE(v136) = v136;
  LOBYTE(v136) = v11;
  BYTE1(v136) = BYTE2(v9);
  BYTE2(v136) = BYTE1(v9);
  v10->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, v4->fileExtensionAAS, (signed int)v136);
  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v136, 4uLL);
  v12 = v136;
  v13 = v3->vftbl;
  v14 = v136 >> 24;
  HIBYTE(v136) = v136;
  LOBYTE(v136) = v14;
  BYTE1(v136) = BYTE2(v12);
  BYTE2(v136) = BYTE1(v12);
  v13->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, v4->groupName, (signed int)v136);
  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v136, 4uLL);
  v15 = v136;
  v16 = v3->vftbl;
  v17 = v136 >> 24;
  HIBYTE(v136) = v136;
  LOBYTE(v136) = v17;
  BYTE1(v136) = BYTE2(v15);
  BYTE2(v136) = BYTE1(v15);
  v16->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, v4->explicitGroupName, (signed int)v136);
  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->boundingBox, 24uLL);
  v18 = LOBYTE(v4->boundingBox.b[0].x);
  v19 = BYTE2(v4->boundingBox.b[0].x);
  v20 = BYTE1(v4->boundingBox.b[0].x);
  LOBYTE(v4->boundingBox.b[0].x) = HIBYTE(v4->boundingBox.b[0].x);
  HIBYTE(v4->boundingBox.b[0].x) = v18;
  BYTE1(v4->boundingBox.b[0].x) = v19;
  BYTE2(v4->boundingBox.b[0].x) = v20;
  v21 = LOBYTE(v4->boundingBox.b[0].y);
  v22 = BYTE2(v4->boundingBox.b[0].y);
  v23 = BYTE1(v4->boundingBox.b[0].y);
  LOBYTE(v4->boundingBox.b[0].y) = HIBYTE(v4->boundingBox.b[0].y);
  HIBYTE(v4->boundingBox.b[0].y) = v21;
  BYTE1(v4->boundingBox.b[0].y) = v22;
  BYTE2(v4->boundingBox.b[0].y) = v23;
  v24 = LOBYTE(v4->boundingBox.b[0].z);
  v25 = BYTE2(v4->boundingBox.b[0].z);
  v26 = BYTE1(v4->boundingBox.b[0].z);
  LOBYTE(v4->boundingBox.b[0].z) = HIBYTE(v4->boundingBox.b[0].z);
  HIBYTE(v4->boundingBox.b[0].z) = v24;
  BYTE1(v4->boundingBox.b[0].z) = v25;
  BYTE2(v4->boundingBox.b[0].z) = v26;
  v27 = LOBYTE(v4->boundingBox.b[1].x);
  v28 = BYTE2(v4->boundingBox.b[1].x);
  v29 = BYTE1(v4->boundingBox.b[1].x);
  LOBYTE(v4->boundingBox.b[1].x) = HIBYTE(v4->boundingBox.b[1].x);
  HIBYTE(v4->boundingBox.b[1].x) = v27;
  BYTE1(v4->boundingBox.b[1].x) = v28;
  BYTE2(v4->boundingBox.b[1].x) = v29;
  v30 = LOBYTE(v4->boundingBox.b[1].y);
  v31 = BYTE2(v4->boundingBox.b[1].y);
  v32 = BYTE1(v4->boundingBox.b[1].y);
  LOBYTE(v4->boundingBox.b[1].y) = HIBYTE(v4->boundingBox.b[1].y);
  HIBYTE(v4->boundingBox.b[1].y) = v30;
  BYTE1(v4->boundingBox.b[1].y) = v31;
  BYTE2(v4->boundingBox.b[1].y) = v32;
  v33 = LOBYTE(v4->boundingBox.b[1].z);
  v34 = BYTE2(v4->boundingBox.b[1].z);
  v35 = BYTE1(v4->boundingBox.b[1].z);
  LOBYTE(v4->boundingBox.b[1].z) = HIBYTE(v4->boundingBox.b[1].z);
  HIBYTE(v4->boundingBox.b[1].z) = v33;
  BYTE1(v4->boundingBox.b[1].z) = v34;
  BYTE2(v4->boundingBox.b[1].z) = v35;
  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->primitiveModeBrush, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->primitiveModeModel, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->gravityDir, 12uLL);
  v42 = LOBYTE(v4->gravityDir.x);
  v43 = BYTE2(v4->gravityDir.x);
  v44 = BYTE1(v4->gravityDir.x);
  LOBYTE(v4->gravityDir.x) = HIBYTE(v4->gravityDir.x);
  HIBYTE(v4->gravityDir.x) = v42;
  BYTE1(v4->gravityDir.x) = v43;
  BYTE2(v4->gravityDir.x) = v44;
  v45 = LOBYTE(v4->gravityDir.y);
  v46 = BYTE2(v4->gravityDir.y);
  v47 = BYTE1(v4->gravityDir.y);
  LOBYTE(v4->gravityDir.y) = HIBYTE(v4->gravityDir.y);
  HIBYTE(v4->gravityDir.y) = v45;
  BYTE1(v4->gravityDir.y) = v46;
  BYTE2(v4->gravityDir.y) = v47;
  v48 = LOBYTE(v4->gravityDir.z);
  v49 = BYTE2(v4->gravityDir.z);
  v50 = BYTE1(v4->gravityDir.z);
  LOBYTE(v4->gravityDir.z) = HIBYTE(v4->gravityDir.z);
  HIBYTE(v4->gravityDir.z) = v48;
  BYTE1(v4->gravityDir.z) = v49;
  BYTE2(v4->gravityDir.z) = v50;

  return result;
}
*/
static void read_settings(idAAS2Settings& s, raw_loader_t&r) {

	s.type = r.rd<idAAS2Settings::type_t>();
	r.read_string<unsigned>(s.fileExtensionAAS);
	r.read_string<unsigned>(s.groupName);
	r.read_string<unsigned>(s.explicitGroupName);

	r.read_n_into<float>(&s.boundingBox, sizeof(idBounds) / sizeof(float));
	s.primitiveModeBrush = r.rd<unsigned>();
	s.primitiveModeModel = r.rd<unsigned>();
	r.read_n_into<float>(&s.gravityDir, 3);
	/*
	  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->gravityValue, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->maxStepHeight, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->maxBarrierHeight, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->maxWaterJumpHeight, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->maxFallHeight, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->minFloorCos, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->minHighCeiling, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->groundSpeed, 4uLL);


	*/

	s.gravityValue = r.rd<float>();
	s.maxStepHeight = r.rd<float>();
	s.maxBarrierHeight = r.rd<float>();
	s.maxWaterJumpHeight = r.rd<float>();
	s.maxFallHeight = r.rd<float>();
	s.minFloorCos = r.rd<float>();
	s.minHighCeiling = r.rd<float>();
	s.groundSpeed = r.rd<float>();

	/*
	  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->waterSpeed, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->ladderSpeed, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->wallCornerEdgeRadius, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->ledgeCornerEdgeRadius, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->obstaclePVSRadius, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->minCrouchingCoverHeight, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->minStandingCoverHeight, 4uLL);

	*/

	s.waterSpeed = r.rd<float>();
	s.ladderSpeed = r.rd<float>();
	s.wallCornerEdgeRadius = r.rd<float>();
	s.ledgeCornerEdgeRadius = r.rd<float>();
	s.obstaclePVSRadius = r.rd<float>();
	s.minCrouchingCoverHeight = r.rd<float>();
	s.minStandingCoverHeight = r.rd<float>();

	/*

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->obstaclePVSRadius, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->standingFireHeight, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->minWallWidth, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->maxWallWidth, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->minDoorWidth, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->maxDoorWidth, 4uLL);

	*/
	//obstacePVSRadius is read twice??? why

	s.obstaclePVSRadius = r.rd<float>();
	s.standingFireHeight = r.rd<float>();

	s.minWallWidth = r.rd<float>();
	s.maxWallWidth = r.rd<float>();
	s.minDoorWidth = r.rd<float>();
	s.maxDoorWidth = r.rd<float>();
	/*
	
  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->coverCornerDistance, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->coverWallDistance, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->chokePointWidth, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->tt_barrierJump, 4uLL);

  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->tt_waterJump, 4uLL);
  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->tt_startWalkOffLedge, 4uLL);
  v3->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v3, &v4->tt_startLadderClimb, 4uLL);
	*/

	s.coverCornerDistance = r.rd<float>();
	s.coverWallDistance = r.rd<float>();
	s.chokePointWidth = r.rd<float>();
    s.tt_barrierJump = r.rd<int>();
	s.tt_waterJump = r.rd<int>();
	s.tt_startWalkOffLedge = r.rd<int>();
	s.tt_startLadderClimb = r.rd<int>();

}

static bool read_impl(idAAS2File* f, raw_loader_t& r) {
	
	unsigned magic = r.rd<unsigned>();

	if(magic != '2SAA') {
		return false;
	}

	char magic2 = r.rd<char>();
	char magic3 = r.rd<char>();
	if(magic2!=3 || magic3 != 29)
		return false;
	/*
		probably minorVersion and majorVersion
		nope its crc and timestamp 
		the previous char ones are major and minorversion
	*/
	unsigned idk = r.rd<unsigned>();

	unsigned idk2 = r.rd<unsigned>();

	f->crc = idk;
	f->timestamp = idk2;
	f->firstFakeVertex = r.rd<int>();
	/*
	  v141->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v141, &v9->firstFakeVertex, 4uLL);

  v141->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v141, &v9->firstFakeEdge, 4uLL);

  v141->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v141, &v9->firstFakeEdgeIndex, 4uLL);
  v141->vftbl->_ZN13idFile_Memory4ReadEPvm((idFile_Memory *)v141, &v9->firstFakeArea, 4uLL);
	*/
	f->firstFakeEdge = r.rd<int>();
	f->firstFakeEdgeIndex = r.rd<int>();
	f->firstFakeArea = r.rd<int>();
    assert(r.position==30);
	read_settings(f->settings, r);
	/*
	planes
	vertices
	edges
	edgeIndex
	reachabilities
	areas
	nodes
	portals
	portalIndex
	clusters
	obstacePVS
	reachabilityNames
	animNames
	dependencyNames
	interactionEntityNames
	cover
	areaCoverIndex
	touchingCoverIndex
	traversalPoints
	hintNodes
	trees
	areaBounds
	then endian swap
	*/
	r.read_vector(f->planes);

	r.read_vector(f->vertices);r.read_vector(f->edges);r.read_vector(f->edgeIndex);
	r.read_vector(f->reachabilities);r.read_vector(f->areas);r.read_vector(f->nodes);
	r.read_vector(f->portals);r.read_vector(f->portalIndex);r.read_vector(f->clusters);
	r.read_vector(f->obstaclePVS); r.read_vector(f->reachabilityNames);
	r.read_vector(f->animNames);r.read_vector(f->dependencyNames);
	r.read_vector(f->interactionEntityNames);// r.read_vector(f->interactionEntityNames);
	r.read_vector(f->cover); r.read_vector(f->areaCoverIndex); r.read_vector(f->touchingCoverIndex);
	r.read_vector(f->traversalPoints); r.read_vector(f->hintNodes); r.read_vector(f->trees);
	r.read_vector(f->areaBounds);

    idAAS2File_EndianSwap(f);
    idAAS2File__FlagNoPushAreas(f);
    //dont need to do maxtreedepth_r, it doesnt set anything up
}

void  idAAS2File_EndianSwap(idAAS2File *result)
{
  signed __int64 v1; // x8
  signed __int64 v2; // x9
  char *v3; // x10
  char v4; // w11
  char v5; // w13
  char v6; // w14
  char v7; // w15
  char v8; // w16
  char v9; // w17
  char v10; // w18
  char v11; // w1
  char v12; // w2
  char v13; // w3
  char v14; // w4
  char v15; // w5
  char v16; // w6
  char v17; // w7
  char v18; // w19
  signed __int64 v19; // x8
  signed __int64 v20; // x9
  char *v21; // x10
  char v22; // w11
  char v23; // w13
  char v24; // w14
  char v25; // w15
  char v26; // w16
  char v27; // w17
  char v28; // w18
  char v29; // w1
  char v30; // w2
  char v31; // w3
  char v32; // w4
  __int64 v33; // x8
  signed __int64 v34; // x9
  char *v35; // x10
  char v36; // w11
  char v37; // w13
  char v38; // w14
  char v39; // w15
  char v40; // w16
  char v41; // w17
  char v42; // w18
  char *v43; // x10
  char v44; // w12
  char v45; // w13
  char v46; // w14
  __int64 v47; // x8
  signed __int64 v48; // x9
  char *v49; // x10
  char v50; // w12
  char v51; // w13
  char v52; // w14
  __int64 v53; // x8
  signed __int64 v54; // x9
  char *v55; // x10
  char v56; // w12
  char v57; // w13
  char v58; // w14
  char *v59; // x10
  char v60; // w12
  char *v61; // x10
  char v62; // w12
  char *v63; // x10
  char v64; // w12
  char *v65; // x10
  char v66; // w12
  char *v67; // x10
  char v68; // w11
  char v69; // w13
  char v70; // w14
  char v71; // w15
  char v72; // w16
  char *v73; // x10
  char v74; // w11
  char v75; // w13
  char v76; // w14
  char v77; // w15
  char v78; // w16
  char *v79; // x10
  char v80; // w12
  char v81; // w13
  char v82; // w14
  char *v83; // x10
  char v84; // w12
  char v85; // w13
  char v86; // w14
  char *v87; // x10
  char v88; // w12
  char v89; // w13
  char v90; // w14
  char *v91; // x10
  char v92; // w12
  char v93; // w13
  char v94; // w14
  __int64 v95; // x8
  signed __int64 v96; // x9
  char *v97; // x10
  char v98; // w12
  char *v99; // x10
  char v100; // w12
  char v101; // w13
  char v102; // w14
  char *v103; // x10
  char v104; // w12
  char *v105; // x10
  char v106; // w12
  char v107; // w13
  char v108; // w14
  char *v109; // x10
  char v110; // w12
  char *v111; // x10
  char v112; // w12
  char *v113; // x10
  char v114; // w12
  char v115; // w13
  char v116; // w14
  char *v117; // x10
  char v118; // w12
  char v119; // w13
  char v120; // w14
  char *v121; // x10
  char v122; // w12
  char v123; // w13
  char v124; // w14
  char *v125; // x10
  char v126; // w12
  char *v127; // x10
  char v128; // w12
  char *v129; // x10
  char v130; // w12
  char *v131; // x10
  char v132; // w12
  char *v133; // x10
  char v134; // w12
  char *v135; // x10
  char v136; // w12
  char *v137; // x10
  char v138; // w12
  char *v139; // x10
  char v140; // w12
  __int64 v141; // x8
  signed __int64 v142; // x9
  char *v143; // x10
  char v144; // w12
  char v145; // w13
  char v146; // w14
  char *v147; // x10
  char v148; // w12
  char v149; // w13
  char v150; // w14
  char *v151; // x10
  char v152; // w11
  char v153; // w13
  char v154; // w14
  char v155; // w15
  char v156; // w16
  char v157; // w17
  char v158; // w18
  signed __int64 v159; // x8
  signed __int64 v160; // x9
  char *v161; // x10
  char v162; // w12
  char *v163; // x10
  char v164; // w12
  char v165; // w13
  char v166; // w14
  char *v167; // x10
  char v168; // w12
  char v169; // w13
  char v170; // w14
  char *v171; // x10
  char v172; // w12
  __int64 v173; // x8
  signed __int64 v174; // x9
  char *v175; // x10
  char v176; // w12
  char v177; // w13
  char v178; // w14
  __int64 v179; // x8
  signed __int64 v180; // x9
  char *v181; // x10
  char v182; // w12
  char v183; // w13
  char v184; // w14
  char *v185; // x10
  char v186; // w12
  char v187; // w13
  char v188; // w14
  char *v189; // x10
  char v190; // w12
  char v191; // w13
  char v192; // w14
  char *v193; // x10
  char v194; // w12
  char v195; // w13
  char v196; // w14
  __int64 v197; // x8
  signed __int64 v198; // x9
  char *v199; // x10
  char v200; // w12
  char v201; // w13
  char v202; // w14
  __int64 v203; // x8
  signed __int64 v204; // x9
  char *v205; // x10
  char v206; // w11
  char v207; // w13
  char v208; // w14
  char v209; // w15
  char v210; // w16
  char v211; // w17
  char v212; // w18
  char v213; // w1
  char v214; // w2
  char v215; // w3
  char v216; // w4
  char *v217; // x10
  char v218; // w11
  char v219; // w13
  char v220; // w14
  char v221; // w15
  char v222; // w16
  char v223; // w17
  char v224; // w18
  char v225; // w1
  char v226; // w2
  char v227; // w3
  char v228; // w4
  char *v229; // x10
  char v230; // w12
  char v231; // w13
  char v232; // w14
  char *v233; // x10
  char v234; // w12
  char *v235; // x10
  char v236; // w12
  char *v237; // x10
  char v238; // w12
  char *v239; // x10
  char v240; // w12
  char *v241; // x10
  char v242; // w12
  char v243; // w13
  char v244; // w14
  char *v245; // x10
  char v246; // w12
  char v247; // w13
  char v248; // w14
  char *v249; // x10
  char v250; // w12
  char v251; // w13
  char v252; // w14
  char *v253; // x10
  char v254; // w12
  char v255; // w13
  char v256; // w14
  char *v257; // x10
  char v258; // w12
  char v259; // w13
  char v260; // w14
  __int64 v261; // x8
  signed __int64 v262; // x9
  char *v263; // x10
  char v264; // w12
  char v265; // w13
  char v266; // w14
  __int64 v267; // x8
  signed __int64 v268; // x9
  char *v269; // x10
  char v270; // w12
  char v271; // w13
  char v272; // w14
  __int64 v273; // x8
  signed __int64 v274; // x9
  char *v275; // x10
  char v276; // w11
  char v277; // w13
  char v278; // w14
  char v279; // w15
  char v280; // w16
  char v281; // w17
  char v282; // w18
  char v283; // w1
  char v284; // w2
  char v285; // w3
  char v286; // w4
  char *v287; // x10
  char v288; // w11
  char v289; // w13
  char v290; // w14
  char v291; // w15
  char v292; // w16
  char v293; // w17
  char v294; // w18
  char v295; // w1
  char v296; // w2
  char v297; // w3
  char v298; // w4
  char *v299; // x10
  char v300; // w12
  char *v301; // x10
  char v302; // w12
  char *v303; // x10
  char v304; // w12
  char *v305; // x10
  char v306; // w12
  char *v307; // x10
  char v308; // w12
  char *v309; // x10
  char v310; // w12
  char *v311; // x10
  char v312; // w12
  char *v313; // x10
  char v314; // w12
  char *v315; // x10
  char v316; // w12
  char v317; // w13
  char v318; // w14
  char *v319; // x10
  char v320; // w12
  char *v321; // x10
  char v322; // w12
  char *v323; // x10
  char v324; // w12
  char v325; // w13
  char v326; // w14
  char *v327; // x10
  char v328; // w12
  char *v329; // x10
  char v330; // w12
  char *v331; // x10
  char v332; // w12
  char *v333; // x10
  char v334; // w12
  __int64 v335; // x8
  signed __int64 v336; // x9
  char *v337; // x10
  char v338; // w11
  char v339; // w13
  char v340; // w14
  char v341; // w15
  char v342; // w16
  char v343; // w17
  char v344; // w18
  char v345; // w1
  char v346; // w2
  char v347; // w3
  char v348; // w4
  char *v349; // x10
  char v350; // w12
  char *v351; // x10
  char v352; // w12
  char *v353; // x10
  char v354; // w12
  char v355; // w13
  char v356; // w14
  __int64 v357; // x8
  signed __int64 v358; // x9
  char *v359; // x10
  char v360; // w11
  char v361; // w13
  char v362; // w14
  char v363; // w15
  char v364; // w16
  char v365; // w17
  char v366; // w18
  char v367; // w1
  char v368; // w2
  char v369; // w3
  char v370; // w4
  char *v371; // x10
  char v372; // w12
  char v373; // w13
  char v374; // w14
  char *v375; // x10
  char v376; // w12
  char v377; // w13
  char v378; // w14
  char *v379; // x10
  char v380; // w12
  char v381; // w13
  char v382; // w14
  signed __int64 v383; // x8
  signed __int64 v384; // x9
  char *v385; // x10
  char v386; // w11
  char v387; // w13
  char v388; // w14
  char v389; // w15
  char v390; // w16
  char *v391; // x10
  char v392; // w11
  char v393; // w13
  char v394; // w14
  char v395; // w15
  char v396; // w16

  if ( result->planes.size() >= 1 )
  {
    v1 = 0LL;
    v2 = 15LL;
    do
    {
      ++v1;
      v3 = (char *)result->planes.data() + v2;
      v2 += 16LL;
      v4 = *(v3 - 15);
      v5 = *(v3 - 14);
      v6 = *(v3 - 13);
      v7 = *(v3 - 11);
      v8 = *(v3 - 8);
      v9 = *(v3 - 10);
      v10 = *(v3 - 9);
      v11 = *(v3 - 7);
      v12 = *(v3 - 4);
      v13 = *(v3 - 6);
      v14 = *(v3 - 5);
      v15 = *(v3 - 3);
      v16 = *v3;
      v17 = *(v3 - 2);
      v18 = *(v3 - 1);
      *(v3 - 15) = *(v3 - 12);
      *(v3 - 12) = v4;
      *(v3 - 14) = v6;
      *(v3 - 13) = v5;
      *(v3 - 11) = v8;
      *(v3 - 8) = v7;
      *(v3 - 10) = v10;
      *(v3 - 9) = v9;
      *(v3 - 7) = v12;
      *(v3 - 4) = v11;
      *(v3 - 6) = v14;
      *(v3 - 5) = v13;
      *(v3 - 3) = v16;
      *v3 = v15;
      *(v3 - 2) = v18;
      *(v3 - 1) = v17;
    }
    while ( v1 < result->planes.size() );
  }
  if ( result->vertices.size() >= 1 )
  {
    v19 = 0LL;
    v20 = 11LL;
    do
    {
      ++v19;
      v21 = (char *)result->vertices.data() + v20;
      v20 += 12LL;
      v22 = *(v21 - 11);
      v23 = *(v21 - 10);
      v24 = *(v21 - 9);
      v25 = *(v21 - 7);
      v26 = *(v21 - 4);
      v27 = *(v21 - 6);
      v28 = *(v21 - 5);
      v29 = *(v21 - 3);
      v30 = *v21;
      v31 = *(v21 - 2);
      v32 = *(v21 - 1);
      *(v21 - 11) = *(v21 - 8);
      *(v21 - 8) = v22;
      *(v21 - 10) = v24;
      *(v21 - 9) = v23;
      *(v21 - 7) = v26;
      *(v21 - 4) = v25;
      *(v21 - 6) = v28;
      *(v21 - 5) = v27;
      *(v21 - 3) = v30;
      *v21 = v29;
      *(v21 - 2) = v32;
      *(v21 - 1) = v31;
    }
    while ( v19 < result->vertices.size() );
  }
  if ( result->edges.size() >= 1 )
  {
    v33 = 0LL;
    v34 = 0LL;
    do
    {
      ++v34;
      v35 = (char *)result->edges.data() + v33;
      v36 = *v35;
      v37 = v35[1];
      v38 = v35[2];
      v39 = v35[4];
      v40 = v35[7];
      v41 = v35[5];
      v42 = v35[6];
      *v35 = v35[3];
      v35[3] = v36;
      v35[1] = v38;
      v35[2] = v37;
      v35[4] = v40;
      v35[7] = v39;
      v35[5] = v42;
      v35[6] = v41;
      v43 = (char *)result->edges.data() + v33;
      v33 += 12LL;
      v44 = v43[8];
      v45 = v43[10];
      v46 = v43[9];
      v43[8] = v43[11];
      v43[11] = v44;
      v43[9] = v45;
      v43[10] = v46;
    }
    while ( v34 < result->edges.size() );
  }
  if ( result->edgeIndex.size() >= 1 )
  {
    v47 = 0LL;
    v48 = 0LL;
    do
    {
      ++v48;
      v49 = (char *)result->edgeIndex.data() + v47;
      v47 += 4LL;
      v50 = *v49;
      v51 = v49[2];
      v52 = v49[1];
      *v49 = v49[3];
      v49[3] = v50;
      v49[1] = v51;
      v49[2] = v52;
    }
    while ( v48 < result->edgeIndex.size() );
  }
  if ( result->reachabilities.size() >= 1 )
  {
    v53 = 0LL;
    v54 = 0LL;
    do
    {
      ++v54;
      v55 = (char *)result->reachabilities.data() + v53;
      v56 = *v55;
      v57 = v55[2];
      v58 = v55[1];
      *v55 = v55[3];
      v55[3] = v56;
      v55[1] = v57;
      v55[2] = v58;
      v59 = (char *)result->reachabilities.data() + v53;
      v60 = v59[4];
      v59[4] = v59[5];
      v59[5] = v60;
      v61 = (char *)result->reachabilities.data() + v53;
      v62 = v61[6];
      v61[6] = v61[7];
      v61[7] = v62;
      v63 = (char *)result->reachabilities.data() + v53;
      v64 = v63[8];
      v63[8] = v63[9];
      v63[9] = v64;
      v65 = (char *)result->reachabilities.data() + v53;
      v66 = v65[10];
      v65[10] = v65[11];
      v65[11] = v66;
      v67 = (char *)result->reachabilities.data() + v53;
      v68 = v67[12];
      v69 = v67[14];
      v70 = v67[15];
      v71 = v67[16];
      v72 = v67[17];
      v67[12] = v67[13];
      v67[13] = v68;
      v67[14] = v70;
      v67[15] = v69;
      v67[16] = v72;
      v67[17] = v71;
      v73 = (char *)result->reachabilities.data() + v53;
      v74 = v73[18];
      v75 = v73[20];
      v76 = v73[21];
      v77 = v73[22];
      v78 = v73[23];
      v73[18] = v73[19];
      v73[19] = v74;
      v73[20] = v76;
      v73[21] = v75;
      v73[22] = v78;
      v73[23] = v77;
      v79 = (char *)result->reachabilities.data() + v53;
      v80 = v79[24];
      v81 = v79[26];
      v82 = v79[25];
      v79[24] = v79[27];
      v79[27] = v80;
      v79[25] = v81;
      v79[26] = v82;
      v83 = (char *)result->reachabilities.data() + v53;
      v84 = v83[28];
      v85 = v83[30];
      v86 = v83[29];
      v83[28] = v83[31];
      v83[31] = v84;
      v83[29] = v85;
      v83[30] = v86;
      v87 = (char *)result->reachabilities.data() + v53;
      v88 = v87[32];
      v89 = v87[34];
      v90 = v87[33];
      v87[32] = v87[35];
      v87[35] = v88;
      v87[33] = v89;
      v87[34] = v90;
      v91 = (char *)result->reachabilities.data() + v53;
      v53 += 40LL;
      v92 = v91[36];
      v93 = v91[38];
      v94 = v91[37];
      v91[36] = v91[39];
      v91[39] = v92;
      v91[37] = v93;
      v91[38] = v94;
    }
    while ( v54 < result->reachabilities.size() );
  }
  if ( result->areas.size() >= 1 )
  {
    v95 = 0LL;
    v96 = 0LL;
    do
    {
      ++v96;
      v97 = (char *)result->areas.data() + v95;
      v98 = v97[4];
      v97[4] = v97[5];
      v97[5] = v98;
      v99 = (char *)result->areas.data() + v95;
      v100 = *v99;
      v101 = v99[2];
      v102 = v99[1];
      *v99 = v99[3];
      v99[3] = v100;
      v99[1] = v101;
      v99[2] = v102;
      v103 = (char *)result->areas.data() + v95;
      v104 = v103[6];
      v103[6] = v103[7];
      v103[7] = v104;
      v105 = (char *)result->areas.data() + v95;
      v106 = v105[8];
      v107 = v105[10];
      v108 = v105[9];
      v105[8] = v105[11];
      v105[11] = v106;
      v105[9] = v107;
      v105[10] = v108;
      v109 = (char *)result->areas.data() + v95;
      v110 = v109[12];
      v109[12] = v109[13];
      v109[13] = v110;
      v111 = (char *)result->areas.data() + v95;
      v112 = v111[14];
      v111[14] = v111[15];
      v111[15] = v112;
      v113 = (char *)result->areas.data() + v95;
      v114 = v113[16];
      v115 = v113[18];
      v116 = v113[17];
      v113[16] = v113[19];
      v113[19] = v114;
      v113[17] = v115;
      v113[18] = v116;
      v117 = (char *)result->areas.data() + v95;
      v118 = v117[20];
      v119 = v117[22];
      v120 = v117[21];
      v117[20] = v117[23];
      v117[23] = v118;
      v117[21] = v119;
      v117[22] = v120;
      v121 = (char *)result->areas.data() + v95;
      v122 = v121[24];
      v123 = v121[26];
      v124 = v121[25];
      v121[24] = v121[27];
      v121[27] = v122;
      v121[25] = v123;
      v121[26] = v124;
      v125 = (char *)result->areas.data() + v95;
      v126 = v125[28];
      v125[28] = v125[29];
      v125[29] = v126;
      v127 = (char *)result->areas.data() + v95;
      v128 = v127[30];
      v127[30] = v127[31];
      v127[31] = v128;
      v129 = (char *)result->areas.data() + v95;
      v130 = v129[32];
      v129[32] = v129[33];
      v129[33] = v130;
      v131 = (char *)result->areas.data() + v95;
      v132 = v131[34];
      v131[34] = v131[35];
      v131[35] = v132;
      v133 = (char *)result->areas.data() + v95;
      v134 = v133[36];
      v133[36] = v133[37];
      v133[37] = v134;
      v135 = (char *)result->areas.data() + v95;
      v136 = v135[38];
      v135[38] = v135[39];
      v135[39] = v136;
      v137 = (char *)result->areas.data() + v95;
      v138 = v137[40];
      v137[40] = v137[41];
      v137[41] = v138;
      v139 = (char *)result->areas.data() + v95;
      v95 += 44LL;
      v140 = v139[42];
      v139[42] = v139[43];
      v139[43] = v140;
    }
    while ( v96 < result->areas.size() );
  }
  if ( result->nodes.size() >= 1 )
  {
    v141 = 0LL;
    v142 = 0LL;
    do
    {
      ++v142;
      v143 = (char *)result->nodes.data() + v141;
      v144 = *v143;
      v145 = v143[2];
      v146 = v143[1];
      *v143 = v143[3];
      v143[3] = v144;
      v143[1] = v145;
      v143[2] = v146;
      v147 = (char *)result->nodes.data() + v141;
      v148 = v147[4];
      v149 = v147[6];
      v150 = v147[5];
      v147[4] = v147[7];
      v147[7] = v148;
      v147[5] = v149;
      v147[6] = v150;
      v151 = (char *)result->nodes.data() + v141;
      v141 += 16LL;
      v152 = v151[8];
      v153 = v151[9];
      v154 = v151[10];
      v155 = v151[12];
      v156 = v151[15];
      v157 = v151[13];
      v158 = v151[14];
      v151[8] = v151[11];
      v151[11] = v152;
      v151[9] = v154;
      v151[10] = v153;
      v151[12] = v156;
      v151[15] = v155;
      v151[13] = v158;
      v151[14] = v157;
    }
    while ( v142 < result->nodes.size() );
  }
  if ( result->portals.size() >= 1 )
  {
    v159 = 0LL;
    v160 = 11LL;
    do
    {
      ++v159;
      v161 = (char *)result->portals.data() + v160;
      v162 = *(v161 - 11);
      *(v161 - 11) = *(v161 - 10);
      *(v161 - 10) = v162;
      v163 = (char *)result->portals.data() + v160;
      v164 = *(v163 - 9);
      v165 = *(v163 - 6);
      v166 = *(v163 - 7);
      *(v163 - 9) = *(v163 - 8);
      *(v163 - 8) = v164;
      *(v163 - 7) = v165;
      *(v163 - 6) = v166;
      v167 = (char *)result->portals.data() + v160;
      v168 = *(v167 - 5);
      v169 = *(v167 - 2);
      v170 = *(v167 - 3);
      *(v167 - 5) = *(v167 - 4);
      *(v167 - 4) = v168;
      *(v167 - 3) = v169;
      *(v167 - 2) = v170;
      v171 = (char *)result->portals.data() + v160;
      v160 += 12LL;
      v172 = *(v171 - 1);
      *(v171 - 1) = *v171;
      *v171 = v172;
    }
    while ( v159 < result->portals.size() );
  }
  if ( result->portalIndex.size() >= 1 )
  {
    v173 = 0LL;
    v174 = 0LL;
    do
    {
      ++v174;
      v175 = (char *)result->portalIndex.data() + v173;
      v173 += 4LL;
      v176 = *v175;
      v177 = v175[2];
      v178 = v175[1];
      *v175 = v175[3];
      v175[3] = v176;
      v175[1] = v177;
      v175[2] = v178;
    }
    while ( v174 < result->portalIndex.size() );
  }
  if ( result->clusters.size() >= 1 )
  {
    v179 = 0LL;
    v180 = 0LL;
    do
    {
      ++v180;
      v181 = (char *)result->clusters.data() + v179;
      v182 = *v181;
      v183 = v181[2];
      v184 = v181[1];
      *v181 = v181[3];
      v181[3] = v182;
      v181[1] = v183;
      v181[2] = v184;
      v185 = (char *)result->clusters.data() + v179;
      v186 = v185[4];
      v187 = v185[6];
      v188 = v185[5];
      v185[4] = v185[7];
      v185[7] = v186;
      v185[5] = v187;
      v185[6] = v188;
      v189 = (char *)result->clusters.data() + v179;
      v190 = v189[8];
      v191 = v189[10];
      v192 = v189[9];
      v189[8] = v189[11];
      v189[11] = v190;
      v189[9] = v191;
      v189[10] = v192;
      v193 = (char *)result->clusters.data() + v179;
      v179 += 16LL;
      v194 = v193[12];
      v195 = v193[14];
      v196 = v193[13];
      v193[12] = v193[15];
      v193[15] = v194;
      v193[13] = v195;
      v193[14] = v196;
    }
    while ( v180 < result->clusters.size() );
  }
  if ( result->reachabilityNames.size() > 0 )
  {
    v197 = 0LL;
    v198 = 0LL;
    do
    {
      ++v198;
      v199 = (char *)result->reachabilityNames.data() + v197;
      v197 += 132LL;
      v200 = v199[128];
      v201 = v199[130];
      v202 = v199[129];
      v199[128] = v199[131];
      v199[131] = v200;
      v199[129] = v201;
      v199[130] = v202;
    }
    while ( v198 < result->reachabilityNames.size() );
  }
  if ( result->cover.size() > 0 )
  {
    v203 = 0LL;
    v204 = 0LL;
    do
    {
      ++v204;
      v205 = (char *)result->cover.data() + v203;
      v206 = *v205;
      v207 = v205[1];
      v208 = v205[2];
      v209 = v205[4];
      v210 = v205[7];
      v211 = v205[5];
      v212 = v205[6];
      v213 = v205[8];
      v214 = v205[11];
      v215 = v205[9];
      v216 = v205[10];
      *v205 = v205[3];
      v205[3] = v206;
      v205[1] = v208;
      v205[2] = v207;
      v205[4] = v210;
      v205[7] = v209;
      v205[5] = v212;
      v205[6] = v211;
      v205[8] = v214;
      v205[11] = v213;
      v205[9] = v216;
      v205[10] = v215;
      v217 = (char *)result->cover.data() + v203;
      v218 = v217[12];
      v219 = v217[13];
      v220 = v217[14];
      v221 = v217[16];
      v222 = v217[19];
      v223 = v217[17];
      v224 = v217[18];
      v225 = v217[20];
      v226 = v217[23];
      v227 = v217[21];
      v228 = v217[22];
      v217[12] = v217[15];
      v217[15] = v218;
      v217[13] = v220;
      v217[14] = v219;
      v217[16] = v222;
      v217[19] = v221;
      v217[17] = v224;
      v217[18] = v223;
      v217[20] = v226;
      v217[23] = v225;
      v217[21] = v228;
      v217[22] = v227;
      v229 = (char *)result->cover.data() + v203;
      v230 = v229[24];
      v231 = v229[26];
      v232 = v229[25];
      v229[24] = v229[27];
      v229[27] = v230;
      v229[25] = v231;
      v229[26] = v232;
      v233 = (char *)result->cover.data() + v203;
      v234 = v233[28];
      v233[28] = v233[29];
      v233[29] = v234;
      v235 = (char *)result->cover.data() + v203;
      v236 = v235[30];
      v235[30] = v235[31];
      v235[31] = v236;
      v237 = (char *)result->cover.data() + v203;
      v238 = v237[32];
      v237[32] = v237[33];
      v237[33] = v238;
      v239 = (char *)result->cover.data() + v203;
      v240 = v239[34];
      v239[34] = v239[35];
      v239[35] = v240;
      v241 = (char *)result->cover.data() + v203;
      v242 = v241[36];
      v243 = v241[38];
      v244 = v241[37];
      v241[36] = v241[39];
      v241[39] = v242;
      v241[37] = v243;
      v241[38] = v244;
      v245 = (char *)result->cover.data() + v203;
      v246 = v245[40];
      v247 = v245[42];
      v248 = v245[41];
      v245[40] = v245[43];
      v245[43] = v246;
      v245[41] = v247;
      v245[42] = v248;
      v249 = (char *)result->cover.data() + v203;
      v250 = v249[44];
      v251 = v249[46];
      v252 = v249[45];
      v249[44] = v249[47];
      v249[47] = v250;
      v249[45] = v251;
      v249[46] = v252;
      v253 = (char *)result->cover.data() + v203;
      v254 = v253[48];
      v255 = v253[50];
      v256 = v253[49];
      v253[48] = v253[51];
      v253[51] = v254;
      v253[49] = v255;
      v253[50] = v256;
      v257 = (char *)result->cover.data() + v203;
      v203 += 56LL;
      v258 = v257[52];
      v259 = v257[54];
      v260 = v257[53];
      v257[52] = v257[55];
      v257[55] = v258;
      v257[53] = v259;
      v257[54] = v260;
    }
    while ( v204 < result->cover.size() );
  }
  if ( result->areaCoverIndex.size() >= 1 )
  {
    v261 = 0LL;
    v262 = 0LL;
    do
    {
      ++v262;
      v263 = (char *)result->areaCoverIndex.data() + v261;
      v261 += 4LL;
      v264 = *v263;
      v265 = v263[2];
      v266 = v263[1];
      *v263 = v263[3];
      v263[3] = v264;
      v263[1] = v265;
      v263[2] = v266;
    }
    while ( v262 < result->areaCoverIndex.size() );
  }
  if ( result->touchingCoverIndex.size() >= 1 )
  {
    v267 = 0LL;
    v268 = 0LL;
    do
    {
      ++v268;
      v269 = (char *)result->touchingCoverIndex.data() + v267;
      v267 += 4LL;
      v270 = *v269;
      v271 = v269[2];
      v272 = v269[1];
      *v269 = v269[3];
      v269[3] = v270;
      v269[1] = v271;
      v269[2] = v272;
    }
    while ( v268 < result->touchingCoverIndex.size() );
  }
  if ( result->traversalPoints.size() >= 1 )
  {
    v273 = 0LL;
    v274 = 0LL;
    do
    {
      ++v274;
      v275 = (char *)result->traversalPoints.data() + v273;
      v276 = *v275;
      v277 = v275[1];
      v278 = v275[2];
      v279 = v275[4];
      v280 = v275[7];
      v281 = v275[5];
      v282 = v275[6];
      v283 = v275[8];
      v284 = v275[11];
      v285 = v275[9];
      v286 = v275[10];
      *v275 = v275[3];
      v275[3] = v276;
      v275[1] = v278;
      v275[2] = v277;
      v275[4] = v280;
      v275[7] = v279;
      v275[5] = v282;
      v275[6] = v281;
      v275[8] = v284;
      v275[11] = v283;
      v275[9] = v286;
      v275[10] = v285;
      v287 = (char *)result->traversalPoints.data() + v273;
      v288 = v287[12];
      v289 = v287[13];
      v290 = v287[14];
      v291 = v287[16];
      v292 = v287[19];
      v293 = v287[17];
      v294 = v287[18];
      v295 = v287[20];
      v296 = v287[23];
      v297 = v287[21];
      v298 = v287[22];
      v287[12] = v287[15];
      v287[15] = v288;
      v287[13] = v290;
      v287[14] = v289;
      v287[16] = v292;
      v287[19] = v291;
      v287[17] = v294;
      v287[18] = v293;
      v287[20] = v296;
      v287[23] = v295;
      v287[21] = v298;
      v287[22] = v297;
      v299 = (char *)result->traversalPoints.data() + v273;
      v300 = v299[24];
      v299[24] = v299[25];
      v299[25] = v300;
      v301 = (char *)result->traversalPoints.data() + v273;
      v302 = v301[26];
      v301[26] = v301[27];
      v301[27] = v302;
      v303 = (char *)result->traversalPoints.data() + v273;
      v304 = v303[28];
      v303[28] = v303[29];
      v303[29] = v304;
      v305 = (char *)result->traversalPoints.data() + v273;
      v306 = v305[30];
      v305[30] = v305[31];
      v305[31] = v306;
      v307 = (char *)result->traversalPoints.data() + v273;
      v308 = v307[32];
      v307[32] = v307[33];
      v307[33] = v308;
      v309 = (char *)result->traversalPoints.data() + v273;
      v310 = v309[34];
      v309[34] = v309[35];
      v309[35] = v310;
      v311 = (char *)result->traversalPoints.data() + v273;
      v312 = v311[36];
      v311[36] = v311[37];
      v311[37] = v312;
      v313 = (char *)result->traversalPoints.data() + v273;
      v314 = v313[38];
      v313[38] = v313[39];
      v313[39] = v314;
      v315 = (char *)result->traversalPoints.data() + v273;
      v316 = v315[40];
      v317 = v315[42];
      v318 = v315[41];
      v315[40] = v315[43];
      v315[43] = v316;
      v315[41] = v317;
      v315[42] = v318;
      v319 = (char *)result->traversalPoints.data() + v273;
      v320 = v319[44];
      v319[44] = v319[45];
      v319[45] = v320;
      v321 = (char *)result->traversalPoints.data() + v273;
      v322 = v321[46];
      v321[46] = v321[47];
      v321[47] = v322;
      v323 = (char *)result->traversalPoints.data() + v273;
      v324 = v323[48];
      v325 = v323[50];
      v326 = v323[49];
      v323[48] = v323[51];
      v323[51] = v324;
      v323[49] = v325;
      v323[50] = v326;
      v327 = (char *)result->traversalPoints.data() + v273;
      v328 = v327[52];
      v327[52] = v327[53];
      v327[53] = v328;
      v329 = (char *)result->traversalPoints.data() + v273;
      v330 = v329[54];
      v329[54] = v329[55];
      v329[55] = v330;
      v331 = (char *)result->traversalPoints.data() + v273;
      v332 = v331[56];
      v331[56] = v331[57];
      v331[57] = v332;
      v333 = (char *)result->traversalPoints.data() + v273;
      v273 += 60LL;
      v334 = v333[58];
      v333[58] = v333[59];
      v333[59] = v334;
    }
    while ( v274 < result->traversalPoints.size() );
  }
  if ( result->hintNodes.size() >= 1 )
  {
    v335 = 0LL;
    v336 = 0LL;
    do
    {
      ++v336;
      v337 = (char *)result->hintNodes.data() + v335;
      v338 = *v337;
      v339 = v337[1];
      v340 = v337[2];
      v341 = v337[4];
      v342 = v337[7];
      v343 = v337[5];
      v344 = v337[6];
      v345 = v337[8];
      v346 = v337[11];
      v347 = v337[9];
      v348 = v337[10];
      *v337 = v337[3];
      v337[3] = v338;
      v337[1] = v340;
      v337[2] = v339;
      v337[4] = v342;
      v337[7] = v341;
      v337[5] = v344;
      v337[6] = v343;
      v337[8] = v346;
      v337[11] = v345;
      v337[9] = v348;
      v337[10] = v347;
      v349 = (char *)result->hintNodes.data() + v335;
      v350 = v349[12];
      v349[12] = v349[13];
      v349[13] = v350;
      v351 = (char *)result->hintNodes.data() + v335;
      v352 = v351[14];
      v351[14] = v351[15];
      v351[15] = v352;
      v353 = (char *)result->hintNodes.data() + v335;
      v335 += 24LL;
      v354 = v353[20];
      v355 = v353[22];
      v356 = v353[21];
      v353[20] = v353[23];
      v353[23] = v354;
      v353[21] = v355;
      v353[22] = v356;
    }
    while ( v336 < result->hintNodes.size() );
  }
  if ( result->trees.size() >= 1 )
  {
    v357 = 0LL;
    v358 = 0LL;
    do
    {
      ++v358;
      v359 = (char *)result->trees.data() + v357;
      v360 = *v359;
      v361 = v359[1];
      v362 = v359[2];
      v363 = v359[4];
      v364 = v359[7];
      v365 = v359[5];
      v366 = v359[6];
      v367 = v359[8];
      v368 = v359[11];
      v369 = v359[9];
      v370 = v359[10];
      *v359 = v359[3];
      v359[3] = v360;
      v359[1] = v362;
      v359[2] = v361;
      v359[4] = v364;
      v359[7] = v363;
      v359[5] = v366;
      v359[6] = v365;
      v359[8] = v368;
      v359[11] = v367;
      v359[9] = v370;
      v359[10] = v369;
      v371 = (char *)result->trees.data() + v357;
      v372 = v371[12];
      v373 = v371[14];
      v374 = v371[13];
      v371[12] = v371[15];
      v371[15] = v372;
      v371[13] = v373;
      v371[14] = v374;
      v375 = (char *)result->trees.data() + v357;
      v376 = v375[16];
      v377 = v375[18];
      v378 = v375[17];
      v375[16] = v375[19];
      v375[19] = v376;
      v375[17] = v377;
      v375[18] = v378;
      v379 = (char *)result->trees.data() + v357;
      v357 += 24LL;
      v380 = v379[20];
      v381 = v379[22];
      v382 = v379[21];
      v379[20] = v379[23];
      v379[23] = v380;
      v379[21] = v381;
      v379[22] = v382;
    }
    while ( v358 < result->trees.size() );
  }
  if ( result->areaBounds.size() >= 1 )
  {
    v383 = 0LL;
    v384 = 5LL;
    do
    {
      ++v383;
      v385 = (char *)result->areaBounds.data() + v384;
      v386 = *(v385 - 5);
      v387 = *(v385 - 3);
      v388 = *(v385 - 2);
      v389 = *(v385 - 1);
      v390 = *v385;
      *(v385 - 5) = *(v385 - 4);
      *(v385 - 4) = v386;
      *(v385 - 3) = v388;
      *(v385 - 2) = v387;
      *(v385 - 1) = v390;
      *v385 = v389;
      v391 = (char *)result->areaBounds.data() + v384;
      v384 += 12LL;
      v392 = v391[1];
      v393 = v391[3];
      v394 = v391[4];
      v395 = v391[5];
      v396 = v391[6];
      v391[1] = v391[2];
      v391[2] = v392;
      v391[3] = v394;
      v391[4] = v393;
      v391[5] = v396;
      v391[6] = v395;
    }
    while ( v383 < result->areaBounds.size() );
  }
}

static signed __int64 __fastcall idAAS2File__PushPointIntoAreaNum(idAAS2File *a1, int a2, idVec3 *a3)
{
  __int64 v3; // x8
  char *v4; // x11
  __int64 v5; // x10
  int *v6; // x9
  signed __int16 *v7; // x12
  signed __int64 v8; // x8
  char *v9; // x13
  float v10; // s3
  float v11; // s4
  float v12; // s0
  float v13; // w14
  __int64 v14; // x12
  float *v15; // x11
  char *v16; // x10
  signed __int64 v17; // x9
  float v18; // s5
  signed int v19; // w1
  signed __int64 v20; // x17
  unsigned int v21; // w3
  int v22; // w4
  char *v23; // x6
  unsigned int v24; // w3
  signed __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x3
  float *v28; // x4
  float *v29; // x3
  float v30; // s6
  float v31; // s17
  float v32; // s19
  float v33; // s7
  float v34; // s16
  float v35; // s20
  float v36; // s22
  float v37; // s21
  float v38; // s23
  float v39; // s24
  float v40; // s25
  float v41; // s26
  int v42; // w4
  float v43; // w5
  int v44; // w1
  bool v45; // zf
  int v46; // w1
  signed __int64 result; // x0

  v3 = a1->trees.size();
  v4 = (char *)a1->trees.data();
  if ( (signed int)v3 < 1 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v5 = 0LL;
    v6 = (int *)(v4 + 20);
    while ( *(v6 - 1) > a2 || *v6 <= a2 )
    {
      ++v5;
      v6 += 6;
      if ( v5 >= v3 )
        goto LABEL_6;
    }
  }
  v7 = (signed __int16 *)a1->areas.data();
  v8 = v7[22 * a2 + 3];
  if ( v8 < 1 )
    return 0LL;
  v9 = (char *)a1->edgeIndex.data();
  v10 = a3->x;
  v11 = a3->y;
  v12 = 1.0e30;
  v13 = *(float *)&v5;
  v14 = *(signed int *)&v7[22 * a2 + 4];
  v15 = (float *)&v4[24 * (signed int)v5];
  v16 = (char*)a1->edges.data();
  v17 = 0LL;
  v18 = a3->z;
  v19 = 0;
  v20 = (signed __int64)&v9[4 * v14];
  do
  {
    v21 = *(int *)(v20 + 4 * v17);
    if ( (v21 & 0x80000000) == 0 )
      v22 = *(int *)(v20 + 4 * v17);
    else
      v22 = !v21;
    if ( !(v16[12 * v22 + 8] & 0x40) )
    {
      v23 = (char *)a1->vertices.data();
      v24 = v21 >> 31;
      v25 = (signed __int64)&v16[12 * v22];
      v26 = *(signed int *)(v25 + 4LL * (v24 ^ 1));
      v27 = *(signed int *)(v25 + 4LL * v24);
      v28 = (float *)&v23[12 * v26];
      v29 = (float *)&v23[12 * v27];
      v30 = v28[1];
      v31 = v28[2];
      v32 = *v28;
      v33 = v29[1];
      v34 = v29[2];
      v35 = v30 - v33;
      v36 = v18 - v34;
      v37 = v31 - v34;
      v38 = v11 - v33;
      v39 = v10 - *v29;
      v40 = *v28 - *v29;
      if ( (float)((float)((float)((float)-(float)((float)((float)(v18 - v34) * (float)(v30 - v33))
                                                 - (float)((float)(v11 - v33) * (float)(v31 - v34)))
                                 * *v15)
                         + (float)((float)-(float)((float)(v39 * (float)(v31 - v34)) - (float)((float)(v18 - v34) * v40))
                                 * v15[1]))
                 + (float)(v15[2]
                         * (float)-(float)((float)((float)(v11 - v33) * v40) - (float)(v39 * (float)(v30 - v33))))) < (float)-0.00000011921 )
      {
        v41 = (float)((float)((float)(v39 * v40) + (float)(v38 * v35)) + (float)(v36 * v37))
            / (float)((float)((float)(v40 * v40) + (float)(v35 * v35)) + (float)(v37 * v37));
        if ( v41 >= 0.0 )
        {
          if ( v41 < 1.0 )
          {
            result = 1LL;
            a3->x = *v29 + (float)(v41 * v40);
            a3->y = v33 + (float)(v41 * v35);
            a3->z = v34 + (float)(v41 * v37);
            return result;
          }
          v42 = *((int *)v28 + 1);
          v43 = v31;
          v46 = ((float)((float)((float)((float)(v10 - v32) * (float)(v10 - v32))
                               + (float)((float)(v11 - v30) * (float)(v11 - v30)))
                       + (float)((float)(v18 - v31) * (float)(v18 - v31))) < v12) | ~v19;
          v45 = (v46 & 1) == 0;
          if ( v46 & 1 )
            v13 = v32;
          if ( v46 & 1 )
            v12 = (float)((float)((float)(v10 - v32) * (float)(v10 - v32))
                        + (float)((float)(v11 - v30) * (float)(v11 - v30)))
                + (float)((float)(v18 - v31) * (float)(v18 - v31));
        }
        else
        {
          v42 = *((int *)v29 + 1);
          v43 = v29[2];
          v44 = ((float)((float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)(v36 * v36)) < v12) | ~v19;
          v45 = (v44 & 1) == 0;
          if ( v44 & 1 )
            v13 = *v29;
          if ( v44 & 1 )
            v12 = (float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)(v36 * v36);
        }
        if ( !v45 )
          v9 = (char*)(int)v42;
        if ( !v45 )
          *(float *)&v14 = v43;
        v19 = 1;
      }
    }
    ++v17;
  }
  while ( v17 < v8 );
  if ( !(v19 & 1) )
    return 0LL;
  result = 1LL;
  a3->x = v13;
  *reinterpret_cast<int*>(&a3->y) = (int)v9;
  *reinterpret_cast<int*>(&a3->z) = v14;
  return result;
}

static void __fastcall idAAS2File__FlagNoPushAreas(idAAS2File *result)
{
  idAAS2File *v1; // x19
  signed __int64 v2; // x20
  short *v3; // x23
  float v4; // s0
  float v5; // s1
  float v6; // s2
  signed __int64 v7; // x8
  signed __int64 v8; // x9
  unsigned int v9; // w13
  unsigned v10; // w14
  float *v11; // x13
  float v12; // s3
  idVec3 v13; // [xsp+0h] [xbp-50h]

  v1 = result;
  if ( result->areas.size() >= 2 )
  {
    v2 = 1LL;
    do
    {
      v3 = (short*)v1->areas.data();
      v4 = 0.0;
      v5 = 0.0;
      v6 = 0.0;
      v7 = (signed __int16)v3[22 * v2 + 3];
      v13.z = 0.0;
      *(unsigned long long *)&v13.x = 0LL;
      if ( v7 >= 1 )
      {
        v4 = 0.0;
        v5 = 0.0;
        v6 = 0.0;
        v8 = 0LL;
        do
        {
          v9 = *((int *)v1->edgeIndex.data() + *(signed int *)&v3[22 * v2 + 4] + v8++);
          if ( (v9 & 0x80000000) == 0 )
            v10 = v9;
          else
            v10 = !v9;
          v11 = (float *)((char *)v1->vertices.data() + 12 * *((signed int *)v1->edges.data() + 3 * v10 + (v9 >> 31)));
          v6 = v6 + *v11;
          v5 = v5 + v11[1];
          v4 = v4 + v11[2];
        }
        while ( v8 < v7 );
        v13.x = v6;
        v13.y = v5;
        v13.z = v4;
      }
      v12 = 1.0 / (float)(signed __int16)v7;
      v13.x = v6 * v12;
      v13.y = v5 * v12;
      v13.z = v4 * v12;
      if ( idAAS2File__PushPointIntoAreaNum(v1, v2, &v13) & 1 )
        v3[22 * v2 + 2] |= 0x10u;
      ++v2;
    }
    while ( v2 < v1->areas.size() );
  }
}