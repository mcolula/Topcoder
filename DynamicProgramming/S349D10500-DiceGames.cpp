#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class DiceGames {

  private:

  typedef long long   lld;
  typedef vector<int>  vi;
  static const int A = 50;

  int mem[A][A];
  int tst[A][A];

  lld count(vi& data, int idx, int num) {
    if (idx == data.size())
      return 1;
    if (tst[idx][num] != 0)
      return mem[idx][num];
    int ans = 0;
    for (int i = num; i <= data[idx]; i++)
      ans += count(data, idx + 1, i);
    tst[idx][num] = 1;
    return mem[idx][num] = ans;
  }

  public:

  lld countFormations(vector<int> dice) {
    sort(dice.begin(), dice.end());
    return count(dice, 0, 1);
  }

};
