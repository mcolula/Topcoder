#include <iostream>

using namespace std;

const int lim = 2000;
const int A   = 2001;

struct PointSystem {


  double mem[A][A];
  int    tes[A][A];

  double pro;
  int    ptw;
  int    pwb;


  double probability(int p, int q) {
    if (q >= ptw && q >= p + pwb)
      return 1.0;
    if (p >= ptw && p >= q + pwb)
      return 0.0;
    if (q >= lim || p >= lim)
      return 0.0;
    if (tes[p][q] == 1)
      return mem[p][q];
    tes[p][q] = 1;
    return mem[p][q] = probability(p + 1, q) * (1.0 - pro) + probability(p, q + 1) * pro;
  }

  double oddsOfWinning(int pointsToWin, int pointsToWinBy, int skill) {
    pro = skill / 100.0;
    ptw =   pointsToWin;
    pwb = pointsToWinBy;
    return probability(0, 0);
  }

};
