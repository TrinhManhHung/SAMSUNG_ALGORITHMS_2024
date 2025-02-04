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

int n; 
int a[maxn];

bool check(int x){
	int s = 0;
	for(int i =1; i <=n; i++){
		s += a[i];
		if(s == x){
			s = 0;
		}
		else if(s > x){
			return false;
		}
	}
	return true;
}

void solve(){
	cin >> n;
	
	int sum = 0;
	for(int i =1; i <=n; i++){
		cin >> a[i];
		sum += a[i];
	}
	
	set<int> se;
	for(int i =1; i <=sqrt(sum); i++){
		if(sum % i == 0){
			se.insert(i);
			se.insert(sum / i);
		}
	}
	
	for(auto x : se){
		if(check(x)){
			cout << x << endl;
			return;
		}
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
