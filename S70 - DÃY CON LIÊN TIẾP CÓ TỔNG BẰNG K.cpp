#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n; ll k; cin >> n >> k;
		ll a[n+1];
		for(int i =1; i <=n; i++) cin >> a[i];
		bool res = false;
		unordered_map<ll, int> mp; mp[0] = 1;
		ll sum = 0;
		for(int i =1; i <=n; i++){
			sum += a[i];
			if(sum >= k){
				if(mp[sum - k] == 1){
					res = true;
					break;
				}
			}
			mp[sum] = 1;
		}
		if(res) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}