#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector< vi> vv;
const int A = 1E2;

struct ChromaticNumber {

  vv graph;

  int vis[A];
  int cyc[A];
  int cnt[A];
  int X;

  void dfs(int s, int p) {
    cnt[X] += 1;
    vis[s]  = 1;
    for (auto u: graph[s]) if (u != p) {
      if (!vis[u])
        dfs(u,  s);
      else
        cyc[X] = 1;
    }
  }

  int color(int n) {
    int ans = 0; X = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
      dfs(i, i);
      if (cnt[X] == 3 && cyc[X])
        ans += 1;
      else
        ans += (cnt[X] + 1) / 2;
      X++;
    }
    return ans;
  }

  int minColors(vector<string> data) {
    graph = vv(data.size());
    for (int i = 0; i < data.size(); i++)
      for (int j = 0; j < data.size(); j++)
        if (data[i][j] == 'N' && i != j)
          graph[i].push_back(j);
    return color(data.size());
  }

};
