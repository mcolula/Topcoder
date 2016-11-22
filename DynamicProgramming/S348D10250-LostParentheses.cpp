#include <iostream>
#include <sstream>

using namespace std;

const int A = 1E2;
const int M = 1E8;

struct LostParentheses {

  int memo[A][A];
  int test[A][A];
  int data[A];
  int N;

  int minexp(int idx, int opn) {
    if (idx >= N)
      return 0;
    if (test[idx][opn] == 1)
      return memo[idx][opn];
    int ans = M;
    if (opn > 0)
      ans = min(ans, minexp(idx, opn - 1));
    if (opn % 2 == 0)
      ans = min(ans, +data[idx] + minexp(idx + 1, opn + (data[idx] < 0)));
    if (opn % 2 != 0)
      ans = min(ans, -data[idx] + minexp(idx + 1, opn + (data[idx] < 0)));
    test[idx][opn] = 1;
    return memo[idx][opn] = ans;
  }

  int minResult(string e) {
    stringstream ss(e);   N  = 0;
    while (ss >> data[N]) N += 1;
    return minexp(0, 0);
  }

};
