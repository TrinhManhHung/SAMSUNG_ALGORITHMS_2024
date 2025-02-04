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

bool cmp(pii a, pii b){
	if(a.se > b.se) return true;
	return false;
}
void solve(){
	vector<pii> v;
	int s = 0;
	for(int i =0; i <3; i++){
		int x, y; cin >> x >> y;
		if(x > y) swap(x, y);
		v.pb({x, y});
		s += x * y;
	}	
	int canh = sqrt(s);
	if(canh * canh != s){
		cout << "NO";
		return;
	}
	
	sort(v.begin(), v.end(), cmp);
//	for(auto x : v) cout << x.fi << " " << x.se << endl;
	if(v[0].se == v[1].se && v[1].se == v[2].se && v[2].se == canh){
		if(v[0].fi + v[1].fi + v[2].fi == canh){
			cout << "YES\n";
			return;
		}
		else cout << "NO\n";
	}
	else{
		bool check = true;
		if(v[0].se != canh) check = false;
		int tmp = 0;
		for(int i =1; i <=2; i++){
			if(v[i].fi + v[0].fi == canh) tmp += v[i].se;
			else if(v[i].se + v[0].fi == canh) tmp += v[i].fi;
			else check = false;
		}
		if(check && tmp == canh) cout << "YES";
		else cout << "NO";
	}
}	

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.inp", "w", stdout);
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
8 2
1 6
7 6
**/
