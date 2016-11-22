#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> p3i;

#define snd second
#define fst first

const int M = 1E6;
const int A = 1E2;

struct 	ShortPalindromes {

  int memo[A][A];
  int test[A][A];
  string s;

  int mincst(int l, int r) {
    if (l >= r)
      return 0;
    if (test[l][r] == 1)
      return memo[l][r];
    int ans = M;
    if (s[l] == s[r])
      ans = min(ans, 0 + mincst(l + 1, r - 1));
    ans = min(ans, 1 + mincst(l + 1, r)),
    ans = min(ans, 1 + mincst(l, r - 1));
    test[l][r] = 1;
    return memo[l][r] = ans;
  }

  string solution(int l, int r) {
    if (l >  r)
      return "";
    if (l == r)
      return string(1, s[l]);
    vector<p3i> nxt;
    if (s[l] == s[r])
      nxt.push_back({0 + mincst(l + 1, r - 1), pii(s[r], 0)});
    nxt.push_back({1 + mincst(l + 1, r), pii(s[l], 1)});
    nxt.push_back({1 + mincst(l, r - 1), pii(s[r], 2)});
    sort(nxt.begin(), nxt.end()); p3i bst = nxt[0];
    if (bst.snd.snd == 0) return string(1, bst.snd.fst) + solution(l + 1, r - 1) + string(1, bst.snd.fst);
    if (bst.snd.snd == 1) return string(1, bst.snd.fst) + solution(l + 1, r - 0) + string(1, bst.snd.fst);
    if (bst.snd.snd == 2) return string(1, bst.snd.fst) + solution(l + 0, r - 1) + string(1, bst.snd.fst);
  }

  string shortest(string base) {
    s = base; return solution(0, s.size() - 1);
  }
  
};
