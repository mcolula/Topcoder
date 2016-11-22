#include <iostream>
#include <vector>

using namespace std;

#define bits(n) __builtin_popcount(n)

typedef vector<int> vi;
typedef long long  lld;

const int B = 2048;
const int A =   50;
const int C =    2;


struct TheInteger {
  int memo[A][B][C][C];
  vi  s;
  int K;

  bool possible(int idx, int msk, bool zero, bool great) {
    if (idx >= s.size() && bits(msk) == K)
      return 1;
    if (idx >= s.size())
      return 0;
    if (bits(msk)  >  K)
      return 0;
    if (memo[idx][msk][zero][great] >= 0)
      return memo[idx][msk][zero][great];
    bool ans = 0;
    if ( great)
      for (int i = 0;      i <= 9; i++)
        ans |= possible(idx + 1, (msk | (1 << i)), zero && i == 0, great);
    if (!great)
      for (int i = s[idx]; i <= 9; i++)
        ans |= possible(idx + 1, (zero && i == 0) ? 0 : (msk | (1 << i)), zero && i == 0, s[idx] != i);
    return (memo[idx][msk][zero][great] = ans);
  }

  string solution(int idx, int msk, bool zero, bool great) {
    if (idx >= s.size() && bits(msk) == K)
      return "";
    if ( great)
      for (int i = 0;      i <= 9; i++)
        if (possible(idx + 1, (msk | (1 << i)), zero && i == 0, great))
          return to_string(i) + solution(idx + 1, (msk | (1 << i)), zero && i == 0, great);
    if (!great)
      for (int i = s[idx]; i <= 9; i++)
        if (possible(idx + 1, (zero && i == 0) ? 0 : (msk | (1 << i)), zero && i == 0, s[idx] != i))
          return to_string(i) + solution(idx + 1, (zero && i == 0) ? 0 : (msk | (1 << i)), zero && i == 0, s[idx] != i);
    return "";
  }

  lld find(lld n, int k) {
    s = vi(20); K = k;
    for (int i = 0; i < A; i++)
      for (int j = 0; j < B; j++)
        for (int k = 0; k < C; k++)
          fill(memo[i][j][k], memo[i][j][k] + C, -1);
    for (auto c: to_string(n))
      s.push_back(c - '0');
    return stoll(solution(0, 0, 1, 0));
  }

};
