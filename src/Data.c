#include "Header.h"
#include <ctype.h>


List* new_persons() { // Создания списка студентов
	system("cls");
	printf("Введите необходимое число строк для добавления: ");
	ui size;
	if (scanf_s("%d", &size) == 0) {
		printf("\nПроизошла ошибка(\nПопробуйте ещё раз\n");
		return NULL;
	}
	Student* temp = calloc(size, sizeof(Student)); // Создать массив студентов нужного размера
	if (temp == NULL) {
		printf("\nНе удалось выделить память");
		return NULL;
	}
	for (int i = 0; i < size; i++) {
		init_person(&temp[i], i + 1);
		putchar('\n');
		system("pause");
	}
	system("cls");
	List* ptr = calloc(1, sizeof(List)); // Преобразуем массив студентов в список
	*ptr = (List) { temp, size };
	print_List(ptr);
	return ptr;
}


int init_person(Student* person, int num) { // Инициализация студентов
	system("cls");
	if (num != 1) // Для инициализации в списке
		printf("Инициализация студента %d\n", num);
	edit_ID(person, 0);
	edit_Name(person, 0);
	edit_Group(person, 0);
	edit_Modul(person, 1, 0);
	edit_Modul(person, 2, 0);
	edit_Rate(person, 0); 
	print_Person(person);
}


List* sum_lists(List* first, List* second) { // Суммируем списки
	if (second == NULL) // Проверка корректности новых данных
		return first;
	ui size = first->size + second->size;
	List* ptr = calloc(1, sizeof(List));
	ptr->size = size;
	ptr->arr = calloc(size, sizeof(Student)); 
	for (int i = 0; i < first->size; i++)
		ptr->arr[i] = first->arr[i];
	for (int i = 0; i < second->size; i++)
		ptr->arr[first->size + i] = second->arr[i];
	free(first->arr);
	free(first);
	free(second->arr);
	free(second);
	return ptr;
}


void drop_data(List* data) { // Сьрасываем данные по указателю, попутно очищая Кучу
	if (data)
		free(data->arr);
	else
		data = calloc(1, sizeof(List));
	data->arr = NULL;
	data->size = NULL;
}


int str_is_alpha(char* str, int space) { // Проверки корректности строки
	int i = 0;
	while ((str[i] != '\n') && (str[i] != '\0')) {
		if (ispunct(str[i]) || isdigit(str[i]) || iscntrl(str[i]) || (space ? 0: isspace(str[i])))
			return 1;
		i++;
	}
	return 0;
}


int input_id() { // Введение ID
	int temp;
	while (1) {
		printf("\nВведите номер студенческого билета: ");
		if (scanf_s("%d", &temp) == 0) {
			printf("Ошибка ввода! Попробуйте ещё раз.\n\n");
			continue;
		}
		if ((temp < 100'000) || (temp >= 1'000'000))
			printf("Ошибка ввода! Попробуйте ещё раз.\n\n");
		else
			break;
	}
	return temp;
}


void input_name(char* temp) { // Введение имени
	getchar();
	while (1) {
		printf("\nВведите имя студента: ");
		if ((fgets(temp, 256, stdin) == NULL) || (str_is_alpha(temp, 1))) {
			printf("Ошибка ввода! Попробуйте ещё раз.\n\n");
			continue;
		}
		int l = strlen(temp);
		if (strlen(temp) > 32 || strlen(temp) < 2)
			printf("\nНедопустимая длина. Попробуйте ещё раз.\n\n");
		else
			break;
	}
	temp[strlen(temp) - 1] = '\0';
}


void input_group(char* temp, short* year, short* number) { // Введение группы
	while (1) {
		printf("\nВведите группу студента по образцу ИДБ-25-00: ");
		if ((scanf_s(" %[^-]-%hd-%hd", temp, (unsigned int)sizeof(temp), year, number) != 3) || (str_is_alpha(temp, 0))) {
			printf("\nОшибка формата ввода! Попробуйте ещё раз.\n");
			continue;
		}
		if (strlen(temp) != 3) {
			printf("Ошибка в буквеной части. Попробуйте ещё раз.\n\n");
			continue;
		}
		else if (*year < 0) {
			printf("Ошибка в годе группы. Попробуйте ещё раз.\n\n");
			continue;
		}
		else if ((*number < 1) || (*number >= 100)) {
			printf("Ошибка в номере группы. Попробуйте ещё раз.\n\n");
			continue;
		}
		else
			break;
	}
	for (int i = 0; i < 3; i++)
		temp[i] = toupper(temp[i]);
}


int input_modul(int num) { // Введение модуля
	int temp;
	while (1) {
		if (num == 0)
			printf("\nВведите итоговую оценку: ");
		else
			printf("\nВведите результат Модуля %d: ", num);
		if (scanf_s("%d", &temp) == 0) {
			printf("Ошибка ввода! Попробуйте ещё раз.\n\n");
			continue;
		}
		if (temp == 0) {
			temp = NULL;
			break;
		}
		if ((temp > 100) || (temp < 25))
			printf("Ошибка ввода! Попробуйте ещё раз.\n\n");
		else
			break;
	}
	return temp;
}


void find_persons(enum Column cl) {  // Поиск студентов в списке по условию
	system("cls");
	drop_data(findData);
	findData->size = 0;
	findData->arr = calloc(mainData->size, sizeof(Student));
	int tempi;
	char tempc[256];
	is_find = 0;
	switch (cl) { // Раздел поиска
		case ID:
			tempi = input_id();
			ui el;
			for (int i = 0; i < mainData->size; i++) {
				el = mainData->arr[i].id;
				if (el == tempi) {
					findData->arr[findData->size] = mainData->arr[i];
					findData->size++;
				}
			}
			break;

		case Name:
			input_name(tempc);
			for (int i = 0; i < mainData->size; i++) {
				if (strcmp(mainData->arr[i].name, tempc) == 0) {
					findData->arr[findData->size] = mainData->arr[i];
					findData->size++;
				}
			}
			break;

		case Group:
			short year, number;
			input_group(tempc, &year, &number);
			for (int i = 0; i < mainData->size; i++) {
				if ((strcmp(mainData->arr[i].group.name, tempc) == 0) && (mainData->arr[i].group.number == number) && (mainData->arr[i].group.year == year)) {
					findData->arr[findData->size] = mainData->arr[i];
					findData->size++;
				}
			}
			break;

		case M1:
			tempi = input_modul(1);
			for (int i = 0; i < mainData->size; i++) {
				el = mainData->arr[i].m1;
				if (el == tempi) {
					findData->arr[findData->size] = mainData->arr[i];
					findData->size++;
				}
			}
			break;

		case M2:
			tempi = input_modul(2);
			for (int i = 0; i < mainData->size; i++) {
				el = mainData->arr[i].m2;
				if (el == tempi) {
					findData->arr[findData->size] = mainData->arr[i];
					findData->size++;
				}
			}
			break;

		case Rate:
			tempi = input_modul(0);
			for (int i = 0; i < mainData->size; i++) {
				el = mainData->arr[i].rate;
				if (el == tempi) {
					findData->arr[findData->size] = mainData->arr[i];
					findData->size++;
				}
			}
			break;
	}
	if (findData->size == 0) // Возвращаем указатель на список найденых студентов
		is_find++;
	findData->arr = realloc(findData->arr, findData->size * sizeof(Student));
	is_find++;
}


void del_persons(enum Column cl) { // Удаление людей по столбцам
	system("cls");
	int tempi;
	char tempc[256];
	int deleted = 0;
	switch (cl) {
	case ID:
		tempi = input_id();
		ui el;
		for (int i = 0; i < mainData->size; i++) {
			el = mainData->arr[i].id;
			if (el == tempi)
				deleted++;
			else
				mainData->arr[i - deleted] = mainData->arr[i];
		}
		break;

	case Name:
		input_name(tempc);
		for (int i = 0; i < mainData->size; i++) {
			if (strcmp(mainData->arr[i].name, tempc) == 0)
				deleted++;
			else
				mainData->arr[i - deleted] = mainData->arr[i];
		}
		break;

	case Group:
		short year, number;
		input_group(tempc, &year, &number);
		for (int i = 0; i < mainData->size; i++) {
			if ((strcmp(mainData->arr[i].group.name, tempc) == 0) && (mainData->arr[i].group.number == number) && (mainData->arr[i].group.year == year))
				deleted++;
			else
				mainData->arr[i - deleted] = mainData->arr[i];
		}
		break;

	case M1:
		tempi = input_modul(1);
		for (int i = 0; i < mainData->size; i++) {
			el = mainData->arr[i].m1;
			if (el == tempi)
				deleted++;
			else
				mainData->arr[i - deleted] = mainData->arr[i];
		}
		break;

	case M2:
		tempi = input_modul(2);
		for (int i = 0; i < mainData->size; i++) {
			el = mainData->arr[i].m2;
			if (el == tempi)
				deleted++;
			else
				mainData->arr[i - deleted] = mainData->arr[i];
		}
		break;

	case Rate:
		tempi = input_modul(0);
		for (int i = 0; i < mainData->size; i++) {
			el = mainData->arr[i].rate;
			if (el == tempi)
				deleted++;
			else
				mainData->arr[i - deleted] = mainData->arr[i];
		}
		break;
	}
	mainData->size -= deleted;
	mainData->arr = realloc(mainData->arr, mainData->size * sizeof(Student));
}


void sort_persons(List* data, enum Cloumn cl) { // Сортировка по столбцам
	if (data->size < 2)
		return NULL;
	Student temp;
	switch (cl) {
	case ID:
		for (int i = 0; i < data->size - 1; i++) {
			for (int j = 0; j < data->size - i - 1; j++) {
				if (data->arr[j].id > data->arr[j + 1].id) {
					temp = data->arr[j];
					data->arr[j] = data->arr[j + 1];
					data->arr[j + 1] = temp;
				}
			}
		}
		break;

	case Name:
		for (int i = 0; i < data->size - 1; i++) {
			for (int j = 0; j < data->size - i - 1; j++) {
				if (strcmp(data->arr[j].name, data->arr[j + 1].name) > 0) {
					temp = data->arr[j];
					data->arr[j] = data->arr[j + 1];
					data->arr[j + 1] = temp;
				}
			}
		}
		break;

	case Group:
		for (int i = 0; i < data->size - 1; i++) {
			for (int j = 0; j < data->size - i - 1; j++) {
				if (strcmp(data->arr[j].groupstr, data->arr[j + 1].groupstr) > 0) {
					temp = data->arr[j];
					data->arr[j] = data->arr[j + 1];
					data->arr[j + 1] = temp;
				}
			}
		}
		break;

	case M1:
		for (int i = 0; i < data->size - 1; i++) {
			for (int j = 0; j < data->size - i - 1; j++) {
				if (data->arr[j].m1 > data->arr[j + 1].m1) {
					temp = data->arr[j];
					data->arr[j] = data->arr[j + 1];
					data->arr[j + 1] = temp;
				}
			}
		}
		break;

	case M2:
		for (int i = 0; i < data->size - 1; i++) {
			for (int j = 0; j < data->size - i - 1; j++) {
				if (data->arr[j].m2 > data->arr[j + 1].m2) {
					temp = data->arr[j];
					data->arr[j] = data->arr[j + 1];
					data->arr[j + 1] = temp;
				}
			}
		}
		break;

	case Rate:
		for (int i = 0; i < data->size - 1; i++) {
			for (int j = 0; j < data->size - i - 1; j++) {
				if (data->arr[j].rate > data->arr[j + 1].rate) {
					temp = data->arr[j];
					data->arr[j] = data->arr[j + 1];
					data->arr[j + 1] = temp;
				}
			}
		}
		break;
	}
}


void  revers_persons(List* data) { // Инверсия списка студентов
	if (data->size < 2)
		return NULL;
	Student temp;
	for (int i = 0; i < data->size / 2; i++) {
		temp = data->arr[i];
		data->arr[i] = data->arr[data->size - i - 1];
		data->arr[data->size - i - 1] = temp;
	}
}