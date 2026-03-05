#include "Header.h"
#include <conio.h>


void menu(int select, enum Menu page) {
	system("cls");
	char** options = NULL;

	switch (page) { // Выбор раздела меню
	case Del:
		if (save_success == 1)
			printf("\nОшибка сохранения!\n\n");
		else if (save_success == 0)
			printf("\nУспешно сохранено!\n\n");
		print_List(Data); // Вывод заголовка
		printf("\nВыберете пункт по которым будите удалять студентов:\n\n");
		menu_size = 9;
		static char* options_del[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг\n", "Отменить", "Сохранить", "Назад" };
		options = options_del;
		break;

	case Edit:
		if (save_success == 1)
			printf("\nОшибка сохранения!\n\n");
		else if (save_success == 0)
			printf("\nУспешно сохранено!\n\n");
		print_Person(&fData->arr[0]); // Вывод заголовка
		printf("\nВыберете пункты для изменения:\n\n");
		menu_size = 8;
		static char* options_edit[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг\n", "Сохранить", "Назад"};
		options = options_edit;
		break;
		
	case Start:
		if (load_success)
			printf("Пока данных нет\nИли случилась ошибка при загруске данных.\n\n");
		if (save_success == 1)
			printf("\nОшибка сохранения!\n\n");
		else if (save_success == 0)
			printf("\nУспешно сохранено!\n\n");
		menu_size = 4;
		static char* options_start[] = { "Список студентов", "Сбросить данные", "Сохранить", "Выход" };
		options = options_start;
		break;

	case Exit:
		printf("Вы уверены, что хотите выйти? Все несохранённые данные будут утерены!\n\n");
		menu_size = 2;
		static char* options_exit[] = { "Назад", "Выйти" };
		options = options_exit;
		break;

	case DataOptions:
		print_List(Data);
		if (save_success == 1)
			printf("\nОшибка сохранения!\n\n");
		else if (save_success == 0)
			printf("\nУспешно сохранено!\n\n");
		menu_size = 7;
		static char* options_data[] = { "Добавить студентов", "Удалить студентов", "Сортировать", "Поиск", "Изменить\n", "Сохранить", "Назад"};
		options = options_data;
		break;

	case Drop:
		printf("Вы уверены, что хотите сбросить данные? Отменить изменения невозможно!\n\n");
		menu_size = 2;
		static char* options_drop[] = { "Назад", "Сбросить" };
		options = options_drop;
		break;

	case Find:
		if (is_find == 1) {
			printf("Найдены студенты по вашему запросу\n");
			print_List(fData);
		}
		else if (is_find == 2)
			printf("По вашему запросу студентов не найдено!\n\n");
		printf("Выберите столбец для поиска:\n\n");
		menu_size = 7;
		static char* options_find[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг\n", "Назад"};
		options = options_find;
		break;
	}


	for (int i = 0; i < menu_size; i++) {
		if (i == select)
			printf("-> %s\n", options[i]);
		else
			printf("%s\n", options[i]);
	}
}


void find_menu() {
	int select = 0;
	int flag = 1;
	while (flag) {
		menu(select, Find);
		if (move(&select)) { // Enter
			switch (select) {
			case 0:
				find_persons(ID);
				break;
			case 1:
				find_persons(Name);
				break;
			case 2:
				find_persons(Group);
				break;
			case 3:
				find_persons(M1);
				break;
			case 4:
				find_persons(M2);
				break;
			case 5:
				find_persons(Rate);
				break;
			case 6:
				flag = 0;
				break;
			}
		}
	}
	is_find = 0;
	save_success = 2;
}


void del_menu() {
	int select = 0;
	int flag = 1;
	while (flag) {
		menu(select, Del);
		if (move(&select)) { // Enter
			switch (select) {
			case 0:
				del_persons(ID);
				break;
			case 1:
				del_persons(Name);
				break;
			case 2:
				del_persons(Group);
				break;
			case 3:
				del_persons(M1);
				break;
			case 4:
				del_persons(M2);
				break;
			case 5:
				del_persons(Rate);
				break;
			case 6:
				load_success = load_data();
				break;
			case 7:
				save_success = save_data();
				break;
			case 8:
				flag = 0;
				break;
			}
		}
	}
	is_find = 0;
	save_success = 2;
}


void start_menu() {
	int select = 0;
	
	while (1) {
		menu(select, Start);
		if (move(&select)) { // Enter
			switch (select) {
				case 0:
					data_menu();
					break;
				case 1:
					drop_menu();
					break;
				case 2:
					save_success = save_data();
					break;
				case 3:
					exit_menu();
					break;
			}
		}
	}
	save_success = 2;
	load_success = 0;
}


void data_menu() {
	int select = 0;
	int flag = 1;
	while (flag) {
		menu(select, DataOptions);
		if (move(&select)) {
			switch (select) {
			case 0:
				Data = sum_lists(Data, new_persons()); //TODO: добавить функции
				break;
			case 1:
				del_menu(); 
				break;
			//case 2:
			//  sort()
			case 3:
				find_menu();
				break;
			case 4:
				edit_menu();
				break;
			case 5:
				save_success = save_data();
				break;
			case 6:
				flag = 0;
				break;
			}
		}
	}
	save_success = 2;
}


void exit_menu() {
	int select = 0;
	while (1) {
		menu(select, Exit);
		if (move(&select)) { // Управление
			if (select == 0) {
				break;
			}
			else {
				exit(0);
			}
		}
	}
}


void drop_menu() {
	int select = 0;
	
	while (1) {
		menu(select, Drop);
		if (move(&select)) { // Управление
			if (select == 0) {
				break;
			}
			else {
				drop_data(Data);
				break;
			}
		}
	}
}


void edit_menu() {
	int select = 0;
	int flag = 1;
	Student* person;
	while (1) {
		system("cls");
		printf("Для изменения информации о студенте введите его ID\n");
		system("pause");
		person = find_to_edit();
		if (person == NULL) {
			printf("Студент с данным ID не найден. Попробуйте ещё раз.\n");
			system("pause");
		}
		else
			break;
	}
	fData->size = 1;
	fData->arr = person;
	while (flag) {
		menu(select, Edit);
		if(move(&select)) { //Управление
			switch (select) { 
			case 0:
				edit_ID(person, 1);
				break;
			case 1:
				edit_Name(person, 1);
				break;
			case 2:
				edit_Group(person, 1);
				break;
			case 3:
				edit_Modul(person, 1, 1);
				break;
			case 4:
				edit_Modul(person, 2, 1);
				break;
			case 5:
				edit_Rate(person, 1);
				break;
			case 6:
				save_success = save_data(); // TODO: fData сохранять в дата
				break;
			case 7:
				flag = 0;
				break;
			}
		}
	}
	save_success = 2;
}


int move(int* select) {
	int key = _getch();
	if (key == 224) { // Начало ввода с клавиатуры
		key = _getch();
		if (key == 72) // Вверх
			*select = (*select > 0) ? *select - 1 : menu_size - 1;
		if (key == 80) // Вниз
			*select = (*select < menu_size - 1) ? *select + 1 : 0;
		return 0;
	}
	else if (key == 13)
		return 1;
	return 0;
}