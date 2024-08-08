// TỔ HỢP C(n, k)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)

void solve(){
    int n, k; cin >> n >> k;
    ll F[n+1][n+1]; //F[i][j] = C(k, n)
    for(int i =1; i <=n; i++){
        F[1][i] = i;
        F[i][i] = 1;
    }
    for(int i =2; i <=k; i++){
        for(int j =i+1; j <=n; j++){
            F[i][j] = (F[i-1][j-1] % mod + F[i][j-1] % mod) % mod;
        }
    }
    cout << F[k][n] << "\n";
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}