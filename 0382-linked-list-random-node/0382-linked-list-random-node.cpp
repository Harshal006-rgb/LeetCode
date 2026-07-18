class Solution {
public:

    vector<int> arr;

    Solution(ListNode* head) {
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
      int n = arr.size();
      int idx = rand()%n;

      return arr[idx];
    }
};