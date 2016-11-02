/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //date 2016/2/23
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p;
       
      
        if(node->next) {
            p = node->next;
            node->val = p->val;
            node->next = p->next;
            free(p);
        } else {
            cout<<"列表中没有元素x"<<endl;
        }
    }
};