#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define max 100
int G[max][max];
int vis[max];
void DFS(int v, int n) {
    vis[v] = 1;
    printf(" %d", v);
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0 && G[v][i] > 0) {
            DFS(i, n);
        }
    }
}
void BFS(int v, int n) {
    vis[v] = 1;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int j = q.front();
        q.pop();
        printf(" %d", j);
        for (int i = 0; i < n; i++) {
            if (G[j][i] && !vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}
int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    memset(vis, 0, sizeof(vis));
    int v1, v2, i;
    for (i = 0; i < e; i++) {
        scanf("%d %d", &v1, &v2);
        getchar();
        G[v1][v2] = G[v2][v1] = 1;
    }
    //DFS
    for (i = 0; i < n; i++) {
        if (!vis[i]) {
            printf("{");
            DFS(i, n);
            printf(" }\n");
        }
    }
    //BFS
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < n; i++) {
        if (!vis[i]) {
            printf("{");
            BFS(i, n);
            printf(" }\n");
        }
    }
    return 0;
}