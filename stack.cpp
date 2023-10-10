#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>
struct node
{
	char inf[256]; // полезная информация
	struct node* next; // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;
void spstore(void), review(void), del(char* name);
char find_el[256];

struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(void); // функция создания элемента
void main() {

	setlocale(LC_ALL, "Russian");
	printf("Введите данные\n");
	head = get_struct();
	last = head;
	while (true) {
		printf("Введите данные, если хотите окончить ввод введите *\n");
		spstore();
		if (f == NULL) {
			break;
		}

	}

	review();
	printf("Введите данные, которые хотите удалить\n");
	scanf("%s", find_el);
	del(find_el);
	review();
}
void spstore(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (p == NULL) {
		f = NULL;
	}
	else {
		p->next = last;
		last = p;
		head = last;
	}
	f = p;
	return;
}
struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}


	scanf("%s", s);

	if (strcmp(s, "*") == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s,\n", struc->inf);
		struc = struc->next;
	}
	return;
}
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}
void del(char* name)
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало
	struct node* prev=NULL;
	int flag = 0; // индикатор отсутствия удаляемого элемента в списке
	if (strcmp(name, struc->inf) == 0) // если удаляемый элемент - первый
		{
			flag = 1;
			head = struc->next; // установливаем голову на следующий элемент
			free(struc); // удаляем первый элемент
			struc = head; // устанавливаем указатель для продолжения поиска
			return;
		}
	prev=struc;
	struc=struc->next;

	while (struc) {
		if (strcmp(name, struc->inf) == 0){
			flag=1;
			prev->next=struc->next;
			free(struc);
			return;
		}

	}
	if (flag == 0) // если флаг = 0, значит нужный элемент не

	{
		printf("Элемент не найден\n");
		return;
	}
}