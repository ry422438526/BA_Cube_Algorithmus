//
//  F2L.c
//  BA_Cube_Algorithmus
//
//  Created by 杨春霞 on 28.10.15.
//  Copyright © 2015 Chunxia Yang. All rights reserved.
//

#include "F2L.h"
#include "Color_search.h"
#include "Seiten_veraenderung.h"


int F2L(){
    int Getpos_e=0;
    int Getpos_k=0;
    int color_ecken[4]={1,5,3,4};
    int i;
    for (i=0; i<=3; i++) {
        change_topface(2);
        change_rightface(color_ecken[i]);
        Getpos_e=Eckenstein_suchen(0, color_ecken[(i+1)%4], color_ecken[i%4]);
        Getpos_k=Kantenstein_suchen(color_ecken[(i+1)%4], color_ecken[i%4]);
        
        
    }
    
    
    return 0;
}

int basis1()
{
    int Getpos_e=0;
    int Getpos_k=0;
    if(Getpos_e==1510 && Getpos_k==103)
    {
        rs_dreh(1, 90);
        ls_dreh(1,90);
        fs_dreh(-1, 90);
    }
    return 0;
}

int basis2()
{
    int Getpos_e=0;
    int Getpos_k=0;
    if(Getpos_e==1105&&Getpos_k==140)
    {
        fs_dreh(-1, 90);
        ls_dreh(-1,90);
        ds_dreh(1, 90);
    }
    return 0;
}

int basis3()
{
    int Getpos_e=0;
    int Getpos_k=0;
    if (Getpos_e== 1510 && Getpos_k==110) {
        us_dreh(-1, 90);
        fs_dreh(-1, 90);
        ds_dreh(1, 90);
        fs_dreh(1, 90);
    }
    return 0;
}

int basis4()
{
    int Getpos_e=0;
    int Getpos_k=0;
    if (Getpos_e==1105 && Getpos_k==105) {
        us_dreh(1, 90);
        ls_dreh(1, 90);
        rs_dreh(-1, 90);
        rs_dreh(-1, 90);
    }
    return 0;
}


