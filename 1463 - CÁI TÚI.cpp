// CÁI TÚI
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, v; cin >> n >> v;
    int a[n+1], c[n+1];
    for(int i =1; i <=n; i++) cin >> a[i];
    for(int i =1; i <=n; i++) cin >> c[i];

    int dp[n+1][v+1]; //dp[i][j] gia tri lon nhat tinh den do vat i co the tich j
    memset(dp, 0, sizeof(dp));

    for(int i =1; i <=n; i++){
        for(int j =0; j <=v; j++){
            if(j >= a[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + c[i]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][v] << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}