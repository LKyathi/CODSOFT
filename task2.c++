#include<iostream>
using namespace  std;
int main()
{
    int a,b;
    char oper;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    cout<<"Choose an option"<<endl;
    cout<<"1.Addition(+)"<<endl;
    cout<<"2.Subtraction(-)"<<endl;
    cout<<"3.Multiplication(*)"<<endl;
    cout<<"4.Division(/)"<<endl;
    cout<<"5.Modulo Division(%)"<<endl;
    cin>> oper;
    switch(oper)
    {
        case '+':
        cout<<a+b<<"is sum of the numbers"<<endl;
        break;
        case '-':
        cout<<a-b<<"is the difference of numbers"<<endl;
        break;
        case '*':
        cout<<a*b<<"is the product of numbers"<<endl;
        break;
        case '/':
        cout<<a/b<<"is the quotient of numbers"<<endl;
        break;
        case '%':
        cout<<a%b<<"is the remainder of numbers"<<endl;
        break;
        default:
        cout<<"Invalid operator!! try again"<<endl;
    }
} 

