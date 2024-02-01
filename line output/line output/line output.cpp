#include "ext.h"

int main()
{
    setlocale(LC_ALL, "ru");
    char quit[6], symbol[5];
    int number, type_l, speed, speed_value;

    while (true)
    {
        cout << "Доступные направления: 1 - Вертикальная линия. 2 - Горизонтальная линия \n";
        cout << "************************************************************************** \n";
        cout << "Введите через Enter тип линии, число символов, и символ, которым будет рисоваться линия\n";
        cin >> type_l >> number >> symbol;

        cout << "Введите скорости прорисовки линии.\n1 - медленно (2 сек), 2 - быстрее (1 сек), 3 - мгновенно\n";
        cin >> speed;
        cout << "\n";

        switch (speed)
        {
        case 1: speed_value = 2000;
            break;

        case 2: speed_value = 1000;
            break;

        case 3: speed_value = 0;
            break;

        default: cout << "Значение скорости введено некорректно.\n";
        }

        if (type_l == 1)
        {
            for (number; number != 0; number--)
            {
                Sleep(speed_value); cout << symbol << "\n";
            }

        }
        else if (type_l == 2)
        {
            for (number; number != 0; number--)
            {
                Sleep(speed_value); cout << symbol;
            }
        }
        else
            cout << "АХТУНГ! Некорректное значение";
            cout << "\nДля выхода введите \"quit\" для продолжения работы введите любой другой символ\n"; //Выход из бесконечного цикла.
            cin >> quit;
            cout << "************************************************************************** \n";
            if (strcmp(quit, "quit") == 0) break;
    }
}