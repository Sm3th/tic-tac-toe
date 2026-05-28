#include <iostream>
#include <limits>
using namespace std;

char spaces[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
char currentPlayer = 'x';
bool isTie = false;
string player1 = "Player 1";
string player2 = "Player 2";

void displayBoard()
{
    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++)
    {
        cout << "  " << spaces[i][0] << "  |  " << spaces[i][1] << "  |  " << spaces[i][2] << "\n";
        if (i < 2)
        {
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
        }
    }
    cout << "     |     |     \n";
    cout << "-------------------------------------------------------------------------------\n";
}

void processInput(){
    int digit;
    while (true)
    {
        cout << (currentPlayer == 'x' ? player1 : player2) << " enter a number: ";
        cin >> digit;

        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        if (digit < 1 || digit > 9)
        {
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        int row = (digit - 1) / 3;
        int col = (digit - 1) % 3;

        if (spaces[row][col] == 'x' || spaces[row][col] == 'o')
        {
            cout << "This cell is already taken. Please choose another one.\n";
            continue;
        }

        spaces[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'x' ? 'o' : 'x');
        break;
    }
}

bool checkGameResults(){

    for(int i = 0; i < 3; i++){
        if ((spaces[i][0] == spaces[i][1] && spaces[i][0] == spaces[i][2]) ||
           	(spaces[0][i] == spaces[1][i] && spaces[0][i] == spaces[2][i]))

        {
            return true;// Win
        }
    }

    if ((spaces[0][0] == spaces[1][1] && spaces[1][1] == spaces[2][2]) ||
        (spaces[0][2] == spaces[1][1] && spaces[1][1] == spaces[2][0]))
    {
        return true;// Win
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(spaces[i][j] != 'x' && spaces[i][j] != 'o')
            {
                return false;// Continue
            }
        }
    }

    isTie = true;
    return false;
}

int main()
{
    cout << "Player 1 enter your name: ";

    getline(cin, player1);

    cout << "Player 2 enter your name: ";

    getline(cin, player2);

    cout << player1 << " is player 1 and will play with x\n";
    cout << player2 << " is player 2 and will play with o\n";

    while (!checkGameResults()){
        displayBoard();
        processInput();
        
    }

    displayBoard();

    if (isTie)
    {
        cout << "It's a tie!" << endl;
    }
    else if (currentPlayer == 'o')
    {
        cout << player1 << " wins!!!" << endl;
    }
    else
    {
        cout << player2 << " wins!!!" << endl;
    }
    
    return 0;
}