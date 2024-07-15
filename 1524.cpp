//Gia tri nho nhat cua xau

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string s; cin >> s;
        map<char, long long> mp;
        priority_queue<long long> pq;
        for(int i =0; i <s.size(); i++){
            mp[s[i]]++;
        }
        for(auto x : mp){
            pq.push(x.second);
        }
        while(k--){
            long long top = pq.top(); pq.pop();
            top -= 1;
            if(top < 0) top = 0;
            pq.push(top);
        }
        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top() * pq.top();
            pq.pop();
        }
        cout << sum << endl;
    }
    return 0;
}