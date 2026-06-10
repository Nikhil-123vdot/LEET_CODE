class Solution {
    public ListNode middleNode(ListNode head) {

        int count = 0;
        ListNode temp = head;

        // Length count
        while(temp != null)
        {
            count++;
            temp = temp.next;
        }

        int middle = count / 2;

        // Head se fir start
        temp = head;

        // Middle tak jao
        for(int i = 0; i < middle; i++)
        {
            temp = temp.next;
        }

        return temp;
    }
}