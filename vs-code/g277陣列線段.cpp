#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<limits>
using namespace std;
class node{
public:
    long long i_Sum=0;
    node* min_Node = this;
    
    //int i_Max = -2147483648;
    //node *pa_Node;
    //node *l_Node;
    //node *r_Node;
};
class Segment_Tree{
public:
    node* top=nullptr;
    node *t_Node;
    int size;
    Segment_Tree(int* tmp,int n)
    {
        
        size = n;
        t_Node = new node[2*n];
        top = t_Node+1;
        for (int i = 0; i < n;++i)
        {
            t_Node[n + i].i_Sum = tmp[i];
        }
        for (int i = n-1; i > 0; --i)
        {
            t_Node[i].i_Sum = t_Node[2 * i].i_Sum + t_Node[2 * i + 1].i_Sum;
            if(t_Node[2 * i].min_Node->i_Sum<t_Node[2*i+1].min_Node->i_Sum)
            {
                t_Node[i].min_Node = t_Node[ 2 * i].min_Node;
            }
            else
            {
                t_Node[i].min_Node =  t_Node[ 2 * i+1].min_Node;
            }
            //t_Node[i].min_Node = min(t_Node[2 * i].min_Node->i_Sum,t_Node[2*i+1].min_Node->i_Sum);
        }
        /*
        for (auto it = t_Node + size; it != t_Node + size * 2;++it)
        {
            cout << it->i_Sum << " ";

        }
        
        cout << "\n";
        */
        
    }
    ~Segment_Tree()
    {
        delete [] t_Node;
    }
    //node *build(node *op, node *ed);
    long long prior_Sum(node* op,node* ed)
    {
        /*
        cout << "list";
        for (auto it = op ; it !=ed ;++it)
        {
            cout << it->i_Sum << " ";
        }
        cout << "\n";
        */
        long long t_Sum=0;
        int i_op = op-t_Node;
        int i_ed = ed-t_Node;
        while(i_op<i_ed)
        {
            //cout << "index " << i_op << " " << i_ed << "\n";
            if(i_op&1)
            {
                t_Sum += t_Node[i_op].i_Sum;
                ++i_op;
            }
            if(i_ed&1)
            {
                --i_ed;
                t_Sum += t_Node[i_ed].i_Sum;
            }
            i_op >>= 1;
            i_ed >>= 1;
        }
        //cout << "Sum" << t_Sum << "\n";
        return t_Sum;
    }
    node* rn_Min(node* op,node* ed)
    {
        /*
    	cout << "Min_list";
        for (auto it = op ; it !=ed ;++it)
        {
            cout << it->i_Sum << " ";
        }
        cout << "\n";
        */
        int i_op = op-t_Node;
        int i_ed = ed-t_Node;
        node *min_Node=op;
        while(i_op<i_ed)
        {
        	//cout << "Min_index " << i_op << " " << i_ed << "\n";
            if(i_op&1)
            {
                if(min_Node->i_Sum>t_Node[i_op].min_Node->i_Sum)
                {
                    min_Node = t_Node[i_op].min_Node;
                }
                ++i_op;
            }
            if(i_ed&1)
            {
                --i_ed;
                if(min_Node->i_Sum>t_Node[i_ed].min_Node->i_Sum)
                {
                    min_Node = t_Node[i_ed].min_Node;
                }
            }
            i_op >>= 1;
            i_ed >>= 1;
        }
        return min_Node;
    }
    int i_Licky()
    {
        return i_Licky(t_Node + size, t_Node + size * 2);
    }
    int i_Licky(node *op, node *ed)
    {
        /*
        for (auto it = op; it != ed;++it)
        {
            cout << it->i_Sum << " ";
        }
        
        cout << "\n";
        */
        if (op + 1 == ed)
        {
            return op->i_Sum;
            }
        node* min_Node=rn_Min(op,ed);
        //cout<<"min: "<<min_Node->i_Sum<<"\n";
        //cout<<"prior"<<prior_Sum(op,min_Node)<<" "<<prior_Sum(min_Node,t_Node+size*2)<<"\n";
        if(prior_Sum(op,min_Node)>prior_Sum(min_Node+1,ed))
        {
            return i_Licky(op, min_Node);
        }
        else
        {
            return i_Licky(min_Node + 1, ed);
        }
    }
};
int main()
{
    //cin.tie(0)->sync_with_stdio(0);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n;++i)
    {
        cin >> list[i];
    }
    Segment_Tree Licky(list,n);
    cout << Licky.i_Licky();
}