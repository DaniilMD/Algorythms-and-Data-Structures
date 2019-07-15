// Дементьев Д.М.

#include <stdio.h>
#include <stdlib.h>

const int NO_COINC = -1;

void swap(int *a, int *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void fillArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++)
	arr[i] = rand() % 100;
}

void printArray(int* arr, int  len) {
  int i;
  for (i = 0; i < len; i++)
	  printf("%d ", arr[i]);
  printf("\n");
}


//Задание 1. Оптимизировать пузырьковую сортировку.
//Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
//Написать функции сортировки, которые возвращают количество операций.
int bubbleSort(int* arr, int len) {
  int i;
  int j;
  int counter = 0;
  for (i = 0; i < len; i++)
	  for (j = 0; j < len - 1; j++) {
		  if (arr[j] > arr[j + 1]) {
			  swap(&arr[j], &arr[j + 1]);
		  }
		  counter++;
	  }
  return counter;
}

int HastenedBubbleSort(int* arr, int len) {
  int i;
  int j;
  int Len2 = len;
  int counter = 0;
  for (i = 0; i < len; i++) {
	  for (j = 0; j < Len2 - 1; j++) {
		  if (arr[j] > arr[j + 1]) {
			  swap(&arr[j], &arr[j + 1]);
		  }
		  counter++;
	  }
	  Len2--;
  }
  return counter;
}


//Задание 2. Рекурсивное решение задачи линейного поиска.
int recurLinear(int *arr, int len, int searchNum, int arrNum, int *counter) {
	if (arrNum == len) {
		++*counter;
		return NO_COINC;
	} else {
		++*counter;
		if (arr[arrNum] == searchNum) {
			return arrNum;
		} else {
			return recurLinear(arr, len, searchNum,  ++arrNum, counter);
		}
	}
}

//Задание 3. *Реализовать шейкерную сортировку.
int ShakerSort(int* arr, int len) {
  int i;
  int j;
  int right = len - 1;
  int left = 0;
  int counter = 0;
  for (i = 0; i < len / 2; i++) {
	  for (j = left; j < right; j++) {
		  if (arr[j] > arr[j + 1]) {
			  swap(&arr[j], &arr[j + 1]);
		  }
		  counter++;
	  }
	  right--;

	  for (j = right; j > left; j--) {
		  if (arr[j - 1] > arr[j]) {
			  swap(&arr[j - 1], &arr[j]);
		  }
		  counter++;
	  }
	  left++;
  }
  return counter;
}
