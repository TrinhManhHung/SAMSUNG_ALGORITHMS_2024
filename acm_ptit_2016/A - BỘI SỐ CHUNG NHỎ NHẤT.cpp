//https://www.spoj.com/PTIT/problems/PTIT016A/

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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF INT_MAX
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

void solve(){
	ll a, b; cin >> a >> b;
	
	if(a == b){
		cout << 1 << endl;
		return;
	}
	if(a > b) swap(a, b);
	ll sub = b - a;
	
	ll min_lcm = lcm(a+1, b+1);
	ll res = 1;
	
	
	for(int i = 1; i * i <= sub; i++){
		if(sub % i == 0){
			vll v; 
			v.pb(i); v.pb(sub/i);
			for(ll g : v){
				ll n = (g - a % g) % g;
				if(!n) n = g;
				ll cura = a + n;
				ll curb = b + n;
				ll cur_lcm = lcm(cura, curb);
				
				if(cur_lcm < min_lcm || (cur_lcm == min_lcm && n < res)){
					min_lcm = cur_lcm;
					res = n;
				}
			}
		}
	}
	
	cout << res << endl;
}

int main(){
    faster();
    int t = 1;
//    cin >> t;
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