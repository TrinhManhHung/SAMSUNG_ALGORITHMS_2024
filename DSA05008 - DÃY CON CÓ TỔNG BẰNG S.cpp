// DÃY CON CÓ TỔNG BẰNG S

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, s; cin >> n >> s;
    int dp[n+5][s+5]; //dp[i][j] = 1 co the tao ra tong bang j bang i phan tu dau
    memset(dp, 0, sizeof(dp));
    int a[n+1];
    for(int i =1; i <=n; i++){
        cin >> a[i];
    } 

    dp[0][0] = 1;
    for(int i =1; i <=n; i++){
        dp[i][0] = 1;
        for(int j =1; j <=s; j++){
            if(j >= a[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[n][s] == 1) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}