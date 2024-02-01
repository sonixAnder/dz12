#include "ext.h"
int main()
{
	setlocale(LC_ALL, "ru");
	int level, a, b, magicNum, userNum;
	int userChoice, userLives, userPoints, guessed;
	userPoints = 0;
	guessed = 0;
	srand(time(NULL));

	do
	{
		cout << "Добро пожаловать в игру\n";
		cout << "Твой выбор:\n";
		cout << "1 - 1-ый уровень, случайное число [1..10]\n";
		cout << "2 - 2-ой уровень, случайное число [10..100]\n";
		cout << "3 - выход\n";
		cin >> userChoice;

		switch (userChoice) 
		{
		case 1:
		{
			cout << "Добро пожаловать в 1-ый уровень: "
				"случайное число.. [1..10]!\n";
			a = 1;
			b = 10;
			userLives = (b - a + 1) / 2;
			cout << "Бот считает число...\n";
			Sleep(1000);
			magicNum = a + rand() % (b - a);
			cout << "Случайное число готово! "
				"Давайте попробуем угадать его!\n";
			do 
			{
				cout << "Сейчас у вас "<< userLives << "жизней.\n";
				cout << "Попробуй угадать, твой вариант?\n";
				cin >> userNum;
				if (userNum == magicNum)
				{
					cout << "Т!\n";
					guessed = 1;
				}
				else
				{
					cout << "Охх.. я потерял 1-у жизнь!\n";
					userLives--;
					cout << "Сейчас у вас " << userLives << "жизней.\n";
					do
					{
						cout << "Хотите небольшую подсказку? Стоимость - 1 жизнь\n";
						cout << "Выбирайте:\n";
						cout << "1 - хочу\n";
						cout << "0 - не хочу\n";
						cin >> userChoice;

						if (userChoice == 1)
						{
							if (userNum > magicNum)
							{
								cout << "-1 жизнь в связи с подсказкой...\n";
								userLives--;
							}
							else
							{
								cout << "Жизнь оставлена в связи с отказом от подсказки...\n";
								userLives--;
							}
						}
					} while ((userChoice != 1) &&
						(userChoice != 0));
				}
			} while ((userLives > 0) && (guessed == 0));
			userPoints = userLives * 5;
			if (userPoints == 0)
			{
				cout << "Ты програл!\n";
			}
			else
			{
				cout << "Твои очки:" << userPoints;
				cout << "\n";
			}
			break;

		}
		case 2:
		{
			cout << "Вэлком во 2-ой уровень: Случайное число [10..100]!\n";
			a = 10;
			b = 100;
			userLives = (b - a + 1) / 4;

			cout << "Бот придумывает число...\n";

			Sleep(1000);
			magicNum = a + rand() % (b - a);

			cout << "Случайное число готово! "
				"Давайте попробуем угадать его\n";
			do 
			{
				cout << "Сейчас у вас " << userLives << "жизней.\n";
				cout << "Давай отгадывать, твоя очередь\n";
				cin >> userNum;
				if (userNum == magicNum)
				{
					cout << "Ты угадал число!\n";
					guessed = 1;
				}
				else 
				{
					cout << "Блин, потерял 1-у жизнь\n";
					userLives--;
					cout << "Сейчас у вас " << userLives << "жизней.\n";

					do 
					{
						cout << "Хотите небольшую подсказку? Стоимость - 1 жизнь\n";
						cout << "Твой выбор:\n";
						cout << "1 - хочу\n";
						cout << "0 - не хочу\n";
						cin >> userChoice;
						if (userChoice == 1)
						{
							if (userNum > magicNum)
							{
								cout << "-1 жизнь в связи с подсказкой...\n ";
								userLives--;
							}
							else
							{
								cout << "Жизнь оставлена в связи с отказом от подсказки...\n";
								userLives--;
							}
						}
					} while ((userChoice != 1) &&
						(userChoice != 0));
				}
			} while ((userLives > 0) && (guessed == 0));
			userPoints = userLives * 10;
			if (userPoints == 0)
			{
				cout << "Ты проиграл!\n";
			}
			else
			{
				cout << "Твой счёт:" << userPoints << "\n";
			}
			break;
		}

		case 3:
		{
			cout << "Увидимся!";
			break;
		}
		default:
			cout << "АХТУНГ!";
		}
	} while (userChoice != 3);
	return 0;
}