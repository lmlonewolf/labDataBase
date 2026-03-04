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
	init_group(person); 
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


void drop_data() {
	free(Data->arr);
	Data->arr = NULL;
	Data->size = NULL;
}
