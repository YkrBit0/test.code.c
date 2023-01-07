/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int lenA = 1;
    while(tailA->next)
    {
        ++lenA;
        tailA = tailA->next;
    }
    int lenB = 1;
    while(tailB->next)
    {
        lenB++;
        tailB = tailB->next;
    }
    //≤ªœ‡Ωª
    if(tailA != tailB)
    {
        return NULL;
    }
    int gap = abs(lenA - lenB);
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;

    if(lenA < lenB)
    {
        shortlist = headA;
        longlist = headB;
    }
    while(gap--)
    {
        longlist = longlist->next;
    }
    while(longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}