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
		"Задание №1 Вычисление простейших арифметических выражений \n\
Задача – разработать asm-вставку для подсчета суммы, разности, \n\
произведения, целой части частного и остатка от целочисленного \n\
деления двух целочисленных значений.";

	cout << info << endl;
	cout << endl;
	cout << taskInfo << endl;
	cout << endl;

	int firstOperand = 0,
		secondOperand = 0,
		sum = 0,
		sub = 0,
		prod = 0,
		div = 0,
		remain = 0;

	firstOperand = GetInt("Введите первый операнд: ");
	secondOperand = GetInt("Введите второй операнд: ");

	// Сложение
	_asm {
		MOV EAX, firstOperand
		MOV EBX, secondOperand
		ADD EAX, EBX
		MOV sum, EAX
	}
	cout << firstOperand << " + " << secondOperand << " = " << sum << endl;

	// Вычитание
	_asm {
		MOV EAX, firstOperand
		MOV EBX, secondOperand
		SUB EAX, EBX
		MOV sub, EAX
	}
	cout << firstOperand << " - " << secondOperand << " = " << sub << endl;

	// Умножение
	_asm {
		MOV EAX, firstOperand
		MOV EBX, secondOperand
		IMUL EAX, EBX
		MOV prod, EAX
	}
	cout << firstOperand << " * " << secondOperand << " = " << prod << endl;

	// Целочисленное деление с остатком
	_asm {
		mov eax, firstOperand
		mov ebx, secondOperand
		cdq
		idiv ebx
		mov div, eax
		mov remain, edx
	}
	cout << firstOperand << " / " << secondOperand << " = " << div << endl;
	cout << "Остаток от деления: " << remain << endl;

	system("pause");
}