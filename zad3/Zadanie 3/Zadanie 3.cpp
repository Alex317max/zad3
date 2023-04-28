#include <iostream>
#include "pch.h"
using namespace std;
struct btree { char elem; btree* left, * right; } tr;

struct btree* addnode(int x, btree* tree) {
    if (tree == NULL) { // Если дерева нет, то формируем корень
        tree = new btree; // память под узел
        tree->elem = x;   // поле данных
        tree->left = NULL;
        tree->right = NULL; // ветви инициализируем пустотой
    }
    else  if (x < tree->elem)   // условие добавление левого потомка
        tree->left = addnode(x, tree->left);
    else    // условие добавление правого потомка
        tree->right = addnode(x, tree->right);
    return(tree);
}
void treeprint(struct btree* p) {
    if (p != NULL) {
        treeprint(p->left);
        cout<<  p->elem;
        treeprint(p->right);
    }
}
void treeprint1(btree* tree) {
    if (tree != NULL) { //Пока не встретится пустой узел
        treeprint(tree->left); //Рекурсивная функция для левого поддерева
        cout << tree->elem; //Отображаем корень дерева
        treeprint(tree->right); //Рекурсивная функция для правого поддерева
    }
}
int main()
{    
    setlocale(LC_ALL, "Ru");
    char ch;
    btree* s;
    btree* d;
    s = NULL;
    
    cout << "\n Введите корень дерева: ";
    cin >> ch;
    addnode(ch, s);
    d = s;
    while (ch != '.') {
        cout << "\n Введите элемент дерева: ";
        cin >> ch;
        if(ch!='.') addnode(ch, s);
    } 
    cout << "\n Введите искомый элемент: ";
    cin >> ch;
    treeprint(d);
    treeprint1(s);
    return 0;
}

