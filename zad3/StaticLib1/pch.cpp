#include "pch.h"
#include<iostream>  //Подключение библиотеки потокового ввода-вывода
using namespace std; //Подключение пространства имён
struct stack { int top; int el[15]; } s; //Создание структуры Stack

void Sozd() {		//Процедура Sozd, создающая пустой стек
	s.top = 0;
	cout << "\n Пустой стек успешно создан. \n";
};
int Prover() {		//Функция Prover, проверяющая стек на пустоту
	return (s.top == 0);
};
int Dobav(int l) {  //Функция Dobav, добавляющая элемент в стек

	if (s.top < 9) { s.top++; s.el[s.top] = l; return 1; }
	else return 0;

};
int Vzyatie() {    //Функция Vzyatie, берущая элемент из стека
	int t;
	if (s.top > 0) {
		t = s.el[s.top]; s.top -= 1; return t;
	}
	else  cout << "\n Нечего взять.";

};
void Vivod() {	//Процедура Vivod, распечатывающая содержимое стека
	while (s.top > 0) {
		cout << s.el[s.top]; s.top -= 1;
	}

};

