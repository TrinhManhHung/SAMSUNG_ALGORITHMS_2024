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

const int maxn = 2e5 + 5;

void solve() {
    int n; cin >> n;
    int a[n+1];
    int b[n+1];
    FOR(i, 1, n){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1, b+n+1);
	int l =0, r =0;
	
	FOR(i, 1, n){
		if(a[i] != b[i]){
			if(l == 0) l = i;
			r = i;
		}
	}
	cout << l << " " << r << endl;
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
