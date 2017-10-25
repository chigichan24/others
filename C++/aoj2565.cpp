#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 2*1e9;
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
 
int main() {
 
    int N;
    while(cin >> N,N){
        int a[1024];
        vi idx;
        bool flg = true;
        rep(i,N){
            string str;
            cin >> str;
            if(str == "x") {
                if(idx.size() > 0 && idx[idx.size()-1]+1 == i){
                    flg = false;
                }
                idx.pb(i);
                a[i] = INF;
            }
            else{
                a[i] = atoi(str.c_str());
            }
        }
        if(!flg){
            puts("none");
            continue;
        }
        int mn = INF;
        int mx = -INF;
        rep(i,idx.size()) {
            if(idx[i] == 0) {
                mn = min(mn,a[idx[i]+1] - 1);
            }
            else if (idx[i] == N-1) {
                if(N%2 == 1){
                    mn = min(mn,a[idx[i]-1] -1);
                }
                else{
                    mx = max(mx, a[idx[i]-1] +1);
                }
            }
            else{
                if(idx[i] % 2 == 0 ){
                    mn = min(mn,min(a[idx[i]-1],a[idx[i]+1])-1);
                }
                else{
                    mx = max(mx, max(a[idx[i]-1],a[idx[i]+1])+1);
                }
            }
        }
 
        rep(i,N) {
            if(a[i] == INF){
                continue;
            }
            if(i == 0) {
                if(a[i+1] == INF){
                    continue;
                }
                if(a[i] > a[i+1]){
                    flg = false;
                }
            }
            else if ( i == N -1) {
                if(a[i-1] == INF) {
                    continue;
                }
                if(N % 2 == 1){
                    if(a[i] > a[i-1]){
                        flg = false;
                    }
                }
                else{
                    if(a[i] < a[i-1]) {
                        flg = false;
                    }
                }
            }
            else{
                if(a[i+1] == INF && a[i-1] == INF){
                    continue;
                }
                if(a[i+1] == INF){
                    if(i % 2 == 1){
                        if(a[i-1] > a[i]){
                            flg = false;
                        }
                    }
                    else{
                        if(a[i-1] < a[i]){
                            flg = false;
                        }
                    }
                }
                else if(a[i-1] == INF) {
                    if(i % 2 == 1){
                        if(a[i+1] > a[i]){
                            flg = false;
                        }
                    }
                    else{
                        if(a[i+1] < a[i]){
                            flg = false;
                        }
                    }
                }
                else{
                    if(i % 2 == 1){
                        if(a[i-1] > a[i] || a[i] < a[i+1]){
                            flg = false;
                        }
                    }
                    else{
                        if(a[i-1] < a[i] || a[i] > a[i+1]) {
                            flg = false;
                        } 
                    }
                }
            }
        }
        if(mn == mx && flg){
            printf("%d\n",mn);
        }
        else if(mn > mx && flg){
            puts("ambiguous");
        }
        else{
            puts("none");
        }
 
    }
 
    return 0;
}