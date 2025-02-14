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
#define MOD (ll)(1e9 + 7)
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define REP(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush

void solve(){
	int n; cin >> n;
	vi v;
	while(n--){
		string type; cin >> type;
		if(type == "add"){
			int x; cin >> x;
			if(!v.sz) v.pb(x);
			else{
				auto idx = lower_bound(v.begin(), v.end(), x);
				v.insert(idx, x);
			}
		}
		else if(type == "del"){
			int x; cin >> x;
			v.erase(find(v.begin(), v.end(), x));
		}
		else{
			cout << v[(v.sz-1)/2] << endl;
		}
	}
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.out", "w", stdout);
  	}
//    int t; cin >> t;
//    while(t--){
        solve();
//    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/