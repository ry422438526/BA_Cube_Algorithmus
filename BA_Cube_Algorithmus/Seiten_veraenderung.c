//
//  Seiten_veraenderung.c
//  BA_Cube_Algorithmus
//
//  Created by 杨春霞 on 26.10.15.
//  Copyright © 2015 Chunxia Yang. All rights reserved.
//

#include "Seiten_veraenderung.h"
#include <stdio.h>
#include "main.h"



void change_topface(int center_color)
{   int i;
    for (i=0; i<=5; i++) {
        if (color_data[i][4]==center_color)
        {
            switch (i) {
                case 0://ober Seite
                    break;
                case 1://vorne Seite
                    drehen(-1);
                    klappen();
                    break;
                case 2://untere Seite
                    klappen();
                    klappen();
                    break;
                case 3://hintere Seite
                    drehen(1);
                    klappen();
                    break;
                case 4://linke Seite
                    klappen();
                    klappen();
                    klappen();
                    break;
                case 5://rechte Seite
                    klappen();
                    break;
                    
                default:
                    break;
            }
        }
    }
}

void change_rightface(int rightface)
{
    int i;
    for (i=0; i<=5; i++) {
        if (color_data[i][4]==rightface) {
            switch (i) {
             case 1://vorne Seite
                   drehen(-1);
                   break;
             case 3://hintere Seite
                   drehen(1);
                   break;
             case 4://linke Seite
                   drehen(1);
                   drehen(1);
                   break;
        default:
            break;
            }
        }
    }
}


void klappen()
{
    int i,j;
    unsigned char temp_color_data[6][9];
    for(i=0;i<3;i++)
    {
        for (j=0; j<3; j++)
        {
            temp_color_data[1][3*i+j]=color_data[1][3*j+(2-i)]; //
            temp_color_data[3][3*i+j]=color_data[3][3*(2-j)+i]; //
            temp_color_data[5][3*i+j]=color_data[2][3*(2-j)+i]; //
            temp_color_data[2][3*(2-j)+i]=color_data[4][3*(2-i)+(2-j)];//
            temp_color_data[4][3*(2-i)+(2-j)]=color_data[0][3*j+(2-i)];//
            temp_color_data[0][3*j+(2-i)]=color_data[5][3*i+j];//
        }
    }
    
    int a,b;
    for (a=0;a<6;a++)
    {
        for (b=0;b<9;b++)
        {
            color_data[a][b]=temp_color_data[a][b];
        }
    }
    
}

void drehen_unter(int dir)
{
    int i,j;
    unsigned char temp_color_data[6][9];
    if (dir==1)
    {
        for(i=0;i<3;i++)
        {
            temp_color_data[5][3*0+i]=color_data[1][3*2+(2-i)];
            temp_color_data[5][3*1+i]=color_data[5][3*1+i];
            temp_color_data[5][3*2+i]=color_data[5][3*2+i];
            
            temp_color_data[1][3*0+i]=color_data[1][3*0+i];
            temp_color_data[1][3*1+i]=color_data[1][3*1+i];
            temp_color_data[1][3*2+(2-i)]=color_data[4][3*0+i];
            
            temp_color_data[4][3*0+i]=color_data[3][3*0+i];
            temp_color_data[4][3*1+i]=color_data[4][3*1+i];
            temp_color_data[4][3*2+i]=color_data[4][3*2+i];
            
            temp_color_data[3][3*0+i]=color_data[5][3*0+i];
            temp_color_data[3][3*1+i]=color_data[3][3*1+i];
            temp_color_data[3][3*2+i]=color_data[3][3*2+i];
            
            for (j=0; j<3; j++) {
                temp_color_data[2][3*i+j]=color_data[2][3*(2-j)+i];
                temp_color_data[0][3*i+j]=color_data[0][3*i+j];
            }
        }
    }
    else
    {
        for(i=0;i<3;i++)
        {
            temp_color_data[5][3*0+i]=color_data[3][3*0+i];
            temp_color_data[5][3*1+i]=color_data[5][3*1+i];
            temp_color_data[5][3*2+i]=color_data[5][3*2+i];
            
            temp_color_data[3][3*0+i]=color_data[4][3*0+i];
            temp_color_data[3][3*1+i]=color_data[3][3*1+i];
            temp_color_data[3][3*2+i]=color_data[3][3*2+i];
            
            temp_color_data[4][3*0+i]=color_data[1][3*2+2-i];
            temp_color_data[4][3*1+i]=color_data[4][3*1+i];
            temp_color_data[4][3*2+i]=color_data[4][3*2+i];
            
            temp_color_data[1][3*0+i]=color_data[1][3*0+i];
            temp_color_data[1][3*1+i]=color_data[1][3*1+i];
            temp_color_data[1][3*2+2-i]=color_data[5][3*0+i];
            
            for (j=0; j<3; j++)
            {
                temp_color_data[2][3*i+j]=color_data[2][3*j+(2-i)];
                temp_color_data[0][3*i+j]=color_data[0][3*i+j];
            }
        }
        
    }
    
    int a,b;
    for (a=0;a<6;a++)
    {
        for (b=0;b<9;b++)
        {
            color_data[a][b]=temp_color_data[a][b];
        }
    }
}

void drehen(int dir)
{
    int i,j;
    unsigned char temp_color_data[6][9];
    if(dir==1)
    {
        for (i=0; i<3; i++) {
            for (j=0; j<3; j++) {
                temp_color_data[0][3*i+j]=color_data[0][3*(2-j)+i];
                temp_color_data[2][3*i+j]=color_data[2][3*j+(2-i)];
                temp_color_data[4][3*i+j]=color_data[1][3*(2-i)+(2-j)];
                temp_color_data[1][3*(2-i)+(2-j)]=color_data[5][3*i+j];
                temp_color_data[5][3*i+j]=color_data[3][3*i+j];
                temp_color_data[3][3*i+j]=color_data[4][3*i+j];
            }
        }
    }else{
        for (i=0; i<3; i++) {
            for (j=0; j<3; j++) {
                temp_color_data[0][3*i+j]=color_data[0][3*j+(2-i)];
                temp_color_data[2][3*i+j]=color_data[2][3*(2-j)+i];
                temp_color_data[5][3*i+j]=color_data[1][3*(2-i)+(2-j)];
                temp_color_data[1][3*(2-i)+(2-j)]=color_data[4][3*i+j];
                temp_color_data[4][3*i+j]=color_data[3][3*i+j];
                temp_color_data[3][3*i+j]=color_data[5][3*i+j];
            }
        }
    }
    int a,b;
    for (a=0;a<6;a++)
    {
        for (b=0;b<9;b++)
        {
            color_data[a][b]=temp_color_data[a][b];
        }
    }
}
void us_dreh(int dir,int dreh_Angel_u)                        //Oben_Seite
{
    int i;
    klappen();
    klappen();
    for (i=0;i<dreh_Angel_u/90; i++) {
        drehen_unter(dir);
    }
}

void ds_dreh(int dir,int dreh_Angel_d)                        //Untern_Seite
{
    int i;
    for (i=0;i<dreh_Angel_d/90; i++) {
        drehen_unter(dir);
    }
}

void fs_dreh(int dir,int dreh_Angel_f)                          //vornen_Seite
{
    
    int i;
    drehen(1);
    klappen();
    for (i=0; i<=dreh_Angel_f/90; i++) {
        drehen_unter(dir);
    }
}

void bs_dreh(int dir,int dreh_Angel_b)                         //hinteren_Seite
{
    int i;
    drehen(-1);
    klappen();
    for (i=0; i<dreh_Angel_b/90; i++) {
        drehen_unter(dir);
    }
    
}

void ls_dreh(int dir,int dreh_Angel_l)                         //linken_Seite
{
    int i;
    klappen();
    for (i=0; i<dreh_Angel_l/90; i++) {
        drehen_unter(dir);
    }
}

void rs_dreh(int dir,int dreh_Angel_r)                         //rechten_Seite
{
    int i;
    klappen();
    klappen();
    klappen();
    for (i=0;i<dreh_Angel_r/90; i++) {
        drehen_unter(dir);
    }
}


