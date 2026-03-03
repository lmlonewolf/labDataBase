#include "Header.h"



void menu(int select, enum Menu page) {
	system("cls");
	char** options = NULL;
	switch (page) { // Выбор раздела меню
	case Edit:
		menu_size = 8;
		static char* options_edit[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг", "Сохранить", "Выйти"};
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
		menu_size = 6;
		static char* options_data[] = { "Добавить студентов", "Удалить студентов", "Сортировать", "Поиск", "Сохранить", "Назад"};
		options = options_data;
		break;
	case Drop:
		menu_size = 2;
		printf("Вы уверены, что хотите сбросить данные? Отменить изменения невозможно!\n\n");
		static char* options_drop[] = { "Назад", "Сбросить" };
		options = options_drop;
		break;
	}


	for (int i = 0; i < menu_size; i++) {
		if (i == select)
			printf("-> %s\n", options[i]);
		else
			printf("%s\n", options[i]);
	}
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
				Data = sum_lists(Data, new_persons()); //TODO: FIX
				break;
			//case 1:
			//	//del_persons(); 
			case 4:
				save_success = save_data();
				break;
			case 5:
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
			else { // TODO: Добавить сохнанение сброса
				//free(Data->arr);
				//Data->arr = NULL;
				//Data->size = NULL;
				drop_data();
				break;
			}
		}
	}
}


void edit_menu(Student* person) {
	int select = 0;
	int flag = 1;
	while (flag) {
		print_Person(person); // Вывод заголовка
		printf("\nВыберете пункты для изменения:\n\n");
		menu(select, Edit);
		if(move(&select)) { //Управление
			switch (select) { // TODO: Добавить изменение по пунктам
			//case 0:
			//case 1:
			//case 2:
			//case 3:
			//case 4:
			//case 5:
			//case 6:
			case 7:
				flag = 0;
				break;
			}
		}
	}
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