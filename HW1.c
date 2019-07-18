#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "HW2.h"
#include "HW3.h"
#include "HW4.h"

// Задание 1
double MassIndexCounter(double m, double h) {

    return m / (h * h);
}

// Задание 2
int calculateSquareEquation(int a, int b, int c, double* x1, double* x2) {
    int D = (b*b - 4*a*c);
    double sqrtD = sqrt(D);
    if (D > 0) {
        *x1 = ((-b + sqrtD) / (2*a));
        *x2 = ((-b - sqrtD) / (2*a));
        return 1; // 2 корня
    } else if (D == 0) {
        *x1 = *x2 = ((-b + sqrtD) / (2*a));
        return 0; // 1 корень
    } else {
        return -1; // нет корней
    }
}

// Задание 3
void AgeAnalysis(int age) {
    if ((((age % 10) >= 5) && ((age % 10) <= 9)) || ((age % 10) == 0) ){
        printf("%d лет\n", age);
    } else if (((age % 100) >= 11) && ((age % 100) <= 19))  {
        printf("%d лет\n", age);
    } else if ((age % 10) == 1) {
        printf("%d год\n", age);
    } else {
        printf("%d года\n", age);
    }

}


//Задание 4

int ColourEquality(int x1, int y1, int x2, int y2) {
	if ((x1 % 2) == (y1 % 2)) {
		if (((x2 % 2) == (y2 % 2))) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if (((x2 % 2) != (y2 % 2))) {
				return 1;
			} else {
				return 0;
		}
	}
}


// Задание 5

void AutomorphicNumber() {
	int num;
	int counter;
	int b;

	for (int i = 0; i < 10000; i++) {
		num = i;
		counter = 0;
		while (num != 0) {
			num /= 10;
			counter++;
		}

		b = 10;

		for (int j = 1; j < counter; j++) {
			b *= 10;
		}


		if (((i * i - i) % b) == 0) {
			printf("%d\n", i);
		}
	}
}


int main () {

	/*
	// Test 1 task
    printf("%.2f\n", MassIndexCounter(60, 1.85));


    //Test 2 task
    double X1, X2;
    int indicator = calculateSquareEquation(1, 5, 2, &X1, &X2);
    if (indicator == 1) {
        printf("В вашем уравнении 2 действительных корня: x1 = %f, x2 = %f\n", X1, X2);
    } else if (indicator == 0) {
        printf("В вашем уравнении 1 действительный корень кратности 2: x1 = x2 = %f\n", X1);
    } else {
        printf("В вашем уравнении нет действительных корней\n");
    }


    //Test 3 task
    for (int i = 1; i <= 150; i++) {
        AgeAnalysis(i);
    }


    //Test 4 task
    printf("Если 1, то одинаковые цвета, если 0, то разные: %d\n", ColourEquality(5, 5, 2, 3));


    //Test 5 task
    printf("Автоморфные числа от 0 до 10000:\n");
    AutomorphicNumber();
	*/


	//Test 1 task
	long long Dec = 0;
    TransformDecIntoBin(12443, &Dec, 0);
    printf("%I64d\n", Dec);


    //Test 2 task b)
    printf("%d\n", Involution(2, 10));


    //Test 2 task c)
    printf("%d\n", Power(4, 4));



    //Test 3 task
    int NumOfVar = 0;
    VariantCounter(3, 20, &NumOfVar);
    printf("%d\n", NumOfVar);



    const int SIZE = 52;
    int arr[SIZE];

    /*fillArray(arr, SIZE);
    printArray(arr, SIZE);
    printf("Amount of bubbleSort operations: %d\n",  bubbleSort(arr, SIZE));
    printArray(arr, SIZE);
    printf("\n");

    fillArray(arr, SIZE);
    printArray(arr, SIZE);
    printf("Amount of HastenedBubbleSort operations: %d\n",  HastenedBubbleSort(arr, SIZE));
    printArray(arr, SIZE);
    printf("\n");

    int counter = 0;
    int searchNum = 50;
    fillArray(arr, SIZE);
    printArray(arr, SIZE);
    printf("The index of looked for number: %d\n",  recurLinear(arr, SIZE, searchNum, 0, &counter));
    printf("Amount of recurLinear operations: %d\n",  counter);
    printf("\n");

    fillArray(arr, SIZE);
	printArray(arr, SIZE);
	printf("Amount of ShakerSort operations: %d\n",  ShakerSort(arr, SIZE));
	printArray(arr, SIZE);
	printf("\n");*/

    //Task 3
	fillArray(arr, SIZE);
	printArray(arr, SIZE);
	HastenedBubbleSort(arr, SIZE);
	printArray(arr, SIZE);
	printf("The index of looked for number: %d\n", RecurBinarySearch(arr, SIZE, 27));

	//Task 1
	const int NoOfBlocks = 3;
	const int BoardX = 8;
	const int BoardY = 8;
	int Blocks[] = {5, 1, 4, 4, 7, 6};
	for (int i = 0; i < BoardX; i++) {
		for (int j = 0; j < BoardY; j++) {
			printf("%5d", RoutesForKingWithBlocks(i, j, NoOfBlocks, Blocks));
		}
   		printf("\n");
    }


	//Task 2
	annull();
	horses(1, -1, -2);
	printBoard();
}
