#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector< vi> vv;

const int A = 1E2;

struct DancingFoxes {

  vv graph;

  int dis[A];
  int vis[A];

  void shortestPath(int s = 0) {
    queue<int> q;
    dis[s] = 0;
    vis[s] = 1;
    q.push( s);
    while (!q.empty()) {
      int s = q.front(); q.pop();
      for (auto u: graph[s]) if (!vis[u])
        vis[u] = 1, dis[u] = 1 + dis[s], q.push(u);
    }
  }

  int mincst(int n) {
    return n <= 2 ? 0 : 1 + mincst(n - n / 3);
  }

  int minimalDays(vector<string> data) {
    graph = vv(data.size());
    for (int i = 0; i < data.size(); i++)
      for (int j = 0; j < data.size(); j++)
        if (data[i][j] == 'Y' && i != j)
          graph[i].push_back(j);
    shortestPath(0);
    return vis[1] ? mincst(dis[1] + 1) : -1;
  }

};
