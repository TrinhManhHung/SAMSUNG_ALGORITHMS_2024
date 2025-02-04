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
#define MOD (ll)1e9 + 7;
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define REP(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush

void cal1(vi a, vi b, vi &c){ //a.sz < b.sz
	if(!a.sz || !b.sz) return;
	if(a.sz) FOR(i, 0, a.sz-1) c.pb(a[i]);
	if(b.sz >= 2) FOR(i, 0, b.sz-2) c.pb(b[i]);
}

void cal2(vi a, vi b, vi &c){ //a.sz < b.sz
	if(!a.sz || !b.sz) return;
	if(a.sz >= 2) FOR(i, 0, a.sz-2) c.pb(a[i]);
	if(b.sz) FOR(i, 0, b.sz-1) c.pb(b[i]);
}
void solve(){
	int n; cin >> n;
	int a[n+1];
	
	vi v[3];
	FOR(i, 1, n){
		cin >> a[i];
		v[a[i] % 3].pb(a[i]);
	}
	
	FOR(i, 0, 2){
		sort(v[i].begin(), v[i].end(), greater<int>());
	}
	if(abs(int(v[1].sz - v[2].sz)) % 3 == 0){
		if(v[1].sz && v[2].sz){
			FOR(i, 0, v[1].sz-1){
				v[0].pb(v[1][i]);
			}
			FOR(i, 0, v[2].sz-1){
				v[0].pb(v[2][i]);
			}
		}
	}
	else if(abs(int(v[1].sz - v[2].sz)) % 3 == 1){
		if(v[1].sz < v[2].sz) cal1(v[1], v[2], v[0]);
		else cal1(v[2], v[1], v[0]);
	}
	else{
		if(v[1].sz < v[2].sz) cal2(v[1], v[2], v[0]);
		else cal2(v[2], v[1], v[0]);
	}
	
	sort(v[0].begin(), v[0].end(), greater<int>());
	if(v[0].sz == 0){
		cout << -1 << endl;
		return;
	}
	if(v[0][0] == 0){
		cout << 0 << endl;
		return;
	}
	FOR(i, 0, v[0].sz-1) cout << v[0][i];
	cout << endl;
}

int main(){
//    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.out", "w", stdout);
  	}
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/
