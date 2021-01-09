#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Exception.h"
#include "File.h"
#include "Casino.h"

using namespace std;



int main()
{
    system("chcp 1251");
    system("CLS");
    Casino u1("777", 11111, 2000, 40), u2("MaxBet", 30000, 3000, 200),
        u3("1TBit", 22222, 1000, 150), u4("WelBik", 12000, 450, 20), u5("DoretyCosino", 20000, 300, 100);
    Casino flg[5] = { u4,u1,u3,u2, u5 };
    Casino flg2[5] = { u1, u2, u3, u4, u5 };

    cout << "Вывод текстового файла (txt):\n" << endl;
    File f1("1.txt", txt);
    f1.open("w");
    f1.set_size(5);
    f1 << u1;
    f1 << u2;
    f1 << u3;
    f1 << u4;
    f1 << u5;
    f1.close();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n";

    cout << "Вывод текстового файла (bin):\n" << endl;
    File f2("2.txt", bin);
    f2.open("w");
    f2.set_size(5);
    f2 << u1;
    f2 << u2;
    f2 << u3;
    f2 << u4;
    f2 << u5;
    f2.close();
    f2.open("r");
    cout << f2;
    f2.close();
    cout << "\n\n";

    cout << "Вывод бинарного файла (bin):\n" << endl;
    File f3("3.bin", bin);
    f3.open("w");
    f3.set_size(5);
    f3 << u1;
    f3 << u2;
    f3 << u3;
    f3 << u4;
    f3 << u5;
    f3.close();
    f3.open("r");
    cout << f3;
    f3.close();
    cout << "\n\n";

    cout << "Сортировка по имени:\n" << endl;
    f1.bubble_sort_name();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n";

    cout << "Сортировка по количеству денег:\n" << endl;
    f1.bubble_sort_money();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n";

    cout << "Сортировка по выгоде:\n" << endl;
    f1.bubble_sort_profit();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n";

    cout << "Сортировка по игрокам:\n" << endl;
    f1.bubble_sort_players();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n";
    
    int a, k=1;

    while (k!=0) {
        cout << "\n\n\nРедактирование текстового файла!\n\n\n";
        f1.open("r");
        cout << f1;
        f1.close();
        cout << "\n\nВыберите строку для изменения:\n" << endl;
        do {
            rewind(stdin);
            cin >> a;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "\n\nПовторите ввод: ";
                a = -1;
                rewind(stdin);
            }
        } while (a < 0 || a>5);
        k = f1.edit(a);
        f1.open("r");
        if(k!=0)cout << f1;
        f1.close();
        cout << "\n";
    }

    k = 1;

    while (k!=0) {
        cout << "\n\n\nРедактирование бинарного файла!\n\n\n";
        f3.open("r");
        cout << f3;
        f3.close();
        cout << "\n\nВыберите строку для изменения:\n" << endl;
        do {
            rewind(stdin);
            cin >> a;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "\n\nПовторите ввод: ";
                a = 0;
                rewind(stdin);
            }
        } while (a < 0 || a>5);
        k = f3.edit(a);
        f3.open("r");
        if(k!=0)cout << f3;
        f3.close();
        cout << "\n";
    }


    cout << "\n\n\nУдаление из текстового файла!\n\n\n";
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "Выберите строку для удаления:\n" << endl;
    do {
        rewind(stdin);
        cin >> a;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\n\nПовторите ввод: ";
            a = 0;
            rewind(stdin);
        }
    } while (a < 0 || a>5);
    f1.del(a);
    f1.open("r");
    cout << f1;
    f1.close();

    cout << "\n\n\nУдаление из бинарного файла!\n\n\n";
    f3.open("r");
    cout << "\n\nf3 в bin формате: \n" << f3<<"\n\n";
    f3.close();
    cout << "Выберите строку для удаления:\n" << endl;
    do {
        rewind(stdin);
        cin >> a;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\n\nПовторите ввод: ";
            a = 0;
            rewind(stdin);
        }
    } while (a < 0 || a>5);
    f3.del(a);
    f3.open("r");
    cout << f3;
    f3.close();


    getchar(); getchar();
    return 0;
}