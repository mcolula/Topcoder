#include <iostream>
#include <vector>

using namespace std;

const int M = 1E9;
const int A = 2E3;

struct WindowWasher {

  vector<int> data;
  int memo[A][A];
  int test[A][A];
  int W;
  int H;

  int mincst(int idx, int win) {
    if (idx == data.size() && win == 0)
      return 0;
    if (idx == data.size() && win != 0)
      return M;
    if (test[idx][win] == 1)
      return memo[idx][win];
    int ans = M;
    for (int i = 0; i <= win; i++)
      ans = min(ans, max(i * H * data[idx], mincst(idx + 1, win - i)));
    test[idx][win] = 1;
    return memo[idx][win] = ans;
  }

  int fastest(int w, int h, vector<int> washTimes) {
    W    = w;
    H    = h;
    data = washTimes;
    return mincst(0, w);
  }

};
