

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
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int carry=0;
        while(curr1!=nullptr&& curr2!=nullptr){
            int sum=curr1->val+curr2->val+carry;
            carry=sum/10;
            curr1->val=sum%10;
            if(curr1->next==nullptr && curr2->next==nullptr && carry==0) {
                return l1;
            }
            if(curr1->next==nullptr){
                curr1->next=new ListNode(0);
            }
            if(curr2->next==nullptr){
                curr2->next=new ListNode(0);
            }
            curr1=curr1->next;
            curr2=curr2->next;

        }
        return l1;
    }
};