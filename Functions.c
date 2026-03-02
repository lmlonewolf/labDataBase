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


int init_person(Student* person, int num) { // TODO: раскидать по функциям проверки и изменения
	system("cls");
	if (num != 1) // для инициализации в списке
		printf("Инициализация студента %d\n", num);
	edit_ID(person, 0);
	edit_Name(person, 0);
	edit_Group(person, 0);
	edit_Modul(person, 1, 0);
	edit_Modul(person, 2, 0);
	edit_Rate(person, 0);
	init_group(person); 
	print_Person(person);
}


void print_List(List* persons) {
	if (persons->size % 10 == 1)
		printf("\nСписок из %d студента:\n", persons->size);
	else
		printf("\nСписок из %d студентов:\n", persons->size);
	printf("\n%6s|%20s|%9s|%5s|%5s|%s\n", "ID", "Имя", "Группа", "M1", "M2", "Рейтинг");
	for (int i = 0; i < persons->size; i++) {
		const Student* p = &persons->arr[i];

		printf("%6d|%20s|%9s|%5d|%5d|%5d\n", p->id, p->name, p->groupstr, p->m1, p->m2, p->rate);
	}
	putchar('\n');
	putchar('\n');
}


void print_Person(Student* persons) {
	printf("\n%6s|%20s|%9s|%5s|%5s|%s\n", "ID", "Имя", "Группа", "M1", "M2", "Рейтинг");
	const Student* p = persons;
	printf("%6d|%20s|%9s|%5d|%5d|%5d\n", p->id, p->name, p->groupstr, p->m1, p->m2, p->rate);
	
}