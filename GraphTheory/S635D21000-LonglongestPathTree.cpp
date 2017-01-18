#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class LonglongestPathTree {

  private:

  typedef pair<int, int> pii;
  typedef long long  lld;
  typedef vector<lld> vi;
  typedef vector<pii> vp;
  typedef vector<vp > vv;
  #define add push_back
  #define snd second
  #define fst first

  static const lld A = 2001;

  lld  used[A][A];
  vv   tree;
  vi   dist;
  vi   test;
  lld T = 1;


  lld shortestPath(ll acd s) {
    queue<lld> q;
    dist[s] = 0;
    test[s] = T;
    q.push(s);
    while (!q.empty()) {
      lld u = q.front(); q.pop();
      for (auto & p: tree[u]) {
        lld v = p.fst;
        lld d = p.snd;
        if (!used[u][v] && !used[v][u] && test[v] != T) {
          dist[v] = d + dist[u];
          test[v] = T;
          q.push(v);
        }
      }
    }
    lld mx = -1;
    lld id = -1;
    for (lld i = 0; i < tree.size(); i++)
      if (test[i] == T && dist[i] > mx)
        mx = dist[i], id = i;
    T += 1;
    return id;
  }

  public:

  lld getLength(vector<int> A, vector<int> B, vector<int> L) {
    lld size = A.size();
    tree = vv(size + 1);
    for (lld i = 0; i < size; i++)
      tree[A[i]].add(pii(B[i], L[i])),
      tree[B[i]].add(pii(A[i], L[i]));
    dist = vi(size + 1, 0);
    test = vi(size + 1, 0);
    lld ans = 0;

    for (lld i = 0; i < size; i++) {
      lld a  =  A[i];
      lld b  =  B[i];
      used[a][b] = 1;
      used[b][a] = 1;
      lld sum = L[i];

      lld u = shortestPath(a);
      lld v = shortestPath(u);
      sum += dist[v];

      lld x = shortestPath(b);
      lld y = shortestPath(x);
      sum += dist[y];

      used[a][b] = 0;
      used[b][a] = 0;

      ans = max(ans, sum);
    }
    return ans;
  }

};
