#include <iostream>

using namespace std;


const int M = 1E6;
const int A =  51;

struct BoxesArrangement {

  int memo[A][A][A][3][4];
  int test[A][A][A][3][4];
  int data[3];
  string    s;


  int mincst(int a, int b, int c, int cnt, int lst) {
    if (a == data[0] && b == data[1] && c == data[2] && cnt <  3)
      return 0;
    if (a >  data[0] || b >  data[1] || c >  data[2] || cnt >= 3)
      return M;
    if (test[a][b][c][cnt][lst] == 1)
      return memo[a][b][c][cnt][lst];
    int ans = M;
    ans = min(ans, (s[a + b + c] != 'A') + mincst(a + 1, b, c, lst == 0 ? cnt + 1 : 1, 0));
    ans = min(ans, (s[a + b + c] != 'B') + mincst(a, b + 1, c, lst == 1 ? cnt + 1 : 1, 1));
    ans = min(ans, (s[a + b + c] != 'C') + mincst(a, b, c + 1, lst == 2 ? cnt + 1 : 1, 2));
    test[a][b][c][cnt][lst] = 1;
    return memo[a][b][c][cnt][lst] = ans;
  }

  int maxUntouched(string boxes) {
    s = boxes;
    for (auto box: boxes)
      data[box - 'A']++;
    return max(-1, (int)boxes.size() - mincst(0, 0, 0, 0, 3));
  }

};
