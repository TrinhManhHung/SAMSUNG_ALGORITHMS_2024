// TỔNG SỐ CÁCH DI CHUYỂN

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, k; cin >> n >> k;
    ll F[n+1];
    F[0] = 1;
    F[1] = 1;
    for(int i =2; i <=n; i++){
        F[i] = 0;
        for(int j =0; j <=min(i, k); j++){
            F[i] =( F[i] % mod + F[i-j] % mod) % mod;
        }
    }
    cout << F[n] << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}