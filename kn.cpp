#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    lol data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(lol node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(lol node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void prlol_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     lol data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
lol findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{

    SinglyLinkedListNode *i;
    while (head1)
    {

        i = head2;
        while (i)
        {
            if (head1->next == i->next)
            {
                if (head1->next != NULL)
                    return head1->next->data;
            }
            i = i->next;
        }
        head1 = head1->next;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    lol tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (lol tests_itr = 0; tests_itr < tests; tests_itr++)
    {
        lol index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList *llist1 = new SinglyLinkedList();

        lol llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (lol i = 0; i < llist1_count; i++)
        {
            lol llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }

        SinglyLinkedList *llist2 = new SinglyLinkedList();

        lol llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (lol i = 0; i < llist2_count; i++)
        {
            lol llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode *ptr1 = llist1->head;
        SinglyLinkedListNode *ptr2 = llist2->head;

        for (lol i = 0; i < llist1_count; i++)
        {
            if (i < index)
            {
                ptr1 = ptr1->next;
            }
        }

        for (lol i = 0; i < llist2_count; i++)
        {
            if (i != llist2_count - 1)
            {
                ptr2 = ptr2->next;
            }
        }

        ptr2->next = ptr1;

        lol result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
