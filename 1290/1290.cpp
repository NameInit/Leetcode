#include <iostream>
#include <cassert>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
		while(head!=nullptr){
			ans=ans*2+head->val;
			head=head->next;
		}
		return ans;
    }
};

// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         int ans=0;
// 		for(ListNode *it = head; it!=nullptr; it=it->next){
// 			ans=ans*2+it->val;
// 		}
// 		return ans;
//     }
// };

int main(){
	Solution test;
	{
		ListNode *root = new ListNode(1);
		ListNode *branch1 = new ListNode(0);
		ListNode *branch2 = new ListNode(1);
		root->next = branch1;
		branch1->next = branch2;
		branch2->next = nullptr;
		assert(5 == test.getDecimalValue(root));
		delete root;
		delete branch1;
		delete branch2;
	}
	return 0;
}