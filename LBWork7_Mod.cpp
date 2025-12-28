#include <iostream>
#include "LBWork7.h"
#include <fstream>
#include <vector>
#include <iomanip>

void Iteration(int Array[], int N, int Position) {
    std::ofstream f2("LBWork7Answers.txt", std::ios::app);
    for (int i = 0; i < Position; i++) {
        std::cout << Array[i] << " ";
        f2 << Array[i] << " ";
    }
    std::cout << "| ";
    f2 << " | ";
    for (int i = Position; i < N; i++) {
        std::cout << Array[i] << " ";
        f2 << Array[i] << " ";
    }
    std::cout << "\n";
    f2 << "\n"; 
    f2.close();
}
void Sort_Vybor(int *Array, int N) {
    std::ofstream ClearFile("LBWork7Answers.txt", std::ios::trunc);
    ClearFile.close();
    
    int K, M, It = 1;
    for (int i = N - 1; i > 0; i--) {
        K = i; M = Array[i];
        for (int j = 0; j < i; j++) {
            if (Array[j] > M) {
                K = j; M = Array[K];
            }
        }
        if (K != i) {
            Array[K] = Array[i];
            Array[i] = M;
        }
        std::cout << "Итерация #" << It << ": ";

        std::ofstream f2("LBWork7Answers.txt", std::ios::app);
        f2 << "Итерация #" << It << ": ";
        f2.close();

        Iteration(Array, N, i);
        It++;
    }
}
void OutputArray(int *Array, int N) {
    for (int i = 0; i < N; i++) {
        std::cout << Array[i] << " ";
    }
    std::cout << "\n";
}
void Sort6() {
    std::cout << "\n===== Задача №1 - Sort6 =====\n";
    int N;
    std::cout << "Введите размер массива: ";
    std::cin >> N;
    int Array[N];
    std::cout << "Введите " << N << " эл-в в массив: ";
    for (int i = 0; i < N; i++) {
        std::cin >> Array[i];
    }

    std::cout << "Исходный массив: ";
    OutputArray(Array, N);

    Sort_Vybor(Array, N);
    
    std::cout << "Итоговый массив: ";
    OutputArray(Array, N);
    std::cout << "======= Конец задачи =======\n\n";
    return;
}

void ExamTaskC14() {
    std::cout << "\n===== Задача №2 - ExamTaskC14 =====\n";
    int N, Code;
    std::cout << "Введите кол-во записей фитнес-центра: ";
    std::cin >> N;
    std::cout << "Введите код клиента (10-99): ";
    std::cin >> Code;
    if (Code < 10 || Code > 99) { std::cout << "Некорректно введены данные!\n"; std::cout << "========= Конец задачи =========\n\n";  return; }
    else { 
        int MaxQuantityData = 1000, CntRecord = 0;
        Clients Data[MaxQuantityData];
        std::cout << "Введите данные клиентов в формате: Год (2000-2010)/Месяц (1-12)/Код_клиента (10-99)/Продолжительность (1-30).\n";
        for (int i = 0; i < N; i++) {
            Clients FitN; 
            std::cout << "Клиент №" << i + 1 << ": ";
            std::cin >> FitN.Year >> FitN.Month >> FitN.Code >> FitN.Duration;
            if (FitN.Year < 2000 || FitN.Year > 2010 || FitN.Month < 1 || FitN.Month > 12 || FitN.Code < 10 || FitN.Code > 99 || FitN.Duration < 1 || FitN.Duration > 30) {
                std::cout << "Некорректно введены данные!\n";
                return;
            }
            if (FitN.Code == Code) {
                if (CntRecord < MaxQuantityData) {
                    Data[CntRecord] = FitN;
                    CntRecord++;
                }
            }
        }
        if (CntRecord == 0) { 
            std::cout << "Нет данных!\n"; 
            std::cout << "========= Конец задачи =========\n"; 
            return; 
        }
        for (int Year = 2000; Year <= 2010; Year++) {
            int MonthHours[12] = {0};
            bool HasData = false;
            for (int i = 0; i < CntRecord; i++) {
                if (Data[i].Year == Year) {
                    MonthHours[Data[i].Month - 1] += Data[i].Duration;
                    HasData = true;
                }
            }
            if (HasData) {
                int MinHours = 100, BestMonth = 0;
                for (int Month = 12; Month >= 1; Month--) {
                    int Hours = MonthHours[Month - 1];
                    if (Hours > 0) {
                        if (Hours < MinHours) { MinHours = Hours; BestMonth = Month; }
                    }
                }
                std::cout << "Результаты: ";
                if (BestMonth > 0) {
                    std::cout << Year << " " << BestMonth << " " << MinHours << "\n";  
                }
            }
        }
    }
    std::cout << "===== Конец задачи =====\n";
}

void QSort(std::vector<Students>& Array, int L, int R) {
    int i = L, j = R;
    Students Temp;
    std::string X = Array[(L + R)/2].SurName;
    do {
        while (Array[i].SurName < X) { i++; }
        while (Array[j].SurName > X) { j--; }
        if (i <= j) {
            Temp = Array[i];
            Array[i] = Array[j];
            Array[j] = Temp; 
            i++; j--;
        }
    } while (i < j);
    if (L < j) { QSort(Array, L, j); }
    if (R > i) { QSort(Array, i, R); }
}
void TaskFive11() {
    std::ifstream f1("LBWork7.txt", std::ios::in);
    std::ofstream f2("LBWork7Answers.txt", std::ios::out);
    if (!f1.is_open()) { std::cerr << "Error!\n"; return; }
    
    std::vector<Students> Student;
    Students TempStudent;

    while (f1 >> TempStudent.SurName >> TempStudent.Point) {
        Student.push_back(TempStudent);
    }
    f1.close();

    if (!Student.empty()) {
        QSort(Student, 0, Student.size() - 1);
    }
    for (const auto& Sstudent : Student) {
        f2 << std::left << std::setw(15) << Sstudent.SurName << std::right << std::setw(3) << Sstudent.Point << "\n";
    }
    f2.close();
    std::cout << "\n===== 3. Задача №3 - Five11 =====\nРезультаты задачи записаны в файл 'LBWork7Answers.txt'.\n========= Конец задачи =========\n\n";
}

