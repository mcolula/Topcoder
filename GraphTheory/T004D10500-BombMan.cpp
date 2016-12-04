#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;


class BombMan {

  private:

  typedef pair<int, int> pii;
  typedef pair<pii, pii> p4i;

  static const int A = 1E2;
  static const int K = 4E0;
  static const int I = 1E7;

  #define snd second
  #define fst first

  vector<string> dat;
  int dis[A][A];
  int N;
  int M;


  bool valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
  }


  int is[K] = {1, 0, -1, 0};
  int js[K] = {0, 1, 0, -1};

  void shortestPath(int y, int x, int b) {
    priority_queue<p4i> q;
    pii u = pii(0, b);
    pii v = pii(y, x);
    q.push(p4i(u, v));
    dis[y][x] = 0;
    while (!q.empty()) {
      int curD = -q.top().fst.fst;
      int curB =  q.top().fst.snd;
      int curI =  q.top().snd.fst;
      int curJ =  q.top().snd.snd; q.pop();
      for (int k = 0; k < K; k++) {
        int nxtI = curI + is[k];
        int nxtJ = curJ + js[k];
        if (valid(nxtI, nxtJ)) {
          int nxtD = 0;
          int nxtB = 0;
          if (dat[nxtI][nxtJ] != '#') {
            nxtD = curD + 1;
            nxtB = curB + 0;
          }
          if (dat[nxtI][nxtJ] == '#') {
            nxtD = curD + 3;
            nxtB = curB - 1;
          }
          if (dis[nxtI][nxtJ] > nxtD && nxtB >= 0) {
            dis[nxtI][nxtJ]  = nxtD ;
            pii u = pii(-nxtD, nxtB);
            pii v = pii( nxtI, nxtJ);
            q.push(p4i(u, v));
          }
        }
      }
    }
  }

  public:

  int shortestPath(vector<string> maze, int bombs) {
    dat = maze;
    N   = maze   .size();
    M   = maze[0].size();
    int found  = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        dis[i][j] = I;
    for (int i = 0; i < N && !found; i++)
      for (int j = 0; j < M && !found; j++)
        if (dat[i][j] == 'B')
          found = 1, shortestPath(i, j, bombs);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (dat[i][j] == 'E')
          return dis[i][j] == I ? -1 : dis[i][j];
    return 0;
  }
};
