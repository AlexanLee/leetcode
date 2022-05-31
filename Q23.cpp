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
    // 分治法
    ListNode* mergeTwoLists(ListNode *a,ListNode *b){
        if((!a) || (!b)) return a?a:b;
        ListNode head, *tail=&head, *aPtr=a, *bPtr=b;

        while(aPtr && bPtr){
            // cout<<aPtr->val<<"::"<<bPtr->val<<endl;
            if(aPtr->val<bPtr->val){
                tail->next=aPtr;
                aPtr=aPtr->next;
            }else{
                tail->next=bPtr;
                bPtr=bPtr->next;
            }

            tail=tail->next;
        }

        tail->next = (aPtr?aPtr:bPtr);
        return head.next;
    } 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans= nullptr;
        for(size_t i=0;i<lists.size();++i){
            ans=mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }

};

int main(){
    cout<<"main"<<endl;

    vector<ListNode*> nums;

    ListNode *a=new ListNode;
    ListNode *paHead=a;
    for(int i=0;i<5;i++){
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
    // while(pbHead){
    //     cout<<pbHead->val<<endl;
    //     pbHead=pbHead->next;
    // }
    cout<<"===================="<<endl;
    nums.push_back(paHead->next);
    nums.push_back(pbHead->next);
    Solution sl;

    ListNode *c=sl.mergeKLists(nums);
   
    cout<<"===================="<<endl;
    while(c){
        cout<<c->val<<endl;
        c=c->next;
    }
    return 0;
}