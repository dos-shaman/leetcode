class Solution {
 public:
  int integerBreak(int n) {
    if (n == 2)  // 1 * 1
      return 1;
    if (n == 3)  // 1 * 2
      return 2;

    int ans = 1;

    while (n > 4) {
      n -= 3;
      ans *= 3;
    }
    ans *= n;

    return ans;
  }
};