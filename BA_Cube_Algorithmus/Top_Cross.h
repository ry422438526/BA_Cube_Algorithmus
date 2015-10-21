//
//  Top_Cross.h
//  BA_Cube_Algorithmus
//
//  Created by 杨春霞 on 20.10.15.
//  Copyright © 2015 Chunxia Yang. All rights reserved.
//

#ifndef Top_Cross_h
#define Top_Cross_h

#include <stdio.h>

#endif /* Top_Cross_h */
typedef enum
{
    WEISS=0,
    BLAU=1,
    GELB=2,
    GRUEN=3,
    ROT=4,
    ORANGE=5
} COLOR;

char color_data[6][9]={
    {5,0,5,5,0,1,3,2,1},
    {0,1,4,4,1,5,3,3,0},
    {4,5,5,4,2,5,2,4,4},
    {1,0,1,2,3,1,0,3,3},
    {2,1,5,2,4,3,4,0,1},
    {0,2,3,0,5,1,2,4,2}
};

int Top_cross()
{
    
}