#include <iostream>
using namespace std;

int& numCheck(int&);

int main()
{
    srand(time(NULL));      //to generate random number on each run
    int randNum = rand() % 101;
    int num;
    int tries = 0;
    
    cout << "\n---------------------*  NUMBER GUESS GAME  *---------------------\n";
    cout << "\n Instructions:  Guess the number between the range 0-100\n";
   
    while (true)
    {
                
        cout<<"\n - Enter your guess =  ";
        num = numCheck(num);

        ++tries;
        
        if (num > randNum) 
            cout << "\n  \t Too high, guess lower\n";
            
        else if (num<randNum) 
            cout <<"\n  \t Too low, try a little higher\n";
            
        else 
        {
            cout<<"\n\n \t\t*****  CORRECT! *****\n     CONGRATULATIONS! YOU GUESSED THE NUMBER IN "<<tries<<" ATTEMPTS! :D\n";
            break;
        }
    }
    
    cout << "\n \t\tThe number was  '" << randNum << "'\n\n\n";

    for (int i = 0; i < 66; i++) cout << "-";
    cout << "\n\n\n";

    return 0;
}

int& numCheck(int& n)
{
    cin >> n;
    while (cin.fail() || n > 100 || n < 0)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "\n\t ***  Error! Input must be numeric  ***\n";
            cout << "\n - Enter your guess = ";
            cin >> n;
        }
        else
        {
            cout << "\n\t ***  Error! Input must be in the range 0-100  ***\n";
            cout << "\n - Enter your guess = ";
            cin >> n;
        }
    }
    return n;
}
