//SỐ BƯỚC ÍT NHẤT
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n+1];
		int dp[n+1];
		for(int i=1; i<=n; i++){
			cin >> a[i];
			dp[i] = 1;
		}
		for(int i=2; i<=n; i++){
			for(int j=1; j<i; j++){
				if(a[i] >= a[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		cout << n - *max_element(dp+1, dp+n+1) << endl;
	}
	return 0;
}
