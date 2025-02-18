#include<iostream>
#include<vector>
#include<tuple>
#include<unordered_map>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> dist(n,(1ll<<60));
    vector<long long> path_From(n,-1);
    dist[0] = 0;
    vector<vector<pair<int, long long>>> vec(n);
    int a, b;
    long long c;
    for (int i = 0;i < m; ++i)
    {
        cin >> a >> b >> c;
        vec[a-1].push_back(make_pair(b-1,c));

    }
    
    bool flag = 0;
    int u, v;
    long long d;
    int op=0;
    for (int i = 0; i < n; ++i)
    {   
        flag = 0;
        for(int i=0;i<n;++i)
        {
            for(auto it=vec[i].begin();it!=vec[i].end();++it)
            {
                u = i;
                v = it->first;
                d = it->second;
                if(dist[u]+d<dist[v])
                {
                    flag = 1;
                    dist[v] = dist[u]+d;
                    path_From[v] = u;
                    op = v;
                }
            }

        }
        if(!flag)
        {
            break;
        }
    }
    
    if(flag)
    {
        
        vector<bool> pass_By(n,0);
        vector<int> ans;

        
        //int tmp = n - 1;
        int now = op;
        cout << "YES\n";
        //now = path_From[now];
        while(!pass_By[now])
        {
            //cout << now << "n\n";
            pass_By[now] = 1;
            ans.push_back(now+1);
            now = path_From[now];
        }
        //ans.push_back(op+1);
        cout << now+1 << " ";
        for(auto it=ans.rbegin(); it!=ans.rend();++it)
        {
            
            cout << *it << " ";
            if(*it==now+1)
            {
                break;
            }
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
    }


        return 0;
}