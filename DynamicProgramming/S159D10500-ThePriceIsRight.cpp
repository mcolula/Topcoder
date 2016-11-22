#include <iostream>
#include <vector>

using namespace std;

const int A = 101;

struct ThePriceIsRight {

  vector<int> data;
  int memo[A][A];
  int test[A][A];

  int maxseq(int idx) {
    if (test[idx][100] == 1)
      return memo[idx][100];
    int ans = 1;
    for (int i = idx + 1; i < data.size(); i++)
      if (data[idx] < data[i])
        ans = max(ans, 1 + maxseq(i));
    test[idx][100] = 1;
    return memo[idx][100] = ans;
  }

  int cntseq(int idx, int len) {
    if (len <= 0)
      return 1;
    int ans = 0;
    if (test[idx][len] == 1)
      return memo[idx][len];
    for (int i = idx + 1; i < data.size(); i++)
      if (data[idx] < data[i])
        ans += cntseq(i, len - 1);
    test[idx][len] = 1;
    return memo[idx][len] = ans;
  }


  vector<int> howManyReveals(vector<int> prices) {
    vector<int> ans(2); data = prices;
    int len = 0, cnt = 0;
    for (int i = 0; i < data.size(); i++)
      len  = max(len, maxseq(i));
    for (int i = 0; i < data.size(); i++)
      cnt += cntseq(i, len - 1);
    ans[0] = len;
    ans[1] = cnt;
    return ans;
  }

};
