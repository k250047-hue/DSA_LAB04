#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* nxt;
    Node* down;

    Node(int v)
    {
        val = v;
        nxt = nullptr;
        down = nullptr;
    }
};

class MultiLevelList
{
public:
    Node* head;

    MultiLevelList()
    {
        head = nullptr;
    }

    Node* locate(int key)
    {
        Node* cur = head;

        while (cur != nullptr)
        {
            if (cur->val == key)
                return cur;

            cur = cur->nxt;
        }

        return nullptr;
    }

    void append(int v)
    {
        Node* fresh = new Node(v);

        if (head == nullptr)
        {
            head = fresh;
            return;
        }

        Node* cur = head;

        while (cur->nxt != nullptr)
            cur = cur->nxt;

        cur->nxt = fresh;
    }

    void linkNext(int a, int b)
    {
        Node* src = locate(a);

        if (src == nullptr)
        {
            append(a);
            src = locate(a);
        }

        if (locate(b) == nullptr)
            append(b);

        src->nxt = locate(b);
    }

    void linkChild(int a, int b)
    {
        Node* src = locate(a);

        if (src == nullptr)
        {
            append(a);
            src = locate(a);
        }

        if (locate(b) == nullptr)
            append(b);

        src->down = locate(b);
    }

    void flatten()
    {
        Node* cur = head;

        while (cur != nullptr)
        {
            if (cur->down != nullptr)
            {
                Node* rest = cur->nxt;
                Node* branch = cur->down;

                cur->nxt = branch;
                cur->down = nullptr;

                Node* tail = branch;
                while (tail->nxt != nullptr)
                    tail = tail->nxt;

                tail->nxt = rest;
            }

            cur = cur->nxt;
        }
    }

    void display()
    {
        Node* cur = head;

        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->nxt;
        }

        cout << endl;
    }
};

int main()
{
    MultiLevelList list;

    int a, b, mode;
    cout << "Enter Node: ";

    for (int i = 0; i < 8; i++)
    {
        cin >> a >> b >> mode;

        if (mode == 0)
            list.linkNext(a, b);
        else
            list.linkChild(a, b);
    }

    list.flatten();
    list.display();

    return 0;
}