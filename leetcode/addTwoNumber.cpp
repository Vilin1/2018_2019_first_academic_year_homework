#include <iostream>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *re = result;
        int sum = 0, carry = 0;
        while(l1 != NULL||l2 != NULL) {
        	int num1,num2;
        	if(l1 == NULL) {
        		num1 = 0;
        	} else {
        		num1 = l1->val;
        	}
        	if(l2 == NULL) {
        		num2 = 0;
        	} else {
        		num2 = l2->val;
        	}
        	sum = num1 + num2 + carry;
        	result->next = new ListNode(sum%10);
        	result = result->next;
        	carry = sum/10;
        	if(l1 != NULL) {
        		l1 = l1->next;
        	}
        	if(l2 != NULL) {
        		l2 = l2->next;
        	}
        }
        if(carry != 0){
        	result->next = new ListNode(carry);
 		}
 		return re;    
	}
};

int main() {
	struct ListNode *a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	ListNode *result = addTwoNumbers()
	return 0;
}