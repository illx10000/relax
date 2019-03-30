#include <vector>
#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryBit = 0 , sum = 0; //进位
        ListNode* lr = l1, *ll = l2 ,*cur = NULL , *head = NULL;
        while (lr != NULL || ll != NULL)
        {
            if(lr != NULL) { sum += lr->val; lr = lr->next; }
            if(ll != NULL) { sum += ll->val; ll = ll->next; }

            sum     += carryBit;
            carryBit = sum / 10;
            sum     = (sum % 10);

            if (head == NULL) 
            {
                head = new ListNode(sum);
                cur  = head;
            }
            else
            {
                ListNode* pNewNode = new ListNode(sum);
                cur->next = pNewNode;
                cur       = pNewNode;
            }
            sum = 0;
        }

        if (carryBit) //如果有进位
        {
            if (head == NULL)
            {
                head = new ListNode(carryBit);
                cur  = head;
            }
            else
            {
                ListNode* pNewNode = new ListNode(carryBit);
                cur->next = pNewNode;
                cur       = pNewNode;
            }
        }
        return head;
    }
};

void printListNode(ListNode* p)
{
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
}

ListNode* genFromArry(int* arr,int size)
{
    ListNode *head = NULL, *cur = NULL;

    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            head = new ListNode(arr[i]);
            cur = head;
        }
        else
        {
            ListNode* pNewNode = new ListNode(arr[i]);
            cur->next = pNewNode;
            cur = pNewNode;
        }
    }
    return head;
}

int main(int argc,char** argv)
{
    int a1[3] = {2,4,3};
    int a2[3] = {5,6,6};

    printListNode( Solution::addTwoNumbers( genFromArry(a1,3), genFromArry(a2,3)) );
}


