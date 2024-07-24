// XEM PHIM

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;

int main(){
	int c, n; cin >> c >> n;
	int a[n+1];
	for(int i =1; i <=n; i++) cin >> a[i];
	int dp[n+1][c+1]; //dp[i][j] = 1:den con bo thu i co the tao dc j kg
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int res = 0;
	for(int i =1; i <=n; i++){
		for(int j =0; j <=c; j++){
			if(dp[i-1][j] == 1){
				dp[i][j] = 1;
				if(j + a[i] <= c){
					dp[i][j+a[i]] = 1;
					res = max(res, j+a[i]);
				}	
			}
		}
	}
	cout << res << endl;
	return 0;
}


// 259 5
// 81
// 58
// 42
// 33
// 61