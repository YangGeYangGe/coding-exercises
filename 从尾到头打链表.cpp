// https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> nodes;
        vector<int> result;
        ListNode *node = head;
        while(node != NULL){
            nodes.push(node->val);
            node = node->next;
        }
        while(!nodes.empty()){
            result.push_back(nodes.top());
            nodes.pop();
        }
        return result;
    }
};