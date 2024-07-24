// BẬC THANG
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void Solve(){
	int n, k; cin >> n >> k;
	ll dp[n+1]; //dp[i] so cach di den bac i
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=n; i++){
		for(int j=1; j<= min(i, k); j++){
			dp[i] = (dp[i] % mod + dp[i-j] % mod) % mod;
		}
	}
	cout << dp[n] << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
