//DÃY CON TĂNG DÀI NHẤT
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
void Solve(){
	int n; cin >> n;
	int a[n+1];
	for(int i=1; i<=n; i++) cin >> a[i];
	int dp[n+1];
	memset(dp, 0, sizeof(dp)); dp[1] = 1;
	for(int i=2; i<=n; i++){
		for(int j=1; j<i; j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	cout << *max_element(dp+1, dp+n+1) << endl;
}
int main(){
//	int t; cin >> t;
//	while(t--){
		Solve();
}
