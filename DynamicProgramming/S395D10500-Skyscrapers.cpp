#include <iostream>

using namespace std;

typedef long long lld;

const lld M = 1000000007;
const lld A =        110;

struct Skyscrapers {

  lld memo[A][A][A];

  lld count(lld n, lld l, lld r) {
    if (n == 1 && l == 1 && r == 1)
      return 1;
    if (n == 1 || l <= 0 || r <= 0)
      return 0;
    if (memo[n][l][r] >= 0)
      return memo[n][l][r];
    lld ans = 0;
    ans =  (ans + count(n - 1, l - 1, r    )) % M;
    ans =  (ans + count(n - 1, l    , r - 1)) % M;
    ans =  (ans + count(n - 1, l    , r    ) * (n - 2)) % M;
    return memo[n][l][r] = ans;
  }

  int buildingCount(int n, int leftSide, int rightSide) {
    for (int i = 0; i < A; i++)
      for (int j = 0; j < A; j++)
        fill(memo[i][j], memo[i][j] + A, -1);
    return count(n, leftSide, rightSide);
  }

};
