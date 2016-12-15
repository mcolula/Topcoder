#include <iostream>

using namespace std;

class RedIsGood {

  private:

  static const int A = 5001;

  double mem[2][A];

  public:

  double getProfit(int R, int B) {
    for (int r = 1; r <= R; r++) {
      mem[r % 2][0] = r;
      for (int b = 1; b <= B; b++) {
        double ansr = r * (mem[(r - 1) % 2][b] + 1) / (double)(r + b);
        double ansb = b * (mem[(r) % 2][b - 1] - 1) / (double)(r + b);
        mem[r % 2][b] = max(0.0, ansr + ansb);
      }
    }
    return mem[R % 2][B];
  }
};
