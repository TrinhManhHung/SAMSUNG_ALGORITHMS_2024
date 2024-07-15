// XÂU CON ĐỐI XỨNG DÀI NHẤT

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

void Solve(){
	string s; cin >> s;
	int n = s.size();
	s = " " + s;
	int dp[n+1][n+1];
	//tim dp[1][n]
	int res = 1;
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++) dp[i][i] = 1;
	for(int len=2; len<=n; len++){
		for(int i=1; i<= n-len+1; i++){
			int j = i + len - 1;
			if(len == 2){
				if(s[i] == s[j]){
					dp[i][j] = 1;
				}
			}
			else{
				if(s[i] == s[j] && dp[i+1][j-1] == 1){
					dp[i][j] = 1;
				}
			}
			if(dp[i][j] == 1) res = max(res, j-i+1);
		}
	}
	cout << res << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
}
