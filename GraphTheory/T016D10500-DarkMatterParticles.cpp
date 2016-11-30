#include <iostream>
#include <vector>

using namespace    std;
typedef vector<int> vi;
typedef vector< vi> vv;
const int A = 1001;

struct DarkMatterParticles {

  vv   graph;

  int mem[A][A];
  int tes[A][A];
  int vis[A];
  int cnt[A];
  int N =  0;

  void colour(int s, int p) {
    vis[s]  = 1;
    cnt[N] += 1;
    for (auto u: graph[s])
      if (u != p && !vis[u])
        colour(u, s);
  }

  bool possible(int idx, int k) {
    if (idx >= N && k == 0)
      return 1;
    if (idx >= N && k != 0)
      return 0;
    if (tes[idx][k] == 1)
      return mem[idx][k];
    bool ans = possible(idx + 1, k);
    if (cnt[idx] <= k)
      ans |= possible(idx + 1, k - cnt[idx]);
    tes[idx][k] = 1;
    return mem[idx][k] = ans;
  }

  bool possible(int k) {
    for (int i = 0; i < graph.size(); i++) if (!vis[i])
      colour(i, i), N += 1;
    return possible(0,  k);
  }

  string SplitParticles(int n, int k, vector<int> x, vector<int> y) {
    graph = vv(n);
    for (int i = 0; i < x.size(); i++)
      graph[x[i]].push_back(y[i]),
      graph[y[i]].push_back(x[i]);
    if (possible(k))
      return "Possible";
    return "Impossible";
  }

};
