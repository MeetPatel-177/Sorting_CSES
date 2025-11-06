/**
 *    author:  Meet
 *    created: 28.10.2025 18:34:04
**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

multiset<ll> tickets;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        for(ll i=0; i<n; ++i) {
            ll x;
            cin >> x;
            tickets.insert(x);
        }

        for(ll i=0; i<m; ++i) {
            ll price;
            cin >> price;
            auto it = tickets.upper_bound(price);
            if(it == tickets.begin()) {
                minus;
            }else {
                --it;
                cout << (*it) << "\n";
                tickets.erase(it);
            }
        }
    }
    return 0;
}