#include<bits/stdc++.h>
using namespace std;

int dp[1000]={-1};
int solve(int n){
    if(n == 0) return 1;
    if(n < 0) return 0;

    if(dp[n] != -1) return dp[n];

    int one_step = solve(n - 1);
    int two_step = solve(n - 2);

    return dp[n] = one_step + two_step;
}

int main(){
    int n = 4;

    memset(dp, -1, sizeof(dp));

    cout << "Ways to climb " << n << " stairs = " << solve(n) << endl;

    return 0;
}
