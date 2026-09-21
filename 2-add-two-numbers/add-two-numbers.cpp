class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* newHead = new ListNode(0);
        ListNode* tempu = newHead;

        int carry = 0;

        while(temp1 || temp2 || carry)
        {
            int val1 = 0;
            int val2 = 0;

            if(temp1)
                val1 = temp1->val;

            if(temp2)
                val2 = temp2->val;

            int temper = val1 + val2 + carry;

            carry = temper / 10;
            int digit = temper % 10;

            tempu->next = new ListNode(digit);
            tempu = tempu->next;

            if(temp1)
                temp1 = temp1->next;

            if(temp2)
                temp2 = temp2->next;
        }

        return newHead->next;
    }
};