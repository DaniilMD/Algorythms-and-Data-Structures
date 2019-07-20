#ifndef HW5_H_
#define HW5_H_

// Дементьев Д.М.

// Задание 1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.

#define TYPE char
#define SIZE 100

TYPE Stack[SIZE];
int idx = -1;

void Stack0() {
	for (int i = 0; i < SIZE; i++) {
		Stack[i] = 0;
	}
}

void push(TYPE i) {
	if (idx < SIZE) {
		Stack[++idx] = i;
	} else {
		printf("%s\n", "Stack overflow");
 	 }
}

TYPE pop() {
	if (idx != -1) {
		return Stack[idx--];
	} else {
		return 0;
	}
}

int DecToBinStack(int number, char* BinArr) {
	int counter = 0;
	while (number > 0) {
		if (number % 2 == 0) {
			push('0');
		} else {
			push('1');
		}
		counter++;
		number /= 2;
	}

	int z = 0;
	while(idx != -1) {
		BinArr[z] = pop();
		z++;
	}

	return counter;
}


// Задание 2. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
//Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
//Например: (2+(2*2)) или [2/{5*(4+7)}]

TYPE popBr() {
	if (idx != -1) {
		return Stack[idx];
	} else {
		return 0;
	}
	return 0;
}

int CheckBr(int amount, char* Brackets) {
	Stack0();
	idx = -1;
	for (int i = 0; i < amount; i++) {
		if (Brackets[i] == '{') {
			push('a');
		}
		if (Brackets[i] == '[') {
			push('b');
		}
		if (Brackets[i] == '(') {
			push('c');
		}

		if (Brackets[i] == '}') {
			if (popBr() != 'a')
				return 0;
			idx--;
		}
		if (Brackets[i] == ']') {
			if (popBr() != 'b')
				return 0;
			idx--;
		}
		if (Brackets[i] == ')') {
			if (popBr() != 'c')
				return 0;
			idx--;
		}
	}
	return 1;
}

// Задание 3. *Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, без удаления первого списка).

typedef struct Node {
	TYPE data;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} Stck;

/*
int StructCpy(Stck *st, Stck *stCpyTo) {
	Node *temp = (Node*) malloc(sizeof(Node));
	if (temp == NULL) return 0;

	temp->data = st->head->data;
	temp->next = st->head;

 	stCpyTo->head = temp;
 	stCpyTo->size++;

 	if ((stCpyTo->size) < (st->size))
 		StructCpy(Stck st->head->next, Stck stCpyTo);
 	return 1;
}
*/

// Задание 4. *Реализовать очередь.

typedef struct DoubleNode {
	TYPE data;
	struct DoubleNode *next;
	struct DoubleNode *prev;
} DNode;

typedef struct {
	DNode *head;
	DNode *tail;
	int size;
} DQueue;

int pushhead(DQueue *st, TYPE val) {
	DNode *temp = (DNode*) malloc(sizeof(DNode));
	if (temp == NULL) return 0;

	temp->data = val;
	temp->next = st->head;

	st->head = temp;
	st->size++;
	return 1;
}

int pushtail(DQueue *st, TYPE val) {
	DNode *temp = (DNode*) malloc(sizeof(DNode));
	if (temp == NULL) return 0;

	temp->data = val;
	temp->prev = st->tail;

	st->tail = temp;
	st->size++;
	return 1;
}

TYPE popDQhead(DQueue *st) {
	if (st->size == 0) {
		return -1;
	}
	DNode *temp = st->head;
 	TYPE result = st->head->data;

 	st->head = st->head->next;
 	st->size--;
 	free(temp);
 	return result;
}

TYPE popDQtail(DQueue *st) {
	if (st->size == 0) {
		return -1;
	}
	DNode *temp = st->tail;
 	TYPE result = st->tail->data;

 	st->tail = st->tail->prev;
 	st->size--;
 	free(temp);
 	return result;
}
#endif /* HW5_H_ */
