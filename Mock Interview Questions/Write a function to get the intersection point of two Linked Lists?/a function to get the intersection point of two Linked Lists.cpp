#include <bits/stdc++.h>
using namespace std;
struct ListNode{
  int data;
  ListNode *next;
};
ListNode* create(int data){
  ListNode* tmp = new ListNode();
  tmp->data = data;
  tmp->next = NULL;
  return tmp;
}
int length(ListNode *tmp){
    int cnt =  0;
    while(tmp != NULL){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);
    
    if(lenA > lenB){
        int cnt = lenA - lenB;
        while(cnt--)
            headA = headA->next;
    } else {
        int cnt = lenB - lenA;
        while(cnt--)
            headB = headB->next;
    }
    while(headA != NULL && headB != NULL){
        if(headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
int main(){
  ListNode *headA = create(1);
  headA->next = create(2);
  ListNode *headB = create(3);
  headB->next = create(4);
  headA->next->next = headB->next->next = create(5);
  headA->next->next->next = headB->next->next->next = create(6);
  cout<<"Intersection at node: ";
  cout<<getIntersectionNode(headA, headB)->data<<endl;
}
