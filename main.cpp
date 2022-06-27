#include <iostream>
#include <string>
#include <random>

using namespace std;

struct globalBattle
{
    char board[10][10] = {
            {'0','0','0','0','0','0','0','0','0','0'}, // 0
            {'0','0','0','0','0','0','0','0','0','0'}, // 1
            {'0','0','0','0','0','0','0','0','0','0'}, // 2
            {'0','0','0','0','0','0','0','0','0','0'}, // 3
            {'0','0','0','0','0','0','0','0','0','0'}, // 4
            {'0','0','0','0','0','0','0','0','0','0'}, // 5
            {'0','0','0','0','0','0','0','0','0','0'}, // 6
            {'0','0','0','0','0','0','0','0','0','0'}, // 7
            {'0','0','0','0','0','0','0','0','0','0'}, // 8
            {'0','0','0','0','0','0','0','0','0','0'} // 9
    };

    void randSettings()
    {
        int shipSymCoord = rand() % 10 + 1;
        int shipNumCoord = rand() % 10 + 1;
        int countTh = 0;
        int *ptrCountTh = &countTh;
        for (int i = 0; i < 4; i++)
        {
            board[shipSymCoord][shipNumCoord] = '1';
        }
    }

    void handleSettings(char type, int sym, int num)
    {
        for (int i = 0; i < type; i++)
        {
            board[sym][num+i] = type;
        }
    }

    void setBomb(string player, int sym, int num)
    {
        board[sym][num] = 'X';
        cout << player << " has bomb is planted";
    }

    void winChecker()
    {
        for (int s = 0; s < 10; s++)
        {
            for (int i = 0; i < 10; i++)
            {
                if (board[s][i] == '0' || board[s][i] == 'X')
                {
                    cout << "Win";
                }
                else {
                    cout  << "Lose";
                    break;
                }
            }
        }
    }
};

int main()
{
    char select;
    cout << "You need bot for game in ship battle? y/n";
    cin >> select;
    globalBattle global;
    switch (select)
    {
        case 'y':
            global.randSettings();
        case 'n':
            string playerOne, playerTwo;
            cin >> playerOne;
            cin >> playerTwo;
            int type, sym, num;
            for (int i = 0; i < 10; i++)
            {
                cout << playerOne;
                cout << "Введите тип: " << endl;
                cin >> type;
                cout << "Куда поставить: " << endl;
                cin >> sym;
                cout << "Число: " << endl;
                cin >> num;
                global.handleSettings(type, sym, num);
            }
            for (int i = 0; i < 80; i++)
            {
                cout << playerTwo << " Точка: " << endl;
                cin >> sym;
                cin >> num;
                global.setBomb(playerTwo, sym, num);
            }
            global.winChecker();
    }
}
