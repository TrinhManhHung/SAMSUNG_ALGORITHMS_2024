#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define INF INT_MAX
const int maxn = 1e5;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

void solve(){
	int n, k; cin >> n >> k;
	vi v(n);
	bool check = false;
	FOR(i, 0, n-1){
		cin >> v[i];
		if(v[i] == k) check = true;
	}
	
	if(check){
		cout << 1 << endl;
		return;
	}
	
	FOR(len, 2, n){
		if(v.sz == 0) break;
		vi v_next;
		for(int i =0; i <v.sz-1; i++){
			int _gcd = gcd(v[i], v[i+1]);
			if(_gcd == k){
				cout << len << endl;
				return;
			}
			if(_gcd > k){
				v_next.pb(_gcd);
			}
		}
		v = v_next;
	}
	
	cout << -1 << endl;
}

int main() {
    faster();
    int t = 1; 
	cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/

