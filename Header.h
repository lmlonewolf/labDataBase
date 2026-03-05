#pragma once

#define ui unsigned int
#define us unsigned short


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
	Find,
	DataOptions,
	Drop
};


enum Column {
	ID,
	Name,
	Group,
	M1,
	M2,
	Rate
};


// Функции меню
void menu(int select, enum Menu page);
void edit_menu();
void exit_menu(void);
void start_menu(void);
void data_menu(void);
void drop_menu(void);
int move(int* select);
Student* find_to_edit(void);


// Функции вывода
void print_List(List* persons);
void print_Person(Student* person);


// Функции именения полей
void edit_ID(Student* person, int flag);
void edit_Name(Student* person, int flag);
void edit_Group(Student* person, int flag);
void edit_Modul(Student* person, us num, int flag);
void edit_Rate(Student* person, int flag);
void init_group(Student* person);


// Функции с данными
List* new_persons(void);
int input_id(void);
void input_name(char* temp);
void input_group(char* temp, short* year, short* number);
int input_modul(int num);
int init_person(Student* person, int num);
List* sum_lists(List* first, List* second);
void drop_data(List* data);
void find(enum Column cl);


// Функции работы с файлами
int save_data(void);
int load_data(void);



// Глобальные переменные
extern int menu_size;
extern us save_success;
extern us load_success;
extern List* Data;
extern int is_find;
extern List* fData;