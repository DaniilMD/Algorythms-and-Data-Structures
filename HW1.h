#ifndef HW1_H_
#define HW1_H_

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

#endif /* HW1_H_ */
