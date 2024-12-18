#include <stdio.h> 
void adj(int a[20][20], int n, int k) { 
    int i, j, visited[20] = {0};   
    for (j = 1; j <= n; j++) { 
        if (a[k][j] == 1 || a[j][k] == 1) { 
            visited[j] = 1; 
            printf("%d -> %d\n", k, j); 
        } 
    } 
    printf("\n"); 
    for (i = 1; i <= n; i++) { 
        if ((a[i][k] == 0) && (i != k)) { 
            for (j = 1; j <= n; j++) { 
                if (a[i][j] != 0 && visited[i] != 1) { 
                    visited[i] = 1; 
                    printf("%d -> %d\n", j, i); 
                } 
            } 
        } 
    } 
} 
int main() { 
    int i, j, n, root, a[20][20]; 
    printf("Enter number of nodes: "); 
    scanf("%d", &n); 
    printf("Enter adjacency matrix:\n"); 
    for (i = 1; i <= n; i++) { 
        for (j = 1; j <= n; j++) { 
            scanf("%d", &a[i][j]); 
        } 
    } 
    printf("Enter root node: "); 
    scanf("%d", &root); 
    adj(a, n, root); 
    return 0; 
}
