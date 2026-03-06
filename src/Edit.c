#include "Header.h"
#include <ctype.h>


Student* find_to_edit() { // поиск студента для последующего изменения
	int temp = input_id();
	ui el;
	for (int i = 0; i < mainData->size; i++) {
		el = mainData->arr[i].id;
		if (el == temp)
			return &mainData->arr[i];
	}
	return NULL;
}


void edit_ID(Student* person, int flag){ // Изменить ID
	if (flag == 1) {
		printf("\nПрежнее значение: %d\n", person->id);
	}

	person->id = input_id();
}


void edit_Name(Student* person, int flag) { // Изменить имя
	if (flag == 1) {
		printf("\nПрежнее значение: %s\n", person->name);
	}

	char temp[256];
	input_name(temp);
	strcpy(person->name, temp);
}


void edit_Group(Student* person, int flag) { // Изменить группу
	if (flag == 1) {
		printf("\nПрежнее значение: %s\n", person->groupstr);
	}

	char temp[32];
	short year, number;
	input_group(temp, &year, &number);

	strcpy(person->group.name, temp);
	person->group.year = year;
	person->group.number = number;
	init_group(person);
}


void edit_Modul(Student* person, us num, int flag) { // Изменить модуль
	if (flag == 1 && num == 1)
		printf("\nПрежнее значение: %d\n", person->m1);
	else if (flag == 1)
		printf("\nПрежнее значение: %d\n", person->m2);

	if (num == 1)
		person->m1 = input_modul(1);
	else
		person->m2 = input_modul(2);
}


void edit_Rate(Student* person, int flag) { // Изменить рейтинг
	if (flag == 1) {
		printf("\nПрежнее значение: %d\n", person->rate);
	}

	int temp;
	if ((person->m1 != NULL) && (person->m2 != NULL)) {
		person->rate = input_modul(0);
	}
	else {
		printf("\nМодули не закрыты! Поэтому итоговой оценки нет.\n");
		person->rate = NULL;
	}
}


void init_group(Student* person) { // Инициализация строки с названием группы и структуры группы
	snprintf(person->groupstr, sizeof(person->groupstr), "%s-%d-%s%d", person->group.name, person->group.year, (person->group.number / 10 == 0) ? "0" : "", person->group.number);
}