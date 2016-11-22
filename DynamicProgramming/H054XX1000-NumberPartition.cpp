#include <iostream>
#include <vector>

using namespace std;

const int A = 1E2;

struct NumberPartition {

  vector<int> ans;
  int  test[A][A];
  int  memo[A][A];

  int count(int n, int x) {
    if (n == 0)
      return 1;
    if (test[n][x] == 1)
      return memo[n][x];
    int ans = 0;
    for (int i = x; i <= n; i++)
      ans += count(n - i, i);
    test[n][x] = 1;
    return memo[n][x] = ans;
  }

  void partition(int n, int x, int k) {
    if (n  == 0) return;
    int cnt = 0;
    int idx = x;
    while (cnt + count(n - idx, idx) <= k)
      cnt += count(n - idx, idx), idx++;
    ans.push_back(idx); partition(n - idx, idx, k - cnt);
  }

  vector<int> kthPartition(int n, int k) {
    if (count(n, 1) < k)
      return vector<int>();
    partition(n, 1, k - 1);
    return ans;
  }

};
