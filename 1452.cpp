//DÃY CON CHUNG DÀI NHẤT CỦA BA XÂU
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
void Solve(){
	int n, m, k; cin >> n >> m >> k;
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	s1 = " " + s1; s2 = " " + s2; s3 = " " + s3;
	int dp[n+1][m+1][k+1]; //dp[i][j][k] xau con chung dai nhat tinh den i, j, k
	//tim dp[n][m][k]
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int h=1; h<=k; h++){
				if(s1[i] == s2[j] && s2[j] == s3[h]){
					dp[i][j][h] = dp[i-1][j-1][h-1] + 1;
				}
				else{
					dp[i][j][h] = max ({dp[i-1][j][h], 
										dp[i][j][h-1],
										dp[i][j-1][h]
									});
				}
			}
		}
	}
	cout << dp[n][m][k] << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
}
