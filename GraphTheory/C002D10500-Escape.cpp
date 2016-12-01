#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> p3i;

#define snd second
#define fst first

const int M = 1E7;
const int N = 500;
const int A = 501;
const int K =   4;

struct Escape {

  int cst[A][A];
  int dis[A][A];

  bool valid(int i, int j) {
    return i >= 0 && i < A && j >= 0 && j < A;
  }

  int is[K] = {1, 0, -1,  0};
  int js[K] = {0, 1,  0, -1};

  int shortestPath(int u, int v) {
    priority_queue<p3i> q;
    int d = dis[v][u] = 0;
    pii p = pii(v, u);
    q.push(p3i(-d, p));
    while (!q.empty()) {
      int curI =  q.top().snd.fst;
      int curJ =  q.top().snd.snd;
      int curD = -q.top().fst; q.pop();
      for (int k = 0; k < K; k++) {
        int nxtI = curI + is[k];
        int nxtJ = curJ + js[k];
        if (valid(nxtI, nxtJ) && cst[nxtI][nxtJ] != 2 && cst[nxtI][nxtJ] + curD < dis[nxtI][nxtJ]) {
          int c = dis[nxtI][nxtJ] = cst[nxtI][nxtJ] + curD;
          pii p = pii(nxtI, nxtJ);
          q.push(p3i(-c, p));
        }
      }
    }
    return dis[N][N] == M ? -1 : dis[N][N];
  }

  void setRangesTo(vector<string> ranges, int value) {
    int x, y;
    int u, v;
    for (auto & range: ranges) {
      stringstream ss(range);
      ss >> x >> y;
      ss >> u >> v;
      int lowerX = min(x, u);
      int upperX = max(x, u);
      int lowerY = min(y, v);
      int upperY = max(y, v);
      for (int i = lowerY; i <= upperY; i++)
        for (int j = lowerX; j <= upperX; j++)
          cst[i][j] = value;
    }
  }

  int lowest(vector<string> harmful, vector<string> deadly){
    for (int i = 0; i < A; i++)
      fill(dis[i], dis[i] + A, M);
    setRangesTo(harmful, 1);
    setRangesTo(deadly , 2);
    return shortestPath(0, 0);
  }

};
