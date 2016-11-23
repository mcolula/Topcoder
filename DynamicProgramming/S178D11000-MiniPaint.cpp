#include <iostream>
#include <vector>

using namespace std;

const short B = 3001;
const short X = 5000;
const short A =   51;

struct 	MiniPaint {

  short memo[A][A][3][B];
  short data[A][A];
  short N;
  short M;

  short mincst(short row, short idx, short clr, short cnt) {
    if (row >= N)
      return 0;
    if (memo[row][idx][clr][cnt] >= 0)
      return memo[row][idx][clr][cnt];
    if (idx >= M)
      return memo[row][idx][clr][cnt] = mincst(row + 1, 0, 2, cnt);
    short ans = mincst(row, idx + 1, clr, cnt) + (clr != data[row][idx]);
    if (cnt >  0)
      ans = min(ans, mincst(row, idx + 1, data[row][idx], cnt - 1));
    return memo[row][idx][clr][cnt] = ans;
  }

  int leastBad(vector<string> picture, short maxStrokes) {
    N = picture.size(); M = picture[0].size();
    for (short i = 0; i < N; i++)
      for (short j = 0; j < M; j++)
        data[i][j] = picture[i][j] == 'W';
    for (short i = 0; i < A; i++)
      for (short j = 0; j < A; j++)
        for (short k = 0; k < 3; k++)
          fill(memo[i][j][k], memo[i][j][k] + B, -1);
    return mincst(0, 0, 2, maxStrokes);
  }

};
