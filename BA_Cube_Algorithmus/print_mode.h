//
//  print_mode.h
//  BA_Cube_Algorithmus
//
//  Created by 杨春霞 on 26.10.15.
//  Copyright © 2015 Chunxia Yang. All rights reserved.
//

#ifndef print_mode_h
#define print_mode_h

#include <stdio.h>

void reset_terminal_mode();
void set_conio_terminal_mode();
int kbhit();
int getch();
void wuerfel_print(int mode);

#endif /* print_mode_h */
