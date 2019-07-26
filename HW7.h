#ifndef HW7_H_INCLUDED
#define HW7_H_INCLUDED
//Дементьев Д.М.

//Задание 1. Написать рекурсивную функцию обхода графа в глубину.
#define GNAm 5
int AdjMatrix[GNAm + 1][GNAm + 1];

typedef struct GraphNode {
    int data;
    int index;
    int used;
    int children[GNAm + 1];
} GraphNode;


GraphNode GNStack[GNAm];
int indx = -1;

void pushGN(GraphNode i) {
	if (indx < GNAm) {
		GNStack[++indx] = i;
	} else {
		printf("%s\n", "Stack overflow");
 	 }
}

GraphNode popGN() {
	if (indx != -1) {
		return GNStack[indx--];
	} else {
		return ;
	}
}



int widthTravers(GraphNode *start, GraphNode *stop) {
    pushGN(*start);
    start->used = 1;
    while (indx != -1) {
        GraphNode current = popGN(GNStack);
        if (current->data == stop->data)
            return 1;

        for (int i = 0; i < GNAm + 1; i++) {
            if (current->children[i] == 1) {
                if (GN[i]->used != 1) {
                    pushGN(GN[i]);
                    GN[i]->used = 1;
                }
            }
        }
    }
}

//Задание 2. Написать функцию обхода графа в ширину.
int RecurDepthTravers(GraphNode *start, GraphNode *stop) {
    if (start->data == stop->data)
        return 1;
    for (int i = 0; i < GNAm + 1; i++) {
        if (start->children[i] == 1) {
            if (GN[i]->used != 1) {
                RecurDepthTravers(GN[i],  stop);
            }
        }
    }
    return 0;
}
//Задание 3. Запустить алгоритм Ли
const int w = 11;
const int h = 12;
const int OBSTACLE = -1;
const int UNVISITED = -2;
int grid[h][w];
int len;
int pointX[h * w];
int pointY[h * w];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

grid[4][7] = OBSTACLE;
grid[4][8] = OBSTACLE;
grid[4][9] = OBSTACLE;
grid[4][10] = OBSTACLE;

grid[7][9] = OBSTACLE;
grid[8][9] = OBSTACLE;
grid[9][9] = OBSTACLE;


grid[6][6] = OBSTACLE;
grid[7][7] = OBSTACLE;
grid[8][8] = OBSTACLE;

for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
        grid[y][x] = UNVISITED;
    }
}

int lee(int sx, int sy, int ex, int ey) {
    int x, y, vector, dist, stop;
    if (sx == ex && sy == ey) return 0;
    if (grid[sy][sx] == OBSTACLE || grid[ey][ex] == OBSTACLE) return 0;

    dist = 0;
    grid[sy][sx] = dist;
    do {
        stop = 1;
        for (y = 0; y < h; y++) {
            for (x = 0; x < w; x++) {
                if (grid[y][x] == dist) {
                    for (vector = 0; vector < 4; vector++) {
                        int nextX = x + dx[vector];
                        int nextY = y + dy[vector];
                        if ( nextX >= 0 && nextX < w && nextY >= 0 && nextY < h && grid[nextY][nextX] == UNVISITED) {
                            stop = 0;
                            grid[nextY][nextX] == dist + 1;
                        }
                    }
                }
            }
        }
        dist++;
    } while (!stop && grid[ey][ex] == UNVISITED);

    if (grid[ey][ex] == UNVISITED) return 0;

    len = grid[ey][ex];
    x = ex;
    y = ey;
    while (dist > 0) {
        pointX[dist] = x;
        pointY[dist] = y;
        dist--;
        for (vector = 0; vector < 4; vector++) {
            int nextX = x + dx[vector];
            int nextY = y + dy[vector];
            if ( nextX >= 0 && nextX < w && nextY >= 0 && nextY < h && grid[nextY][nextX] == dist) {
                    x = nextX;
                    y = nextY;
                }
        }
    }
    return 1;
}

#endif // HW7_H_INCLUDED
