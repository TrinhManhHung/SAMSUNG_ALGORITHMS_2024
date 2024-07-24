// TÍNH P(N, K)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)

ll p[1005][1005]; //p[i][j] = p(k, n)
int main(){
	int t; cin >> t;
	while(t--){
	    int n, k; cin >> n >> k;
	    memset(p, 0, sizeof(p));
	    for(int j =0; j <=n; j++){
	        p[0][j] = 1;
	    }
	    for(int i =1; i <=k; i++){
	        for(int j =i; j <=n; j++){
	            p[i][j] = (p[i-1][j-1] % mod * j % mod) % mod;
	        }
	    }
	    cout << p[k][n] << endl;
	}
}