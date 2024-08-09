#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Thong tin moi nguoi
struct Person{
	string name;
	int age;
};

//Giay khai sinh
struct Infor{
	string dad;
	string son;
	int dadAge;
};

bool cmp(Person a, Person b){
	if(a.age != b.age)
		return a.age > b.age;
	else return a.name < b.name;
}
int main(){
	faster();
	int test; cin >> test;
	int t = 1;
	while(t <= test){
		cout << "DATASET " << t << "\n"; 
		//Nhap thong tin giay khai sinh
		int n; cin >> n;
		vector<Infor> v(n);
		for(int i =0; i <n; i++){
			cin >> v[i].dad >> v[i].son >> v[i].dadAge;
		}
		vector<Person> res;
		stack<Person> st; //luu cac bo da co tuoi
		st.push({"Ted", 100});
		//Find all son of the dad at the top of stack
		while(!st.empty()){
			auto top = st.top(); st.pop();
			for(auto x : v){
				if(top.name == x.dad){
					st.push({x.son, top.age - x.dadAge});
					res.push_back({x.son, top.age - x.dadAge});
				}
			}
		}
		//sort all son by age and print
		sort(res.begin(), res.end(), cmp);
		for(auto x : res){
			cout << x.name << " " << x.age << endl;
		}
		t++;
	}
	return 0;
}
//1 4
//Ray James 40
//James Beelzebub 17
//Ray Mark 75
//Ted Ray 20

// DATASET 2
// Ray 80
// James 40
// Beelzebub 23
// Mark 5

