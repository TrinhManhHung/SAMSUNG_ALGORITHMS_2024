#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(1e9 + 7)
#define endl "\n"
int n;
int a[25];
vector<vector<int>> res;

bool nt(int n){
	for(int i =2; i * i <=n; i++){
		if(n % i == 0) return false;
	}
	return n > 1;
}

void Try(int bd, vector<int> tmp, int cursum){
	for(int j =bd; j <=n; j++){
		cursum += a[j];
		tmp.pb(a[j]);
		if(nt(cursum)){
			res.pb( tmp);
		}
		Try(j+1, tmp, cursum);
		cursum -= a[j];
		tmp.pop_back();
	}
}

bool cmp(vector<int> a, vector<int> b){
	int sz = min(a.size(), b.size());
	for(int i =0; i <sz; i++){
		if(a[i] < b[i]){
			return true;
		}
		else if(b[i] < a[i])
			return false;
	}
	return a.size() < b.size();
}
int main(){
	int t; cin >> t;
	while(t--){
		res.clear();
		cin >> n;
		for(int i =1; i <=n; i++) cin >> a[i];
		sort(a+1, a+n+1, greater<int>());
		
		vector<int> tmp;
		Try(1, tmp, 0);
		
		sort(res.begin(), res.end(), cmp);
		for(auto x : res){
			for(int i =0; i <x.size(); i++) cout << x[i] << " ";
			cout << "\n";
		}
	}
	return 0;
}
