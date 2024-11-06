#include <iostream>
using namespace std;

int Sum(int num1, int num2)
{
    return num1 + num2;
}
int Sub(int num1, int num2)
{
    return num1 - num2;
}
int Mul(int num1, int num2)
{
    return num1 * num2;
}
int Div(int num1, int num2)
{
    return num1 / num2;
}
void Print(int result)
{
    cout << "Output is: " << result << endl;
}

int main()
{
    int num1, num2;
    char operand;
    int result = 0;

    cout << "Basic Calculator" << endl;
    cout << "Enter Two Num: " << endl;
    cin >> num1 >> num2;

    cout << "Enter the operation you want to execute: " << endl;
    cout << "+ : Addition" << endl;
    cout << "- : Subtraction" << endl;
    cout << "* : Multiplication" << endl;
    cout << "/ : Division" << endl;
    cin >> operand;

    switch (operand)
    {
    case '+':
        result = Sum(num1, num2);
        Print(result);
        break;
    case '-':
        result = Sub(num1, num2);
        Print(result);
        break;
    case '*':
        result = Mul(num1, num2);
        Print(result);
        break;
    case '/':
        if (num2 == 0)
        {
            cout << "*ERROR*: Division by 0 not allowed" << endl;
        }
        else
        {
            result = Div(num1, num2);
            Print(result);
        }
        break;

    default:
        cout << "*ERROR*: Invalid operation" << endl;
        break;
    }
    return 0;
}