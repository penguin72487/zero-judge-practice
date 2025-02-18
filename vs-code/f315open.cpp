#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
class node{
public:
    long long i_Sum=0;
    
    //int i_Max = -2147483648;
    //node *pa_Node;
    //node *l_Node;
    //node *r_Node;
};
class Segment_Tree{
public:
    //node* top=nullptr;
    node *t_Node;
    long long int ans = 0;
    int size;
    int max_size;
    int index_Op;
    Segment_Tree(vector<pair<int,int>> &a)
    {
        size = a.size();
        int tmp = log2((size - 2) << 1) + 1;
        max_size = i_Pow(2,tmp+1);
        index_Op = i_Pow(2,tmp);
        t_Node = new node[max_size];
        for (auto it = ++a.begin(); it != a.end();++it)
        {
           // t_Node[index_Op + it->first].i_Sum = 1;
            //t_Node[index_Op + it->second].i_Sum = 1;
            ans += rang_Sum(index_Op + it->first,index_Op + it->second);
            update(index_Op + it->first,index_Op + it->second);
        }
    }
    ~Segment_Tree()
    {
        delete [] t_Node;
    }
    long long int rang_Sum(int op,int ed)//(op,ed)
    {
        //long long int ans=0;
        while(op<ed)
        {
            
            if(op&1)
            {
                ans += t_Node[op].i_Sum;
                ++op;
                
            }
            if(ed&1)
            {
               
            }
            else
            {
                //ans += t_Node[ed].i_Sum;
                 --ed;
                

            }
            
            op >>= 1;
            ed >>= 1;
        }
        
        return t_Node[op].i_Sum;
    }
    void update(int op,int ed)
    {
        while(op>1)
        {
            op >>=1;
            ++t_Node[op].i_Sum;
            
        }
        while(ed>1)
        {
            ed >>= 1;
            ++t_Node[ed].i_Sum;
        }
    }
    int i_Pow(int a,int n)
    {
        int ans = 1;
        while(n)
        {
            if(n&1)
            {
                ans *= a;
            }
            a *= a;
            n >>= 1;
        }
        return ans;
    }
};

int main()
{
    
    int n;
    fstream file;
    file.open("f315p409_in.txt");
    file>>n;
    int N = (n << 1)+1;
    vector<pair<int, int>> a(n+1);
    for (auto it = a.begin(); it != a.end();++it)
    {
        it->first = -1;
        it->second = -1;
    }
    int tmp;
    for (int i = 1; i <N;++i)
    {
        
        file >> tmp;
        if(a[tmp].first!=-1)
        {
            a[tmp].second = i-1;
        }    
        else
        {
            a[tmp].first = i-1;
        }
    }
    /*
    for (auto it = a.begin(); it != a.end();++it)
    {
        cout << it->first << " " << it->second << "\n";
    }
    */
        Segment_Tree low_Dis(a);
    cout << low_Dis.ans << "\n";
}