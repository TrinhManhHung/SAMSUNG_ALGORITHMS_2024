//DÃY CON LẶP LẠI DÀI NHẤT
#include<bits/stdc++.h>
using namespace std;

void Solve(){
	int n; cin >> n;
	string s1, s2; cin >> s1;
	s1 = " " + s1;
	s2 = s1;
	int dp[n+1][n+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			dp[i][j] = 0;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i != j && s1[i] == s2[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[n][n] << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
