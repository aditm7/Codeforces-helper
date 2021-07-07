//****************************Template Begins****************************//
 
// Header Files
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list> 
#include<iterator>
#include<deque>  
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<chrono>
#include<cstring>
#include<string>
// Header Files End  
 
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define inf 9999999999999
const ll mod=1e9+7;
 
ll inv(ll i){if(i==1) return 1;return (mod-((mod/i)*inv(mod%i))%mod)%mod;}
 
ll gcd(ll a,ll b){ if (b==0) return a;return gcd(b,a%b);}
 
ll pwr(ll a, ll b) {a %= mod; ll res = 1;while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;}return res;}
//****************************Template Ends*******************************//
//****************************Functions*******************************//
class Graph
{
    ll V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    list<ll> *adj;// FOR BFS(comment out this to run DFS)
public:
    Graph(ll V); // Constructor
    // map<int, bool> visited; 
                            // (FOR DFS         --->>> //remove comments)
    // map<int, list<int>> adj;
 
    // function to add an edge to graph
    void addEdge(ll v, ll w);
 
    // prints BFS traversal from a given source s
    void BFS(ll s); 
    void DFS(int v);
};
 
Graph::Graph(ll V)
{
    this->V = V;
    adj = new list<ll>[V];
}
 
void Graph::addEdge(ll v, ll w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(ll s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(ll i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<ll> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<ll>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
// void Graph::DFS(ll v)
// {
//     // Mark the current node as visited and
//     // print it
//     visited[v] = true;
//     cout << v << " ";
 
//     // Recur for all the vertices adjacent
//     // to this vertex
//     list<ll>::iterator i;
//     for (i = adj[v].begin(); i != adj[v].end(); ++i)
//         if (!visited[*i])
//             DFS(*i);
// }
ll findMinNumber(ll n)
{
    ll count = 0, ans = 1;
 
    // Since 2 is only even prime, compute its
    // power seprately.
    while (n%2 == 0)
    {
        count++;
        n /= 2;
    }
 
    // If count is odd, it must be removed by dividing
    // n by prime number.
    if (count%2)
        ans *= 2;
 
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        count = 0;
        while (n%i == 0)
        {
            count++;
            n /= i;
        }
 
        // If count is odd, it must be removed by
        // dividing n by prime number.
        if (count%2)
            ans *= i;
    }
 
    if (n > 2)
        ans *= n;
 
    return ans;
}
ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    if (r >= l) {
        ll mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
ll nCrModp(ll n, ll r, ll p)
{
    // Optimization for the cases when r is large
    if (r > n - r)
        r = n - r;
 
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    ll C[r + 1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // Top row of Pascal Triangle
 
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (ll i = 1; i <= n; i++) {
 
        // Fill entries of current row using previous
        // row values
        for (ll j = min(i, r); j > 0; j--)
 
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}
ll fact(ll n , ll mod)
{   
    ll p=1;
    if (n == 0)
        return 1;
    
    else
    {
        for(int i=1;i<=n;i++)
        {p*=i;
        p=p%mod;}
        return p;
    }
}
ll count_set_bit(ll n)
{
    ll count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    fio;
	ll t=1;
// 	cin>>t;
	while(t--)
	{
	   ll n;
	   cin>>n;
	   ll a[n],i,min,sum=0,cnt=0,j,idx;
	   fo(i,0,n)
	   cin>>a[i];
	   priority_queue <int, vector<int>, greater<int>> d;  
	   fo(i,0,n)
	   {   
	       if(a[i] < 0){
	           d.push(a[i]);
	       }
	       sum+=a[i];
	       if(sum<0)
	       {
					 	 cout<<sum<<" "<<d.top()<<endl;
	           min = d.top();
	           sum -= min;
	           d.pop();
	       }
	       else
	       cnt++;
	       
	   }
	   cout<<cnt<<endl;
	}
    return 0;
}
