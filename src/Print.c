#include "Header.h"


void print_Line() { // Вывод разделения
	putchar('+');
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < (int[]) { 6, 20, 9, 5, 5, 7 }[i]; j++)
			putchar('-');
		putchar('+');
	}
	putchar('\n');
}

void print_List(const List* const persons) { // Вывод списка студентов ввиде таблицы
	if (persons->size % 10 == 1)
		printf("\nСписок из %d студента:\n", persons->size);
	else
		printf("\nСписок из %d студентов:\n", persons->size);
	print_Line();
	printf("|%6s|%20s|%9s|%5s|%5s|%s|\n", "ID", "Имя", "Группа", "M1", "M2", "Рейтинг");
	print_Line();
	for (int i = 0; i < persons->size; i++) {
		const Student* p = &persons->arr[i];
		printf("|%6d|%20s|%9s|%5d|%5d|%7d|\n", p->id, p->name, p->groupstr, p->m1, p->m2, p->rate);
		print_Line();
	}
	putchar('\n');
	putchar('\n');
}


void print_Person(const Student* const person) { // Вывод студента
	print_Line();
	printf("|%6s|%20s|%9s|%5s|%5s|%s|\n", "ID", "Имя", "Группа", "M1", "M2", "Рейтинг");
	print_Line();
	printf("|%6d|%20s|%9s|%5d|%5d|%7d|\n", person->id, person->name, person->groupstr, person->m1, person->m2, person->rate);
	print_Line();
}