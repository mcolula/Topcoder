#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector< vi> vv;
const int X = 1E6;
const int A = 3E2;

struct FlowNetwork {

  int cpy[A][A];
  int flo[A][A];
  int prt[A];
  vv  net;

  FlowNetwork(int n): net(n) {}

  void addEdge(int u, int v, int w = 1) {
    net[u].push_back(v);
    net[v].push_back(u);
    cpy[u][v] += w;
    cpy[v][u] += w;
    flo[v][u] += w;
  }

  int updateFlow(int u, int f = X) {
    int p = prt[u];
    f = p == u ? f: updateFlow(p, min(f, cpy[p][u] - flo[p][u]));
    flo[p][u] += f;
    flo[u][p] -= f;
    return f;
  }

  int bfs(int s, int t) {
    queue<int> q; q.push(s);
    fill(prt, prt + A,  -1);
    prt[s] = s;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;
      for (auto v: net[u])
        if (prt[v] < 0 && cpy[u][v] > flo[u][v])
          prt[v] = u, q.push(v);
    }
    return prt[t] >= 0 ? updateFlow(t) : 0;
  }

  int maxFlow(int s, int t) {
    int ans = 0;
    while (int f = bfs(s, t))
      ans += f;
    return ans;
  }

};

#define nxt(i, j) (cur(i,  j) + n * m)
#define cur(i, j) (i * m + j)

const int K = 4E0;

struct PrinceOfPersia {

  int is[K] = {1, 0, -1, 0};
  int js[K] = {0, 1, 0, -1};


  bool valid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
  }

  int minObstacles(vector<string> maze) {
    vector<int> pts;
    int n = maze   .size();
    int m = maze[0].size();
    FlowNetwork net(2 *  n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (maze[i][j] != '#') {
          for (int k = 0; k < K; k++) {
            int nxtI = i + is[k];
            int nxtJ = j + js[k];
            if (valid(nxtI, nxtJ, n, m) && maze[nxtI][nxtJ] != '#') {
              net.addEdge(nxt(nxtI, nxtJ), cur(i, j), X);
              net.addEdge(nxt(i, j), cur(nxtI, nxtJ), X);
            }
          }
          net.addEdge(cur(i, j), nxt(i, j));
        }
        if (maze[i][j] == 'P')
          pts.push_back(cur(i, j)),
          pts.push_back(nxt(i, j));
      }
    }
    int ans = net.maxFlow(pts[1], pts[2]);
    return ans >= X ? -1 : ans;
  }
};
