#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

// ������� 1
double MassIndexCounter(double m, double h) {

    return m / (h * h);
}

// ������� 2
int calculateSquareEquation(int a, int b, int c, double* x1, double* x2) {
    int D = (b*b - 4*a*c);
    double sqrtD = sqrt(D);
    if (D > 0) {
        *x1 = ((-b + sqrtD) / (2*a));
        *x2 = ((-b - sqrtD) / (2*a));
        return 1; // ��� �����
    } else if (D == 0) {
        *x1 = *x2 = ((-b + sqrtD) / (2*a));
        return 0; // ���� ������
    } else {
        return -1; // ��� ������
    }
}

// ������� 3
void AgeAnalysis(int age) {
    if ((((age % 10) >= 5) && ((age % 10) <= 9)) || ((age % 10) == 0) ){
        printf("%d ���\n", age);
    } else if (((age % 100) >= 11) && ((age % 100) <= 19))  {
        printf("%d ���\n", age);
    } else if ((age % 10) == 1) {
        printf("%d ���\n", age);
    } else {
        printf("%d ����\n", age);
    }

}


//������� 4

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


// ������� 5

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
	setlocale(LC_ALL, "RUS");

	// Test 1 task
    printf("%.2f\n", MassIndexCounter(60, 1.85));


    //Test 2 task
    double X1, X2;
    int indicator = calculateSquareEquation(1, 5, 2, &X1, &X2);
    if (indicator == 1) {
        printf("���� ��������� ����� 2 �����: x1 = %f, x2 = %f\n", X1, X2);
    } else if (indicator == 0) {
        printf("���� ��������� ����� 1 ������ ��������� 2: x1 = x2 = %f\n", X1);
    } else {
        printf("���� ��������� �� ����� �������������� ������\n");
    }


    //Test 3 task
    for (int i = 1; i <= 150; i++) {
        AgeAnalysis(i);
    }


    //Test 4 task
    printf("���� 1, �� ���������� �����, ���� 0, �� ������: %d\n", ColourEquality(5, 5, 2, 3));


    //Test 5 task
    printf("����������� ����� �� 0 �� 10000 \n");
    AutomorphicNumber();


    return 0;
}
