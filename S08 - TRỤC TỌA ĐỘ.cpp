#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(1e9 + 7)
#define endl "\n"

bool cmp(pair<int, int> x, pair<int, int> y){
	return x.second < y.second;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		pair<int, int> a[n];
		for(int i =0; i <n; i++){
			int x, y; cin >> x >> y;
			a[i] = {x, y};
		}
		sort(a, a+n, cmp);
		
		int cnt = 0, curFinish = 0;
		for(int i =0; i <n; i++){
			if(a[i].first >= curFinish){
				curFinish = a[i].second;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
