#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)

int main(){
	int n, x, y, z; cin >> n >> x >> y >> z;
	pair<int, int> a[n + 1];
	set<int> salary;
	for(int i =1; i <=n; i++){
		int u, v; cin >> u >> v;
		a[i] = {u, v};
		salary.insert(u);
		salary.insert(v);
	}
	
	int ans = 0;
	for(int sal :salary){
		int tmp = 0;
		for(int i =1; i <=n; i++){
			if(sal >= a[i].first && sal <= a[i].second){
				tmp += y;
			}
			else if(sal < a[i].first)
				tmp += x;
			else
				tmp += z;
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
