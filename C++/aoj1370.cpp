#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-8;
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define reps(i,j,k) for(int i = (j); i < (k); ++i)
#define rep(i,j) reps(i,0,j)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> Pii;
typedef pair<Pii,int> P;
typedef vector<short> vi;
 
template<class T>
ostream& operator<<(ostream &out, const vector<T> &v){
    out << "{";
    rep(i,v.size()){
        out << v[i] <<", ";
    }
    return out << "}" << endl;
}
string s,q;
short sumS[32][4001];
short sumQ[32][4001];
 
set<vi> memo;
 
bool insertVi(){
    rep(l,s.size()+1){
        reps(r,l+1,s.size()+1){
            vi a(26);
            rep(k,27){
                a[k] = (sumS[k][r]-sumS[k][l]);
            }
            memo.insert(a);
        }
    }
    return true;
}
 
int main(){
     
    cin >> s >> q;
 
    rep(i,s.size()){
        rep(j,26+1){
            sumS[j][i+1] = sumS[j][i] + (s[i]-'a'==j);
        }
    }
 
    rep(i,q.size()){
        rep(j,26+1){
            sumQ[j][i+1] = sumQ[j][i] + (q[i]-'a'==j);
        }
    }
 
    insertVi();
    int ans = 0;
    rep(l,q.size()+1){
        reps(r,l+1,q.size()+1){
            vi a(26);
            rep(k,27){
                a[k] = (sumQ[k][r]-sumQ[k][l]);
            }
            set<vi>::iterator it = memo.find(a);
            if(it != memo.end()){
                ans = max(r-l,ans);
            }
        }
    }
 
    cout << ans << endl;
    return 0;
}