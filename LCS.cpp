#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 3000 + 100;
string a, b;
int dp[N][N];

int lcs(int i, int j)
{
    if(i >= a.size() or j >= b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = lcs(i, j + 1);
    ans = max(ans, lcs(i + 1, j));
    if(a[i] == b[j]) ans = max(ans, lcs(i + 1, j + 1) + 1);
    return dp[i][j] = ans;
}
void print_lcs(int i, int j)
{
    if(i >= a.size() or j >= b.size()) return;
    if(a[i] == b[j])
    {
        cout << a[i];
        print_lcs(i + 1, j + 1);
        return;
    }
    int x = lcs(i + 1, j);
    int y = lcs(i, j + 1);
    if(x >= y)
    {
        print_lcs(i + 1, j);
    }
    else
    {
        print_lcs(i, j + 1);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    print_lcs(0, 0);
    cout << lcs(0, 0) << endl;
    return 0;
}
