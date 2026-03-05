#include "Header.h"




List* new_persons() {
	system("cls");
	printf("Введите необходимое число строк для добавления: ");
	ui size;
	if (scanf_s("%d", &size) == 0) {
		printf("\nПроизошла ошибка(\nПопробуйте ещё раз\n");
		return NULL;
	}
	Student* arr = calloc(size, sizeof(Student)); // Создать массив студентов нужного размера
	if (arr == NULL) {
		printf("\nНе удалось выделить память");
		return NULL;
	}
	for (int i = 0; i < size; i++) {
		init_person(&arr[i], i + 1);
		putchar('\n');
		system("pause");
	}
	system("cls");
	List* ptr = calloc(1, sizeof(List));
	*ptr = (List) { arr, size };
	print_List(ptr);
	return ptr;
}


int init_person(Student* person, int num) { 
	system("cls");
	if (num != 1) // для инициализации в списке
		printf("Инициализация студента %d\n", num);
	edit_ID(person, 0);
	edit_Name(person, 0);
	edit_Group(person, 0);
	edit_Modul(person, 1, 0);
	edit_Modul(person, 2, 0);
	edit_Rate(person, 0); 
	print_Person(person);
}


List* sum_lists(List* first, List* second) {
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


void drop_data(List* data) {
		if (data)
			free(data->arr);
		data->arr = NULL;
		data->size = NULL;
}


int input_id() {
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


void input_name(char* temp) {
	while (1) {
		printf("\nВведите имя студента: ");
		if (fgets(temp, 256, stdin) == NULL) {
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


void input_group(char* temp, short* year, short* number) {
	while (1) {
		printf("\nВведите группу студента по образцу ИДБ-25-00: ");
		if (scanf_s(" %[^-]-%hd-%hd", temp, (unsigned int)sizeof(temp), year, number) != 3) {
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


int input_modul(int num) {
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



void find(enum Column cl) {
	system("cls");
	drop_data(fData);
	fData->size = 0;
	fData->arr = calloc(Data->size, sizeof(Student));
	int tempi;
	char tempc[256];

	switch (cl) {
		case ID:
			tempi = input_id();
			ui el;
			for (int i = 0; i < Data->size; i++) {
				el = Data->arr[i].id;
				if (el == tempi) {
					fData->arr[fData->size] = Data->arr[i];
					fData->size++;
				}
			}
			break;

		case Name:
			input_name(tempc);
			for (int i = 0; i < Data->size; i++) {
				if (strcmp(Data->arr[i].name, tempc) == 0) {
					fData->arr[fData->size] = Data->arr[i];
					fData->size++;
				}
			}
			break;

		case Group:
			short year, number;
			input_group(tempc, &year, &number);
			for (int i = 0; i < Data->size; i++) {
				if ((strcmp(Data->arr[i].group.name, tempc) == 0) && (Data->arr[i].group.number == number) && (Data->arr[i].group.year == year)) {
					fData->arr[fData->size] = Data->arr[i];
					fData->size++;
				}
			}
			break;

		case M1:
			tempi = input_modul(1);
			for (int i = 0; i < Data->size; i++) {
				el = Data->arr[i].m1;
				if (el == tempi) {
					fData->arr[fData->size] = Data->arr[i];
					fData->size++;
				}
			}
			break;

		case M2:
			tempi = input_modul(2);
			for (int i = 0; i < Data->size; i++) {
				el = Data->arr[i].m2;
				if (el == tempi) {
					fData->arr[fData->size] = Data->arr[i];
					fData->size++;
				}
			}
			break;

		case Rate:
			tempi = input_modul(0);
			for (int i = 0; i < Data->size; i++) {
				el = Data->arr[i].rate;
				if (el == tempi) {
					fData->arr[fData->size] = Data->arr[i];
					fData->size++;
				}
			}
			break;
	}
	if (fData->size == 0)
		is_find++;
	fData->arr = realloc(fData->arr, fData->size * sizeof(Student));
	is_find++;
}