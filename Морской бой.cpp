#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char ships1[10][10]{};   // поля, которые не будут меняться (исходные)
    ifstream file1("Корабли игрока 1.txt");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            file1 >> ships1[i][j];
        }
    }
    file1.close();

    char ships2[10][10]{};   // поля, которые не будут меняться (исходные)
    ifstream file2("Корабли игрока 2.txt");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            file2 >> ships2[i][j];
        }
    }
    file2.close();

    char ships1_1[10][10]{};  // поля, которые будут меняться во время игры
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ships1_1[i][j] = '.';
        }
    }

    char ships2_2[10][10]{};  // поля, которые будут меняться во время игры
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ships2_2[i][j] = '.';
        }
    }

    int a = 0;  // счетчик победы
    int b = 0;  // счетчик конца хода игрока
    int m = 0;
    int n = 0;
    int d1 = 0; // счётчик подбитых клеток игроком 1
    int d2 = 0; // счётчик подбитых клеток игроком 2
    char cordinaty;
    int cordinaty1;
    bool around = false;
    char bykvi[10]{ 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ж', 'З', 'И', 'К' };

    while (a == 0)
    {
        while (b == 0)
        {
            cout << endl << endl << "Ход 1-ГО ИГРОКА: " << endl
                << endl
                << "   ";
            for (int i = 0; i < 10; i++)
                cout << bykvi[i] << " ";
            cout << endl;
            for (int i = 0; i < 10; i++)
            {
                if (i != 9)
                    cout << i + 1 << "  ";
                else
                    cout << i + 1 << " ";
                for (int j = 0; j < 10; j++)
                {
                    cout << ships2_2[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl
                << "1-Й ИГРОК ВВОДИТ КООРДИНАТЫ: ";
            cin >> cordinaty >> cordinaty1;
            cout << endl << endl;
            if (cordinaty < 'А'|| cordinaty > 'К' || cordinaty1 < 1 || cordinaty1 > 10)    // проверка на правильные координаты
            {
                cout << "Некорректные координаты. Попробуйте снова." << endl;
                continue;
            }

            m = cordinaty1 - 1;
            for (int i = 0; i < 10; i++)
            {
                if (cordinaty == bykvi[i])
                    n = i;
            }

            if (ships2[m][n] == 'K')
            {
                if (ships2_2[m][n] == 'П' || ships2_2[m][n] == 'Р' || ships2_2[m][n] == 'У')
                {
                    cout << "Повторные координаты. Попробуйте снова. " << endl;
                    continue;
                }
                around = false;
                d1++;
                ships2_2[m][n] = 'Р';
                ships2[m][n] = 'Р';
                cout << "Попадание! ";
                for (int i = 0; i < 15; i++)
                {
                    around = false;
                    if (n != 0 && n != 9 && m != 0 && m != 9 && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р') && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                    }
                    if (n == 0 && m != 0 && m != 9 && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m != 0 && m != 9 && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (m == 0 && n != 0 && n != 9 && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    if (m == 9 && n != 0 && n != 9 && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р') && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    if (n == 0 && m == 0 && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m == 0 && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m == 9 && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                    }
                    if (n == 0 && m == 9 && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    i = 15;
                } 

                for (int i = 0; i < 15; i++)
                {
                    around = false;
                    if (n != 0 && n != 9 && m != 0 && m != 9 && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р') && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    if (n == 0 && m != 0 && m != 9 && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m != 0 && m != 9 && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                    }
                    if (m == 0 && n != 0 && n != 9 && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (m == 9 && n != 0 && n != 9 && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р') && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                    }
                    if (n == 0 && m == 0 && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m == 0 && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р') && (ships2[m + 1][n] == 'M' || ships2[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m == 9 && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n - 1] == 'M' || ships2[m][n - 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                    }
                    if (n == 0 && m == 9 && (ships2[m - 1][n] == 'M' || ships2[m - 1][n] == 'Р') && (ships2[m][n + 1] == 'M' || ships2[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships2_2[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships2_2[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    i = 15;
                }
                if (around == true)                                          
                {
                    for (int i = 0; i < 15; i++)
                    {
                        if (n != 0 && n != 9 && m != 0 && m != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if(ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if(ships2[m - 1][n + 1] == 'M')
                                ships2_2[m - 1][n + 1] = 'П';
                            if(ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m + 1][n + 1] == 'M')
                                ships2_2[m + 1][n + 1] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';
                            if (ships2[m + 1][n - 1] == 'M')
                                ships2_2[m + 1][n - 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';
                            if (ships2[m - 1][n - 1] == 'M')
                                ships2_2[m - 1][n - 1] = 'П';

                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                        }
                        if (n == 0 && m != 0 && m != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n ] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m - 1][n + 1] == 'M')
                                ships2_2[m - 1][n + 1] = 'П';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m + 1][n + 1] == 'M')
                                ships2_2[m + 1][n + 1] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';

                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m != 0 && m != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';
                            if (ships2[m + 1][n - 1] == 'M')
                                ships2_2[m + 1][n - 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';
                            if (ships2[m - 1][n - 1] == 'M')
                                ships2_2[m - 1][n - 1] = 'П';

                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (m == 0 && n != 0 && n != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m + 1][n + 1] == 'M')
                                ships2_2[m + 1][n + 1] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';
                            if (ships2[m + 1][n - 1] == 'M')
                                ships2_2[m + 1][n - 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';

                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        if (m == 9 && n != 0 && n != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m - 1][n + 1] == 'M')
                                ships2_2[m - 1][n + 1] = 'П';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';
                            if (ships2[m - 1][n - 1] == 'M')
                                ships2_2[m - 1][n - 1] = 'П';

                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        if (n == 0 && m == 0)
                        {      
                            ships2_2[m][n] = 'У';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m + 1][n + 1] == 'M')
                                ships2_2[m + 1][n + 1] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';

                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m == 0)
                        {    
                            ships2_2[m][n] = 'У';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';
                            if (ships2[m + 1][n - 1] == 'M')
                                ships2_2[m + 1][n - 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';

                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m == 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';
                            if (ships2[m - 1][n - 1] == 'M')
                                ships2_2[m - 1][n - 1] = 'П';

                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                        }
                        if (n == 0 && m == 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m - 1][n + 1] == 'M')
                                ships2_2[m - 1][n + 1] = 'П';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';

                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        i = 15;
                    }



                    for (int i = 0; i < 15; i++)
                    {
                        if (n != 0 && n != 9 && m != 0 && m != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m - 1][n + 1] == 'M')
                                ships2_2[m - 1][n + 1] = 'П';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m + 1][n + 1] == 'M')
                                ships2_2[m + 1][n + 1] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';
                            if (ships2[m + 1][n - 1] == 'M')
                                ships2_2[m + 1][n - 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';
                            if (ships2[m - 1][n - 1] == 'M')
                                ships2_2[m - 1][n - 1] = 'П';

                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        if (n == 0 && m != 0 && m != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m - 1][n + 1] == 'M')
                                ships2_2[m - 1][n + 1] = 'П';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m + 1][n + 1] == 'M')
                                ships2_2[m + 1][n + 1] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';

                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m != 0 && m != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';
                            if (ships2[m + 1][n - 1] == 'M')
                                ships2_2[m + 1][n - 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';
                            if (ships2[m - 1][n - 1] == 'M')
                                ships2_2[m - 1][n - 1] = 'П';

                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                        }
                        if (m == 0 && n != 0 && n != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m + 1][n + 1] == 'M')
                                ships2_2[m + 1][n + 1] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';
                            if (ships2[m + 1][n - 1] == 'M')
                                ships2_2[m + 1][n - 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';

                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (m == 9 && n != 0 && n != 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m - 1][n + 1] == 'M')
                                ships2_2[m - 1][n + 1] = 'П';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';
                            if (ships2[m - 1][n - 1] == 'M')
                                ships2_2[m - 1][n - 1] = 'П';

                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                        }
                        if (n == 0 && m == 0)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';
                            if (ships2[m + 1][n + 1] == 'M')
                                ships2_2[m + 1][n + 1] = 'П';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';

                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m == 0 )
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m + 1][n] == 'M')
                                ships2_2[m + 1][n] = 'П';
                            if (ships2[m + 1][n - 1] == 'M')
                                ships2_2[m + 1][n - 1] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';

                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m == 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m][n - 1] == 'M')
                                ships2_2[m][n - 1] = 'П';
                            if (ships2[m - 1][n - 1] == 'M')
                                ships2_2[m - 1][n - 1] = 'П';

                            if (ships2[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                        }
                        if (n == 0 && m == 9)
                        {
                            ships2_2[m][n] = 'У';
                            if (ships2[m - 1][n] == 'M')
                                ships2_2[m - 1][n] = 'П';
                            if (ships2[m - 1][n + 1] == 'M')
                                ships2_2[m - 1][n + 1] = 'П';
                            if (ships2[m][n + 1] == 'M')
                                ships2_2[m][n + 1] = 'П';

                            if (ships2[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships2[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        i = 15;
                    }
                    cout << "   Корабль потоплен!";
                }
            }
            else
            {
                if (ships2_2[m][n] == 'П' || ships2_2[m][n] == 'Р' || ships2_2[m][n] == 'У')
                {
                    cout << "Повтороные координаты. Попробуйте снова. " << endl;
                    continue;
                }
                ships2_2[m][n] = 'П';
                b = 1;
                cout << "Мимо!" << endl<< endl;
            }

            if ( d1 == 20)     // проверка победы
            {
                cout << endl << "Игрок 1 победил!" << endl;
                a++;
                b = 2;
            }
        }

        while (b == 1)
        {
            cout << endl << endl << "Ход 2-ГО ИГРОКА: " << endl
                << endl
                << "   ";
            for (int i = 0; i < 10; i++)
                cout << bykvi[i] << " ";
            cout << endl;
            for (int i = 0; i < 10; i++)
            {
                if (i != 9)
                    cout << i + 1 << "  ";
                else
                    cout << i + 1 << " ";
                for (int j = 0; j < 10; j++)
                {
                    cout << ships1_1[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl
                << "2-Й ИГРОК ВВОДИТ КООРДИНАТЫ: ";
            cin >> cordinaty >> cordinaty1;
            cout << endl << endl;
            if (cordinaty < 'А' || cordinaty > 'К' || cordinaty1 < 1 || cordinaty1 > 10)    // проверка на правильные координаты
            {
                cout << "Некорректные координаты. Попробуйте снова." << endl;
                continue;
            }

            m = cordinaty1 - 1;
            for (int i = 0; i < 10; i++)
            {
                if (cordinaty == bykvi[i])
                    n = i;
            }

            if (ships1[m][n] == 'K')
            {
                if (ships1_1[m][n] == 'П' || ships1_1[m][n] == 'Р' || ships1_1[m][n] == 'У')
                {
                    cout << "Повторные координаты. Попробуйте снова. " << endl;
                    continue;
                }
                around = false;
                d2++;
                ships1_1[m][n] = 'Р';
                ships1[m][n] = 'Р';
                cout << "Попадание! ";
                for (int i = 0; i < 15; i++)
                {
                    around = false;
                    if (n != 0 && n != 9 && m != 0 && m != 9 && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р') && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                    }
                    if (n == 0 && m != 0 && m != 9 && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m != 0 && m != 9 && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (m == 0 && n != 0 && n != 9 && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    if (m == 9 && n != 0 && n != 9 && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р') && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    if (n == 0 && m == 0 && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m == 0 && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m == 9 && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                    }
                    if (n == 0 && m == 9 && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    i = 15;
                }

                for (int i = 0; i < 15; i++)
                {
                    around = false;
                    if (n != 0 && n != 9 && m != 0 && m != 9 && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р') && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    if (n == 0 && m != 0 && m != 9 && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m != 0 && m != 9 && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                    }
                    if (m == 0 && n != 0 && n != 9 && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (m == 9 && n != 0 && n != 9 && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р') && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                    }
                    if (n == 0 && m == 0 && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m == 0 && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р') && (ships1[m + 1][n] == 'M' || ships1[m + 1][n] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m + 1][n] == 'Р')
                        {
                            m = m + 1;
                            continue;
                        }
                    }
                    if (n == 9 && m == 9 && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n - 1] == 'M' || ships1[m][n - 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m][n - 1] == 'Р')
                        {
                            n = n - 1;
                            continue;
                        }
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                    }
                    if (n == 0 && m == 9 && (ships1[m - 1][n] == 'M' || ships1[m - 1][n] == 'Р') && (ships1[m][n + 1] == 'M' || ships1[m][n + 1] == 'Р'))
                    {
                        around = true;
                        if (ships1_1[m - 1][n] == 'Р')
                        {
                            m = m - 1;
                            continue;
                        }
                        if (ships1_1[m][n + 1] == 'Р')
                        {
                            n = n + 1;
                            continue;
                        }
                    }
                    i = 15;
                }
                if (around == true)
                {
                    for (int i = 0; i < 15; i++)
                    {
                        if (n != 0 && n != 9 && m != 0 && m != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m - 1][n + 1] == 'M')
                                ships1_1[m - 1][n + 1] = 'П';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m + 1][n + 1] == 'M')
                                ships1_1[m + 1][n + 1] = 'П';
                            if (ships1_1[m + 1][n] = 'П');
                            if (ships1[m + 1][n - 1] == 'M')
                                ships1_1[m + 1][n - 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';
                            if (ships1[m - 1][n - 1] == 'M')
                                ships1_1[m - 1][n - 1] = 'П';

                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                        }
                        if (n == 0 && m != 0 && m != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m - 1][n + 1] == 'M')
                                ships1_1[m - 1][n + 1] = 'П';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m + 1][n + 1] == 'M')
                                ships1_1[m + 1][n + 1] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';

                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m != 0 && m != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';
                            if (ships1[m + 1][n - 1] == 'M')
                                ships1_1[m + 1][n - 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';
                            if (ships1[m - 1][n - 1] == 'M')
                                ships1_1[m - 1][n - 1] = 'П';

                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (m == 0 && n != 0 && n != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m + 1][n + 1] == 'M')
                                ships1_1[m + 1][n + 1] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';
                            if (ships1[m + 1][n - 1] == 'M')
                                ships1_1[m + 1][n - 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';

                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        if (m == 9 && n != 0 && n != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m - 1][n + 1] == 'M')
                                ships1_1[m - 1][n + 1] = 'П';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';
                            if (ships1[m - 1][n - 1] == 'M')
                                ships1_1[m - 1][n - 1] = 'П';

                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        if (n == 0 && m == 0)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m + 1][n + 1] == 'M')
                                ships1_1[m + 1][n + 1] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';

                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m == 0)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';
                            if (ships1[m + 1][n - 1] == 'M')
                                ships1_1[m + 1][n - 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';

                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m == 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';
                            if (ships1[m - 1][n - 1] == 'M')
                                ships1_1[m - 1][n - 1] = 'П';

                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                        }
                        if (n == 0 && m == 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m - 1][n + 1] == 'M')
                                ships1_1[m - 1][n + 1] = 'П';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';

                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        i = 15;
                    }



                    for (int i = 0; i < 15; i++)
                    {
                        if (n != 0 && n != 9 && m != 0 && m != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m - 1][n + 1] == 'M')
                                ships1_1[m - 1][n + 1] = 'П';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m + 1][n + 1] == 'M')
                                ships1_1[m + 1][n + 1] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';
                            if (ships1[m + 1][n - 1] == 'M')
                                ships1_1[m + 1][n - 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';
                            if (ships1[m - 1][n - 1] == 'M')
                                ships1_1[m - 1][n - 1] = 'П';

                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        if (n == 0 && m != 0 && m != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m - 1][n + 1] == 'M')
                                ships1_1[m - 1][n + 1] = 'П';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m + 1][n + 1] == 'M')
                                ships1_1[m + 1][n + 1] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';

                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m != 0 && m != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';
                            if (ships1[m + 1][n - 1] == 'M')
                                ships1_1[m + 1][n - 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';
                            if (ships1[m - 1][n - 1] == 'M')
                                ships1_1[m - 1][n - 1] = 'П';

                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                        }
                        if (m == 0 && n != 0 && n != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m + 1][n + 1] == 'M')
                                ships1_1[m + 1][n + 1] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';
                            if (ships1[m + 1][n - 1] == 'M')
                                ships1_1[m + 1][n - 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';

                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (m == 9 && n != 0 && n != 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m - 1][n + 1] == 'M')
                                ships1_1[m - 1][n + 1] = 'П';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';
                            if (ships1[m - 1][n - 1] == 'M')
                                ships1_1[m - 1][n - 1] = 'П';

                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                        }
                        if (n == 0 && m == 0)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';
                            if (ships1[m + 1][n + 1] == 'M')
                                ships1_1[m + 1][n + 1] = 'П';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';

                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m == 0)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m + 1][n] == 'M')
                                ships1_1[m + 1][n] = 'П';
                            if (ships1[m + 1][n - 1] == 'M')
                                ships1_1[m + 1][n - 1] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';

                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m + 1][n] == 'Р')
                            {
                                m = m + 1;
                                continue;
                            }
                        }
                        if (n == 9 && m == 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m][n - 1] == 'M')
                                ships1_1[m][n - 1] = 'П';
                            if (ships1[m - 1][n - 1] == 'M')
                                ships1_1[m - 1][n - 1] = 'П';

                            if (ships1[m][n - 1] == 'Р')
                            {
                                n = n - 1;
                                continue;
                            }
                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                        }
                        if (n == 0 && m == 9)
                        {
                            ships1_1[m][n] = 'У';
                            if (ships1[m - 1][n] == 'M')
                                ships1_1[m - 1][n] = 'П';
                            if (ships1[m - 1][n + 1] == 'M')
                                ships1_1[m - 1][n + 1] = 'П';
                            if (ships1[m][n + 1] == 'M')
                                ships1_1[m][n + 1] = 'П';

                            if (ships1[m - 1][n] == 'Р')
                            {
                                m = m - 1;
                                continue;
                            }
                            if (ships1[m][n + 1] == 'Р')
                            {
                                n = n + 1;
                                continue;
                            }
                        }
                        i = 15;
                    }
                    cout << "   Корабль потоплен!";
                }
            }
            else
            {
                if (ships1_1[m][n] == 'П' || ships1_1[m][n] == 'Р' || ships1_1[m][n] == 'У')
                {
                    cout << "Повтороные координаты. Попробуйте снова. " << endl;
                    continue;
                }
                ships1_1[m][n] = 'П';
                b = 0;
                cout << "Мимо!" << endl << endl;
            }

            if (d2 == 20)     // проверка победы
            {
                cout<< endl << "Игрок 2 победил!" << endl;
                a++;
                b = 2;
            }
        }
    }

    system("pause>nul");
    return 0;
    
}

