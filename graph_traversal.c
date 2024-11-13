#include <stdio.h>

#define MAX 20

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array

void bfs(int start, int n);
void dfs(int start, int n);

int main() {
    int n, start;
    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    // Input the start vertex
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);
    
    // Input validation
    if (start < 0 || start >= n) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex %d: ", start);
    dfs(start, n);

    return 0;
}

// DFS function using a stack
void dfs(int start, int n) {
    int stack[MAX], top = -1;
    stack[++top] = start;

    while (top != -1) {
        int vertex = stack[top--];

        if (!visited[vertex]) {
            printf("%d ", vertex);
            visited[vertex] = 1;

            // Push all unvisited adjacent vertices
            for (int i = n - 1; i >= 0; i--) {
                if (adj[vertex][i] == 1 && visited[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
}
