/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class timer{
public:
    clock_t start;
    clock_t end;
    string name;
    timer(string n){
        start=clock();
        name=n;
    }
    ~timer(){
        end=clock();
        printf("%s time: %f\n", name.c_str(),(end-start)*1.0/CLOCKS_PER_SEC*1000);
    }
    
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;

        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }

        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }

        int carry=0;
        ListNode *ans=nullptr;
        while(!s1.empty()|| !s2.empty()|| carry!=0){
            int a=s1.empty()?0:s1.top();
            int b=s2.empty()?0:s2.top();
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            int cur=a+b+carry;
            carry=cur/10;
            cur%=10;
            auto curNode=new ListNode(cur);
            curNode->next=ans;
            ans=curNode;
            cout<<cur<<endl;
        }
        return ans;
    }
};

int main(){
    cout<<"main"<<endl;
    ListNode *a=new ListNode;
    ListNode *paHead=a;
    for(int i=1;i<5;i++){
        ListNode *node= new ListNode;
        cout<<i<<endl;
        node->val=i;
        node->next=nullptr;
        a->next=node;
        a=node;
    }
    // while(paHead){
    //     cout<<paHead->val<<endl;
    //     paHead=paHead->next;
    // }
    cout<<"===================="<<endl;
    ListNode *b=new ListNode;
    ListNode *pbHead=b;
    for(int i=1;i<8;i++){
        ListNode *node= new ListNode;
        node->val=i;
        cout<<i<<endl;
        node->next=nullptr;
        b->next=node;
        b=node;
    }
    cout<<"==================="<<endl;
    Solution sl;
    ListNode *c=sl.addTwoNumbers(paHead->next,pbHead->next);
    cout<<"==================="<<endl;
    // cout<<sizeof(c)/sizeof(*c)<<endl;
    while(c){
        cout<<c->val<<endl;
        c=c->next;
    }

    return 0;
}
