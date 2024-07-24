//  TỔ HỢP C(n, k)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
ll dp[1005][1005];
void Solve(){
	memset(dp, 0, sizeof(dp));
	for(int i =1; i <=1000; i++){
		dp[0][i] = 1;
		dp[1][i] = i;
		dp[i][i] = 1;
	}
	for(int i =1; i <=999; i++){
		for(int j =i+1; j <=1000; j++){
			dp[i][j] = (dp[i-1][j-1] % mod + dp[i][j-1] % mod) % mod;
		}
	}
}
int main(){
	Solve();
	int t; cin >> t;
	while(t--){
		int n, k; 
		cin >> n >> k;
		cout << dp[k][n] << endl;
	}
	return 0;
}


// 259 5
// 81
// 58
// 42
// 33
// 61