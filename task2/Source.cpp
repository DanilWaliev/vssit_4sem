#include <iostream>
#include "IOHandle.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");

	string info =
		"Программу разработали: \n\
Валиев Д. Л., Максимов Д. М. \n\
группа 434";
	string taskInfo =
		"Задание №2 Использование команд сравнения и условного перехода \n\
Задача – разработать asm-вставку для проверки простоты числа.";

	cout << info << endl;
	cout << endl;
	cout << taskInfo << endl;
	cout << endl;

	unsigned int number;
	int isPrime = 1;

	number = GetInt("Введите число не меньшее 2: ");

	// Проверка числа на простоту
	_asm {
		MOV EBX, 1					// В EBX храним делитель
		JMP prenext

		// Очередная итерация
		nextIteration:
			XOR EDX, EDX			// Обнуление EDX
			MOV EAX, number			// Кладем число, которое проверяем на простоту в EAX
			DIV EBX					// Делим EAX на EBX
			CMP EDX, 0				// Сравниваем остаток от деления с 0
			JNZ prenext				// Если флаг нуля не равен нулю (остаток не равен нулю), переходим к prenext
			MOV isPrime, 0			// Если флаг нуля равен нулю

		// Подготовка к очередной итерации
		prenext:
			INC EBX					// Инкремент EBX
			CMP EBX, number			// Сравниваем EBX с числом, которое проверяем на простоту
			JNZ nextIteration		// Если флаг нуля не равен нулю переход к nextIteration
	}

	if (isPrime)
	{
		cout << "Число " << number << " является простым." << endl;
	}
	else
	{
		cout << "Число " << number << " не является простым." << endl;
	}

	system("pause");
}