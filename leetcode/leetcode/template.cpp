#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        long long f[2]={0,1};
        for(int i=0;i<n;++i)
        {
            f[1]^=f[0]^=f[1]^=f[0];
            f[1]=f[0]+f[1];
        }
        return f[0];
        
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    cout<<s.fib(40);
    return 0;
}