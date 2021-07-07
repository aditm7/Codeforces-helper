#include <bits/stdc++.h>
using namespace std; 
using namespace std::chrono;

#define ll long long int
#define ld long double
#define endl "\n"

typedef pair<ll,ll> pll; typedef vector<pair<ll,ll> > vpll; typedef vector<ll> vll; typedef vector<vector<ll> > vvll;
typedef vector<char> vcr; typedef vector<vector<char> > vvcr; typedef vector<string> vstr; typedef vector<vector<string> > vvstr;
typedef long long int* iptr; typedef char* cptr;

#define umap  unordered_map
#define uset  unordered_set
#define lb  lower_bound
#define ub  upper_bound
#define pb  push_back
#define mp  make_pair
#define ppb  pop_back
#define all(V) (V).begin(),(V).end()
#define allr(V) (V).rbegin(),(V).rend()
#define sz(X) (ll)X.size()
#define rep(X,A,B) 	for(auto X=A;X!=B;(B>A?X++:X--))
#define fio	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ss	second
#define ff	first
#define max3(A,B,C) max(max((A),(B)),(C))
#define max4(A,B,C,D) max(max((A),(B)),max((C),(D)))
#define min3(A,B,C) min(min((A),(B)),(C))
#define min4(A,B,C,D) min(min((A),(B)),min((C),(D)))
#define ci(X) ll X; cin>>X
#define cii(X,Y) ll X,Y; cin>>X>>Y
#define ciii(X,Y,Z) ll X,Y,Z; cin>>X>>Y>>Z

template<typename T> void d0(T t){ cout<<t<<" "; }
template<typename T> void dall(T t){ cout<<t<<endl; }
template<typename T, typename... Args> void dall(T t, Args... args) { cout<<t<<" "; dall(args...); }
template<class T> ostream& operator << (ostream &os, vector<T> V){for(auto ELEMV:V) os<<ELEMV<<" "; return os; }
template<class T> ostream& operator << (ostream &os, set<T> S){ for(auto ELEMS:S) os<<ELEMS<<" "; return os; }
template<class L, class R> ostream& operator << (ostream &os, pair<L,R> P){ return os << P.first << " " << P.second; }

const ll mod=1e9+7; const ll inf=999999999999999999; const ll MAXN=1e6;

vector<string> vec_splitter(string S) { S += ','; vector<string> res; while (!S.empty()) { res.push_back(S.substr(0, S.find(','))); S = S.substr(S.find(',') + 1); } return res; } void debug_out(vector<string> __attribute__((unused)) args, __attribute__((unused)) int idx, __attribute__((unused)) int LINE_NUM){ cerr << "\n"; } template <typename Head, typename... Tail> void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) { if (idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") "; stringstream ss; ss << H; cerr << args[idx] << " = " << ss.str(); debug_out(args, idx + 1, LINE_NUM, T...); }
#ifdef DEBUG
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

ll pwr(ll A, ll B) {ll ans = 1; while (B){ if (B & 1) ans = (ans * A) % mod; B = B / 2; A = (A * A) % mod;} return ans;}
ll multiplymod(ll A,ll B){ ll res = 0;A %= mod; while (B){if (B & 1) res = (res + A) % mod; A = (2 * A) % mod; B >>= 1; } return res; }
ll inv(ll i){if(i==1) return 1;return (mod-((mod/i)*inv(mod%i))%mod)%mod;}
ll binarysearch(vll arr, ll L, ll R, ll X){ if (R >= L) { ll mid = L + (R - L) / 2; if (arr[mid] == X) return mid; else if (arr[mid] > X) return binarysearch(arr, L, mid - 1, X); else return binarysearch(arr, mid + 1, R, X); } return -1; }
ll fact(ll N , ll MOD=mod){ ll P=1;if (N == 0) return 1; else { for(int i=1;i<=N;i++) {P*=i; P=P%MOD;} return P; }}
ll nCrModp(ll N, ll R, ll P=mod) { if (R > N - R) R = N - R; ll C[R + 1]; memset(C, 0, sizeof(C)); C[0] = 1; for (ll i = 1; i <= N; i++) { for (ll j = min(i, R); j > 0; j--) C[j] = (C[j] + C[j - 1]) % P; } return C[R]; }
int digits(ll N,ll base=2){ if(N==0) return 1; else if(base==10) return floor(log10(N))+1;else return floor(log2(N))+1; }

void solve(){ //pseudocodes are at the end of code
  
}

int main(){
	fio;
  #ifndef ONLINE_JUDGE
  freopen("./getio/output.out","r",stdin);
  freopen("./getio/input.ini","w",stdout);
  freopen("./getio/error.log","w",stderr);
  #endif
  solve();
	return 0;
}
/* pseudocode1: to generate random numbers between a and b:

  srand(time(0));   //set seed first
  ll randomnumber; ll N,a,b;
  for(ll z = 0; z<N; z++)
      randomnumber = (rand() % b) + a;; // generate N random numbers between a and b (b>a)
*/

/* pseudocode2: to generate from a list of numbers:

  srand(time(0));   //set seed first
  ll randomnumber; ll N; vll v={89,87,9127,212}; //the list of numbers
  for(ll i = 0; i<N; i++)
      randomnumber = v[rand() % sz(v)]; // generate N random numbers in the list
*/
/* pseudocode3: to generate random STRING
  static const char alphanum[] =
  "0123456789"
  "!@#$%^&*"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz";
  ll stringlen = sizeof(alphanum) - 1; srand(time(0));
  ll N;string s="";
  for(int z=0; z < N; z++){
    s.pb(alphanum[rand() % stringlen]); //generate string of size N
  }
*/
/* pseudocode4: to generate random CHARACTER OF ALPHABET:

  ll N;char c;ll r; srand (time(NULL)); 
  for (ll z=0; z<N; i++){    
    r = rand() % 26;
    c = 'a' + r;      // Convert to a character from a-z for N times
  }
*/
/* pseudocode5: to generate random decimal numbers between 0 and 1

  ll N; srand(time(NULL)); // initialize the random number generator
  for (int i = 0; i < N; i++) {
    cout << (float) rand() / RAND_MAX << endl; //RAND_MAX is the largest possible number
                                                // which can generated by rand()
  }
*/