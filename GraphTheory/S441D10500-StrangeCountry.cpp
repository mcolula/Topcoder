#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector< vi> vv;

const int A = 1E2;

struct StrangeCountry {
  vv   graph;

  int lnk[A];
  int cnt[A];
  int vis[A];
  int red[A];
  int X  = 0;

  void colour(int s, int p) {
    lnk[s]  = 1;
    vis[s]  = 1;
    cnt[X] += 1;
    for (auto & u: graph[s]) if (u != p) {
      if (!vis[u])
        colour(u, s);
      else if (!lnk[u])
        red[X] +=  1;
    }
    lnk[s] = 0;
  }

  int joinComponents(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
      colour(i, i);
      if (cnt[X] == 1)
        return -1;
      ans += red[X++];
    }
    return ans + 1 >= X ? X - 1 : -1;
  }

  int transform(vector<string> data) {
    graph = vv(data.size());
    for (int i = 0; i < data.size(); i++)
      for (int j = 0; j < data.size(); j++)
        if (data[i][j] == 'Y' && i != j)
          graph[i].push_back(j);
    return joinComponents(data.size());
  }

};
