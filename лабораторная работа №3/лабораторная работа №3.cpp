#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;
int const n = 6;

void spiralOutput(int* arr, const int n) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int c = 0; c < n / 2; c++) {

        for (int i = 0; i < n - 2 * c; i++) {
            destCoord.Y = c + 3;
            destCoord.X = (c + i) * 4 + 60;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(arr + c * n + c + i) << '\r';
            cout.flush();
            Sleep(100);
        }

        for (int i = 0; i < n - 2 * c - 1; i++) {
            destCoord.Y = c + 1 + i + 3;
            destCoord.X = (n - 1 - c) * 4 + 60;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(arr + (c + 2 + i) * n - 1 - c) << '\r';
            cout.flush();
            Sleep(100);
        }

        for (int i = 0; i < n - 2 * c - 1; i++) {
            destCoord.Y = n - 1 - c + 3;
            destCoord.X = (n - 2 - c - i) * 4 + 60;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(arr + n * (n - c) - 2 - c - i) << '\r';
            cout.flush();
            Sleep(100);
        }

        for (int i = 0; i < n - 2 * c - 2; i++) {
            destCoord.Y = n - 2 - i - c + 3;
            destCoord.X = c * 4 + 60;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(arr + n * (n - 2 - i - c) + c) << '\r';
            cout.flush();
            Sleep(100);
        }
    }
    destCoord.Y = n + 1;
    destCoord.X = 0;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void bentLineOutput(int* arr, const int n) {
    int c = 0;
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int j = 0; j < n / 2; j++) {
        for (int i = 0; i < n; i++) {
            destCoord.Y = i + n + 5;
            destCoord.X = c * 4 + 60;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(arr + n * i + c) << '\r';
            cout.flush();
            Sleep(100);
        }
        c++;
        for (int i = n - 1; i >= 0; i--) {
            destCoord.Y = i + n + 5;
            destCoord.X = c * 4 + 60;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(arr + n * i + c) << '\r';
            cout.flush();
            Sleep(100);
        }
        c++;
    }
}

void swapA(int* arr, const int n) {
    int countNewLine = 0;
    for (int i = 0; i < (n / 2) * (n / 2); i++) {
        if (i % (n / 2) == 0 && i != 0) {
            countNewLine++;
        }
        int iForFirstPart = i + (n / 2) * countNewLine;
        int firstPartNumber = *(arr + iForFirstPart);

        int iForSecondPart = i + (n / 2) * countNewLine;
        int secondPartNumber = *(arr + iForSecondPart + (n / 2));
        *(arr + iForSecondPart + (n / 2)) = firstPartNumber;

        int iForThirdPart = i + (n / 2) + (n / 2) * n + (n / 2) * countNewLine;
        int thirdPartNumber = *(arr + iForThirdPart);
        *(arr + iForThirdPart) = secondPartNumber;

        int iForFourthPart = i + (n / 2) * n + (n / 2) * countNewLine;
        int fourthPartNumber = *(arr + iForFourthPart);
        *(arr + iForFourthPart) = thirdPartNumber;

        *(arr + iForFirstPart) = fourthPartNumber;

    }
    for (int i = 1; i <= n * n; i++)
    {
        cout << *(arr + i - 1) << '\t';
        if (i % n == 0)
        {
            cout << '\n';
        }
        if (i % (n / 2) == 0 && i % n != 0) {
            cout << '\t';
        }
        if (i == n * (n / 2)) {
            cout << '\n';
        }
    }

}

void swapB(int* arr, const int n) {
    int countNewLine = 0;
    for (int i = 0; i < (n / 2) * (n / 2); i++) {
        if (i % (n / 2) == 0 && i != 0) {
            countNewLine++;
        }
        int iForFirstPart = i + (n / 2) * countNewLine;
        int firstPartNumber = *(arr + iForFirstPart);

        int iForFourthPart = i + (n / 2) * n + (n / 2) * countNewLine;
        int fourthPartNumber = *(arr + iForFourthPart);

        int iForSecondPart = i + (n / 2) * countNewLine;
        int secondPartNumber = *(arr + iForSecondPart + (n / 2));
        *(arr + iForSecondPart + (n / 2)) = fourthPartNumber;

        int iForThirdPart = i + (n / 2) + (n / 2) * n + (n / 2) * countNewLine;
        int thirdPartNumber = *(arr + iForThirdPart);
        *(arr + iForThirdPart) = firstPartNumber;

        *(arr + iForFourthPart) = secondPartNumber;

        *(arr + iForFirstPart) = thirdPartNumber;

    }
    for (int i = 1; i <= n * n; i++)
    {
        cout << *(arr + i - 1) << '\t';
        if (i % n == 0)
        {
            cout << '\n';
        }
        if (i % (n / 2) == 0 && i % n != 0) {
            cout << '\t';
        }
        if (i == n * (n / 2)) {
            cout << '\n';
        }
    }

}

void swapC(int* arr, const int n) {
    int countNewLine = 0;
    for (int i = 0; i < (n / 2) * (n / 2); i++) {
        if (i % (n / 2) == 0 && i != 0) {
            countNewLine++;
        }
        int iForFirstPart = i + (n / 2) * countNewLine;
        int firstPartNumber = *(arr + iForFirstPart);

        int iForThirdPart = i + (n / 2) + (n / 2) * n + (n / 2) * countNewLine;
        int thirdPartNumber = *(arr + iForThirdPart);

        int iForFourthPart = i + (n / 2) * n + (n / 2) * countNewLine;
        int fourthPartNumber = *(arr + iForFourthPart);

        int iForSecondPart = i + (n / 2) * countNewLine;
        int secondPartNumber = *(arr + iForSecondPart + (n / 2));
        *(arr + iForSecondPart + (n / 2)) = thirdPartNumber;

        *(arr + iForThirdPart) = secondPartNumber;

        *(arr + iForFourthPart) = firstPartNumber;

        *(arr + iForFirstPart) = fourthPartNumber;

    }
    for (int i = 1; i <= n * n; i++)
    {
        cout << *(arr + i - 1) << '\t';
        if (i % n == 0)
        {
            cout << '\n';
        }
        if (i % (n / 2) == 0 && i % n != 0) {
            cout << '\t';
        }
        if (i == n * (n / 2)) {
            cout << '\n';
        }
    }

}

void swapD(int* arr, const int n) {
    int countNewLine = 0;
    for (int i = 0; i < (n / 2) * (n / 2); i++) {
        if (i % (n / 2) == 0 && i != 0) {
            countNewLine++;
        }
        int iForFirstPart = i + (n / 2) * countNewLine;
        int firstPartNumber = *(arr + iForFirstPart);

        int iForThirdPart = i + (n / 2) + (n / 2) * n + (n / 2) * countNewLine;
        int thirdPartNumber = *(arr + iForThirdPart);

        int iForFourthPart = i + (n / 2) * n + (n / 2) * countNewLine;
        int fourthPartNumber = *(arr + iForFourthPart);

        int iForSecondPart = i + (n / 2) * countNewLine;
        int secondPartNumber = *(arr + iForSecondPart + (n / 2));
        *(arr + iForSecondPart + (n / 2)) = firstPartNumber;

        *(arr + iForThirdPart) = fourthPartNumber;

        *(arr + iForFourthPart) = thirdPartNumber;

        *(arr + iForFirstPart) = secondPartNumber;

    }
    for (int i = 1; i <= n * n; i++)
    {
        cout << *(arr + i - 1) << '\t';
        if (i % n == 0)
        {
            cout << '\n';
        }
        if (i % (n / 2) == 0 && i % n != 0) {
            cout << '\t';
        }
        if (i == n * (n / 2)) {
            cout << '\n';
        }
    }
}


void changeNumbers(int* arr, const int n, int operationValue, int value) {
    if (operationValue == 1) {
        for (int i = 1; i <= n * n; i++) {
            cout << *(arr + i - 1) - value << '\t';
            if (i % n == 0)
            {
                cout << '\n';
            }
        }
    }
    if (operationValue == 2) {
        for (int i = 1; i <= n * n; i++) {
            cout << *(arr + i - 1) + value << '\t';
            if (i % n == 0)
            {
                cout << '\n';
            }
        }
    }
    if (operationValue == 3) {
        for (int i = 1; i <= n * n; i++) {
            cout << *(arr + i - 1) * value << '\t';
            if (i % n == 0)
            {
                cout << '\n';
            }
        }
    }
    if (operationValue == 4) {
        for (int i = 1; i <= n * n; i++) {
            if (*(arr + i - 1) != 0) {
                cout << float(*(arr + i - 1)) / value << '\t';
            }
            if (*(arr + i - 1) == 0) {
                cout << "[0/0]" << '\t';
            }
            if (i % n == 0)
            {
                cout << '\n';
            }
        }
    }
}
void sedlPoints(int const = n) {
    int k;
    int p;
    int arr[n][n];
    int n = sizeof(arr) / sizeof(*arr);
    int m = sizeof(*arr) / sizeof(**arr);
    int* end = *arr + n * m - 1;
    for (int* ptr = *arr; ptr <= end; ptr++)
    {
        *ptr = rand() % (n * n);
    }
    cout << "Полученный массив:" << '\n';
    for (int* ptr = *arr; ptr <= end; ptr++)
    {
        cout << setw(3) << *ptr << " ";
        if ((ptr - *arr + 1) % m == 0)
            cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        int mn = 1000;
        int mx = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < mn) {
                mn = arr[i][j];
                k = j;
            }
        }
        for (int w = 0; w < n; w++) {
            if (arr[w][k] > mx) {
                mx = arr[w][k];
                p = w;

            }
        }
        if (mn != mx) {
            cout << "Точка " << mn << " с координатами (" << p << "," << k << ") является минимальной в своей строчке, но не является максимальной в своём столбце" << endl;
        }
        if (mn == mx) {
            cout << "Точка " << mn << " с координатами (" << p << "," << k << ") является седловой" << endl;
        }
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        int mn = 1000;
        int mx = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > mx) {
                mx = arr[i][j];
                k = j;
            }
        }
        for (int w = 0; w < n; w++) {
            if (arr[w][k] < mn) {
                mn = arr[w][k];
                p = w;

            }
        }
        if (mn != mx) {
            cout << "Точка " << mx << " с координатами (" << p << "," << k << ") является максимальной в своей строчке, но не является минимальной в своём столбце" << endl;
        }
        if (mn == mx) {
            cout << "Точка " << mn << " с координатами (" << p << "," << k << ") является седловой" << endl;
        }
    }
}

int main() {
    int w;
    int arr[n][n];
    int n = sizeof(arr) / sizeof(*arr);
    int m = sizeof(*arr) / sizeof(**arr);
    int* end = *arr + n * m - 1;
    while (true) {
        setlocale(LC_ALL, "");
        srand(time(NULL));
        for (int* ptr = *arr; ptr <= end; ptr++)
        {
            *ptr = rand() % (n * n);
        }
        break;
    }
    do
    {
        cout << "Введите номер задания 1-4, 5 - ИДЗ, 0 для выхода \n";
        cin >> w;
        if (w == 1) {
            HANDLE hStdout;
            COORD destCoord;
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            cout << "Выводимый массив:" << '\n';
            for (int* ptr = *arr; ptr <= end; ptr++)
            {
                cout << setw(3) << *ptr << " ";
                if ((ptr - *arr + 1) % m == 0)
                    cout << '\n';
            }
            spiralOutput(*arr, n);
            bentLineOutput(*arr, n);
            destCoord.Y = 30;
            destCoord.X = 0;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "Нажмите любую клавишу для продолжения:" << '\n';
            int k;
            cout << "Введите любую цифре для продолжения:" << endl;
            cin >> k;
            if (k >= 0 && k < 10) {
                system("cls");
            }
        }

        if (w == 2) {
            cout << "Массив до изменений:" << '\n';
            for (int* ptr = *arr; ptr <= end; ptr++)
            {
                cout << *ptr << '\t';
                if ((ptr - *arr + 1) % m == 0)
                    cout << '\n';
                if ((ptr - *arr + 1) % (m / 2) == 0 && (ptr - *arr + 1) % m != 0 && (ptr - *arr + 1) != 0)
                    cout << '\t';
                if ((ptr - *arr + 1) % (m * (m / 2)) == 0)
                    cout << '\n';
            }
            cout << '\n';
            cout << "Перестановка по схеме A:" << endl;
            swapA(*arr, n);
            cout << '\n';
            cout << "Перестановка по схеме B:" << endl;
            swapB(*arr, n);
            cout << '\n';
            cout << "Перестановка по схеме C:" << endl;
            swapC(*arr, n);
            cout << '\n';
            cout << "Перестановка по схеме D:" << endl;
            swapD(*arr, n);
            cout << '\n';
            cout << "Нажмите любую клавишу для продолжения:" << '\n';
            int k;
            cout << "Введите любую цифре для продолжения:" << endl;
            cin >> k;
            if (k >= 0 && k <= 10) {
                system("cls");
            }
        }
        if (w == 3) {
            cout << "Массив до сортировки:" << '\n';
            for (int* ptr = *arr; ptr <= end; ptr++)
            {
                cout << *ptr << '\t';
                if ((ptr - *arr + 1) % m == 0)
                    cout << '\n';
            }
            cout << '\n';

            int* left = *arr;
            int* right = *arr + n * n - 1;
            while (left <= right) {
                for (int* i = left; i < right; i++) {
                    if (*i > *(i + 1)) swap(*i, *(i + 1));
                }
                --right;
                for (int* i = right; i > left; i--) {
                    if (*i < *(i - 1)) swap(*i, *(i - 1));
                }
                ++left;
            }
            cout << "Массив после сортировки:" << '\n';
            for (int* ptr = *arr; ptr <= end; ptr++)
            {
                cout << *ptr << '\t';
                if ((ptr - *arr + 1) % m == 0)
                    cout << '\n';
            }
            cout << "Нажмите любую клавишу для продолжения:" << '\n';
            int k;
            cout << "Введите любую цифре для продолжения:" << endl;
            cin >> k;
            if (k >= 0 && k <= 10) {
                system("cls");
            }
        }
        if (w == 4) {
            cout << "Массив до изменений:" << '\n';
            for (int* ptr = *arr; ptr <= end; ptr++)
            {
                cout << *ptr << '\t';
                if ((ptr - *arr + 1) % m == 0)
                    cout << '\n';
            }
            cout << '\n';
            int y;
            int s;
            while (true) {
                cout << "Введите номер действия:" << '\n';
                cout << "1 - вычитание" << '\n';
                cout << "2 - сложение" << '\n';
                cout << "3 - умножение" << '\n';
                cout << "4 - деление" << '\n';
                cin >> y;
                if (y > 4 || y < 1) {
                    cout << "Введено неверное значение" << '\n';
                }
                if (y == 1 || y == 2 || y == 3 || y == 4) {
                    break;
                }
            }
            cout << "Введите число:" << '\n';
            cin >> s;
            changeNumbers(*arr, n, y, s);
            int k;
            cout << "Введите любую цифре для продолжения:" << endl;
            cin >> k;
            if (k >= 0 && k <= 10) {
                system("cls");
            }
        }
        if (w == 5) {
            sedlPoints(n);
            cout << "Нажмите любую клавишу для продолжения:" << '\n';
            int k;
            cout << "Введите любую цифре для продолжения:" << endl;
            cin >> k;
            if (k >= 0 && k <= 10) {
                system("cls");
            }
        }
        
    } while (w != 0);
}