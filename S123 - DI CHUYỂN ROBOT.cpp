// DI CHUYỂN ROBOT
#include <bits/stdc++.h>
using namespace std;

void GG(int &i, int &j, char &huong){
	if(huong == 'b'){
		j += 1;
	}
	else if(huong == 'n'){
		j -=1;
	}
	else if(huong == 'd'){
		i += 1;
	}
	else{
		i -= 1;
	}
}

void LL(int &i, int &j, char &huong){
	if(huong == 'b'){
		i -= 1;
		huong = 't';
	}
	else if(huong == 'n'){
		i += 1;
		huong = 'd';
	}
	else if(huong == 'd'){
		j += 1;
		huong = 'b';
	}
	else{
		j -= 1;
		huong = 'n';
	}
}

void RR(int &i, int &j, char &huong){
	if(huong == 'b'){
		i += 1;
		huong = 'd';
	}
	else if(huong == 'n'){
		i -= 1;
		huong = 't';
	}
	else if(huong == 'd'){
		j -= 1;
		huong = 'n';
	}
	else{
		j += 1;
		huong = 'b';
	}
}

void BB(int &i, int &j, char &huong){
	if(huong == 'b'){
		j -= 1;
		huong = 'n';
	}
	else if(huong == 'n'){
		j += 1;
		huong = 'b';
	}
	else if(huong == 'd'){
		i -= 1;
		huong = 't';
	}
	else{
		i += 1;
		huong = 'd';
	}
}
int main() {
    int n; cin >> n;
    string s; cin >> s;
    
    int cur_i =0, cur_j =0;
    char huong = 'b';
    for(int i =0; i <n; i++){
    	if(s[i] == 'B') BB(cur_i, cur_j, huong);
    	else if(s[i] == 'G') GG(cur_i, cur_j, huong);
    	else if(s[i] == 'R') RR(cur_i, cur_j, huong);
    	else if(s[i] == 'L') LL(cur_i, cur_j, huong);
//    	cout << cur_i << " " << cur_j << endl;
	}
	cout << cur_i << " " << cur_j << endl;
    return 0;
}
