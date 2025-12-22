#ifdef _WIN64
#include <windows.h>
#endif

#include <iostream>
#include "LBWork7.h"

int ChooseTask() {
    int Choice;
    std::cout << "Выберите задачу 1-3: \n";
    std::cout << "1. Задача №1 - Sort6;\n";
    std::cout << "2. Задача №2 - ExamTaskC14;\n";
    std::cout << "3. Задача №3 - Five11;\n";
    std::cout << "0. Выход. \n";
    std::cout << "Ваш выбор? ";   
    std::cin >> Choice;
    return Choice;
}

int main() {
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif

    int Choice1;
    do {
        Choice1 = ChooseTask();
        if (Choice1 == 0) { 
            std::cout << "Завершение работы...\n";
            std::cout << "Работа завершена.\n";
            break; 
        }
        switch (Choice1) {
            case 1: {
                Sort6();
                break;
            } case 2: {
                ExamTaskC14();
                break;
            } case 3: {
                TaskFive11();
                break;
            } default: {
                std::cout << "Неверно ввведены данные!\n";
                break;
            }
        } 
    } while (true);
    return 0;
}
