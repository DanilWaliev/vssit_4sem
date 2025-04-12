#include <iostream>
#include "IOHandle.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");

	string info =
		"��������� �����������: \n\
������ �. �., �������� �. �. \n\
������ 434";
	string taskInfo = 
		"������� �1 ���������� ���������� �������������� ��������� \n\
������ � ����������� asm-������� ��� �������� �����, ��������, \n\
������������, ����� ����� �������� � ������� �� �������������� \n\
������� ���� ������������� ��������.";

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

	firstOperand = GetInt("������� ������ �������: ");
	secondOperand = GetInt("������� ������ �������: ");

	// ��������
	_asm {
		MOV EAX, firstOperand
		MOV EBX, secondOperand
		ADD EAX, EBX
		MOV sum, EAX
	}
	cout << firstOperand << " + " << secondOperand << " = " << sum << endl;

	// ���������
	_asm {
		MOV EAX, firstOperand
		MOV EBX, secondOperand
		SUB EAX, EBX
		MOV sub, EAX
	}
	cout << firstOperand << " - " << secondOperand << " = " << sub << endl;

	// ���������
	_asm {
		MOV EAX, firstOperand
		MOV EBX, secondOperand
		IMUL EAX, EBX
		MOV prod, EAX
	}
	cout << firstOperand << " * " << secondOperand << " = " << prod << endl;

	// ������������� ������� � ��������
	_asm {
		mov eax, firstOperand
		mov ebx, secondOperand
		cdq
		idiv ebx
		mov div, eax
		mov remain, edx
	}
	cout << firstOperand << " / " << secondOperand << " = " << div << endl;
	cout << "������� �� �������: " << remain << endl;

	system("pause");
}