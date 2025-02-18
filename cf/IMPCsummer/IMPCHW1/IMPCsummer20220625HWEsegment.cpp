#include <iostream>
#include <vector>
using namespace std;
class Segment_Tree{
    public:
        int n;//i_op
        vector<long long> seg_T;
        Segment_Tree(vector<long long> &seg)
        {
            n=seg.size();
            seg_T.resize(n);
            fill(seg_T.begin(), seg_T.end(), 0ll);
            for(int i=0; i<n; i++)
            {
                seg_T.push_back(seg[i]);
            }
            for(int i=n-1; i>0;--i)//build
            {
                seg_T[i] = max(seg_T[(i << 1)], seg_T[(i << 1) | 1]);
            }
        }
        void update(int &k, int &u)
        {
            seg_T[n+k]-=u;
            for (int i_Now = n + k; i_Now; i_Now >>= 1)
            {
                seg_T[(i_Now >> 1)] = max(seg_T[i_Now ^ 1], seg_T[i_Now]);
            }

        }
        long long query(int a,int b)
        {
            
            long long ans = 0;
            for (int i_op = n + a, i_ed = n + b; i_op < i_ed;i_op >>= 1,i_ed >>= 1)
            {
                if (i_op & 1)
                {
                    ans = max(ans, seg_T[i_op++]);
                }
                if (i_ed & 1)
                {
                    ans = max(ans, seg_T[--i_ed]);
                }
                
            }
            return ans;
        }
        long long sol(int x)
        {
            int i_op = 0;
            int i_ed = n-1;
            int mid;
            bool flag = false;
            while (i_op < i_ed)
            {
                mid=((i_op +i_ed)>>1);
                if(query(0,mid+1)>=x)
                {
                    i_ed=mid;
                    flag = true;
                }
                else
                {
                    i_op = mid+1;
                }
            }
            //mid = ((i_op + i_ed) >> 1);
            if(query(0,i_ed+1)>=x)
            {
                flag=1;
            }
            if(!flag)
            {
                return false;
            }
            update(i_ed,x);
            return i_ed+1;
        }

};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> seg(n);
    for(auto it=seg.begin(); it!=seg.end();++it)
    {
        cin >> *it;
    }
    Segment_Tree seg_T(seg);

    while(q-->0)
    {
        int x;
        cin >> x;
        cout<<seg_T.sol(x)<<" ";
    }
}