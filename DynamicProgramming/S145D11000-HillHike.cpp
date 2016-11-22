#include <iostream>
#include <vector>

using namespace std;

const int A = 110;
const int B =  60;

struct HillHike {

  typedef long long lld;
  lld  memo[A][B][B][2];
  vector<int> data;
  lld N;
  lld M;
  lld X;

  lld count(lld idx, lld top, lld lan, bool big) {
    if (idx  >= N &&  top == 0 && lan == M && big)
      return 1;
    if (idx  >= N || (idx  > 0 && top <= 0))
      return 0;
    if (top  > X)
      return 0;
    if (memo[idx][top][lan][big] >= 0)
      return memo[idx][top][lan][big];
    lld ans = 0;
    lld nxt = lan < M ? lan + (data[lan] == top) : lan;
    ans += count(idx + 1, top + 1, nxt, big || (top == X));
    ans += count(idx + 1, top + 0, nxt, big || (top == X));
    ans += count(idx + 1, top - 1, nxt, big || (top == X));
    return memo[idx][top][lan][big] = ans;
  }

  lld numPaths(int n, int x, vector<int> lands) {
    for (int i = 0; i < A; i++)
      for (int j = 0; j < B; j++)
        for (int k = 0; k < B; k++)
          fill(memo[i][j][k], memo[i][j][k] + 2, -1);
    M = lands.size(); data = lands;
    N = n;
    X = x;
    return count(0, 0, 0, 0);
  }

};
