#include <string>
#include <iostream>
#include "../List_lib/List.h"	
#include "../Polynom_lib/Polynom.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	//исходные строки
 	string str = "6x5y2z5-5x4y3z3+7x7y5z";
	string str1 = "3x5y2z5-5x4y3z3+7x7y5z";

	//полиномы
	Polynom p1(str);
	cout << "Полином 1:" << endl << p1 << endl;

	Polynom p2(str1);
	cout << "Полином 2:" << endl << p2 << endl;
	
	//cложение полиномов
	Polynom p3 = p1 + p2;
	cout << "Полином 1 + Полином 2:" << endl << p3 << endl;

	//вычитание полиномов
	Polynom p4 = p1 - p2;
	cout << "Полином 1 - Полином 2:" << endl << p4 << endl;

	//умножение полиномов
	Polynom p5 = p1 * p2;
	cout << "Полином 1 * Полином 2:" << endl << p5 << endl;

	//вычисление результата полинома
	cout << "Результат умножения полинома при х=1, y=1, z=1:" << endl<< p5.result(1, 1, 1)<<endl;
}