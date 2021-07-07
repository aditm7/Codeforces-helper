//set1:
template<typename T> void d0(T t){ cout<<t<<" "; }
template<typename T, typename... Args> void d0(T t, Args... args) { d0(t); d0(args...); } void d0(char t){ printf("%c ",t); } void d0(ll t){ printf("%lld ",t); } void d0(string t){ printf("%s ",t.c_str()); } void d0(ld t){ printf("%ld ",t); }
template<typename T, typename... Args> void print(T t, Args... args) { d0(t); d0(args...); cout<<endl;}
template<typename T> void print(T t){ cout<<t<<endl; } void print(char t){ printf("%c\n",t); } void print(ll t){ printf("%lld\n",t); } void print(string t){ printf("%s\n",t.c_str()); } void print(ld t){ printf("%ld\n",t); }
template<class T> ostream& operator << (ostream &os, vector<T> V){ /* for(ll I=0; I<V.size();I++) d0(V[I]); */ for(auto v:V) os<<v<<" ";os<<endl; return os; }
template<class T> ostream& operator << (ostream &os, set<T> S){ for(auto s:S) os<<s<<" ";os<<endl; return os; }
template<class L, class R> ostream& operator << (ostream &os, pair<L,R> P){ return os << P.first << " " << P.second<<endl; }

//set2:
template<typename T> void d0(T t){ cout<<t<<" "; }
template<typename T> void dall(T t){cout<<t<<endl;}
template<typename T, typename... Args> void dall(T t, Args... args) { cout<<t<<" "; dall(args...); }
template<class T> ostream& operator << (ostream &os, vector<T> V){for(auto ELEMV:V) os<<ELEMV<<" ";os<<endl; return os; }
template<class T> ostream& operator << (ostream &os, set<T> S){ for(auto ELEM:S) os<<ELEMS<<" ";os<<endl; return os; }
template<class L, class R> ostream& operator << (ostream &os, pair<L,R> P){ return os << P.first << " " << P.second<<endl; }