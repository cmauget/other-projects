#ifndef _BCK_
#define _BCK_
#include "uses_fonc.h"
#include "Types.h"

int backtrack_recursive(GRAPH g , int k, int s);

int backtrack_color(GRAPH g, int k);

int checkColor(int s, GRAPH g, int c);

void affichecolor(GRAPH graph);



#endif
