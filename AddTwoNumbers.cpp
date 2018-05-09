#include <iostream>
#include <vector>
#include <string>
#include<cstdlib>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    int sum = 0;
    ListNode* res = NULL;
    ListNode* head = NULL;

    while(l1 || l2){
        sum = l1->val + l2->val;
        res = new ListNode(sum);
        if(head == NULL)
        {
            head = res;
        }
        else
        {
            res->next = head;
            head = res;
        }
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    return res;
}

void insertAtBeginning(ListNode** head,int dataToBeInserted)
{
    ListNode *curr = new ListNode(dataToBeInserted);
    
    if(*head == NULL)
    {
        *head = curr;
    }
    else
    {
        curr->next = *head;
        *head = curr;
    }

}

int main() {
    //2->4->3 + 5->6->4 = 7->0->8, only test 2 + 5 = 7, 4 + 6 = 10 (do not care carry)
    ListNode *current = NULL;
    ListNode *first;
    ListNode *second;
    insertAtBeginning(&first, 2);
    insertAtBeginning(&first, 4);
    insertAtBeginning(&second, 5);
    insertAtBeginning(&second, 6);
   
    current = addTwoNumbers(first, second);
    while (current != 0) {
        std::cout << "val: " << current->val << " "; //val should be 7, 10
        current = current->next;
    }
    std::cout << std::endl;
    return 0;
}
