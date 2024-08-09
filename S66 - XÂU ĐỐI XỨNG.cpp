#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.size();
		s = " " + s;
		int F[n+1][n+1]; // F[i][j] xau doi dung dai nhat tinh tu s[i] den s[j]
		for(int i =1; i <=n; i++) F[i][i] = 1;
		
		for(int len =2; len <=n; len++){
			for(int i =1; i <=n-len+1; i++){
				int j = i +len -1;
				if(s[i] == s[j]){
					if(len == 2){
						F[i][j] = 2;
					}
					else{
						F[i][j] = F[i+1][j-1] + 2;
					}
				}
				else
					F[i][j] = max(F[i+1][j], F[i][j-1]);
			}
		}
		cout << n - F[1][n] << endl;
	}
	return 0;
}
