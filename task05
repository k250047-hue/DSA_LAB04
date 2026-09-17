#include <iostream>
using namespace std;

class Elem
{
public:
    int val;
    Elem* nxt;

    Elem(int v)
    {
        val = v;
        nxt = nullptr;
    }
};

class Chain
{
    Elem* front;
    Elem* back;

public:

    Chain()
    {
        front = back = nullptr;
    }

    void insert(int v)
    {
        Elem* fresh = new Elem(v);

        if (front == nullptr)
        {
            front = back = fresh;
        }
        else
        {
            back->nxt = fresh;
            back = fresh;
        }
    }

    int length()
    {
        int cnt = 0;
        Elem* cur = front;

        while (cur != nullptr)
        {
            cnt++;
            cur = cur->nxt;
        }

        return cnt;
    }

    void reverseGroups(int k)
    {
        if (k <= 1 || front == nullptr)
            return;

        int total = length();

        Elem* cur = front;
        Elem* prevGroupEnd = nullptr;

        while (cur != nullptr)
        {
            Elem* check = cur;
            int cnt = 0;

            while (check != nullptr && cnt < k)
            {
                check = check->nxt;
                cnt++;
            }

            if (cnt < k)
                break;

            Elem* groupStart = cur;
            Elem* prev = nullptr;
            Elem* nxtElem = nullptr;

            for (int i = 0; i < k; i++)
            {
                nxtElem = cur->nxt;
                cur->nxt = prev;
                prev = cur;
                cur = nxtElem;
            }

            if (prevGroupEnd == nullptr)
            {
                front = prev;
            }
            else
            {
                prevGroupEnd->nxt = prev;
            }

            prevGroupEnd = groupStart;
            prevGroupEnd->nxt = cur;
        }

        back = front;

        while (back != nullptr && back->nxt != nullptr)
        {
            back = back->nxt;
        }
    }

    void print()
    {
        Elem* cur = front;

        while (cur != nullptr)
        {
            cout << cur->val;

            if (cur->nxt != nullptr)
                cout << " -> ";

            cur = cur->nxt;
        }

        cout << endl;
    }
};

int main()
{
    Chain list;

    int n;
    int k;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;

        cout << "Enter element " << i + 1 << ": ";
        cin >> value;

        list.insert(value);
    }

    cout << "Enter K: ";
    cin >> k;

    cout << "Original List: ";
    list.print();

    list.reverseGroups(k);

    cout << "After Reversing Groups: ";
    list.print();

    return 0;
}