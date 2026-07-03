class Solution {
public:
    ListNode* reverse(ListNode* node){
        ListNode* temp = node;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;

        while(fast && fast->next ){
            prev = slow; //break point
            fast= fast->next->next;
            slow = slow->next;
        }
        // break into 2 lists
        prev->next = NULL;

        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);

        while(l1 && l2){
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;
            l1->next = l2;
            l2->next = next1 == NULL ? next2 : next1;
            l1 = next1;
            l2 = next2;
        }

    }
};