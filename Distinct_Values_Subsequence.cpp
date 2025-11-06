/**
 *    author:  Meet
 *    created: 31.10.2025 23:47:07
**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 4e18;
const ll MINF = -4e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];
        
        ll ans = 1;
        //what are we doing essentially is that for every distinct element we have only one possible choice and so either we can choose any one index of the given element or we can probably leave it also so for each there are (freq+1) possibilities and at last we have to do -1 as 1 sequence will be that in which everyone will be considered as nullset so no one will be taken and we have to ignore it

        sort(whole(arr));

        ll i = 0;
        while(i < n) {
            ll curr = arr[i];
            ll j = i;
            while(i < n && arr[i] == curr) ++i;
            ll freq = i - j;
            ans = (ans * (freq+1)) % M;
        }

        --ans;
        cout << ans << "\n";
    }
    return 0;
}