//
//  main.c
//  BA_Cube_Algorithmus
//
//  Created by 杨春霞 on 20.10.15.
//  Copyright © 2015 Chunxia Yang. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include "Top_Cross.h"
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#define RUN_MACOS  1
//#define RUN_EV3    1


//0 =Weisse 1 =Balu 2 =Gelb 3 =Gruen 4 =Rot 5 =Orangen 
unsigned char color_data[6][9]={
    {5,0,5,5,0,1,3,2,1},
    {0,1,4,4,1,5,3,3,0},
    {4,5,5,4,2,5,2,4,4},
    {1,0,1,2,3,1,0,3,3},
    {2,1,5,2,4,3,4,0,1},
    {0,2,3,0,5,1,2,4,2}
};

const  char print_mode[][12][9]=
{
    {{36,37,38,27,28,29,45,46,47},
        {39,40,41,30,31,32,48,49,50},
        {42,43,44,33,34,35,51,52,53},
        {-1,-1,-1, 0, 1, 2,-1,-1,-1},
        {-1,-1,-1, 3, 4, 5,-1,-1,-1},
        {-1,-1,-1, 6, 7, 8,-1,-1,-1},
        {-1,-1,-1, 9,10,11,-1,-1,-1},
        {-1,-1,-1,12,13,14,-1,-1,-1},
        {-1,-1,-1,15,16,17,-1,-1,-1},
        {-1,-1,-1,18,19,20,-1,-1,-1},
        {-1,-1,-1,21,22,23,-1,-1,-1},
        {-1,-1,-1,24,25,26,-1,-1,-1} },
    
    {{-1,-1,-1,27,28,29,-1,-1,-1},
        {-1,-1,-1,30,31,32,-1,-1,-1},
        {-1,-1,-1,33,34,35,-1,-1,-1},
        {38,41,44, 0, 1, 2,51,48,45},
        {37,40,43, 3, 4, 5,52,49,46},
        {36,39,42, 6, 7, 8,53,50,47},
        {-1,-1,-1, 9,10,11,-1,-1,-1},
        {-1,-1,-1,12,13,14,-1,-1,-1},
        {-1,-1,-1,15,16,17,-1,-1,-1},
        {-1,-1,-1,18,19,20,-1,-1,-1},
        {-1,-1,-1,21,22,23,-1,-1,-1},
        {-1,-1,-1,24,25,26,-1,-1,-1} },
    
    {{-1,-1,-1,27,28,29,-1,-1,-1},
        {-1,-1,-1,30,31,32,-1,-1,-1},
        {-1,-1,-1,33,34,35,-1,-1,-1},
        {-1,-1,-1, 0, 1, 2,-1,-1,-1},
        {-1,-1,-1, 3, 4, 5,-1,-1,-1},
        {-1,-1,-1, 6, 7, 8,-1,-1,-1},
        {44,43,42, 9,10,11,53,52,51},
        {41,40,39,12,13,14,50,49,48},
        {38,37,36,15,16,17,47,46,45},
        {-1,-1,-1,18,19,20,-1,-1,-1},
        {-1,-1,-1,21,22,23,-1,-1,-1},
        {-1,-1,-1,24,25,26,-1,-1,-1} },
    
    {{-1,-1,-1,27,28,29,-1,-1,-1},
        {-1,-1,-1,30,31,32,-1,-1,-1},
        {-1,-1,-1,33,34,35,-1,-1,-1},
        {-1,-1,-1, 0, 1, 2,-1,-1,-1},
        {-1,-1,-1, 3, 4, 5,-1,-1,-1},
        {-1,-1,-1, 6, 7, 8,-1,-1,-1},
        {-1,-1,-1, 9,10,11,-1,-1,-1},
        {-1,-1,-1,12,13,14,-1,-1,-1},
        {-1,-1,-1,15,16,17,-1,-1,-1},
        {42,39,36,18,19,20,47,50,53},
        {43,40,37,21,22,23,46,49,52},
        {44,41,38,24,25,26,45,48,51} },            //print_mode
    
};

int main(void)
{
    set_conio_terminal_mode();
    wuerfel_print(1);
    Top_Cross();
    
    while(1)
    {
        if(kbhit())
        {
            switch(getch())
            {
                case 'q':
                case 'Q':
                    return 0;
  
                case '0':
                    wuerfel_print(0);
                    break;
                case '1':
                    wuerfel_print(1);
                    break;
                case '2':
                    wuerfel_print(2);
                    break;
                case '3':
                    wuerfel_print(3);
                    break;
                    
            }
        }
        
    }
}


int Kantenstein_suchen(int Color1,int Color2)
{
    int kantPos=0; //kantPos=100*Schicht+10*ErsteCentrale+zweiteCentrale
    int c1=0,c2=0;
    
    //Erste_schicht
    c1= color_data[0][1]; c2= color_data[3][7];
    if (c1==Color1 && c2==Color2) {kantPos=103;}//weiss_Grün Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=130;}
    c1= color_data[0][3]; c2= color_data[4][7];
    if (c1==Color1 && c2==Color2) {kantPos=104;}//weiss_Rot Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=140;}
    c1= color_data[0][5]; c2= color_data[5][7];
    if (c1==Color1 && c2==Color2) {kantPos=105;}//weiss_Orange Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=150;}
    c1= color_data[0][7]; c2= color_data[1][1];
    if (c1==Color1 && c2==Color2) {kantPos=101;}//weiss_Blau Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=110;}
    
    
    //Zweite_schicht
    c1= color_data[4][3]; c2= color_data[1][3];
    if (c1==Color1 && c2==Color2) {kantPos=241;}//Rot_Blau Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=214;}
    c1= color_data[1][5]; c2= color_data[5][5];
    if (c1==Color1 && c2==Color2) {kantPos=215;}//Blau_Orange Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=251;}
    c1= color_data[5][3]; c2= color_data[3][5];
    if (c1==Color1 && c2==Color2) {kantPos=253;}//Orange_Grün Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=235;}
    c1= color_data[3][3]; c2= color_data[4][5];
    if (c1==Color1 && c2==Color2) {kantPos=234;}//Grün_Rot Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=243;}
    
    
    //Dritte_schicht
    c1= color_data[1][7]; c2= color_data[2][1];
    if (c1==Color1 && c2==Color2) {kantPos=312;}//Blau_Gelb Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=321;}
    c1= color_data[5][1]; c2= color_data[2][5];
    if (c1==Color1 && c2==Color2) {kantPos=352;}//Orange_Gelb Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=325;}
    c1= color_data[3][1]; c2= color_data[2][7];
    if (c1==Color1 && c2==Color2) {kantPos=332;}//Grün_Gelb Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=323;}
    c1= color_data[4][1]; c2= color_data[2][3];
    if (c1==Color1 && c2==Color2) {kantPos=342;}//Rot_Gelb Kantenstein
    if (c1==Color2 && c2==Color1) {kantPos=324;}
    
    return kantPos;
}


int Mittelstein_suchen(int Color)
{
    int i;
    int c1=0,Centrale=6;
    for (i=0; i<=5; i++) {
        c1= color_data[i][4];
        if(c1==Color) Centrale=i;
    }
    return Centrale;
}


int Eckenstein_suchen(int Color1, int Color2, int Color3 )
{
    int eckPos=0; //EckPos= 1000*Schicht+100*ErsteCenterale+10*zweiteCenterale+dritteCentrale
    int Color_eck=100*Color1+10*Color2+Color3;
    
    //Erste Schichte
    if (Color_eck== 100*color_data[0][0]+10*color_data[4][8]+color_data[3][6])
        eckPos=1000*1+100*0+10*4+3;
    if (Color_eck== 100*color_data[0][2]+10*color_data[3][8]+color_data[5][6])
        eckPos=1000*1+100*0+10*3+5;
    if (Color_eck== 100*color_data[0][8]+10*color_data[5][8]+color_data[1][2])
        eckPos=1000*1+100*0+10*5+1;
    if (Color_eck== 100*color_data[0][6]+10*color_data[1][0]+color_data[4][6])
        eckPos=1000*1+100*0+10*1+4;
    
    //Zweite Schichte
    if (Color_eck== 100*color_data[2][0]+10*color_data[1][6]+color_data[4][0])
        eckPos=1000*3+100*2+10*1+4;
    if (Color_eck== 100*color_data[2][2]+10*color_data[1][8]+color_data[5][2])
        eckPos=1000*3+100*2+10*1+5;
    if (Color_eck== 100*color_data[2][8]+10*color_data[5][0]+color_data[3][2])
        eckPos=1000*3+100*2+10*5+3;
    if (Color_eck== 100*color_data[2][6]+10*color_data[4][2]+color_data[3][0])
        eckPos=1000*3+100*2+10*4+3;
    
    return eckPos;
    
}


struct termios orig_termios;

void reset_terminal_mode()
{
    tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
    struct termios new_termios;
    
    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));
    
    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}



int kbhit()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int getch()
{
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

void wuerfel_print(int mode)
{
    
    int zeile;
    int spalte;
    
    setenv("XcodeColor", "YES", 0);
    
    printf("\n");
    for(zeile=0;zeile<12;zeile++)
    {
        for(spalte=0;spalte<9;spalte++)
        {
            char tmp=print_mode[mode][zeile][spalte];
            if(tmp==-1)
                printf("   ");
            else
                switch(color_data[tmp/9][tmp%9])
            {
#ifdef RUN_MACOS
                case 0:
                    printf("\033[fg0,0,0;   %d\033[;",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 1:
                    printf("\033[fg0,0,255;   %d\033[;",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 2:
                    printf("\033[fg255,255,0;   %d\033[;",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 3:
                    printf("\033[fg0,255,0;   %d\033[;",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 4:
                    printf("\033[fg255,0,0;   %d\033[;",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 5:
                    printf("\033[fg255,97,0;   %d\033[;",color_data[tmp/9][tmp%9]);
                    break;
#endif
#ifdef RUN_EV3
                case 0:
                    printf("\033[1;30m   %d\033[0m",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 1:
                    printf("\033[1;34m   %d\033[0m",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 2:
                    printf("\033[1;33m   %d\033[0m",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 3:
                    printf("\033[1;32m   %d\033[0m",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 4:
                    printf("\033[1;35m   %d\033[0m",color_data[tmp/9][tmp%9]);
                    break;
                    
                case 5:
                    printf("\033[1;31m   %d\033[0m",color_data[tmp/9][tmp%9]);
                    break;
#endif
            }
        }
        printf("\n\r");
    }
}

