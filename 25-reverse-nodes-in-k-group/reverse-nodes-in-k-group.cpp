class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        ListNode* prevGroup = NULL;
        
        while (true) {
            
            // Check whether k nodes are available
            ListNode* kth = temp;
            
            for (int i = 0; i < k; i++) {
                if (kth == NULL)
                    return head;
                
                kth = kth->next;
            }
            
            ListNode* nextGroup = kth;
            
            // Reverse current k nodes
            ListNode* prev = nextGroup;
            ListNode* curr = temp;
            
            while (curr != nextGroup) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // Connect previous group
            if (prevGroup == NULL)
                head = prev;
            else
                prevGroup->next = prev;
            
            // First node of current group becomes previous group
            prevGroup = temp;
            
            // Move to next group
            temp = nextGroup;
        }
        
        return head;
    }
};