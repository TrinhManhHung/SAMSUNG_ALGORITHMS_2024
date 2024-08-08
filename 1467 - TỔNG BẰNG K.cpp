// TỔNG BẰNG K

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll F[k+1]; // F[i][j] la cach tao tong j tinh den phan tu thu i
    memset(F, 0, sizeof(F));
	F[0] = 1;
    
    for(int j =1; j <=k; j++){
    	for(int i =1; i <=n; i++){
    		if(j >= a[i]){
				F[j] = (F[j] % mod + F[j-a[i]] % mod) % mod;
			}
		}
	}
	cout << F[k] << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
