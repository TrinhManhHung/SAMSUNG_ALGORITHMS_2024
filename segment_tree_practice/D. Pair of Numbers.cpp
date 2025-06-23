//https://codeforces.com/contest/359/problem/D

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF INT_MAX
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define COUNT_ONE(x) __builtin_popcountll((x))
#define COUNT_LEAD_ZERO(x) __builtin_clzll((x))
#define COUNT_TRAIL_ZERO(x) __builtin_ctzll((x))
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
const int maxVal = 1000000;

struct SegmentTree{
	int n;
	vector<pii> tree; //<min, gcd>
	
	SegmentTree(int _n){
		n = _n;
		tree.assign(4*n+5, {0, 0});
	}
	
	void update(int i, int tl, int tr, int pos, int val){
		if(tl == tr){
			tree[i] = {val, val};
			return;
		}
		
		int mid = (tl + tr) >> 1;
		
		if(pos <= mid) update(2*i, tl, mid, pos, val);
		else update(2*i+1, mid+1, tr, pos, val);
		
		tree[i].fi = min(tree[2*i].fi, tree[2*i+1].fi);
		tree[i].se = __gcd(tree[2*i].se, tree[2*i+1].se);
	}
	
	pii get(int i, int tl, int tr, int l, int r){
		if(r < tl || l > tr){
			return {maxVal, 0};
		}
		if(l <= tl && tr <= r){
			return tree[i];
		}
		
		int mid = (tl + tr) >> 1;
		pii part1 = get(2*i, tl, mid, l, r);
		pii part2 = get(2*i+1, mid+1, tr, l, r);
		
		return {min(part1.fi, part2.fi), __gcd(part1.se, part2.se)};
	}
	
	bool check(int l, int r){
		pii tmp = get(1, 1, n, l, r);
		return (tmp.fi == tmp.se);
	}
};

void solve(){
	int n; cin >> n;
	int a[n+1]; 
	SegmentTree segTree(n); 
	
	FOR(i, 1, n){
		cin >> a[i];
		segTree.update(1, 1, n, i, a[i]);
	}
	
	int miVal = 1, maVal = n;
	int len = 1;
	
	while(miVal <= maVal){
		int mid = (miVal + maVal) >> 1;
		bool check = false;
		
		FOR(left, 1, n - mid +1){
			if(segTree.check(left, left + mid -1)){
				check = true;
				break;
			}
		}
		
		if(check){
			len = mid;
			miVal = mid + 1;
		} else{
			maVal = mid - 1;
		}
	}

	vi res;
	FOR(left, 1, n - len + 1){
		if(segTree.check(left, left + len -1)){
			res.pb(left);
		}
	}
	
	cout << res.sz << " " << len-1 << endl;
	for(auto x : res) cout << x << " ";
	cout << endl;
}

int main(){
   faster();
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
	
YJYYYJJ?7???7!!!~~~~~~~~~~~~~^^~~^::::::^~~~~~~~^77?77?!!7777!~~~~~~~~~~~~~^^^!!~!!!!~~~!!!!!!!!!!~^^^^~7???77?YP5!^^::^
YJYYYJJJ77~^^^~~~!7????7!~~~~~~~~~~^::::^~~~~!!~^~~~~~~^^^~~~^^::^^^^^^^^^:::^!?7???7777??????77!~::::::~77777?J5Y!~^^^^
YYYYYJJ7~^^~~~!!?JJ?????J?7~^^^^^^^:^:::^~~~!7??7777777777!!!!!~~^:::^^::^~7?Y555555555PPGGPPPP55YJ7~^^^^~!!!!!!!!!!!~~^
YYY5YJJ7!~~~~!7?????????7J?7!^^^^^^^::::^~~~~!!7!!!!!!!7777???!~^^:::::~?Y555PPPPPGGGGGGPPPPP55PP555J7~^~!!!!!77777?~~^^
YYYYJYY?!!!!!!7?7?77????7??77!!!~~~^^^::^~~~~!77!~!7?????7!!~~~^::::^7Y55YY555PPPPPGGGGGPPP55555555555Y7~!~!!!!!!!!!~^:^
YYYYY5?!^~~~~!~!!!!!!!!!!!7!!!!!!!!^^:::^~~~~7JJ??7?YY55YYJ?7!!!~^^?5PPPPGGGPPPPPGGGPPPP555YYJJJJ?JJJJJYJ!7!~~~~~!~~^:::
YJJYJY?!~~~~!7?JJJJJJJ??77!!~~~~~~^^::::^~~~~!JJJJYY?777777777!~~?5PPPGGGGGGBBBBGGB###BY55Y5YYYYYJJJJJJ?JJ!!??7777!!!~^^
YJYJ?J?77!!!7J5PPPPPPGGGGPY!~~~~~^:^::::^~~~~!?JJ?5PPPPPPP5555Y?YGGGGGGGGGBP?~^^^^^^~?GBYP555555555555Y5Y5Y7~77!!!!!!^::
JYYJJ?7?777????JY555PP5PGGY!~~~~~^:^::::^~~~~!?YJY555YYYYJJJY?7PGGGGBBGGGBY^..........:GGPP5P555555555555P557~?????7!!~^
?YJJ????77?YJ7?JYP5PPP55GGJ!~~~~~^:^::::^^~~~~7JYGGPPPPPP5JJ?!5BGBGBGGBGBJ.............^GPP5PP5555555PP55PPPY7!?7????77!
JJJ?7???7!7JJ?!?5PPPPP55PGJ~~~~~~^:^::::^^^~~~!7YGP555PPP5J?7JBGGBBBBBPGY.........:::...?PYPPP5P55555PPPPPPP5Y77YYYYYYYJ
JJYJ?7!7??JJYPY?YPPPP555PGJ!~~~~~^:^::::^^^~~~~!YGP555PPPY?!!PBGGBBBGPJP?........!???7!~!GJPPPPPP5555PGPPPPPP5J7555YJY?!
JJYJ?7!?JYYYP55Y?JPPPP55PGJ!~~~~~^::::::^^^~~~^~JGP555PPPY?~7GBGGBGBGJ!~^:.....::^^::....Y!Y5GPGPP555GGPPPPPP5Y?PPGPJJ^:
JJJJ??7J555PP555Y??PPP55PGJ!~~~~~^::::::^^^~~~^^?P5YYYPPPY7~JBGBGBBBBJJ!:.....:::::^~~^^:7!?JPPGPPP55GBGGPGPP55J55G5?7^^
JJJ??77YY5PPP55555??5P55GGJ!~~~~~^::::::^^^^^~^^!YYJYYPPPY7^JBGBGGGG?7&#5^....:::!YYJ5GGP5J7??PGPPPPPPPGGGGGPPPYJ5P5!~^^
JJY??!7YYPPP5555555J7JY5PGJ!~~~~~^::::::^^^^^~^^!YJJJJ5PPY!^?BGBBPJP^^5B#J....::^~^.~B@&#&&#G?PGPPPPGY^JBGGGPPPYJ5P5!~^^
JJY?7!J55PPP55555555J7?YPGJ!~~~~~^:^::::^^^^^^^^7PP55Y5GPY!^7GGG#BJY!.YJ5Y:...:::.  !YB#GGB&J!GGPPPPGJ~JBGGGPPP5J5P5!~^^
YYY?7?Y5PPP5555555555J7JGGJ!~~~~~^:^::::^^^^~!~^!JJJ??YY5J!^~PBG#@B!!.~7!7:...:.:.  7J7YYJPY^!GGPPPPP7!5BGGGPPPPJ5P5!~^^
JYJ??JYPPP555555555555Y7YGY!!~~~~^:^::::^^^~!!!^^^^^^~~^^^^~~?#BG&@J^:^!~^........  .!!!~~!^^JBGGPGGJ!!PGGGGPPPPJYP5!~^^
JJJ???YPPP5555555555555Y7YY7!~~~~:::::::^^^^~~~^~^~~^~~^~~^^~!P###@5^^~!7.........::::^:.:^^7PPBGGG5!!JGBGGGPPPG7^~~~~^^
?JJJJJPPP555555555555555Y?77!~~~~::^^^^^^^^^~~~^^^^^^^^^^~^^^^J###&B~::.::.......:^^^^::.:^!?~PGPP5?YB#BBGGGPPPP7^~^^~^^
JJJJ?5PPP5YY55555555555555?!~~~~~:::::::::::::::::::::::::::::7###&@P^....................^::YPJPGG#&#BBBGGGPPPP?^^^^^^^
JJJ?JPPP5Y!!?Y55555YJY55555J!~~~~:^^^^^^^^^^^~~~^^^^^~~~~^^^^^7P###&&G!...:::..............:?Y!Y#&&###BBBGGGPPPPJ:::::::
????PPPP55!~!!?YY?7~!J555555J!~~~:^^^^^^^^^^^^^^^^^^^^^^^^^^^^77P####&&P!..:...........::^~!!~7B######BBBGGGPPPPY~^^^^^^
7??YPPP55P7~~^~!!~^^!Y5555555Y!~~::::::::^::::::^^^!77??77~^::7~7######&&5^.....::::^~~!!!~~~~P#B#####BBBBGGPPPGP7^:::::
!??PPP55YJ7!^::^^:^~!Y55555555Y!~:::::::^^^^^^:::^Y555555P?^^:J^~BBB#####&#5Y5PGP~~!!!~~~~~~~!BBB##BBBBBBBBGGPPPPPJ!~^^~
7?YP5J?7~~^:::::^~~^^!J55555555Y!^^:::::^^^^!^:::~YYYYYY5PJ~^^J::PBBB#####&&&&&@P^~~~~~~~~~~~!B#BB#BBBB#BBBGGPPPPGGJ!???
7J5P5J?77!!~^^^^^~^^::^7Y5555555Y7~^::^^^^^^!^::::?JYYY55PJ~^77.:PGBBB######&&&&J^~~~~~~~~~~~~Y&###BBBBBBBBBGGPPPPGYYP5Y
7JPPPPPPPPGY!^~J55YYJJ??Y555555Y7^!^^^^^^^^^~~~::^JYYYY5PPJ!~Y^:~GGBBB#####&&&&G~~~~~~~~~~~~~~^!JP####BBBBBBBGGPPPPYJYYY
?YPPP55555GY~^755555555555555Y7~^:~~^^^^^^^~~~^^^^????JYY5?~??^^5BGBBB######BPJ7^~~~~~~~~~~~^:.:::!YPGGBB###BGGGPPY!^:::
7YPP555555GY~~?5555555555555?~~~~:^!~^^^^~~~^^^^^~!!!!!!~~^!J^!PBGGBB##BPYJ?7!7~~~~~~~~~~^::::::......::^~?5B#GGGPP!~^^^
75PP555555G57?Y55555555555J~:^^^^:^^!^^^^^^^^^^^^^^^^^^^^:^?~JGBGGBBB#B5?77!~~~~~~~~^^^^:::::...............^JBBGPP7~:^^
?5PP55555555555555555555Y7~~!!!!!!!!!!^~!!!!!!!!!!!!!!!!!!JJPBBGGBBBBBP?7?777!!!~^^:...::.................... !BBGPY!^^^
7PPP55555555555555555P5?!!!!7777777777!^7777777777777777!JPGBBGGBBBBBPJ!77!!!~^:.::.. ::...................... ?BGPGY7!7
?PPP55555555555555555J7!!!!!!!!!7777777~^77777777777777!?PGBBGGBBB#B57!!!~~~~:....:...:^.......................:GBGGP?77
YPPP55555555555555PY7!!!!!!!!!!!!777777?:~J?77777!7777!?GBBBGGBB##P7~~!~^^^::......:...^:.......................GBGGGJ!7
JYPP55555555555555?!!!!!!7??????????!^^^^:^~~!!7777777?GBBBGGBBBP?~~^^:...:........:....^:..^:.................:GBGGGY77
YJYPP5555555555P57!!!!77!J5555555555YYYY?~^^^^^^^^~7?JPBBBGGBB57^:.::...:::::.......:....:::7^.................~BBGGG577
Y5JJY55555555PPGY!!77777!JYYYYGGGPPPPPPP7^^::::..:...:^~JGBB5!:. ........:...........::....~7^.................?BBBGPP?7
555YY5555555PGGBY!777777!JYYJYBBGGGGGGGGY7??YJ~:.........:??:..............:.........::...^:::::::.............PBBBBGP55
Y555555P55555PGBY!777777!JYJJYGPPPPPGGG5:..::^:.............:...::::........::...........^.  ::...::::........:BBBBBGGGP
YYY55P555PPPPPPBY!777777!JY??JPPP5PPPPPP?!77!~^:.............^:...:. .:.................~^...^.... ....::::::.:YBBBBGGGG
5YYYY5P555GGGPPGY!777777!JJ??JPPPPPPPPPPPJ!~~^:...............:!?~:...:...............^~!:..^^.......     ... :5BBBBGGGP
Y????YP555PPPPPGY!777777!JJ77JPPPGGPPPPPP7^^^~^:::.............!YJ!~~:::::^^:.......:^~!!::^^.......   ....  :PBBBGGBGPP
YJJJJ5P5Y55PPPPGY!!777777JJ!7JP55PP555PPJ^!7777777~^::.........7JJ::^!!!~~~~^:....:^~~~!^:^:. ...............5BBBGPGBG55
5555555YY5PPPPGBY!7777777JJ!!JP5PPPP5P555?!~!!777!!!!!~^^:....:YY7....!^:~!!^^^::~!!~~!!^^:.................?#BBGPPBBG55
555555555555PGBBY!7!77777JJ!!JP5PPPPPP55PP5J7!!!~~~~~!!!?77!!~J5J:....~.  .^~!!!!!!!!!7~~::................!BBBG55GBBG55
?Y5PPP55555PPGBBY!7777777JJ!~JPP555555PPPP555Y?!~~~~~!!!7777PGPY7~:.:!~ ...  ..^~~!!!!!~^^:...............~JYPBG555P55YJ
!~!7J5P55Y55PGGB5!7777777JJ!~?PPP55555555P55YYYYJ7~~~!!!7?7?GG5Y!!~^!7:.......    ......:^~~^:...........^~??~!75G55PP5Y
?7?J5P555555PPGB5!7777777JJ!!?PPP555PPP5P55555PPJ!7~~!!!7??YPP5J7!~!!!..........   .::^....:^~:.........^^^^5!Y?~YPGGGP5
55555PPPP55555GB5!7777777JJ!!?P5Y5PPPPPPP5555PPY!!7!~!!!77??77!!!!!!7~ ..........   ..::....::^:.......^~7P^:?^PY^PGP5J?
55PPPPPPGGPPP55B5!7777777JJ!!?PY5PPPPPGPPPPP555!~77?!!!!7!7?7~~~~~!!7:.............    ......^^^::... ^?^YGJ:^^?G7~PP5YY
5PP5Y5PGPP5YPP5G5!7777777JJ!!JPPPPP5Y555PPPPY?~^~!???!!!!~7??!!!~!~~~................  ...  .:^^^::. :Y~JJPY~^:!P?:PP555
PPPP555PP555555B5!7777777JJ!!?PPPPPP5555PPPP5~^^~~!!7?7!~~!??!!!!!~~~......................  .:^....:YY:P?PY^J:~5:!PPP55
PPPP5PPGGGPPPPGB5!7777777?J!!?P5YY5PPPPGGPPPP?^^:^^^~?!^~~7J7~!!~~~~~........................ ......JG5:J555^J^:^~555555
PPPP55PP55PGGBBB5!7777777?J!!?P55YYY555PPPPPPP5J?~^^~!~^~~??!!!!~~~~~: ...........................:7PGG5^~?Y^?^^:YYYYYYY
PPP5PPP5YYYPGPGB5!7777777?J!!?PP55YYYJJYYPGPPP555PY!!~^^~~77~!!!~~~~~~.........................::!JPGGGGPJ!!!~!5:?5Y?7JY
5555555P55PPPPPB5!7777777?J7!7PPP55YYYYYYY5PGGGP5YJ!~~^~~~7!~!!!~~~~~~!:...................:::^!7~:~5PPPPP5JP?7P!^P5YJ5P
JYYYYY55PPPP55PB5!7777777?J7!755PP55555555555PPPY!~~^^^^^!7~~!!!~~~~~~!~:...............::^^~!77~...^5GPPPPJ5Y7P7:PPPP55
!!!!!!77777??J5P5!!777777?J7!75PP555PPPPPPP555PPY7~^^^^^^!!~~!!!!~~~~~!^~:........:::^~~!!!!!!!!:....:YGP55YJPYY~~PP5555
77!!!!!!!!~~~~!77!7777777??7!7?JJJJYYY555PPPPPPPPP55YJ!!!!!!~!!~~~~~~~!~^~....:^~~!!!!!!~~~~~~:^^.... :JP555Y5P5~YPPPPPP
77777777777777!7!77777777!!!!!!!!!!!!!!77??JJJYYYY55PPJ77!!!!!!!~~~~~~!!~^.:^~~~~~!!~~~~~~^:::..^:......?PPP55555P5PP5Y5
**/