#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int LCS(int i, int j, string &s1, string &s2) {

    // Base case
    if (i == s1.length() || j == s2.length())
        return 0;

    // Already computed
    if (dp[i][j] != -1)
        return dp[i][j];

    // Match case
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2);

    // Not match case
    return dp[i][j] = max(
        LCS(i + 1, j, s1, s2),
        LCS(i, j + 1, s1, s2)
    );
}

int main(){
    string s1, s2;

    cin >> s1 >> s2;

    memset(dp, -1, sizeof(dp));

    cout << LCS(0, 0, s1, s2) << endl;

    return 0;
}
