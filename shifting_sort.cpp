#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define arr(a) new ll int[a]
#define INF 1000000000000000000
#define MOD 1000000007
#define MOD1 998244353
#define arr1(a) new arra[a]
#define str(a) new string[a]
#define all(v) v.begin(),v.end()
#define mp(a,b) make_pair(a,b)
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
const int N = 1000008,p=31;
//ll int pw[N],inv_pw[N],hash2[N+1],hash1[N+1],pw1[N],inv_pw1[N],hash1r[N+1],hash2r[N+1];
ll fact[N];
void factorial(ll mod){
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < N; i++)
        fact[i] = (fact[i-1] * i) % mod;
}
int power(int x, int y, int p)
{
 
    // Initialize answer
    int res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x);
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x);
    }
    return res % p;
}
 
ll modular_inverse(ll n, ll mod){
	return power(n, mod-2, mod);
}
//void precal()
//{
//    pw[0]=1;
//    pw1[0]=1;
//    inv_pw1[0]=1;
//    inv_pw[0]=1;
//    ll int temp=modular_inverse(p,MOD),temp1=modular_inverse(p,MOD1);
//    for(ll int i=1;i<N;i++)
//    {
//        pw[i]=(pw[i-1]*p)%MOD;
//        pw1[i]=(pw1[i-1]*p)%MOD1;
//        inv_pw1[i]=(inv_pw1[i-1]*temp1)%MOD1;
//        inv_pw[i]=(inv_pw[i-1]*temp)%MOD;
//    }
//}
//void build(string& s,ll int hash1[],ll int pw[],ll int mod)
//{
//    ll int n=s.size();
//    for(ll int i=1;i<=n;i++)
//    {
//        hash1[i]=(hash1[i-1]+(pw[i-1]*(s[i-1]-'a'+1))%mod)%mod;
//    }
//}
//ll int get_hash(ll int hash1[],ll int inv_pw[],ll int mod,ll int l,ll int r)
//{
//    if(l>r)return 0;
//    ll int res=(hash1[r]-hash1[l-1]+mod)%mod;
//    res=(res*inv_pw[l-1])%mod;
//    return res;
//}
ll nCr(ll n, ll k, ll mod){
	return (fact[n]*((modular_inverse(fact[k],mod)*modular_inverse(fact[n-k],mod))%mod))%mod;
}
//typedef struct node{
//    node* left;
//    node* right;
//    ll d;
//}node;
//node* create(ll int i)
//{
//    node* temp=new node;
//    temp->d=i;
//    temp->left=NULL;
//    temp->right=NULL;
//    return temp;
//}
//struct arra{
//    ll int a,t;
//}arr[200001];
//bool comp1(ll val,struct arra a) //arr.d in increasing order(upperbound comp function
//{
//    return val<a.d;
//}
//bool comp2(struct arra a,ll val) //arr.d in increasing order(lowerbound comp function
//{
//    return a.d<val;
//}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a;
        cin>>n;
        vector<ll>v(n+1);
        vector<pll>v1;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            v1.pb(mp(a,i));
        }
        sort(all(v1));
        vector<pll> res;
        vll v2(n+1);
        for(int i=1;i<=n;i++)v2[i]=i;
        for(int i=1;i<=n;i++)
        {
//            cout<<i<<endl;
            a=v1[i-1].second;
            for(int j=1;j<=n;j++)
            {
                if(v2[j]==a)
                {
                    a=j;
                    break;
                }
            }
            if(a==i)continue;
            res.pb(mp(i,a));
//            cout<<i<<" "<<a<<" "<<a-i<<endl;
            int c=v2[a];
            for(int j=a;j>i;j--)
            {
                v2[j]=v2[j-1];
            }
            v2[i]=c;
        }
//        cout<<"swde"<<endl;
        cout<<res.size()<<endl;
        for(auto j:res)
        {
            cout<<j.first<<" "<<j.second<<" "<<j.second-j.first<<endl;
        }
    }
    return 0;
}
