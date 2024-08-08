// MÃ SỐ

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n; cin >> n;
    vector<string> alpha;
    vector<string> digit;

    //process alpha
    string s = "";
    for(int i =0; i <n; i++){
        s += char('A' + i);
    }
    do{
        alpha.pb(s);
    } while(next_permutation(s.begin(), s.end()));
    //process digit
    string b;
    for(int i =0; i <n; i++){
        b += '1';
    }
    digit.pb(b);
    while(1){
        int idx = n-1;
        while(idx >=0 && b[idx] == char(n + '0')){
            b[idx] = '1';
            idx--;
        }
        if(idx == -1) break;
        b[idx]++;
        digit.pb(b);
    }
    //display
    for(auto x : alpha){
        for(auto y : digit){
            cout << x << y << endl;
        }
    }
    return 0;
}