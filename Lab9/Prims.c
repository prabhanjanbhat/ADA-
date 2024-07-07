#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void main(){
    printf("Enter number of vertices: ");
    int n;
    scanf("%d", &n);
    int cost[n][n];
    printf("Enter cost adjacency matrix: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    int min = INT_MAX, source = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cost[i][j] != 0 && cost[i][j] < min){
                min = cost[i][j];
                source = i;
            }
        }
    }
    int s[n], d[n], p[n];
    for(int i = 0; i < n; i++){
        s[i] = 0;
        d[i] = cost[source][i];
        p[i] = source;
    }
    s[source] = 1;
    int sum = 0, k = 0, t[n][2];
    for(int i = 0; i < n; i++){
        min = INT_MAX;
        int u = -1;
        for(int j = 0; j < n; j++){
            if(s[j] == 0 && d[j] <= min){
                min = d[j];
                u = j;
            }
        }
        if (u == -1) break;

        t[k][0] = u;
        t[k][1] = p[u];
        k++;
        sum += cost[u][p[u]];
        s[u] = 1;
        for(int j = 0; j < n; j++){
            if(s[j] == 0 && cost[u][j] < d[j]){
                d[j] = cost[u][j];
                p[j] = u;
            }
        }
    }
    if(sum >= INT_MAX){
        printf("Spanning tree does not exist");
    }
    else{
        printf("MST is:\n");
        for(int i = 0; i < k; i++){
            printf("(%d, %d) ", t[i][0] + 1, t[i][1] + 1);
        }
        printf("\nThe cost of MST is %d", sum);
    }
}
