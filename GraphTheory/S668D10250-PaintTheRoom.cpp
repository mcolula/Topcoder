#include <iostream>

using namespace std;

struct PaintTheRoom {

  string canPaintEvenly(int n, int m, int k) {
    if (k == 1 || n % 2 == 0 || m % 2 == 0)
      return "Paint";
    return "Cannot paint";
  }

};
