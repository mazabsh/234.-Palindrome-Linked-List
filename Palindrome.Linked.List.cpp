#include<iostream>

using namespace std; 

struct ListNode{
public: 
    int val; 
    ListNode* next; 
    ListNode(): val(0), next(nullptr){}
    ListNode(int _val): val(_val), next(nullptr){}
    ListNode(int _val, ListNode* _next): val(_val), next(_next){}
};
class Solution{
public: 
    ListNode* getMid(ListNode* head){
      ListNode* slow = head; 
      ListNode* fast = head ->next; 
      while(fast && fast->next){
        slow = slow ->next; 
        fast = fast ->next ->next; 
      }
      return slow; 
    }
     ListNode* reverseList(ListNode* head){
       ListNode* prev = nullptr; 
       ListNode* curr = head; 
       while(curr){
         ListNode* nextNode = curr ->next; 
         curr->next = prev; 
         prev = curr; 
         curr = nextNode; 
       }
       return prev; 
     }
     bool isPalindrome(ListNode* head) {
       if(!head || !head->next) return true; 

       ListNode* mid = getMid(head); 
       ListNode* right = reverseList(mid); 
       mid->next= nullptr;
       ListNode* left = head; 
       while(left && right){
         if(left->val != right->val) return false; 
         else {
           left = left->next; 
           right = right->next; 
         }
       }
       return true; 
     }
};
int main(){
  ListNode* head = new ListNode(1); 
  head->next = new ListNode(2); 
  head->next->next= new ListNode(3); 
  head->next->next->next = new ListNode(2); 
  head ->next->next->next->next = new ListNode(1); 
  Solution sol; 
  cout << boolalpha <<sol.isPalindrome(head) << endl; 
  return 0; 
}
