#ifndef HW4_H_
#define HW4_H_

#define X 8
#define Y 8
#define QUEENS 8
#define HTURNS X * Y

//Дементьев. Д.М.
//Задание 3. Рекурсивное решение бинарного поиска.

int HelpRBS(int* arr, int len, int LookedNum, int left, int right) {
	int mid = (left + right) / 2;
	if (((right - left) > 1) && (arr[mid] != LookedNum)) {
		if (arr[mid] < LookedNum)
			left = mid;
		else
			right = mid;
		return HelpRBS(arr, len, LookedNum, left, right);
	} else if (arr[mid] == LookedNum) {
		return mid;
	} else {
		return -1;
	}

}

int RecurBinarySearch(int* arr, int len, int LookedNum) {
	int left = 0;
	int right = len - 1;
	int mid = (left + right) / 2;

	if (arr[mid] == LookedNum)
		return mid;
	else if (arr[mid] < LookedNum)
		left = mid;
	else
		right = mid;

	return HelpRBS(arr, len, LookedNum, left, right);
}


//Задание 1. * Найти количество маршрутов шахматного короля на поле с препятствиями.

int RoutesForKingWithBlocks(int x, int y, int NoOfBlocks, int* arrBlocks) {
	if (x == 0 || y == 0)
		return 1;
	else {
		int indicator = 0;
		for (int i = 0; i < NoOfBlocks * 2; i += 2) {
			if ((x == arrBlocks[i]) && (y == arrBlocks[i + 1])) {
				indicator++;
			}
		}
		if (indicator == 0) {
			return RoutesForKingWithBlocks(x - 1, y, NoOfBlocks, arrBlocks) + RoutesForKingWithBlocks(x, y - 1, NoOfBlocks, arrBlocks);
		} else {
			return 0;
		}
	}
}


//Задание 2. *** Требуется обойти конём шахматную доску размером 8х8, пройдя через все поля доски по одному разу.
//Здесь алгоритм решения такой же как и в задаче о 8 ферзях.


int board[Y][X];

void annull() {
	int i;
	int j;
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			board[i][j] = 0;
		}
	}
}

void printBoard() {
	int i;
	int j;
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

int checkTurn(int nextRow, int nextCol, int previousR, int previousC) {

	if (abs(nextCol - previousC) == 1) {
		if (abs(nextRow - previousR) == 2)
			return 1;
	}

	if (abs(nextRow - previousR) == 1) {
		if (abs(nextCol - previousC) == 2)
			return 1;
	}

	return 0;
}


int horses(int n, int nextX, int nextY) {
	if (n == HTURNS + 1) return 1;
	int prevRow = nextY;
	int prevCol = nextX;
	int row;
	int col;
	for (row = 0; row < Y; row++) {
		for (col = 0; col < X; col++) {
			if (board[row][col] == 0) {
				if (checkTurn(row, col, prevRow, prevCol) == 0) return 0;

				board[row][col] = n;
				if (horses((n + 1), row, col))
					return 1;
				board[row][col] = 0;
			}
		}

	}

	return 0;
}
#endif /* HW4_H_ */
