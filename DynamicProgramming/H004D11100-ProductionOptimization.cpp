#include <iostream>
#include <vector>

using namespace std;

const int B = 111;
const int A =  61;

struct ProductionOptimization {

  vector<int>  hour;
  vector<int>  cost;
  int memo[A][B][B];
  int test[A][B][B];

  int maxwin(int idx, int cst, int hrs) {
    if (idx >= cost.size())
      return 1;
    if (test[idx][cst][hrs] == 1)
      return memo[idx][cst][hrs];
    int ans    = 0;
    int nxthrs = hrs - hour[idx];
    int nxtcst = cst - cost[idx];
    if (nxthrs >= 0 && nxtcst >= 0)
      for (int i = 0; i <= nxtcst; i++)
        ans = max(ans, maxwin(idx + 1, i, nxthrs) + maxwin(idx, nxtcst - i,  nxthrs));
    test[idx][cst][hrs] = 1;
    return memo[idx][cst][hrs] = ans;
  }

  int getMost(vector<int> costs, vector<int> times, int cst, int hrs) {
    hour = times;
    cost = costs;
    return maxwin(0, cst, hrs);
  }

};
