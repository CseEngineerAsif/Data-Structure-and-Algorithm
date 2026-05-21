#include<bits/stdc++.h>
using namespace std;

int price[100];
int dp[100][100];

// i = current rod length piece
// n = remaining rod length
int RC(int i, int n){

    if(n == 0 || i > n)
        return 0;

    if(dp[i][n] != -1)
        return dp[i][n];

    // Skip current piece length
    int skip = RC(i + 1, n);

    // Take current piece length
    int take = price[i] + RC(i, n - i);

    return dp[i][n] = max(take, skip);
}

int main(){
    int n;
    cin >> n;

    // price[1] to price[n]
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << RC(1, n) << endl;

    return 0;
}
