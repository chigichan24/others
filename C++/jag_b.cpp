#include<bits/stdc++.h>
 
using namespace std;
 
#define reps(i,j,k) for(int i=j;i<k;i++)
#define rep(i,j) reps(i,0,j)
#define pb push_back
#define fs first
#define fr first
#define sc second
#define mk make_pair
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
struct bt{
	char alpha;
	vector<bt> child;
	int score;
	bt(){alpha=-1;}
	bt(char alpha, vector<bt> child,int score){
		this->alpha = alpha;
		this->child = child;
		this->score = score;
	}
};
 
map<char,int> m;
int cnt;
int alphacnt = 0;
 
bt eval(const string &s){
	int p=0;
	if(isalpha(s[p])){
		vector<bt> non;
		return bt(s[p],non,0);
	}
	if(s[p] == '['){
		++p;
		string head = "";
		string tail = "";
		int idxhi = -1;
		int cnt = 0;
		reps(i,p,s.size()){
			if(s[i] == '['){
				++cnt;
			}
			else if(s[i] == ']'){
				--cnt;
			}
 
			if(cnt == 0 && s[i] == '-'){
				idxhi = i;
				break;
			}
		}
		reps(i,p,idxhi){
			head += s[i];
		}
 
		reps(i,idxhi+1,s.size()-1){
			tail += s[i];
		}
		vector<bt> child;
		child.pb(eval(head));
		child.pb(eval(tail));
		return bt(-1,child,0); 
	}
}
bool ans = true;
 
bt dfs(bt node){
	if(node.child.size()==0){
		return node;
	}
	else{
		vector<bt> v;
		bool flg = false;
		int memo=0;
		rep(i, 2){
			bt tmp = dfs(node.child[i]);
			v.pb(tmp);
			if(m[tmp.alpha] == tmp.score){
				flg = true;
				memo = 1 - i;
			}
		}
		if(!flg) ans = false;
		v[memo].score++;
		return v[memo];
	}
}
 
int main(){
	int n;
	string s;
	cin >> s;
	int Q = 0;
	bt root = eval(s);
	rep(i,s.size()){
		if(isalpha(s[i])){
			++Q;
		}
	}
	vector<pair<int, char> > data;
	while(Q--){
		string a;
		int b;
		cin >> a >> b;
		m[a[0]] = b;
	}
 
	bt check = dfs(root);
	if(m[check.alpha] != check.score) ans = false;
 
	cout << (ans ? "Yes" : "No") << endl;
 
	return 0;
}