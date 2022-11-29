// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
using namespace std;
//Hetan Nandre's code 

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants 
#define INF 1e18
#define EPS 1e-9
#define MOD 1000000007

// Macros
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define pb push_back
#define MAX 1e18
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
int GCD(int a, int b)
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
int LCM(int a, int b)
{
   return ((ll)a * b) / GCD(a, b);
}
 
ll modpow(ll x, ll n, int m = MOD)
{
   if (x == 0 && n == 0)
      return 0; // undefined case
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

ll binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(ll a) { return bitset<64>(a).to_string(); }
 
int fact(ll n)
{
      if(n==0)
      return 1;
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
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

int maxSubArraySum(vector <int> a, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
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

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
void tourist_killer()
{
 
}


int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   t=1;
   cin >> t;
   while(t--)
   {
      tourist_killer();
   }
   return 0; 
}

/******************************************
*    HETAN HEMANT NANDRE aka tourist 2.0  *
*    INSTITUITION:   VIT PUNE             *
******************************************/













