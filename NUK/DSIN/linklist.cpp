#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
template<class T>
class linklist{
    struct node{
        T data;
        node* next;
        node(T data):data(data),next(nullptr){}
        node(int index, T data):data(data),next(nullptr){}
    };

    node* head;
    node* tail;
    int n;

    public:
    class iterator{
        node* cur;
        public:
        iterator(node* cur):cur(cur){}
        T& operator*(){
            return cur->data;
        }
        iterator& operator++(){
            cur = cur->next;
            return *this;
        }
        bool operator!=(const iterator& rhs){
            return cur!=rhs.cur;
        }
        bool operator==(const iterator& rhs){
            return cur==rhs.cur;
        }
        iterator operator+(int n){
            iterator tmp = *this;
            for(int i=0;i<n;++i){
                ++tmp;
            }
            return tmp;
        }

        node* operator->(){
            return cur;
        }
        
    };
    linklist():head(nullptr),tail(nullptr),n(0){}
    ~linklist(){
        node* cur = head;
        while(cur!=nullptr){
            node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    void push_back(T data){
        node* cur = new node(data);
        if(head==nullptr){
            head = cur;
            tail = cur;
        }
        else{
            tail->next = cur;
            tail = cur;
        }
        n++;
    }
    void insert(int index, T data){ // by iterator
        if(index<0 || index>n){
            return;
        }
        if(index==0){
            node* cur = new node(data);
            cur->next = head;
            head = cur;
        }
        else{
            node* cur = new node(data);
            auto tmp = begin()+(index-1);
            cur->next = tmp->next;
            tmp->next = cur;
            if(index==n){
                tail = cur;
            }
        }
        n++;
    }
    
    void erase(int index){ // by iterator
        if(index<0 || index>=n){
            return;
        }
        if(index==0){
            node* tmp = head;
            head = head->next;
            delete tmp;
        }
        else{
            auto tmp = begin() + (index - 1);
            node* del = tmp->next;
            tmp->next = del->next;
            delete del;
            if(index==n-1){
                tail = tmp.operator->();
            }
        }
        n--;
        return;
    }
    iterator begin()const{
        return iterator(head);
    }
    iterator end()const{
        return iterator(nullptr);
    }
    int size(){
        return n;
    }
    bool empty(){
        return n==0;
    }
    void clear(){
        node* cur = head;
        while(cur!=nullptr){
            node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head = nullptr;
        tail = nullptr;
        n = 0;
    }
    friend ostream& operator<<(ostream& os, const linklist& ll){
        for(auto& it:ll){
            os<<it<<" ";
        }
        return os;
    }

};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    linklist<char> ll;
    ll.push_back('a');
    ll.push_back('b');
    ll.push_back('c');
    ll.push_back('d');
    ll.push_back('e');

    for(linklist<char>::iterator it = ll.begin(); it!= ll.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<ll<<endl;
    ll.erase(2);
    cout<<ll<<endl;
    ll.insert(2, 'c');
    for(auto it = ll.begin(); it!=ll.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    ll.insert(3, 'f');
    cout<<ll<<endl;

    return 0;
}