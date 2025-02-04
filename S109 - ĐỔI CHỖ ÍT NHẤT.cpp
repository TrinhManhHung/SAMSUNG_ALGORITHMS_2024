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
	if(a.fi != b.fi){
		if(a.fi < b.fi) return true;
		return false;
	}
	else return a.se < b.se;
}
void solve(){
	int n; cin >> n;
	int a[1005];
	vector<pii> v; //<val, idx>
	v.pb({0, 0});
	for(int i =1; i <=n; i++){
		cin >> a[i];
		v.pb({a[i], i});
	}
	sort(v.begin(), v.end());
	
	bool visited[1005]; memset(visited, false, sizeof(visited));
	int res = 0;
	for(int i =1; i <=n; i++){
		if(!visited[v[i].se]){
			int cur = v[i].se;
			int cycleSize = 0;
			while(!visited[cur]){
				visited[cur] = true;
				cur = v[cur].se;
				cycleSize++;
			}
			res += cycleSize - 1;
		}
	}
	cout << res << endl;
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
	  (\(\
	 ( 0.0)
	o_(")(")
**/

