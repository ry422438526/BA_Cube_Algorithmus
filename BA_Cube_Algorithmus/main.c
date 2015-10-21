//
//  main.c
//  BA_Cube_Algorithmus
//
//  Created by 杨春霞 on 20.10.15.
//  Copyright © 2015 Chunxia Yang. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>


//0- weiss 1-blau 2-gelb 3-gruen 4-rot 5-orga
unsigned char color_data[6][9]=
{
    
    
    {0,0,0,0,0,0,0,0,0 },  //0
    {1,1,1,1,1,1,1,1,1 },
    {2,2,2,2,2,2,2,2,2 },
    {3,3,3,3,3,3,3,3,3 },
    {4,4,4,4,4,4,4,4,4 },
    {5,5,5,5,5,5,5,5,5 }                               //initialisieren color_data
    
    //    {0,0,3,0,0,3,0,0,3 },  //0
    //    {1,1,0,1,1,0,1,1,0 },
    //    {2,2,1,2,2,1,2,2,1 },
    //    {3,3,2,3,3,2,3,3,2 },
    //    {4,4,4,4,4,4,4,4,4 },
    //    {5,5,5,5,5,5,5,5,5 }
    /*      {0,0,0,0,0,0,0,0,0 },  //0
     {5,5,5,1,1,1,1,1,1 },  //1
     {2,2,2,2,2,2,2,2,2 },  //2
     {3,3,3,3,3,3,4,4,4 },  //3
     {4,4,4,4,4,4,1,1,1 },  //4
     {5,5,5,5,5,5,3,3,3 }   //5
     */
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
                printf("    ");
            else
                switch(color_data[tmp/9][tmp%9])
            {
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
            }
        }
        printf("\n\r");
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
    //{0ol,0om,0or,0ml,0mm,0mr,0ul,0um,0ur }, weiss {0ol,0om,0or,0ml,0mm,0mr,0ul,0um,0ur }
    //{1ol,1om,1or,1ml,1mm,1mr,1ul,1um,1ur }, blau  {1ol,1om,1or,1ml,1mm,1mr,4ul,4um,4ur }
    //{2ol,2om,2or,2ml,2mm,2mr,2ul,2um,2ur }, gelb  {2ul,2ml,2ol,2um,2mm,2om,2ur,2mr,2or }
    //{3ol,3om,3or,3ml,3mm,3mr,3ul,3um,3ur }, grue  {3ol,3om,3or,3ml,3mm,3mr,5ul,5um,5ur }
    //{4ol,4om,4or,4ml,4mm,4mr,4ul,4um,4ur }, rot   {4ol,4om,4or,4ml,4mm,4mr,3ul,3um,3ur }
    //{5ol,5om,5or,5ml,5mm,5mr,5ul,5um,5ur }  oran  {5ol,5om,5or,5ml,5mm,5mr,1ul,1um,1ur }
    int i,j,k;
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


void wuefel_dreh(int achse,int dir)
{
    switch (achse)
    {
        case 0:
            klappen();
            klappen();
            drehen_unter(dir);
            break;
        case 1:
            drehen(1);
            klappen();
            drehen_unter(dir);
            break;
        case 2:
            drehen_unter(dir);
            break;
        case 3:
            drehen(-1);
            klappen();
            drehen_unter(dir);
            break;
        case 4:
            klappen();
            drehen_unter(dir);
            break;
        case 5:
            klappen();
            klappen();
            klappen();
            drehen_unter(dir);
            break;
            
        default:
            break;
    }
    
}




int main(void)
{
    
    //  color_arrary(color_data);
    set_conio_terminal_mode();
    
    while(1)
    {
        if(kbhit())
        {
            switch(getch())
            {
                case 'q':
                case 'Q':
                    return 0;
                    
                case 'w':
                    wuefel_dreh(0,1);
                    break;
                case 'W':
                    wuefel_dreh(0,-1);
                    break;
                case 'b':
                    wuefel_dreh(1,1);
                    break;
                case 'B':
                    wuefel_dreh(1,-1);
                    break;
                case 'y':
                    wuefel_dreh(2,1);
                    break;
                case 'Y':
                    wuefel_dreh(2,-1);
                    break;
                case 'g':
                    wuefel_dreh(3,1);
                    break;
                case 'G':
                    wuefel_dreh(3,-1);
                    break;
                case 'r':
                    wuefel_dreh(4,1);
                    break;
                case 'R':
                    wuefel_dreh(4,-1);
                    break;
                case 'o':
                    wuefel_dreh(5,1);
                    break;
                case 'O':
                    wuefel_dreh(5,-1);
                    break;
                    
                    
                    
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
