// XÂU ĐỐI XỨNG 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;

void Solve(){
	string s; cin >> s;
	int n = s.size(); s = " " + s;
	int dp[n+1][n+1]; //dp[i][j] = 1 neu xau doi xung
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++) dp[i][i] = 1;
	for(int len = 2; len <= n; len++){
		for(int i=1; i<= n-len+1; i++){
			int j = i + len - 1;
			if(s[i] == s[j]){
				if(len == 2){
					dp[i][j] = 2;
				}
				else{
					dp[i][j] = dp[i+1][j-1] + 2;
				}
			}
			else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
		}
	}
	cout << n - dp[1][n] << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}


