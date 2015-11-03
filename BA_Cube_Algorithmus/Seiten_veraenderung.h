//
//  Seiten_veraenderung.h
//  BA_Cube_Algorithmus
//
//  Created by 杨春霞 on 26.10.15.
//  Copyright © 2015 Chunxia Yang. All rights reserved.
//

#ifndef Seiten_veraenderung_h
#define Seiten_veraenderung_h

#include <stdio.h>

#endif /* Seiten_veraenderung_h */

void change_topface(int center_color);
void change_rightface(int rightface);
void change_backface(int backface);
void klappen();
void drehen_unter(int dir);
void drehen(int dir);
void us_dreh(int dir,int dreh_Angel_u);
void ds_dreh(int dir,int dreh_Angel_d);
void fs_dreh(int dir,int dreh_Angel_f);
void bs_dreh(int dir,int dreh_Angel_b);
void ls_dreh(int dir,int dreh_Angel_l);
void rs_dreh(int dir,int dreh_Angel_r);
