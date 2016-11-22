#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int C = 1001;
const int A =   51;
const int B =    4;



struct Pricing {

  vector<int>  data;
  int memo[A][B][C];
  int test[A][B][C];

  int maxwin(int idx, int cnt, int cst = 1000) {
    if (idx >= data.size())
      return 0;
    if (cnt <  0)
      return 0;
    if (test[idx][cnt][cst] == 1)
      return memo[idx][cnt][cst];
    int nxt = min(cst, data[idx]), ans = 0;
    ans = max(ans, maxwin(idx, cnt - 1, 1000));
    ans = max(ans, maxwin(idx + 1, cnt,  cst));
    ans = max(ans, maxwin(idx + 1, cnt,  nxt) + nxt);
    test[idx][cnt][cst] = 1;
    return memo[idx][cnt][cst] = ans;
  }

  int maxSales(vector<int> price) {
    sort(price.begin(),  price.end());
    data = price; return maxwin(0, 3);
  }

};


int main() {
  int x;
  vector<int> price;
  while (cin >> x)
    price.push_back(x);
  Pricing * p = new Pricing();

  cout << p->maxSales(price) << '\n';
  return 0;
}
