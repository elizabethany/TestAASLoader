#pragma once
/*

  (*(void (__fastcall **)(__int64, idAAS2Settings *, __int64))(*(_QWORD *)a2 + 40i64))(a2, a1, 4i64);

  (*(void (__fastcall **)(__int64, int *, __int64))(v7 + 40))(v2, &v106, 4i64);

  (*(void (__fastcall **)(__int64, char *, _QWORD))(v10 + 40))(v2, v3->fileExtensionAAS, v106);
  (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v106, 4i64);
  (*(void (__fastcall **)(__int64, char *, _QWORD))(v13 + 40))(v2, v3->groupName, v106);
  (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v106, 4i64);
  (*(void (__fastcall **)(__int64, char *, _QWORD))(v16 + 40))(v2, v3->explicitGroupName, v106);
  (*(void (__fastcall **)(__int64, idBounds *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->boundingBox, 24i64);
  sub_140DFC5C0(&v3->boundingBox);
  (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->primitiveModeBrush, 4i64);
  (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->primitiveModeModel, 4i64);
  sub_140DFB850(v2, (char *)&v3->gravityDir);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->gravityValue, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->maxStepHeight, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->maxBarrierHeight, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->maxWaterJumpHeight, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->maxFallHeight, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->minFloorCos, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->minHighCeiling, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->groundSpeed, 4i64);


  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->waterSpeed, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->ladderSpeed, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->wallCornerEdgeRadius, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->ledgeCornerEdgeRadius, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->obstaclePVSRadius, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->minCrouchingCoverHeight, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->minStandingCoverHeight, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->obstaclePVSRadius, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->standingFireHeight, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->minWallWidth, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->maxWallWidth, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->minDoorWidth, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->maxDoorWidth, 4i64);

  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->coverCornerDistance, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->coverWallDistance, 4i64);
  (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->chokePointWidth, 4i64);
  (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->tt_barrierJump, 4i64);
  (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->tt_waterJump, 4i64);
  (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->tt_startWalkOffLedge, 4i64);
  (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v2 + 40i64))(v2, &v3->tt_startLadderClimb, 4i64);


*/