#include <iostream>
using namespace std;

class Elem
{
public:
    int val;
    Elem* nxt;
    Elem* prv;

    Elem(int v)
    {
        val = v;
        nxt = nullptr;
        prv = nullptr;
    }
};

class SinglyChain
{
    Elem* start;
    Elem* end;

public:

    SinglyChain()
    {
        start = nullptr;
        end = nullptr;
    }

    void pushBack(int v)
    {
        Elem* fresh = new Elem(v);

        if (start == nullptr)
        {
            start = end = fresh;
        }
        else
        {
            end->nxt = fresh;
            end = fresh;
        }
    }

    int length()
    {
        int cnt = 0;
        Elem* cur = start;

        while (cur != nullptr)
        {
            cnt++;
            cur = cur->nxt;
        }

        return cnt;
    }

    void input()
    {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int v;
            cout << "Enter element " << i + 1 << ": ";
            cin >> v;

            pushBack(v);
        }
    }

    void bubbleSort()
    {
        int n = length();

        for (int i = 0; i < n - 1; i++)
        {
            Elem* cur = start;

            for (int j = 0; j < n - i - 1; j++)
            {
                if (cur->val > cur->nxt->val)
                {
                    int tmp = cur->val;
                    cur->val = cur->nxt->val;
                    cur->nxt->val = tmp;
                }

                cur = cur->nxt;
            }
        }
    }

    bool hasCycle()
    {
        Elem* slow = start;
        Elem* fast = start;

        while (fast != nullptr && fast->nxt != nullptr)
        {
            slow = slow->nxt;
            fast = fast->nxt->nxt;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void print()
    {
        Elem* cur = start;

        while (cur != nullptr)
        {
            cout << cur->val << " -> ";
            cur = cur->nxt;
        }

        cout << "NULL";
    }
};

class DoublyChain
{
    Elem* start;
    Elem* end;

public:

    DoublyChain()
    {
        start = nullptr;
        end = nullptr;
    }

    void pushBack(int v)
    {
        Elem* fresh = new Elem(v);

        if (start == nullptr)
        {
            start = end = fresh;
        }
        else
        {
            end->nxt = fresh;
            fresh->prv = end;
            end = fresh;
        }
    }

    int length()
    {
        int cnt = 0;
        Elem* cur = start;

        while (cur != nullptr)
        {
            cnt++;
            cur = cur->nxt;
        }

        return cnt;
    }

    void input()
    {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int v;
            cout << "Enter element " << i + 1 << ": ";
            cin >> v;

            pushBack(v);
        }
    }

    void bubbleSort()
    {
        int n = length();

        for (int i = 0; i < n - 1; i++)
        {
            Elem* cur = start;

            for (int j = 0; j < n - i - 1; j++)
            {
                if (cur->val > cur->nxt->val)
                {
                    int tmp = cur->val;
                    cur->val = cur->nxt->val;
                    cur->nxt->val = tmp;
                }

                cur = cur->nxt;
            }
        }
    }

    bool hasCycle()
    {
        Elem* slow = start;
        Elem* fast = start;

        while (fast != nullptr && fast->nxt != nullptr)
        {
            slow = slow->nxt;
            fast = fast->nxt->nxt;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void print()
    {
        Elem* cur = start;

        while (cur != nullptr)
        {
            cout << cur->val << " <-> ";
            cur = cur->nxt;
        }

        cout << "NULL";
    }
};

class CircularChain
{
    Elem* start;
    Elem* end;

public:

    CircularChain()
    {
        start = nullptr;
        end = nullptr;
    }

    void pushBack(int v)
    {
        Elem* fresh = new Elem(v);

        if (start == nullptr)
        {
            start = end = fresh;
            end->nxt = start;
        }
        else
        {
            end->nxt = fresh;
            end = fresh;
            end->nxt = start;
        }
    }

    int length()
    {
        if (start == nullptr)
            return 0;

        int cnt = 0;
        Elem* cur = start;

        do
        {
            cnt++;
            cur = cur->nxt;
        }
        while (cur != start);

        return cnt;
    }

    void input()
    {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int v;
            cout << "Enter element " << i + 1 << ": ";
            cin >> v;

            pushBack(v);
        }
    }

    void bubbleSort()
    {
        int n = length();

        if (n <= 1)
            return;

        for (int i = 0; i < n - 1; i++)
        {
            Elem* cur = start;

            for (int j = 0; j < n - i - 1; j++)
            {
                Elem* nxtElem = cur->nxt;

                if (cur->val > nxtElem->val)
                {
                    int tmp = cur->val;
                    cur->val = nxtElem->val;
                    nxtElem->val = tmp;
                }

                cur = cur->nxt;
            }
        }
    }

    bool hasCycle()
    {
        if (start == nullptr)
            return false;

        Elem* slow = start;
        Elem* fast = start;

        while (fast != nullptr && fast->nxt != nullptr)
        {
            slow = slow->nxt;
            fast = fast->nxt->nxt;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void print()
    {
        if (start == nullptr)
        {
            cout << "Empty";
            return;
        }

        Elem* cur = start;

        do
        {
            cout << cur->val << " -> ";
            cur = cur->nxt;
        }
        while (cur != start);

        cout << "HEAD";
    }
};

class DoublyCircularChain
{
    Elem* start;
    Elem* end;

public:

    DoublyCircularChain()
    {
        start = nullptr;
        end = nullptr;
    }

    void pushBack(int v)
    {
        Elem* fresh = new Elem(v);

        if (start == nullptr)
        {
            start = end = fresh;

            start->nxt = start;
            start->prv = start;
        }
        else
        {
            fresh->prv = end;
            fresh->nxt = start;

            end->nxt = fresh;
            start->prv = fresh;

            end = fresh;
        }
    }

    int length()
    {
        if (start == nullptr)
            return 0;

        int cnt = 0;
        Elem* cur = start;

        do
        {
            cnt++;
            cur = cur->nxt;
        }
        while (cur != start);

        return cnt;
    }

    void input()
    {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int v;
            cout << "Enter element " << i + 1 << ": ";
            cin >> v;

            pushBack(v);
        }
    }

    void bubbleSort()
    {
        int n = length();

        if (n <= 1)
            return;

        for (int i = 0; i < n - 1; i++)
        {
            Elem* cur = start;

            for (int j = 0; j < n - i - 1; j++)
            {
                Elem* nxtElem = cur->nxt;

                if (cur->val > nxtElem->val)
                {
                    int tmp = cur->val;
                    cur->val = nxtElem->val;
                    nxtElem->val = tmp;
                }

                cur = cur->nxt;
            }
        }
    }

    bool hasCycle()
    {
        if (start == nullptr)
            return false;

        Elem* slow = start;
        Elem* fast = start;

        while (fast != nullptr && fast->nxt != nullptr)
        {
            slow = slow->nxt;
            fast = fast->nxt->nxt;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void print()
    {
        if (start == nullptr)
        {
            cout << "Empty";
            return;
        }

        Elem* cur = start;

        do
        {
            cout << cur->val << " <-> ";
            cur = cur->nxt;
        }
        while (cur != start);

        cout << "HEAD";
    }
};

int main()
{
    const int totalChains = 12;

    int kind[totalChains];
    int tally[5] = {0};

    SinglyChain* s[totalChains];
    DoublyChain* d[totalChains];
    CircularChain* c[totalChains];
    DoublyCircularChain* dc[totalChains];

    for (int i = 0; i < totalChains; i++)
    {
        s[i] = nullptr;
        d[i] = nullptr;
        c[i] = nullptr;
        dc[i] = nullptr;
    }

    cout << "Enter 12 Linked Lists" << endl;
    cout << "Each type must occur at least 3 times." << endl;
    cout << "Two consecutive lists cannot have the same type." << endl;

    for (int i = 0; i < totalChains; i++)
    {
        cout << endl;
        cout << "Position " << i + 1 << endl;
        cout << "1. Singly" << endl;
        cout << "2. Doubly" << endl;
        cout << "3. Circular" << endl;
        cout << "4. Doubly Circular" << endl;

        while (true)
        {
            cout << "Enter type: ";
            cin >> kind[i];

            if (kind[i] < 1 || kind[i] > 4)
            {
                cout << "Invalid type." << endl;
                continue;
            }

            if (i > 0 && kind[i] == kind[i - 1])
            {
                cout << "Same type cannot come consecutively." << endl;
                continue;
            }

            break;
        }

        tally[kind[i]]++;

        if (kind[i] == 1)
        {
            s[i] = new SinglyChain();
            s[i]->input();
        }
        else if (kind[i] == 2)
        {
            d[i] = new DoublyChain();
            d[i]->input();
        }
        else if (kind[i] == 3)
        {
            c[i] = new CircularChain();
            c[i]->input();
        }
        else
        {
            dc[i] = new DoublyCircularChain();
            dc[i]->input();
        }
    }

    if (tally[1] < 3 || tally[2] < 3 ||
        tally[3] < 3 || tally[4] < 3)
    {
        cout << endl;
        cout << "Invalid input." << endl;
        cout << "Every type must occur at least 3 times." << endl;

        return 0;
    }

    for (int i = 0; i < totalChains; i++)
    {
        if (kind[i] == 1)
            s[i]->bubbleSort();

        else if (kind[i] == 2)
            d[i]->bubbleSort();

        else if (kind[i] == 3)
            c[i]->bubbleSort();

        else
            dc[i]->bubbleSort();
    }

    cout << endl;
    cout << "Sorted Lists" << endl;

    for (int i = 0; i < totalChains; i++)
    {
        cout << "Position " << i + 1 << ": ";

        if (kind[i] == 1)
            s[i]->print();

        else if (kind[i] == 2)
            d[i]->print();

        else if (kind[i] == 3)
            c[i]->print();

        else
            dc[i]->print();

        cout << endl;
    }

    int cycleTotal = 0;

    cout << endl;
    cout << "Cycle Detection" << endl;

    for (int i = 0; i < totalChains; i++)
    {
        bool cyc = false;

        if (kind[i] == 1)
            cyc = s[i]->hasCycle();

        else if (kind[i] == 2)
            cyc = d[i]->hasCycle();

        else if (kind[i] == 3)
            cyc = c[i]->hasCycle();

        else
            cyc = dc[i]->hasCycle();

        cout << "Position " << i + 1 << ": ";

        if (cyc)
        {
            cout << "Cycle Found";
            cycleTotal++;
        }
        else
        {
            cout << "No Cycle";
        }

        cout << endl;
    }

    cout << endl;
    cout << "Total Number of Cycles: "
         << cycleTotal << endl;

    cout << endl;
    cout << "Final Resultant Lists" << endl;

    for (int i = 0; i < totalChains; i++)
    {
        cout << "Position " << i + 1 << ": ";

        if (kind[i] == 1)
            s[i]->print();

        else if (kind[i] == 2)
            d[i]->print();

        else if (kind[i] == 3)
            c[i]->print();

        else
            dc[i]->print();

        cout << endl;
    }

    return 0;
}