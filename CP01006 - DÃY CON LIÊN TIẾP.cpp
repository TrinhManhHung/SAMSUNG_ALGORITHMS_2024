// DÃY CON LIÊN TIẾP

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n+1];
    for(int i =1; i <=n; i++) cin >> a[i];
    long long dp[n+1];
    memset(dp, 0, sizeof(dp));
    for(int i =1; i <=n; i++){
        if(dp[i-1] < 0) dp[i-1] = 0;
        dp[i] = dp[i-1] + a[i];
    }
    cout << *max_element(dp+1, dp+n+1) << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}