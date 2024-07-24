//ĐỔI CHỖ CÁC CHỮ SỐ
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int k; string s;
		cin >> k >> s;
		int n = s.size();
		s = " " + s;
		int idx = 1;
		while(k >= 1 && idx <= n-1){
			int tmp = idx;
			for(int j=idx+1; j<=n; j++){
				if(s[j] >= s[tmp]){
					tmp = j;
				}
			}
			if(s[idx] < s[tmp]){
				swap(s[idx], s[tmp]);
				k--;
			}
			idx++;
		}
		for(int i=1; i<=n; i++) cout << s[i];
		cout << endl;
	}
	return 0;
}
