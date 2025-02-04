#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

void solve(){
	ll p, q; cin >> p >> q;
	vector<ll> res;
	while(q % p != 0){
		ll tmp = q / p + 1;
		res.pb(tmp);
		p = p * tmp - q;
		q *= tmp;
	}
	for(int i =0; i <res.sz; i++){
		cout << 1 << "/" << res[i] << " + ";
	}
	cout << 1 << "/" << q / p << endl;
}	

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.inp", "w", stdout);
  	}
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
 
/** HungLam
1/2 + 1/6 
	  (\(\
	 ( 0.0)
	o_(")(")
**/
