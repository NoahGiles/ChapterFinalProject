// Roulette.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;

void board(int boardNumbers[], char boardColors[], int arraySize);

int main()
{
    random_device generator;
    uniform_int_distribution<int> distribution(1, 36);
    int boardNumbers[36] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 };
    char boardColors[36] = {'R', 'B' , 'R', 'B', 'R', 'B', 'R', 'B', 'R', 'B', 'B', 'R', 'B', 'R', 'B', 'R', 'B', 'R', 'R', 'B', 'R', 'B', 'R', 'B', 'R', 'B', 'R', 'B', 'B', 'R',
    'B', 'R', 'B', 'R', 'B', 'R'};
    char colorBet;
    int arraySize = sizeof(boardNumbers) / sizeof(boardNumbers[0]), randomNumber = distribution(generator), numberBet;
    string playInput, betType;
    bool betOver = false;
    double money = 100.00, bet;
    cout << "Welcome to roulette! Would you like to play roulette!? (yes or no) >>> \n";
    while (playInput == "yes" && money > 0 || playInput != "no" && money > 0)
    {
        cin >> playInput;
        if (playInput == "yes")
        {
            while (betOver == false)
            {
                cout << "YOU HAVE $" << money << "!\n\n";
                board(boardNumbers, boardColors, arraySize);
                while (betType != "number" && betType != "color")
                {
                    cout << "\nWould you like to bet on a number or a color? >>>\n";
                    cin >> betType;
                    if (betType != "number" && betType != "color")
                    {
                        cout << "That is not a valid input!";
                    }
                }
                cout << "How much money would you like to bet?\n";
                cin >> bet;
                if (betType == "number")
                {
                    cout << "What number would you like to bet on? (1 through 36) >>>\n";
                    cin >> numberBet;
                    cout << boardColors[randomNumber] << boardNumbers[randomNumber] << "\n";
                    if (numberBet == boardNumbers[randomNumber])
                    {

                        cout << "You won " << (bet * 36) << " dollars! ";
                        money += (bet * 36);
                    }
                    else
                    {
                        cout << "You lost $" << bet << "! ";
                        money -= bet;
                    }
                    betOver = true;
                }
                else if (betType == "color")
                {
                    cout << "What color would you like to bet on? (B or R) >>>\n";
                    cin >> colorBet;
                    cout << boardColors[randomNumber] << boardNumbers[randomNumber] << "\n";
                    if (colorBet == boardColors[randomNumber])
                    {

                        cout << "You won " << (bet * 2) << " dollars!";
                        money += (bet * 2);
                    }
                    else
                    {
                        cout << "You lost $" << bet << "! ";
                        money -= bet;
                    }
                    betOver = true;
                }
            }
        }

        

        else if (playInput == "no")
        {
            cout << "GOODBYE";
        }

        else
        {
            cout << "That is not a correct input. Enter yes or no PLEASE >>> \n";
        }
        if (money <= 0)
        {
            if (money < 0)
            {
                cout << "You are not allowed to bet anymore. You are in-debt $" << (money * -1) << ".";
            }
            else
            {
                cout << "You are broke now. You are kicked out for being broke.";
            }
        }
        else if (money > 0 && playInput != "no")
        {
            randomNumber = distribution(generator);
            betOver = false;
            betType = "";
            cout << "Would you like to play again? (yes or no) >>> \n";
        }
    }
    return 0;
    
}
void board(int boardNumbers[], char boardColors[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (i == 2 || i == 5 || i == 8 || i == 11 || i == 14 || i == 17 || i == 20 || i == 23 || i == 26 || i == 29 || i == 32 || i == 37)
        {
            cout << boardColors[i] << boardNumbers[i] << "\n";
            cout << "---------------\n";
        }
        else if (i <= 34)
        {
            if (i <= 8)
            {
                cout << " " << boardColors[i] << boardNumbers[i] << " | ";
            }
            else
            {
                cout << boardColors[i] << boardNumbers[i] << " | ";
            }
        }
        else if (i == 35)
        {
            cout << boardColors[i] << boardNumbers[i];
        }
    }
    cout << "\nBet payout :: Number : 36x, Color, 2x";
}