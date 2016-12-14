#include <iostream>
#include <vector>

using namespace std;

class BagOfDevouring {

  private:

  #define ison(i) (msk & (1 << i))
  #define turn(i) (msk ^ (1 << i))

  static const int A = 5E4;
  static const int B = 1E2;
  static const int C = 1E2;

  double mem[A];
  double cst[B];
  double win[B];

  int vis[A];
  int N;

  double expectation(int msk) {
    if (vis[msk] != 0)
      return mem[msk];
    double ans = 0;
    for (int i = 0; i < N; i++) if (!ison(i)) {
      msk  = turn(i);
      double sum = C;
      for (int j = 0; j < N; j++) if (!ison(j))
        sum += cst[j];
      double exp = C * expectation(msk) / sum;
      for (int j = 0; j < N; j++) if (!ison(j)) {
        msk  = turn(j);
        exp += cst[j] * expectation(msk) / sum;
        msk  = turn(j);
      }
      msk = turn(i);
      ans = max(ans, win[i] + exp);
    }
    vis[msk] = 1;
    return mem[msk] = ans;
  }

  public:

  double expectedYield(vector<int> v, vector<int> w) {
    N = v.size();
    for (int i = 0; i < N; i++)
      win[i] = v[i], cst[i] = w[i];
    return expectation(0);
  }
};
