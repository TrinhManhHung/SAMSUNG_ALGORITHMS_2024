//https://codeforces.com/problemset/problem/296/C

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
const int maxn = 100005;

int n, m, k;
ll BIT[maxn];
ll a[maxn], pre1[maxn], pre2[maxn];

void update(int pos, ll val){
	for(; pos <=n; pos += pos & -pos){
		BIT[pos] += val;
	}
}

ll getSum(int pos){
	ll res = 0;
	for(; pos >0; pos -= pos & -pos){
		res += BIT[pos];
	}
	return res;
}

void solve(){
	memset(BIT, 0, sizeof(BIT));
	memset(pre1, 0, sizeof(pre1));
	memset(pre2, 0, sizeof(pre2));
	cin >> n >> m >> k;
	 
	FOR(i, 1, n){
		cin >> a[i];
	}
	
	vector<pair<pii, ll>> v; //{<li, ri>, di}
	v.pb({{0, 0}, 0}); 
	FOR(i, 1, m){
		int l, r; ll d; cin >> l >> r >> d;
		v.pb({{l, r}, d});
	}
	
	while(k--){
		int l, r; cin >> l >> r;	
		pre2[l]++; pre2[r+1]--;
	}
	
	FOR(i, 1, m){
		pre2[i] += pre2[i-1];
	}
	FOR(i, 1, m){
		v[i].se *= pre2[i];
//		SHOW2(v[i].fi.fi, v[i].se);
		update(v[i].fi.fi, v[i].se);
		update(v[i].fi.se+1, -v[i].se);
	}
	
	FOR(i, 1, n){
		cout << a[i] + getSum(i) << " ";
	}
	cout << endl;
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