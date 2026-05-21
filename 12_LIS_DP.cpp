#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

// LIS with memoization
int LIS(int i, int p, vector<int> &nums) {

    // Base case
    if (i >= nums.size())
        return 0;

    // Check DP
    if (dp[i][p + 1] != -1)
        return dp[i][p + 1];

    // Skip current element
    int skip = LIS(i + 1, p, nums);

    // Take current element
    int take = 0;

    if (p == -1 || nums[p] < nums[i]) {
        take = 1 + LIS(i + 1, i, nums);
    }

    return dp[i][p + 1] = max(take, skip);
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << LIS(0, -1, nums) << endl;

    return 0;
}
