/*
Linked List - 鏈結串列

It can save a continuous data without a continuous memory container, but "Array" can't.
For instance: "Stack", "Queue"

Structure:
1. START - a pointer aims the first node
2. NODE  - the address of the next node of the current node
3. END   - the last data with the address "NULL"

*/

#include <iostream>
using namespace std;

// this struct contain a value and a pointer
struct link
{
    int value;
    link *next;
};

int main()
{
    link *head = new link; // create a memory space as "link" for "head" pointer

    // create the first node
    head->value = 0;
    head->next = NULL;

    // create the nodes before
    link *current = head;
    int count = 10;
    for (int i = 1; i < count; i++)
    {
        current->next = new link();

        current = current->next; // where did Current aim at
        current->value = i;      // assign value to the address that is aimed at
        current->next = NULL;    // end the list
    };

    // delete node
    /*
    case 1: The value you want to delete is at the first place
        Delete the first node and let "head" aim at the next node.
        But this method didn't release the space of the "head".
        So we need to use a "temp" to store the address of the node you want to delete,
        then [head = head->next], then release the temp [delete temp]
    */

    link *temp;
    temp = head; // assign head to temp
    int find = 4;
    if (head->value == find)
    {
        head = head->next; // let head aim at the next
        delete temp;       // release the memory
    }

    /*
    case 2: The value you want to delete is at the inner node
        We just need to let the former node aim at the later node,
        so we need TWO pointer to help us to delete the node.
    */

    else
    {
        link *follow;
        // [Find the Target]
        // If only "temp" is not the last and you didn't find the value, move temp & follow.
        while ((temp != NULL) && (temp->value != find))
        {
            follow = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            cout << "Not found. \n";
        else
        {
            // found, delete the node.
            follow->next = temp->next;
            delete temp;
        }
    }

    // print
    current = head; // let the current aim at the head again
    while (true)
    {
        cout << current->value << "\n";
        current = current->next; // next node
        if (current == NULL)     // the last one
            break;
    }
}