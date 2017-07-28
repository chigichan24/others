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
#define reps(i,j,k) for(ll i = (j); i < (k); ++i) 
#define rep(i,j) reps(i,0,j) 
#define all(a) (a).begin(),(a).end() 
#define MOD 1000000007 
typedef pair<int,int> Pii;
typedef pair<Pii,int> P;
typedef vector<int> vi;
typedef long long ll;
 
template<class T>
ostream& operator<<(ostream &out, const vector<T> &v){
    out << "{";
    rep(i,v.size()){
        out << v[i] <<", ";
    }
    return out << "}" << endl;
}
ll dp[201][201][201];
int main(){
    int n;
    cin >> n;
    vi a;
    rep(i,n){
        string c;
        cin >> c;
        if(c[0] == 'U'){
            a.pb(1);
        }
        else if(c[0] == 'D'){
            a.pb(-1);
        }
    }
    n = a.size();
    dp[0][0][0] = 1;
    rep(i,n){
        rep(j,i+1){
            rep(k,i+1){
                if(a[i] == 1){
                    dp[i+1][j+1][k+1] += dp[i][j][k];
                    dp[i+1][j+1][k+1] %= MOD;
                    dp[i+1][j][k] += dp[i][j][k]*k;
                    dp[i+1][j][k] %= MOD;
                }
                else if(a[i] == -1){
                    dp[i+1][j][k] += dp[i][j][k] * j;
                    dp[i+1][j][k] %= MOD;
                    if(j > 0 && k > 0){
                        dp[i+1][j-1][k-1] += dp[i][j][k] * j * k;
                        dp[i+1][j-1][k-1] %= MOD;
                    }
                }
            }
        }
    }
    cout << dp[n][0][0] << endl;
    return 0;
}
