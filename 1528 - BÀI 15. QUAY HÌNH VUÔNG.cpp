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
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush

const int maxn = 100005;
const int inf = 1e9;

void change1(vi &v){
	int tmp = v[0];
	v[0] = v[3];
	v[3] = v[4];
	v[4] = v[1];
	v[1] = tmp;
}

void change2(vi &v){
	int tmp = v[1];
	v[1] = v[4];
	v[4] = v[5];
	v[5] = v[2];
	v[2] = tmp;
}
bool check(vi a, vi b){
	for(int i =0; i <6; i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
}

void solve(){
	vi a(6), res(6);
	FOR(i, 0, 5) cin >> a[i];
	FOR(i, 0, 5) cin >> res[i];
	
	queue<pair<vi, int>> Q;
	Q.push({a, 0});
	while(true){
		auto top = Q.front(); Q.pop();
		vi cur1 = top.fi;
		vi cur2 = cur1;
		int cnt = top.se;
		if(check(cur1, res)){
			cout << cnt << endl;
			return;
		}
		
		change1(cur1);
		change2(cur2);
		Q.push({cur1, cnt+1});
		Q.push({cur2, cnt+1});
	}
}

int main(){
    faster();
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