#include "Header.h"


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


void print_Person(Student* person) {
	printf("\n%6s|%20s|%9s|%5s|%5s|%s\n", "ID", "Имя", "Группа", "M1", "M2", "Рейтинг");
	const Student* p = person;
	printf("%6d|%20s|%9s|%5d|%5d|%5d\n", p->id, p->name, p->groupstr, p->m1, p->m2, p->rate);

}
