#include <stdio.h>

#define MAX 30

typedef struct edge {
    int u, v, cost;
} Edge;

Edge edges[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskals(int c[MAX][MAX], int n) {
    int i, j, u, v, a, b, min, ne = 0, mincost = 0;

    for (i = 1; i <= n; i++)
        parent[i] = 0;

    while (ne < n - 1) {
        min = 9999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (c[i][j] < min) {
                    min = c[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("(%d, %d) -> %d\n", a, b, min);
            mincost += min;
            ne++;
        }

        c[a][b] = c[b][a] = 9999; // Mark as visited
    }

    printf("Minimum Cost = %d\n", mincost);
}

int main() {
    int c[MAX][MAX], n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0)
                c[i][j] = 9999; // 9999 represents infinity (no edge)
        }
    }

    printf("The Minimum Spanning Tree is:\n");
    kruskals(c, n);

    return 0;
}
