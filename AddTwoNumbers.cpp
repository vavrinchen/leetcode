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
    ListNode* res = new ListNode(0);
    while(l1 || l2){
        res->val = l1->val + l2->val;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    return res;
}



int main() {
    //2->4->3 + 5->6->4 = 7->0->8, only test 2 + 5 = 7
    ListNode *current = NULL;
    ListNode *first = new ListNode(2);
    ListNode *second = new ListNode(5);
   
    current = addTwoNumbers(first, second);
    while (current != 0) {
        std::cout << "val: " << current->val << " "; //val should be 7
        current = current->next;
    }
    std::cout << std::endl;
    return 0;
}

