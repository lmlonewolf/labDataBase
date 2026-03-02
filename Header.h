#pragma once

#define ui unsigned int
#define us unsigned short


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>


struct Group {
	char name[32];
	us year;
	us number;
};

typedef struct {
	ui id;
	char name[256];
	struct Group group;
	char groupstr[64];
	us m1, m2, rate;
} Student;

typedef struct {
	Student* arr;
	ui size;
} List;


enum Menu {
	Start,
	Edit,
	Exit,
	DataOptions,
	Drop
};


void menu(int select, enum Menu page);
void edit_menu(Student* person);
void exit_menu(void);
void start_menu(void);
void data_menu(void);
void drop_menu(void);
int move(int* select);


List* new_persons(void);
void print_List(List* persons);
void print_Person(Student* persons);


// Функции именения полей
int init_person(Student* person, int num);
void edit_ID(Student* person, int flag);
void edit_Name(Student* person, int flag);
void edit_Group(Student* person, int flag);
void edit_Modul(Student* person, us num, int flag);
void edit_Rate(Student* person, int flag);
void init_group(Student* person);



extern int menu_size;
extern List Data;