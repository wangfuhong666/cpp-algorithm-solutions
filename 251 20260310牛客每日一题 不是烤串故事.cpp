#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int P = 13331;
const long long mod = 1e9 + 7;
const int N = 1e6 + 10;
using ULL = unsigned long long;

ULL p[N];
ULL p_mod[N];

ULL hash1[N];
ULL hash2[N];
ULL f[N];

ULL hash3[N];
ULL hash4[N];
ULL f1[N];

int n;

void startp()
{
    p[0] = 1;
    p_mod[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * P;
        p_mod[i] = p_mod[i - 1] * P % mod;
    }
}
 
void hashs(string s, string t)                                                                                                                                   
{
    hash1[0] = hash2[0] = f[n + 1] = 0;
    hash3[0] = hash4[0] = f1[n + 1] = 0;

    for (int i = 1; i <= n; i++)
    {
        hash1[i] = hash1[i - 1] * P + s[i];
        hash2[i] = hash2[i - 1] * P + t[i];

        hash3[i] = (hash3[i - 1] * P % mod + s[i]) % mod;
        hash4[i] = (hash4[i - 1] * P % mod + t[i]) % mod;
    }

    for (int i = n; i >= 1; i--)
    {
        f[i] = f[i + 1] * P + s[i];                                
        f1[i] = (f1[i + 1] * P % mod + s[i]) % mod;
    }
}

bool check(int i, int mid)
{
    if (mid == 0) return true;

    ULL h1, h2;

    if (i >= mid) h1 = f[i - mid + 1] - f[i + 1] * p[mid];  
    else h1 = (f[1] - f[i + 1] * p[i]) * p[mid - i] + (hash1[mid] - hash1[i] * p[mid - i]);  
    h2 = hash2[mid];
    long long h1_mod, h2_mod;
    if (i >= mid)  h1_mod = (f1[i - mid + 1] - f1[i + 1] * p_mod[mid] % mod + mod) % mod;  
    else h1_mod = (((f1[1] - f1[i + 1] * p_mod[i] % mod + mod) % mod) * p_mod[mid - i] % mod + ((hash3[mid] - hash3[i] * p_mod[mid - i] % mod + mod) % mod)) % mod;
    
    h2_mod = hash4[mid];


    return (h1 == h2) && (h1_mod == h2_mod);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    startp();
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        string s, t;
        cin >> s >> t;
        s.insert(s.begin(), '0');
        t.insert(t.begin(), '0');
        hashs(s, t);
        int len = -1, x = 0;
        for (int i = 1; i <= n; i++)
        {
            int l = 0, r = n;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (check(i, mid)) l = mid + 1;
                else r = mid - 1;
            }
            if (r > len) len = r, x = i;
        }
        cout << len << ' ' << x << '\n';
    }
    return 0;
}
