class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        size_t length=0;
        ListNode* temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            length++;
        }
        temp = head;
        for(int i=0;i<(length/2);i++){
            temp= temp->next;
        }
        return temp;
    }
};