#include <stdio.h>
int q[20] ,front =-1,rear = -1,top =-1;
a[20][20];vis[20];stack[20];
void bfs(int s,int n);
void dfs(int s,int n);
int delete();
void add(int item);
void push(int item);
pop();

int main(){
    //no of vercts
    int n;
    scanf("%d",&n);// Adjacency matrix

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",a[i][j]);
        }printf("\n");

    }

    // make the visited array to zero  
    do{
        //the menu
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:void dfs(s,n)
           
            break;
        
        case 2:
        void bfs(s,n)
            break;
        }
        case 0:
        void bfs(s,n)
            break;
        }
        //continue statement
        
    }while(ch!=0)


    return 0;
}


void bfs(int s,int n){
    int p,i;
    add(s);
    vis[s]=1;
    p = delete();
    if(p!=0)printf("%d",p)
    while (p!=0)
    {
        for(i=1;i<=n;i++){
            if(a[p][i]!=0 && vis[i]==0){
                add(i);
                vis[i]=1;
            }
            p = delete();
            if(p!=0)printf("%d",p)
        }
        for(i=1;i,=n;i++)
        if(vis[i]==0)bfs(i,n)
    }
    



}
/*
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array

void bfs(int start, int n);
void dfs(int start, int n);

int main() {
    int n, choice, start;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Menu
    do {
        // Reset visited array for each traversal
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }

        printf("\nMenu:\n1. DFS\n2. BFS\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Enter starting vertex: ");
            scanf("%d", &start);
        }

        switch (choice) {
            case 1:
                printf("DFS traversal starting from vertex %d:\n", start);
                dfs(start, n);
                printf("\n");
                break;
            case 2:
                printf("BFS traversal starting from vertex %d:\n", start);
                bfs(start, n);
                printf("\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// BFS function using a queue
void bfs(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        // Enqueue all unvisited adjacent vertices
        for (int i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
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

*/