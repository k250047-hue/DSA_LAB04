#include <iostream>
using namespace std;

class Item
{
public:
    int val;
    Item* fwd;
    Item* bwd;

    Item(int v)
    {
        val = v;
        fwd = nullptr;
        bwd = nullptr;
    }
};

class SinglyList
{
    Item* front;
    Item* back;

public:
    SinglyList()
    {
        front = back = nullptr;
    }

    void insert(int v)
    {
        Item* fresh = new Item(v);

        if (front == nullptr)
        {
            front = back = fresh;
        }
        else
        {
            back->fwd = fresh;
            back = fresh;
        }
    }

    int length()
    {
        int cnt = 0;
        Item* cur = front;

        while (cur != nullptr)
        {
            cnt++;
            cur = cur->fwd;
        }

        return cnt;
    }

    void rotateLeft(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            Item* cur = front;

            front = front->fwd;
            cur->fwd = nullptr;

            back->fwd = cur;
            back = cur;
        }
    }

    void rotateRight(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            Item* cur = front;

            while (cur->fwd != back)
            {
                cur = cur->fwd;
            }

            cur->fwd = nullptr;
            back->fwd = front;
            front = back;
            back = cur;
        }
    }

    void print()
    {
        Item* cur = front;

        while (cur != nullptr)
        {
            cout << cur->val;

            if (cur->fwd != nullptr)
                cout << " -> ";

            cur = cur->fwd;
        }

        cout << endl;
    }
};

class DoublyList
{
    Item* front;
    Item* back;

public:
    DoublyList()
    {
        front = back = nullptr;
    }

    void insert(int v)
    {
        Item* fresh = new Item(v);

        if (front == nullptr)
        {
            front = back = fresh;
        }
        else
        {
            back->fwd = fresh;
            fresh->bwd = back;
            back = fresh;
        }
    }

    int length()
    {
        int cnt = 0;
        Item* cur = front;

        while (cur != nullptr)
        {
            cnt++;
            cur = cur->fwd;
        }

        return cnt;
    }

    void rotateLeft(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            Item* cur = front;

            front = front->fwd;
            front->bwd = nullptr;

            cur->fwd = nullptr;
            cur->bwd = back;

            back->fwd = cur;
            back = cur;
        }
    }

    void rotateRight(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            Item* cur = back;

            back = back->bwd;
            back->fwd = nullptr;

            cur->bwd = nullptr;
            cur->fwd = front;

            front->bwd = cur;
            front = cur;
        }
    }

    void print()
    {
        Item* cur = front;

        while (cur != nullptr)
        {
            cout << cur->val;

            if (cur->fwd != nullptr)
                cout << " <-> ";

            cur = cur->fwd;
        }

        cout << endl;
    }
};

class CircularList
{
    Item* front;
    Item* back;

public:
    CircularList()
    {
        front = back = nullptr;
    }

    void insert(int v)
    {
        Item* fresh = new Item(v);

        if (front == nullptr)
        {
            front = back = fresh;
            back->fwd = front;
        }
        else
        {
            back->fwd = fresh;
            back = fresh;
            back->fwd = front;
        }
    }

    int length()
    {
        if (front == nullptr)
            return 0;

        int cnt = 0;
        Item* cur = front;

        do
        {
            cnt++;
            cur = cur->fwd;
        }
        while (cur != front);

        return cnt;
    }

    void rotateLeft(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            front = front->fwd;
            back = back->fwd;
        }
    }

    void rotateRight(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            back = front;

            while (back->fwd != front)
            {
                back = back->fwd;
            }

            front = back;
        }
    }

    void print()
    {
        if (front == nullptr)
            return;

        Item* cur = front;

        do
        {
            cout << cur->val;

            cur = cur->fwd;

            if (cur != front)
                cout << " -> ";
        }
        while (cur != front);

        cout << " -> HEAD" << endl;
    }
};

class DoublyCircularList
{
    Item* front;
    Item* back;

public:
    DoublyCircularList()
    {
        front = back = nullptr;
    }

    void insert(int v)
    {
        Item* fresh = new Item(v);

        if (front == nullptr)
        {
            front = back = fresh;

            front->fwd = front;
            front->bwd = front;
        }
        else
        {
            fresh->bwd = back;
            fresh->fwd = front;

            back->fwd = fresh;
            front->bwd = fresh;

            back = fresh;
        }
    }

    int length()
    {
        if (front == nullptr)
            return 0;

        int cnt = 0;
        Item* cur = front;

        do
        {
            cnt++;
            cur = cur->fwd;
        }
        while (cur != front);

        return cnt;
    }

    void rotateLeft(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            front = front->fwd;
            back = back->fwd;
        }
    }

    void rotateRight(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            back = back->bwd;
            front = front->bwd;
        }
    }

    void print()
    {
        if (front == nullptr)
            return;

        Item* cur = front;

        do
        {
            cout << cur->val;

            cur = cur->fwd;

            if (cur != front)
                cout << " <-> ";
        }
        while (cur != front);

        cout << " <-> HEAD" << endl;
    }
};

int main()
{
    int choice;
    int n;
    int k;
    char dir;

    cout << "1. Singly Linked List" << endl;
    cout << "2. Doubly Linked List" << endl;
    cout << "3. Circular Linked List" << endl;
    cout << "4. Doubly Circular Linked List" << endl;

    cout << "Enter list type: ";
    cin >> choice;

    cout << "Enter number of elements: ";
    cin >> n;

    if (choice == 1)
    {
        SinglyList list;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            list.insert(value);
        }

        cout << "Enter K: ";
        cin >> k;

        cout << "Enter direction (L/R): ";
        cin >> dir;

        if (dir == 'L' || dir == 'l')
            list.rotateLeft(k);
        else
            list.rotateRight(k);

        cout << "Result: ";
        list.print();
    }
    else if (choice == 2)
    {
        DoublyList list;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            list.insert(value);
        }

        cout << "Enter K: ";
        cin >> k;

        cout << "Enter direction (L/R): ";
        cin >> dir;

        if (dir == 'L' || dir == 'l')
            list.rotateLeft(k);
        else
            list.rotateRight(k);

        cout << "Result: ";
        list.print();
    }
    else if (choice == 3)
    {
        CircularList list;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            list.insert(value);
        }

        cout << "Enter K: ";
        cin >> k;

        cout << "Enter direction (L/R): ";
        cin >> dir;

        if (dir == 'L' || dir == 'l')
            list.rotateLeft(k);
        else
            list.rotateRight(k);

        cout << "Result: ";
        list.print();
    }
    else if (choice == 4)
    {
        DoublyCircularList list;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            list.insert(value);
        }

        cout << "Enter K: ";
        cin >> k;

        cout << "Enter direction (L/R): ";
        cin >> dir;

        if (dir == 'L' || dir == 'l')
            list.rotateLeft(k);
        else
            list.rotateRight(k);

        cout << "Result: ";
        list.print();
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}