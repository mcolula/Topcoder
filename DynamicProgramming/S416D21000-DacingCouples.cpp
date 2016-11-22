#include <iostream>
#include <vector>

using namespace std;

#define bits(n) __builtin_popcount(n)

const int A = 2E1;
const int B = 2E3;

struct DancingCouples {

  vector<string> data;
  int memo[A][B];
  int K;

  int count(int idx, int msk) {
    if (idx >= data.size() && bits(msk) == K)
      return 1;
    if (idx >= data.size() && bits(msk) != K)
      return 0;
    if (memo[idx][msk] >= 0)
      return memo[idx][msk];
    int ans = count(idx + 1, msk);
    for (int i = 0; i < data[idx].size(); i++)
      if ((msk & (1 << i)) == 0 && data[idx][i] == 'Y')
        ans += count(idx + 1, msk | (1 << i));
    return memo[idx][msk] = ans;
  }

  int countPairs(vector<string> canDance, int K) {
    this->K = K; this->data = canDance;
    for (int i = 0; i < A; i++)
      fill(memo[i], memo[i] + B, -1);
    return count(0, 0);
  }
};
