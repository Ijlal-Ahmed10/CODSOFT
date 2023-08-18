#include <iostream>
using namespace std;


double& numCheck(double&);      

char& operatorCheck(char& op);     



int main()
{
    double num1 = 0.0, num2 = 0.0, result = 0.0;
    char oper= ' ';

    cout << "\n-------------------------*  CALCULATOR  *-------------------------\n";

    cout << "\n\n - Enter first number: ";
    num1 = numCheck(num1);

    cout << "\n\n - Enter second number: ";
    num2 = numCheck(num2);

    cout << "\n\n - Choose an operation i.e. ( +, -, *, / ) :  ";
    oper = operatorCheck(oper);
    
    switch(oper)
    {
        case '+':
            result = num1 + num2;
        break;
        
        case '-':
            result = num1 - num2;
        break;
        
        case '*':
            result = num1 * num2;
        break;
        
        case '/':
            if (num2 == 0)
            {
                cout << "\n\n *** Error! Can't divide by zero ***\n";
                cout << "\n Result =  undefined\n\n";
                return 1;                                   // return with error code 1
            }
            else
                result = num1 / num2;
        break;
        
        default:
            cout << "\n *** Error! Invalid operator ***\n\n";
            return 1;
    }

    cout << "\n\n\n Expression :     " << num1 << " " << oper << " " << num2 << "  =  " << result << "\n";
    
    cout << "\n\n Result =  " << result << "\n\n";

    for (int i = 0; i < 66; i++)cout << "-";
    cout << "\n";


    return 0;
}




double& numCheck(double& x)
{
    cin >> x;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "\n *** Error! Input should be numeric ***\n";
        cout << "\n - Enter number : ";
        cin >> x;
    }
    return x;
}

char& operatorCheck(char& op)
{
    cin >> op;
    while (op != '+' && op!= '-' && op != '*' && op != '/')   
    {
        cout << "\n *** Error! Invalid operator ***\n";
        cout << "\n - Choose an operation (eg: +, - , *, /) :  ";
        cin >> op;
    }
    return op;
}