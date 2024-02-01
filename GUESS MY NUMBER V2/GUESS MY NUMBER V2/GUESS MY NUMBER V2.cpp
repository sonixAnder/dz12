#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int level = 1;
    int lives = 3;
    int totalPoints = 0;

    while (level <= 2) 
    {

        cout << "Уровень " << level << endl;

        int round = 1;
        int roundPoints = 0;

        while (round <= 3 && lives > 0) 
        {

            int targetNumber = rand() % 100 + 1;
            int guess; 

            cout << "Раунд " << round << endl;
            cout << "Угадай число: ";
            cin >> guess;

            if (guess == targetNumber) 
            {
                cout << "Поздравляю, ты угадал!" << endl;
                totalPoints += roundPoints; 
                roundPoints = 0; 
            }
            else 
            {
                cout << "Неправильно, -1 жизнь!" << endl;
                lives--; 
                roundPoints = lives * (level == 1 ? 5 : 10); 
            }

            cout << "Всего очков: " << totalPoints << endl;
            cout << "Жизней потрачено: " << lives << endl;
            cout << endl;

            round++;
        }

        if (lives <= 0) 
        {
            cout << "Гамэ овэр!" << endl;
            break; 
        }

        level++;
        lives += 3; 
    }

    cout << "Ты победил в этой игре!" << endl;
    cout << "Всего очков: " << totalPoints << endl;

    return 0;
}