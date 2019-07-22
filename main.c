#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#include "HW2.h"
#include "HW3.h"
#include "HW4.h"
#include "HW5.h"
#include "HW6.h"

int main () {
    //Test 1 task
    const int HASize = 10;
    char HashArr[HASize];
    strcpy(HashArr, "shfhefvkjbrkjwvbjskjv");
    for (int i = 0; i < HASize; i++){
        printf("%d ", HashArr[i]);
        printf("%c ", HashArr[i]);
    }
    printf("\n%d\n", HashFunc(HashArr, HASize));


    //Test 2 task
    const int BTNSize = 15;
    TREETYPE TreeArr[BTNSize];
    BTN *BTree = NULL;
    for (int i = 0; i < BTNSize; i++){
        TreeArr[i] = rand() % 25;
        BTinsert(&BTree, TreeArr[i]);
    }

    preOrderTravers(BTree);
    printf("\n");
    inOrderTravers(BTree);
    printf("\n");
    postOrderTravers(BTree);
    printf("\n%d ", BTSearch(BTree, 11)->data);
}
