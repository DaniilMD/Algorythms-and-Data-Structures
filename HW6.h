#ifndef HW6_H_INCLUDED
#define HW6_H_INCLUDED

// Дементьев Д.М.
// Задание 1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.

#define TREETYPE int


int HashFunc(char* arr, int len) {
int sum = 0;
for (int i = 0; i < len; i++)
    sum += (arr[i] * arr[i]) % 7;
    return sum;
}


//Задание 2. Написать программу, реализующее двоичное дерево поиска.
//а) Добавить в него обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска;
//в) Добавлять элемент в дерево

typedef struct BinTreeNode {
	TREETYPE data;
	struct BinTreeNode *parent;
	struct BinTreeNode *left;
    struct BinTreeNode *right;
} BTN;

//a)
void preOrderTravers(BTN* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(BTN* root) {
    if (root) {
        preOrderTravers(root->left);
        printf("%d ", root->data);

        preOrderTravers(root->right);
    }
}

void postOrderTravers(BTN* root) {
    if (root) {
        preOrderTravers(root->left);
        preOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

//b)
BTN* BTSearch(BTN *root, int SearchedNum) {
    BTN *tmp = NULL;
    if (root == NULL)
        return NULL;
    tmp = root;
    if (tmp->data == SearchedNum) {
        return tmp;
    } else {
        if (SearchedNum > tmp->data) {
            BTSearch(tmp->right, SearchedNum);
        } else {
            BTSearch(tmp->left, SearchedNum);
        }
    }
}


//c)
// Эту функцию я взял из методички, так что я её не сам сделал, но я её полностью разобрал.
// Она не сложная, проблема была скорее с неопытностью в языке C, а сам принцип работы функции абсолютно элементарный.
// Очень трудно работать с указателями и иногда с выделением памяти путаюсь.

// Создание нового узла
BTN* getFreeNode(TREETYPE value, BTN *parent) {
    BTN* tmp = (BTN*) malloc(sizeof(BTN));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла
void BTinsert(BTN **head, int value) {
    BTN *tmp = NULL;
    if (*head == NULL)
    {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp)
    {
        if (value> tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (value< tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2);                     // Дерево построено неправильно
        }
    }
}

#endif // HW6_H_INCLUDED
