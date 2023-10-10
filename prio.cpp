#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>
struct node
{
	char inf[256]; // �������� ����������
	int prio;
	struct node *next; // ������ �� ��������� ������� 
};
int prior;
struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
int dlinna = 0;
void spstore(void), review(void),del(char* name);
char find_el[256];
struct node* findprio(int prio);
struct node* find(char* name); // ������� ���������� ��������
struct node* get_struct(void); // ������� �������� ��������
int main() {

	setlocale(LC_ALL, "Russian");
	printf("������� ��������� � ������\n");
	scanf("%d", &prior);
	head = get_struct();
	last = head;
	while (true) {
		printf("������� ��������� � ������, ���� ������ �������� ���� ������� -1,���� ������ ������� ������� 0\n");
		scanf("%d", &prior);
		if(prior == 0){
			printf("������� ��������� �������\n");
			scanf("%s", find_el);
			del(find_el);
			review();

		} else	if (prior == -1) {
			printf("���� �������\n");
			break;
		} else	if(prior<0){
			printf("����� ������ ���\n");
			return 0;
		} else {

		spstore();
		review();
		}
	}
	review();
	
	return 0;
}
// ������� ���������� ��������, ��������� ������




struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	
	scanf("%s", s);
	p->prio=prior ;
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}


void spstore(void)
{
	struct node* ideal = NULL;
	
	struct node* p = NULL;
	p = get_struct();
	if (head->prio <= p->prio)	
	{
		p->next = head;
		head = p;
	}
	else if (head->prio > p->prio) 
	{
		ideal =findprio(p->prio);
		if (ideal == NULL) {
			last->next = p;
			last = p;
		}
		else {
			printf("%s\n",ideal->inf);
			p->next = ideal->next;
			ideal->next = p;
		}
	}
	
	return;
}


/* �������� ����������� ������. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("��� - %s,��������� - %d \n", struc->inf,struc->prio);
		struc = struc->next;
	}
	return;
}
struct node* findprio(int prio)
{
	struct node* struc = head;
	struct node* temp =NULL;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{

		if (prio >= struc->prio)
		{
			return temp;
		}
		temp = struc;
		struc = struc->next;
	}
	
	return NULL;
}
void del(char *name)
{
struct node *struc = head; // ���������, ���������� �� ������ ���������� �� ������
struct node *prev;// ��������� �� �������������� ���������� �������
int flag = 0; // ��������� ���������� ���������� �������� � ������
if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
{
printf("������ ����\n");
return;
}
if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
{
flag = 1;
head = struc->next; // ������������� ������ �� ��������� �������
free(struc); // ������� ������ �������
struc = head; // ������������� ��������� ��� ����������� ������
}
else
{
prev = struc;
struc = struc->next;
}
while (struc) // ������ �� ������ � ����� ���������� ��������
{
if (strcmp(name, struc->inf) == 0) // ���� �����, ��
{
flag = 1; // ���������� ���������
if (struc->next) // ���� ��������� ������� �� ��������� � ������
{
prev->next = struc->next; // ������ ���������
free(struc); // ������� �������
struc = prev->next; // ������������� ��������� ��� �����������



}
else // ���� ��������� ������� ��������� � ������
{
prev->next = NULL; // �������� ��������� ���������������


free(struc); // ������� �������
return;

}
}
else 
{
prev = struc; // ������������� ��������� ��� ����������� ������
struc = struc->next;
}
}
if (flag == 0) // ���� ���� = 0, ������ ������ ������� ��

{
printf("������� �� ������\n");
return;
}
}
struct node *find(char *name)
{
struct node *struc = head;
if (head == NULL)
{
printf("������ ����\n");
}
while (struc)
{
if (strcmp(name, struc->inf) == 0)
{
return struc;
}
struc = struc->next;
}
printf("������� �� ������\n");
return NULL;
}