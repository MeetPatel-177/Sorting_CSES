/**
 *    author:  Meet
 *    created: 31.10.2025 11:50:00
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
        ll x,n;
        cin >> x >> n;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];
        
        multiset<ll> gaps, lights;

        lights.insert(0);
        lights.insert(x);

        gaps.insert(x);

        for(ll i=0; i<n; ++i) {
            auto it = lights.upper_bound(arr[i]);
            ll v2 = *it;

            gaps.insert(*it - arr[i]);

            --it;
            ll v1 = *it;
            gaps.insert(arr[i] - *it);

            gaps.erase(gaps.find(v2-v1));
            lights.insert(arr[i]);

            cout << *(gaps.rbegin()) << " ";
        }
    }
    return 0;
}