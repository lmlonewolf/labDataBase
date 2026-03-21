#include "Header.h"


void print_Line() { // Вывод разделения
	printf("\033[0;033m");
	putchar('+');
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < (int[]) { 6, 20, 9, 5, 5, 7 }[i]; j++)
			putchar('-');
		putchar('+');
	}
	putchar('\n');
	printf("\033[0m");
}

void print_List(const List* const persons) { // Вывод списка студентов ввиде таблицы
	if (persons->size % 10 == 1)
		printf("\nСписок из %d студента:\n", persons->size);
	else
		printf("\nСписок из %d студентов:\n", persons->size);
	print_Line();
	printf("\033[0;033m|\033[0m%6s\033[0;033m|\033[0m%20s\033[0;033m|\033[0m%9s\033[0;033m|\033[0m%5s\033[0;033m|\033[0m%5s\033[0;033m|\033[0m%s\033[0;033m|\033[0m\n", "ID", "Имя", "Группа", "M1", "M2", "Рейтинг");
	print_Line();
	for (int i = 0; i < persons->size; i++) {
		const Student* p = &persons->arr[i];
		printf("\033[0;033m|\033[0m%6d\033[0;033m|\033[0m%20s\033[0;033m|\033[0m%9s\033[0;033m|\033[0m%5d\033[0;033m|\033[0m%5d\033[0;033m|\033[0m%7d\033[0;033m|\033[0m\n", p->id, p->name, p->groupstr, p->m1, p->m2, p->rate);
		print_Line();
	}
	putchar('\n');
	putchar('\n');
}


void print_Person(const Student* const person) { // Вывод студента
	print_Line();
	printf("\033[0;033m|\033[0m%6s\033[0;033m|\033[0m%20s\033[0;033m|\033[0m%9s\033[0;033m|\033[0m%5s\033[0;033m|\033[0m%5s\033[0;033m|\033[0m%s\033[0;033m|\033[0m\n", "ID", "Имя", "Группа", "M1", "M2", "Рейтинг");
	print_Line();
	printf("\033[0;033m|\033[0m%6d\033[0;033m|\033[0m%20s\033[0;033m|\033[0m%9s\033[0;033m|\033[0m%5d\033[0;033m|\033[0m%5d\033[0;033m|\033[0m%7d\033[0;033m|\033[0m\n", person->id, person->name, person->groupstr, person->m1, person->m2, person->rate);
	print_Line();
}