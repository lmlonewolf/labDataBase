#include "Header.h"

void edit_ID(Student* person, int flag){
	if (flag == 1) {
		printf("Прежнее значение: %d\n", person->id);
	}

	int temp;
	while (1) {
		printf("\nВведите номер студенческого билета: ");
		scanf_s("%d", &temp);
		if ((temp < 100'000) || (temp >= 1'000'000))
			printf("Ошибка ввода! Попробуйте ещё раз.\n\n");
		else
			break;
	}
	person->id = temp;
}


void edit_Name(Student* person, int flag) {
	if (flag == 1) {
		printf("Прежнее значение: %s\n", person->name);
	}

	char temp[256];
	while (1) {
		printf("\nВведите имя студента: ");
		scanf_s("\n%64[^\n]", temp, (unsigned int)sizeof(temp));
		if (strlen(temp) > 32)
			printf("Слишком длинное имя. Попробуйте ещё раз.\n\n");
		else
			break;
	}
	strcpy(person->name, temp);
}


void edit_Group(Student* person, int flag) {
	if (flag == 1) {
		printf("Прежнее значение: %s\n", person->groupstr);
	}

	time_t mytime = time(NULL);
	struct tm* now = localtime(&mytime);
	char temp[32];
	short year, number;
	while (1) {
		printf("\nВведите группу студента по образцу ИДБ-25-00: ");
		scanf_s(" %[^-]-%hd-%hd", temp, (unsigned int)sizeof(temp), &year, &number);
		if (strlen(temp) != 3) {
			printf("Ошибка в буквеной части. Попробуйте ещё раз.\n\n");
			continue;
		}
		else if ((year < 1) || (year > now->tm_year)) {
			printf("Ошибка в годе группы. Попробуйте ещё раз.\n\n");
			continue;
		}
		else if ((number < 1) || (number >= 100)) {
			printf("Ошибка в номере группы. Попробуйте ещё раз.\n\n");
			continue;
		}
		else
			break;
	}
	strcpy(person->group.name, temp);
	person->group.year = year;
	person->group.number = number;
}


void edit_Modul(Student* person, us num, int flag) {
	if (flag == 1) {
		printf("Прежнее значение: %d\n", person->id);
	}

	int temp;
	while (1) {
		printf("\nВведите результат Модуля %d (если модуль не закрыт введите 0): ", num);
		scanf_s("%d", &temp);
		if (temp == 0) {
			temp = NULL;
			break;
		}
		if ((temp > 100) || (temp < 25))
			printf("Ошибка ввода! Попробуйте ещё раз.\n\n");
		else
			break;
	}
	if (num == 1)
		person->m1 = temp;
	else
		person->m2 = temp;
}


void edit_Rate(Student* person, int flag) {
	if (flag == 1) {
		printf("Прежнее значение: %s\n", person->groupstr);
	}

	int temp;
	if ((person->m1 != NULL) && (person->m2 != NULL)) {
		while (1) {
			printf("\nВведите итоговую оценку (если оценки нет введите \"0\"): ");
			scanf_s("%d", &temp);
			if (temp == 0) {
				temp = NULL;
				break;
			}
			if ((temp > 100) || (temp < 25))
				printf("Ошибка ввода! Попробуйте ещё раз.\n\n");
			else
				break;
		}
		person->rate = temp;
	}
	else {
		printf("\nМодули не закрыты! Поэтому итоговой оценки нет.\n");
		person->rate = NULL;
	}
}


void init_group(Student* person) {
	snprintf(person->groupstr, sizeof(person->groupstr), "%s-%d-%s%d", person->group.name, person->group.year, (person->group.number / 10 == 0) ? "0" : "", person->group.number);
}