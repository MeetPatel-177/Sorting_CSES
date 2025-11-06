/**
 *    author:  Meet
 *    created: 28.10.2025 19:35:21
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

vector<pair<ll,ll>> events;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        events.assign(n,{});
        for(ll i=0; i<n; ++i) {
            ll s,e;
            cin >> s >> e;
            events.push_back({s,1});//{time,type} +1 for arrival
            events.push_back({e,-1});//{time,type} -1 for departure
        }

        sort(whole(events), [](auto& p1, auto& p2) {
            //process arrival first if arrival and departure are same
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        });

        ll ans = 0;

        ll curr = 0;

        for(auto& [time,type] : events) {
            curr += type;
            ans = max(ans, curr);
        }

        cout << ans << "\n";
    }
    return 0;
}