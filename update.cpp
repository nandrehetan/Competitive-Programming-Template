/*
  Compete against Yourself.
  Author - Hetan Hemant Nandre (@hetanhnandre)
*/
 
#include <bits/stdc++.h>
using namespace std;
//Hetan Nandre's code 

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants 
#define INF 2147483647
#define EPS 1e-9
#define MOD 1000000007
// #define sz 1e18

// Macros
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define pb push_back
#define MAX 1e18
#define new "\n"
// #define in(a)        for(auto &i:a) cin>>i
#define MP make_pair
#define rep(i,s,e)   for(int i=s;i<e;i++)
#define repr(i,s,e)  for(int i=s;i>=e;i--)
typedef vector<int>vi;


template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
   for (auto &it : v)
      cin >> it;
   return istream;
}

template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
   for (auto &it : c)
      cout << it << " ";
   return ostream;
}

// Mathematical functions
ll GCD(ll a, ll b)
{
   while (b)
   {
      a %= b;
      swap(a, b);
   }
   return a;
}
 
int GCD_extended(int a, int b, int &x, int &y)
{
   x = 1, y = 0;
   int x1 = 0, y1 = 1, a1 = a, b1 = b;
   while (b1)
   {
      int q = a1 / b1;
      tie(x, x1) = make_tuple(x1, x - q * x1);
      tie(y, y1) = make_tuple(y1, y - q * y1);
      tie(a1, b1) = make_tuple(b1, a1 - q * b1);
   }
   return a1;
}

ll LCM(ll a, ll b)
{
   return ((ll)a * b) / GCD(a, b);
}
 
ll modpow(ll x, ll n, int m = MOD)
{
   if (x == 0 && n == 0)
      return 0; 
   ll res = 1;
   while (n > 0)
   {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
   }
   return res;
}
 
int modinv(int x, int m = MOD)
{
   return modpow(x, m - 2, m);
}
 
mt19937 rng;
int getRandomNumber(int l, int r)
{
   uniform_int_distribution<int> dist(l, r);
   return dist(rng);
}

ll binToDec(string s) { return bitset<4>(s).to_ullong(); }
string decToBin(ll a) { return bitset<4>(a).to_string(); }
 
ull fact(ll n)
{
      if(n==0)
      return 1;
    ull res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll nCr(ll n, ll r)
{
    ll ans = 1;
    for(ll i = 1; i <= r; i++)
    {
        ans *= n--;
         ans /= i;
    }
    return ans ;
}

ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    while (l <= r) {
        ll m = l + (r - l) / 2;
       
        if (arr[m] == x)
            return m; 
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

ll maxSubArraySum(vector <ll> a, ll size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;
 
    for (ll i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

bool isPowerTwo(int x)
{
    return (x && !(x & (x - 1)));
}

ll power(ll x,  ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int longSubSeq(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis + n);
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
    
}
string longestPalindrome(string mainString)
{
  int n = mainString.size();
  if(n == 0)
      return "";
  n = 2*n + 1; int LPS[n]; LPS[0] = 0; LPS[1] = 1; 
  int centerIndex = 1;int rightIndex = 2;int right = 0, left;
  int maxPalLength = 0, maxCenterIndex = 0;int start = -1, end = -1, diff = -1;
  for (right = 2; right < n; right++) {
      left  = 2*centerIndex-right; 
      LPS[right] = 0;
      diff = rightIndex - right;
      if(diff > 0)
        LPS[right] = min(LPS[left], diff);
      while ( ((right + LPS[right]) < n && (right - LPS[right]) > 0) && ( ((right + LPS[right] + 1) % 2 == 0) || (mainString[(right + LPS[right] + 1)/2] == mainString[(right - LPS[right] - 1)/2] )))
        {
        LPS[right]++;
        }
      if(LPS[right] > maxPalLength) {  
        maxPalLength = LPS[right];
        maxCenterIndex = right;
      }
      if (right + LPS[right] > rightIndex) {
        centerIndex = right;
        rightIndex = right + LPS[right];
      }
  }
  start = (maxCenterIndex - maxPalLength)/2;
  end = start + maxPalLength - 1;
  string palindrome;
  for(int i=start; i<=end; i++)
      palindrome += mainString[i];
      return palindrome;
}

vector<vector<ll>>subarray(vector<ll>v, ll n)
{
    vector<vector<ll>>ans;
    for (ll i = 0; i < (1<<n); ++i)
    {
        vector<ll>ok;
        for (ll j = 0; j < n; ++j)
        {
            if (i & (1<<j))
            {
                ok.push_back(v[j]);
            }
        }
        ans.push_back(ok);
    }
    return ans;
}
vector<ll> getLps(string pat){
    ll m = pat.size();
    vector<ll>lps(m);
    ll prev = 0;
    ll ind = 1;
    while (ind < m){
        if (pat[ind]==pat[prev]){
            prev++;
            lps[ind]=prev;
            ind++;
        }
        else if (prev==0){
            lps[ind]=0;
            ind++;
        }
        else{
            prev = lps[prev-1];
        }
    }
    return lps;
}
vector<ll> pattern_matching(string str, string pat){
    vector<ll> lps = getLps(pat);
    vector<ll>ans;
    ll n = str.size();
    ll m = pat.size();
    ll patIdx = 0;
    ll strIdx = 0;
    while (strIdx < n){
        if (str[strIdx] == pat[patIdx]){
            patIdx++;
            strIdx++;
        }
        if (patIdx == m){
            ans.push_back(strIdx - m);
            patIdx = lps[patIdx-1];
        }
        else if (strIdx < n){
            if (str[strIdx]!=pat[patIdx]){
                if (patIdx != 0) 
                    patIdx = lps[patIdx-1];
                else
                    strIdx++;
            }
        }
    }
    return ans;
}

template<class T, class U>
// T -> node, U->update.
 /*   Only update 3 functions in any segment tree (range query problem)
    1. combine
    2. apply
    3. combineupdate
 */
struct Lsegtree{
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;

    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n,identity_element);
        lazy.assign(4*n, identity_update);
    }

    T combine(T l, T r)
    {
        // change this function as required.        
        T ans = l+r;
        // ans++;
        return ans;
    }

    void buildUtil(ll v, ll tl, ll tr, vector<T>&a)
    {
        if(tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
        T ans = (tr-tl+1)*upd;
        // increment range by upd:
        ans = (tr - tl + 1)*upd + curr;

        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        U ans = old_upd;
        ans=new_upd;
        return ans;
    }  

    void push_down(ll v, ll tl, ll tr)
    {
        //for the below line to work, make sure the "==" operator is defined for U.
        if(lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if(2*v + 1 <= 4*n)
        {
            ll tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v,tl,tr);
        if(l > r)return identity_element;
        if(tr < l or tl > r)
        {
            return identity_element;
        }
        if(l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
 
    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v,tl,tr); 
        if(tr < l or tl > r)return;
        if(tl >=l and tr <=r)
        {
            lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
            push_down(v,tl,tr);
        }
        else
        {
            ll tm = (tl + tr)>>1;
            updateUtil(2*v+1,tl,tm,l,r,upd);
            updateUtil(2*v+2,tm+1,tr,l,r,upd);
            st[v] = combine(st[2*v + 1], st[2*v+2]);
        }
    }

    void build(vector<T>a)
    {
        assert( (ll)a.size() == n);
        buildUtil(0,0,n-1,a);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0,0,n-1,l,r);
    }
    void update(ll l,ll r, U upd)
    {
        updateUtil(0,0,n-1,l,r,upd);
    }
};

/*/-----------------------------Code begins----------------------------------/*/


void solve() 
{
    
    
}
//Note : Always check for the following things
//1. Max value of N
//2. Mod value
//3. Test for your own case

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ll t;
   t=1;
   cin>>t;
   while(t--)
   {
      solve();
   }
   return 0;
   
}
