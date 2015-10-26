//
//  Top_Cross.c
//  BA_Cube_Algorithmus
//
//  Created by 杨春霞 on 20.10.15.
//  Copyright © 2015 Chunxia Yang. All rights reserved.
//

#include <stdio.h>
#include "Top_Cross.h"
#include "Seiten_veraenderung.h"

int Top_Cross()
{
    int Getpos=0;
    int color_kanten[4]={1,4,3,5};
    int i;
    
    for(i=0;i<=3;i++)
    {
        change_topface(0);
        change_rightface(i);
        Getpos=Kantenstein_suchen(0, color_kanten[i]);
        switch (Getpos) {
            case 103:
                us_dreh(1, 90);
                break;
            case 130:
                bs_dreh(-1, 90);
                bs_dreh(-1, 90);
                break;
            case 104:
                us_dreh(1, 180);    //obere Seite zwei mal im gegenuhrzeigersinn drehen
                break;
            case 140:
                ls_dreh(1, 90);
                fs_dreh(-1, 90);
                bs_dreh(-1, 90);
                break;
            case 105:
                break;
            case 150:
                us_dreh(-1, 90);
                ls_dreh(-1, 90);
                fs_dreh(-1, 90);
                break;
            case 101:
                us_dreh(-1, 90);
                break;
            case 110:
                fs_dreh(1, 90);
                fs_dreh(1, 90);
                break;
            case 241:
                fs_dreh(1, 90);
                ls_dreh(-1, 90);
                break;
            case 214:
                fs_dreh(1, 180);
                fs_dreh(1, 90);
                break;
            case 215:
                rs_dreh(1, 90);
                break;
            case 251:
                fs_dreh(-1, 90);
                ls_dreh(-1, 90);
                break;
            case 253:
                rs_dreh(-1, 90);
                break;
            case 235:
                bs_dreh(1, 90);
                ls_dreh(1, 90);
                break;
            case 234:
                bs_dreh(-1, 90);
                bs_dreh(-1, 90);
                break;
            case 243:
                bs_dreh(-1, 90);
                ls_dreh(1, 90);
                break;
            case 312:
                fs_dreh(-1, 90);
                fs_dreh(1, 90);
                break;
            case 321:
                us_dreh(1, 90);
                rs_dreh(1, 180);
                break;
            case 352:
                ds_dreh(-1, 90);
                fs_dreh(-1, 90);
                fs_dreh(1, 90);
                break;
            case 325:
                rs_dreh(1, 180);
                break;
            case 323:
                ds_dreh(-1, 90);
                rs_dreh(-1, 180);
                break;
            case 332:
                bs_dreh(1, 90);
                bs_dreh(-1, 90);
                break;
            case 342:
                ds_dreh(1, 90);
                fs_dreh(-1, 90);
                fs_dreh(1, 90);
                break;
            case 324:
                ds_dreh(1, 180);
                rs_dreh(1, 180);
                break;
            default:
                break;
        }
    }
    return 0;
}