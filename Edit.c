#include "Header.h"
#include <ctype.h>


void edit_ID(Student* person, int flag){
	if (flag == 1) {
		printf("Прежнее значение: %d\n", person->id);
	}

	person->id = input_id();
}


void edit_Name(Student* person, int flag) {
	if (flag == 1) {
		printf("Прежнее значение: %s\n", person->name);
	}

	char temp[256];
	input_name(temp);
	strcpy(person->name, temp);
}


void edit_Group(Student* person, int flag) {
	if (flag == 1) {
		printf("Прежнее значение: %s\n", person->groupstr);
	}

	char temp[32];
	short year, number;
	input_group(temp, &year, &number);

	strcpy(person->group.name, temp);
	person->group.year = year;
	person->group.number = number;
	init_group(person);
}


void edit_Modul(Student* person, us num, int flag) {
	if (flag == 1 && num == 1)
		printf("Прежнее значение: %d\n", person->m1);
	else if (flag == 1)
		printf("Прежнее значение: %d\n", person->m2);

	if (num == 1)
		person->m1 = input_modul(1);
	else
		person->m2 = input_modul(2);
}


void edit_Rate(Student* person, int flag) {
	if (flag == 1) {
		printf("Прежнее значение: %d\n", person->rate);
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


void init_group(Student* person) {
	snprintf(person->groupstr, sizeof(person->groupstr), "%s-%d-%s%d", person->group.name, person->group.year, (person->group.number / 10 == 0) ? "0" : "", person->group.number);
}