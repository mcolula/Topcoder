#include <iostream>

using namespace std;


struct Dragon {

  static const int A = 2E2;
  static const int B = 2E0;

  double mem[A][A][B];
  int    tst[A][A][B];
  double K;
  double D;

  double probability(int kni, int dra, bool who) {
    if (dra == 0)
      return   1;
    if (kni == 0)
      return   0;
    if (tst[kni][dra][who] != 0)
      return mem[kni][dra][who];
    if (!who) {
      double k = probability(kni - 1, dra, 0) * (0.0 + D);
      double l = probability(kni, dra - 1, 0) * (1.0 - D);
      tst[kni][dra][who] = 1;
      return mem[kni][dra][who] = min(probability(kni, dra, 1), k + l);
    }
    if ( who) {
      double k = probability(kni - 1, dra    , 1) * (1.0 - K);
      double l = probability(kni - 1, dra - 1, 1) * (0.0 + K);
      tst[kni][dra][who] = 1;
      return mem[kni][dra][who] = k + l;
    }
  }

  double winFight(int h, int k, int probD, int probK) {
    D = probD / 100.0;
    K = probK / 100.0;
    return probability(k, h, 0);
  }

};
