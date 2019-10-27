class Solution {
public:
     bool divideGame(int N) {
        return N % 2 == 0;
     }

     bool divideGameDP(int N) {
         bool *dp = new bool[N + 1];
         dp[0] = false;
         dp[1] = false;

         for (int i = 2; i <= N; ++i) {
             for (int j = 1; j < i; ++j) {
                 if (i % j == 0 && dp[i - j] == false) {
                    dp[i] = true;
                    break;
                 }
             }
         }
         bool ret = dp[N];
         delete []dp;
         return ret;
     }
};
