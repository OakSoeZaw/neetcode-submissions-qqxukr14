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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while( list1 != nullptr && list2 != nullptr){
            int check = list1->val;
            int check2 = list2-> val;
            if(check < check2){
                head->next = list1;
                list1 = list1->next;
            }else{
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
 
        }
        if (list1 != nullptr) {
            head->next = list1;
        } else {
            head->next = list2;
        }
        return curr->next;
    }
};
