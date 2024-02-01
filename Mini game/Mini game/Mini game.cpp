#include <iostream>
#include <cstdlib> //генерации случайных чисел
#include <ctime> //в связке с srand(time(0)) позволяет генерировать новые рандомные числа при запуске программы
using namespace std;

int rollDice() 
{
    return rand() % 6 + 1; // генерация числа от 1 до 6
}

int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int uScore = 0;
    int cScore = 0;

    for (int i = 0; i < 3; i++) 
    {
        cout << "Ход пользователя. Нажмите Enter, чтобы бросить кубики.";
        cin.get(); //считывает одиночный символ

        int uRoll1 = rollDice();
        int uRoll2 = rollDice();
        int uTotal = uRoll1 + uRoll2;

        cout << "Вы выбросили: " << uRoll1 << ", " << uRoll2 << endl;
        cout << "Всего: " << uTotal << endl;


        cout << "Ход компьютера. Компьютер бросает кубики." << endl;

        int cRoll1 = rollDice();
        int cRoll2 = rollDice();
        int cTotal = cRoll1 + cRoll2;

        cout << "Компьютер выбросил: " << cRoll1 << ", " << cRoll2 << endl;
        cout << "Всего: " << cTotal << endl;


        if (uTotal > cTotal) 
        {
            uScore++;
            cout << "Вы выиграли раунд!" << endl;
        }
        else if (uTotal < cTotal) 
        {
            cScore++;
            cout << "Компьютер выиграл раунд!" << endl;
        }
        else 
        {
            cout << "Раунд завершился ничьей!" << endl;
        }

        cout << endl;
    }


    cout << "Игра окончена." << endl;
    cout << "Ваш счет: " << uScore << endl;
    cout << "Счет компьютера: " << cScore << endl;

    if (uScore > cScore) 
    {
        cout << "Вы выиграли игру!" << endl;
    }

    else if (uScore < cScore) 
    {
        cout << "Компьютер выиграл игру!" << endl;
    }

    else 
    {
        cout << "Игра завершилась вничью!" << endl;
    }

    return 0;
}
