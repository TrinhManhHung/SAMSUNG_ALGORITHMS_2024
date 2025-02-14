/*
https://www.spoj.com/PTIT/problems/PTIT018J/
*/
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
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 1e6;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

void solve(){
	string s; cin >> s;
	
	bool check = false;
	FOD(i, s.sz-2, 0){
		if(s[i] > s[i+1]){
			int idxChange = i+1;
			char maxx = s[i+1];
			FOR(j, i+2, s.sz-1){
				if(s[j] > maxx && s[j] < s[i]){
					idxChange = j;
					maxx = s[j];
				}
			}
			check = true;
			swap(s[i], s[idxChange]);
			break;
		}
	}
	
	cout << ((check && s[0] != '0')? s : "-1") << endl;
	
}

int main(){
    faster();
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

