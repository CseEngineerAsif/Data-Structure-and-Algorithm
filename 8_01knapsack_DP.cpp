#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

vector<Item> item;
int dp[105][1005];   // dp[i][cap]

// DP Memoization 0/1 Knapsack
int knapsack(int i, int cap){

    // Base case
    if(i == item.size() || cap == 0)
        return 0;

    // Already calculated
    if(dp[i][cap] != -1)
        return dp[i][cap];

    // Skip case
    int skip = knapsack(i + 1, cap);

    // Take case (if possible)
    int take = 0;
    if(item[i].weight <= cap){
        take = item[i].value + knapsack(i + 1, cap - item[i].weight);
    }

    // Store and return maximum
    return dp[i][cap] = max(take, skip);
}

int main(){
    int n, capacity;
    cin >> n >> capacity;

    item.resize(n);

    for(int i = 0; i < n; i++){
        cin >> item[i].weight >> item[i].value;
    }

    memset(dp, -1, sizeof(dp));

    cout << knapsack(0, capacity) << endl;

    return 0;
}
