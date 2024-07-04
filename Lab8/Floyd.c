#include <stdio.h>
#include <stdlib.h>

int cost[1000][1000];

void floyd(int n){
    int d[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = cost[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    printf("Output: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    floyd(n);
    return 0;
}
