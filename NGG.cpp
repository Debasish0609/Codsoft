#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    cout<<"THE NUMBER GUESSING GAME!!!"<<endl;
    int secretnumber = rand() % 100 + 1 ;
    int chances = 10;
    for (int i = 1 ; i<=chances ; i++)
    {
    int guess;
    cout<<"Guess a no between 1 and 100: "<<endl;
    cin>>guess;

    //check if guess is a correct guess or not
    if (guess == secretnumber)
    {
        cout<<"Your Guess is correct"<<endl;
    }
    else if (guess < secretnumber)
    {
        cout<<"your guess is too low"<<endl;
    }
    else
    {
        cout<<"your guess is too high"<<endl;
    }
    }
    return 0;

}
