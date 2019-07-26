#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#include "HW2.h"
#include "HW3.h"
#include "HW4.h"
//#include "HW5.h"
#include "HW6.h"
#include "HW7.h"

int main () {

//Test 1 task
    GraphNode GN[GNAm + 1];
    for (int i = 0; i < GNAm + 1; i++) {
        GN[i]->data = i;
        GN[i]->used = 0;
        GN[i]->index = i;
    }
    AdjMatrix[1][2] = AdjMatrix[2][1] = 1;
    AdjMatrix[1][4] = AdjMatrix[4][1] = 1;
    AdjMatrix[3][4] = AdjMatrix[4][3] = 1;
    AdjMatrix[4][5] = AdjMatrix[5][4] = 1;
    AdjMatrix[2][5] = AdjMatrix[5][2] = 1;

    for (int i = 0; i < GNAm + 1; i++) {
        GN[i]->children = AdjMatrix[i]
    }

    widthTravers(GN[1], GN[5])

//Test 2 task
    for (int i = 0; i < GNAm + 1; i++) {
        GN[i]->used = 0;
    }
    RecurDepthTravers(GN[1], GN[5]);

//Test 3 task
    printf("\n%d\n", lee(1, 1, 10 , 10));
    for (int i = 0; i < len; i++) {
        printf("%d %d\n", pointX[i], pointY[i]);
    }
}
