#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		int a[n+1];
		for(int i =1; i <=n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		
		int res = INT_MAX;
		int ans = -1;
		for(int i =1; i <=n-2; i++){
			if(ans == m) break;
			for(int j =i+1; j <=n-1; j++){
				int l = j+1, r =n;
				while(l <= r){
					int mid = (l + r) / 2;
					if(a[mid] + a[i] + a[j] == m){
						ans = a[mid] + a[i] + a[j];
						res = 0;
						break;
					}
					else if(a[mid] + a[i] + a[j] > m){
						r = mid - 1;
					}
					else if(a[mid] + a[i] + a[j] < m){
						if(abs(a[mid] + a[i] + a[j] - m) < res){
							res = abs(a[mid] + a[i] + a[j] - m);
							ans = a[mid] + a[i] + a[j];
						}
						l = mid + 1;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
