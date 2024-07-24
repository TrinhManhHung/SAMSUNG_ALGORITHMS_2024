//PHÂN TÍCH SỐ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector<int> res[1005];
int idx;
vector<int> tmp;
void Try(int bd, int cur_sum){
	for(int j=bd; j>=1; j--){
		tmp.pb(j);
		if(cur_sum + j == n){
			idx++;
			res[idx] = tmp;
		}
		else if(cur_sum + j < n){
			Try(j, cur_sum + j);
		}
		tmp.pop_back();
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		idx = 0;
		for(int i=1; i<=1000; i++) res[i].clear();
		
		cin >> n;
		Try(n, 0);
		for(int i=1; i<=idx; i++){
			cout << "(";
			for(int j=0; j<res[i].size()-1; j++){
				cout << res[i][j] << " ";
			}
			cout << res[i][res[i].size()-1] << ") ";
		}
		cout << endl;
	}
	return 0;
}
