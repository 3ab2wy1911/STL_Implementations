#include <bits/stdc++.h>
using namespace std;
template <typename t>
class Stack
{
    int size;
    t* arr ;
    t peek;
public:
    explicit Stack(int s)
    {
        arr = new t [s];
        size = s;
        peek = -1;
    }
    bool is_empty ()
    {
        return (peek == -1);
    }
    bool is_full ()
    {
        return (peek == size - 1);
    }
    void push (t item) {
        try {
            if (is_full()) {
                throw ("Stack is Full");
            } else {
                arr[++peek] = item;
            }
        }
        catch (const char *msg) {
            cout << msg << endl;
            exit(1);
        }
    }
    void pop ()
    {
        try
        {
            if (is_empty())
            {
                throw ("Stack is empty");
            }
            else
            {
                peek--;
            }
        }
        catch (const char* msg)
        {
            cout << msg << endl;
            exit(1);
        }
    }
    t Peek()
    {
        try
        {
            if (is_empty())
            {
                throw ("Stack is empty");
            }
            else
            {
               return arr[peek];
            }
        }
        catch (const char* msg)
        {
            cout << msg << endl;
            exit(1);
        }
    }
    int Size ()
    {
        return peek +1;
    }
    void clear ()
    {
        peek = -1;
    }
};

void menu()
{
    cout<<"Please Enter the size of the Stack\n";
    int SIZE ;
    cin>>SIZE;
    Stack <int> stack (SIZE);
    while (true)
    {
        cout<<"Enter the operation\n";
        cout<<"1.push , 2.pop , 3.Peek , 4.Size , 5.Clear , 6.Empty , 7 Full , 8.Exit:";
        char choice ;
        cin >> choice ;
        int top;
        switch (choice)
        {
            case '1' :
                cout << "Enter the element :";
                int item;
                cin >> item;
                stack.push(item);
                cout<<"Done!";
                break;
            case '2':
                stack.pop();
                cout<<"Done!\n";
                break;
            case '3':
               top = stack.Peek();
                cout<<"The top element is "<<top<<endl;
                break;
            case '4':
                cout<<"The size of the stack is " << stack.Size()<<endl;
                break;
            case'5':
                stack.clear();
                cout<<"Done!\n";
                break;
            case '6':
                if (stack.is_empty())
                    cout<<"Yes\n";
                else cout<<"NO\n";
                break;
            case '7':
                if (stack.is_full())
                    cout<<"Yes\n";
                else cout<<"NO\n";
                break;
            case '8':
                exit(1);
            default : cout<<"Invalid choice!!! \n";
        }
    }
}
int main() {
    menu();
}
