__int64 __fastcall SwapVertexBuffer(void *a1, signed int a2, int a3)
{
  char *v3; // x18
  int v4; // w8
  int v5; // w9
  int v6; // w10
  int v7; // w11
  int v8; // w12
  int v9; // w13
  int v10; // w14
  int v11; // w15
  int v12; // w16
  int v13; // w17
  int v14; // w2
  char v15; // w4
  char v16; // w5
  char v17; // w6
  char v18; // w4
  char v19; // w5
  char v20; // w6
  char v21; // w4
  char v22; // w5
  char v23; // w6
  char v24; // w4
  char v25; // w5
  char v26; // w6
  char v27; // w4
  char v28; // w5
  char v29; // w6
  char v30; // w4
  char v31; // w5
  char v32; // w6
  char v33; // w4
  char v34; // w5
  char v35; // w6
  char v36; // w4
  char v37; // w5
  char v38; // w6
  char v39; // w4
  char v40; // w5
  char v41; // w6
  char v42; // w4
  char v43; // w5
  char v44; // w6
  char v45; // w4
  char v46; // w5
  char v47; // w6
  char v48; // w4
  char v49; // w5
  char v50; // w6
  char v51; // w3
  char v52; // w4
  char v53; // w5
  char v54; // w2
  char v55; // w3
  char *v56; // x2
  char v57; // w3
  char v58; // w4
  char v59; // w5
  char v60; // w2
  char v61; // w3
  char v62; // w4
  char v63; // w5
  char v64; // w2
  char v65; // w3
  char v66; // w4
  char v67; // w5
  char v68; // w3
  char v69; // w4
  char v70; // w5
  char v71; // w3
  char v72; // w4
  char v73; // w5
  char v74; // w3
  char v75; // w4
  char v76; // w5
  char v77; // w3
  char v78; // w4
  char v79; // w5
  char v80; // w3
  char v81; // w4
  char v82; // w5
  char v83; // w3
  char v84; // w4
  char v85; // w5

  v3 = (char *)a1;
  if ( a2 >= 1 )
  {
    v4 = a3 & 0x1000;
    v5 = a3 & 0x40;
    v6 = a3 & 2;
    v7 = a3 & 0x800;
    v8 = a3 & 0x400;
    v9 = a3 & 4;
    v10 = a3 & 0x10;
    v11 = a3 & 8;
    v12 = a3 & 0x8000;
    v13 = a3 & 0x10000;
    if ( a3 & 0x20 )
    {
      v3 = (char *)a1;
      do
      {
        v51 = *v3;
        v52 = v3[3];
        v53 = v3[4];
        *v3 = v3[1];
        v3[1] = v51;
        v54 = v3[2];
        v55 = v3[5];
        v3[2] = v52;
        v3[5] = v53;
        v3[3] = v54;
        v3[4] = v55;
        if ( v4 )
        {
          v57 = v3[6];
          v58 = v3[8];
          v59 = v3[7];
          v3[6] = v3[9];
          v60 = v3[13];
          v3[9] = v57;
          v3[7] = v58;
          v3[8] = v59;
          v61 = v3[10];
          v62 = v3[12];
          v63 = v3[11];
          v3[10] = v60;
          v64 = v3[17];
          v3[13] = v61;
          v3[11] = v62;
          v3[12] = v63;
          v65 = v3[14];
          v66 = v3[16];
          v67 = v3[15];
          v3[14] = v64;
          v56 = v3 + 18;
          v3[17] = v65;
          v3[15] = v66;
          v3[16] = v67;
        }
        else
        {
          v56 = v3 + 6;
        }
        if ( v5 )
        {
          v74 = *v56;
          v75 = v56[3];
          v76 = v56[2];
          *v56 = v56[1];
          v56[1] = v74;
          v56[2] = v75;
          v56[3] = v76;
          v56 += 4;
        }
        else if ( v6 )
        {
          v68 = *v56;
          v69 = v56[2];
          v70 = v56[1];
          *v56 = v56[3];
          v56[3] = v68;
          v56[1] = v69;
          v56[2] = v70;
          v71 = v56[4];
          v72 = v56[6];
          v73 = v56[5];
          v56[4] = v56[7];
          v56[7] = v71;
          v56[5] = v72;
          v56[6] = v73;
          v56 += 8;
        }
        if ( v7 )
        {
          v83 = *v56;
          v84 = v56[3];
          v85 = v56[2];
          *v56 = v56[1];
          v56[1] = v83;
          v56[2] = v84;
          v56[3] = v85;
          v56 += 4;
        }
        else if ( v8 )
        {
          v77 = *v56;
          v78 = v56[2];
          v79 = v56[1];
          *v56 = v56[3];
          v56[3] = v77;
          v56[1] = v78;
          v56[2] = v79;
          v80 = v56[4];
          v81 = v56[6];
          v82 = v56[5];
          v56[4] = v56[7];
          v56[7] = v80;
          v56[5] = v81;
          v56[6] = v82;
          v56 += 8;
        }
        v3 = v56 + 4;
        if ( !v9 )
          v3 = v56;
        if ( v10 )
          v3 += 4;
        if ( v11 )
          v3 += 4;
        if ( v12 )
          v3 += 8;
        if ( v13 )
          v3 += 8;
        --a2;
      }
      while ( a2 );
    }
    else
    {
      v14 = a3 & 1;
      v3 = (char *)a1;
      do
      {
        if ( v14 )
        {
          v15 = *v3;
          v16 = v3[2];
          v17 = v3[1];
          *v3 = v3[3];
          v3[3] = v15;
          v3[1] = v16;
          v3[2] = v17;
          v18 = v3[4];
          v19 = v3[6];
          v20 = v3[5];
          v3[4] = v3[7];
          v3[7] = v18;
          v3[5] = v19;
          v3[6] = v20;
          v21 = v3[8];
          v22 = v3[10];
          v23 = v3[9];
          v3[8] = v3[11];
          v3[11] = v21;
          v3[9] = v22;
          v3[10] = v23;
          v3 += 12;
        }
        if ( v4 )
        {
          v24 = *v3;
          v25 = v3[2];
          v26 = v3[1];
          *v3 = v3[3];
          v3[3] = v24;
          v3[1] = v25;
          v3[2] = v26;
          v27 = v3[4];
          v28 = v3[6];
          v29 = v3[5];
          v3[4] = v3[7];
          v3[7] = v27;
          v3[5] = v28;
          v3[6] = v29;
          v30 = v3[8];
          v31 = v3[10];
          v32 = v3[9];
          v3[8] = v3[11];
          v3[11] = v30;
          v3[9] = v31;
          v3[10] = v32;
          v3 += 12;
        }
        if ( v5 )
        {
          v39 = *v3;
          v40 = v3[3];
          v41 = v3[2];
          *v3 = v3[1];
          v3[1] = v39;
          v3[2] = v40;
          v3[3] = v41;
          v3 += 4;
        }
        else if ( v6 )
        {
          v33 = *v3;
          v34 = v3[2];
          v35 = v3[1];
          *v3 = v3[3];
          v3[3] = v33;
          v3[1] = v34;
          v3[2] = v35;
          v36 = v3[4];
          v37 = v3[6];
          v38 = v3[5];
          v3[4] = v3[7];
          v3[7] = v36;
          v3[5] = v37;
          v3[6] = v38;
          v3 += 8;
        }
        if ( v7 )
        {
          v48 = *v3;
          v49 = v3[3];
          v50 = v3[2];
          *v3 = v3[1];
          v3[1] = v48;
          v3[2] = v49;
          v3[3] = v50;
          v3 += 4;
        }
        else if ( v8 )
        {
          v42 = *v3;
          v43 = v3[2];
          v44 = v3[1];
          *v3 = v3[3];
          v3[3] = v42;
          v3[1] = v43;
          v3[2] = v44;
          v45 = v3[4];
          v46 = v3[6];
          v47 = v3[5];
          v3[4] = v3[7];
          v3[7] = v45;
          v3[5] = v46;
          v3[6] = v47;
          v3 += 8;
        }
        if ( v9 )
          v3 += 4;
        if ( v10 )
          v3 += 4;
        if ( v11 )
          v3 += 4;
        if ( v12 )
          v3 += 8;
        if ( v13 )
          v3 += 8;
        --a2;
      }
      while ( a2 );
    }
  }
  return v3 - (char *)a1;
}