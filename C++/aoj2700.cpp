#include<bits/stdc++.h>
 
#define reps(i,j,k) for(int i=(j); i<(k); i++)
#define rep(i,j) reps(i,0,j)
#define fs first
#define fr fs
#define sc second
#define pb push_back
#define mk make_pair
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
char moth[] = {'a','i','u','e','o'};
int main(){
    int N;
    while(cin >> N,N){
        string str[100];
        int mx = -1;
        rep(i,N){
            cin >> str[i];
            mx = max(mx,(int)str[i].size());
        }
        string splited[100];
        rep(i,N){
            string tmp = "";
            tmp += str[i][0];
            reps(j,1,str[i].size()){
                rep(q,5){
                    if(str[i][j-1] == moth[q]){
                        tmp += str[i][j];
                    }
                }
            }
            splited[i] = tmp;
        }
        int ans = -1;
        reps(k,1,mx+1){
            string strtmp[100];
            rep(i,N){
                strtmp[i] = "";
                rep(j,min(k,(int)splited[i].size())){
                    strtmp[i] += splited[i][j];
                }
            }
            bool flg = false;
            rep(i,N){
                rep(j,N){
                    if(i == j)continue;
                    if(strtmp[i] == strtmp[j]){
                        flg = true;
                        break;
                    }
                }
                if(flg)break;
            }
            if(!flg){
                ans = k;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
