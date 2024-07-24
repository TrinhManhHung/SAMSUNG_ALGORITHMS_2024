// NHÀ KHÔNG KỀ NHAU

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n+1];
    for(int i =1; i <=n; i++) cin >> a[i];
    int dp[n+1]; 
    dp[0] = 0; dp[1] = a[1];
    for(int i =2; i <=n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);
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