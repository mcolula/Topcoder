#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ison(i) (msk & (1 << i))
#define turn(i) (msk | (1 << i))
typedef vector<int> vi;
typedef long long  lld;


const int A = 16;

struct Deranged {

  vi data; map<vi, lld> memo[A];

  vi drop(vi nums, int i) {
    nums[i]--; return nums;
  }

  vi acum(vi & nums) {
    vi ans(A);
    for (auto & i: nums)
      ans[i]++;
    return ans;
  }

 vi debug;

  lld count(int idx, vi nums) {
    if (idx >= data.size())
      return 1;
    lld ans = 0;
    if (memo[idx].find(nums) != memo[idx].end())
      return memo[idx][nums];
    for (int i = 0; i < A; i++)
      if (nums[i] > 0 && i != data[idx])
        ans += count(idx + 1, drop(nums, i));
    return memo[idx][nums] = ans;
  }

  lld numDerangements(vi nums) {
    data = nums; return count(0, acum(nums));
  }

};
