#include <iostream>
using namespace std;

struct Wagon
{
    int code;
    Wagon* fwd;
    Wagon* bwd;
};

class CircularTrain
{
private:
    Wagon* front;

public:
    CircularTrain() : front(nullptr) {}

    void insertCoach(int code)
    {
        Wagon* fresh = new Wagon;
        fresh->code = code;

        if (front == nullptr)
        {
            front = fresh;
            fresh->fwd = front;
            fresh->bwd = front;
            return;
        }

        Wagon* last = front->bwd;

        fresh->fwd = front;
        fresh->bwd = last;

        last->fwd = fresh;
        front->bwd = fresh;
    }

    Wagon* findNode(int code)
    {
        if (front == nullptr)
            return nullptr;

        Wagon* cur = front;

        do
        {
            if (cur->code == code)
                return cur;

            cur = cur->fwd;

        } while (cur != front);

        return nullptr;
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "Empty";
            return;
        }

        Wagon* cur = front;

        do
        {
            cout << cur->code << " <-> ";
            cur = cur->fwd;
        }
        while (cur != front);

        cout << "HEAD";
    }

    void detachNode(int code)
    {
        Wagon* w = findNode(code);

        if (w == nullptr)
        {
            cout << "Coach " << code << " not found." << endl;
            return;
        }

        if (w->fwd == w && w->bwd == w)
        {
            front = nullptr;
            return;
        }

        w->bwd->fwd = w->fwd;
        w->fwd->bwd = w->bwd;

        if (front == w)
        {
            front = w->fwd;
        }

        w->fwd = nullptr;
        w->bwd = nullptr;
    }

    void moveRight(int code)
    {
        Wagon* w = findNode(code);

        if (w == nullptr)
        {
            cout << "Coach " << code << " not found." << endl;
            return;
        }

        if (front->fwd == w)
            return;

        if (w == front)
            return;

        w->bwd->fwd = w->fwd;
        w->fwd->bwd = w->bwd;

        Wagon* right = front->fwd;

        w->bwd = front;
        w->fwd = right;

        front->fwd = w;
        right->bwd = w;
    }

    void moveLeft(int code)
    {
        Wagon* w = findNode(code);

        if (w == nullptr)
        {
            cout << "Coach " << code << " not found." << endl;
            return;
        }

        if (front->bwd == w)
            return;

        if (w == front)
            return;

        w->bwd->fwd = w->fwd;
        w->fwd->bwd = w->bwd;

        Wagon* left = front->bwd;

        w->fwd = front;
        w->bwd = left;

        left->fwd = w;
        front->bwd = w;
    }

    void deleteCoach(int code)
    {
        Wagon* w = findNode(code);

        if (w == nullptr)
        {
            cout << "Coach " << code << " not found." << endl;
            return;
        }

        if (w->fwd == w)
        {
            delete w;
            front = nullptr;
            return;
        }

        Wagon* successor = w->fwd;

        w->bwd->fwd = w->fwd;
        w->fwd->bwd = w->bwd;

        if (w == front)
        {
            front = successor;
        }

        delete w;
    }

    void setHead(int code)
    {
        Wagon* w = findNode(code);

        if (w == nullptr)
        {
            cout << "Coach " << code << " not found." << endl;
            return;
        }

        front = w;
    }

    void searchCoach(int code)
    {
        if (front == nullptr)
        {
            cout << "Train is empty." << endl;
            return;
        }

        Wagon* target = findNode(code);

        if (target == nullptr)
        {
            cout << "Coach " << code << " not found." << endl;
            return;
        }

        int fwdSteps = 0;
        Wagon* cur = front;

        while (cur != target)
        {
            cur = cur->fwd;
            fwdSteps++;
        }

        int bwdSteps = 0;
        cur = front;

        while (cur != target)
        {
            cur = cur->bwd;
            bwdSteps++;
        }

        if (fwdSteps <= bwdSteps)
        {
            cout << "Direction: NEXT" << endl;
            cout << "Path: ";

            cur = front;

            while (true)
            {
                cout << cur->code;

                if (cur == target)
                    break;

                cout << " -> ";
                cur = cur->fwd;
            }

            cout << endl;
            cout << "Steps: " << fwdSteps << endl;
        }
        else
        {
            cout << "Direction: PREV" << endl;
            cout << "Path: ";

            cur = front;

            while (true)
            {
                cout << cur->code;

                if (cur == target)
                    break;

                cout << " -> ";
                cur = cur->bwd;
            }

            cout << endl;
            cout << "Steps: " << bwdSteps << endl;
        }
    }
};

int main()
{
    CircularTrain train;

    int n;

    cout << "Enter number of coaches: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int code;
        cout << "Enter coach " << i + 1 << " ID:";
        cin >> code;

        train.insertCoach(code);
    }

    train.display();
    cout << endl;

    int commands;

    cout << "Enter number of commands: ";
    cin >> commands;

    for (int i = 0; i < commands; i++)
    {
        char command;
        int code;
        cout << "Enter command:";
        cin >> command;
        cout << "Enter ID:";
        cin >> code;

        if (command == 'R' || command == 'r')
        {
            train.moveRight(code);

            cout << "After R " << code << ": " << endl;
            train.display();
            cout << endl;
        }
        else if (command == 'L' || command == 'l')
        {
            train.moveLeft(code);

            cout << "After L " << code << ": " << endl;
            train.display();
            cout << endl;
        }
        else if (command == 'D' || command == 'd')
        {
            train.deleteCoach(code);

            cout << "After D " << code << ": " << endl;
            train.display();
            cout << endl;
        }
        else if (command == 'S' || command == 's')
        {
            train.setHead(code);

            cout << "After S " << code << ": " << endl;
            train.display();
            cout << endl;
        }
        else if (command == 'F' || command == 'f')
        {
            cout << endl;
            cout << "F " << code << ":" << endl;

            train.searchCoach(code);
        }
        else
        {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}