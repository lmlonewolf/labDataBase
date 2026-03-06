#include "Header.h"
#include <conio.h>


void menu(int select, enum Menu page) { // Функция меню
	system("cls");
	char** options = NULL;

	switch (page) { // Выбор раздела меню
	case Del: // Раздел удаления данных
		if (save_success == 1)
			printf("\nОшибка сохранения!\n\n");
		else if (save_success == 0)
			printf("\nУспешно сохранено!\n\n");
		print_List(mainData); 
		printf("\nВыберете пункт по которым будите удалять студентов:\n\n");
		menu_size = 9;
		static char* options_del[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг\n", "Отменить", "Сохранить", "Назад" };
		options = options_del;
		break;

	case Edit: // Раздел изменения данных
		if (save_success == 1)
			printf("\nОшибка сохранения!\n\n");
		else if (save_success == 0)
			printf("\nУспешно сохранено!\n\n");
		print_Person(&findData->arr[0]); 
		printf("\nВыберете пункты для изменения:\n\n");
		menu_size = 8;
		static char* options_edit[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг\n", "Сохранить", "Назад"};
		options = options_edit;
		break;
		
	case MainSort: // Раздел сортировки основных данных
		print_List(mainData); 
		printf("\nВыберете пункты для сортировки:\n\n");
		menu_size = 8;
		static char* options_sort_main[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг\n", "Обратный порядок", "Назад" };
		options = options_sort_main;
		break;

	case FindSort:// Раздел сортировки найденных данных
		print_List(findData); 
		printf("\nВыберете пункты для сортировки:\n\n");
		menu_size = 8;
		static char* options_sort_find[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг\n", "Обратный порядок" , "Назад"};
		options = options_sort_find;
		break;

	case Start: // Раздел начального экрана
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

	case Exit: // Раздел выхода
		printf("Вы уверены, что хотите выйти? Все несохранённые данные будут утерены!\n\n");
		menu_size = 2;
		static char* options_exit[] = { "Назад", "Выйти" };
		options = options_exit;
		break;

	case DataOptions: // Раздел операций с  данными
		print_List(mainData);
		if (save_success == 1)
			printf("\nОшибка сохранения!\n\n");
		else if (save_success == 0)
			printf("\nУспешно сохранено!\n\n");
		menu_size = 7;
		static char* options_data[] = { "Добавить студентов", "Удалить студентов", "Сортировать", "Поиск", "Изменить\n", "Сохранить", "Назад"};
		options = options_data;
		break;

	case Drop: // Раздел сброса данных
		printf("Вы уверены, что хотите сбросить данные? Отменить изменения невозможно!\n\n");
		menu_size = 2;
		static char* options_drop[] = { "Назад", "Сбросить" };
		options = options_drop;
		break;

	case Find: // Раздел поиска данных
		if (is_find == 1) {
			printf("Найдены студенты по вашему запросу\n");
			print_List(findData);
		}
		else if (is_find == 2)
			printf("По вашему запросу студентов не найдено!\n\n");
		printf("Выберите столбец для поиска:\n\n");
		menu_size = 8;
		static char* options_find[] = { "ID", "Имя", "Группа", "Модуль 1", "Модуль 2", "Рейтинг\n", "Сортировать", "Назад" };
		options = options_find;
		break;
	}

	
	for (int i = 0; i < menu_size; i++) { // Вывод пунктов меню
		if (i == select)
			printf("-> %s\n", options[i]);
		else
			printf("%s\n", options[i]);
	}
}


void find_menu() { // Меню поиска данных
	int select = 0;
	int flag = 1;
	while (flag) {
		menu(select, Find);
		if (move(&select)) { 
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
				sort_menu_find();
				break;
			case 7:
				flag = 0;
				break;
			}
		}
	}
	is_find = 0;
	save_success = 2;
}


void del_menu() { // Меню удаления данных
	int select = 0;
	int flag = 1;
	while (flag) {
		menu(select, Del);
		if (move(&select)) {
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


void sort_menu_main() { // Меню сортировки основных данных
	int select = 0;
	int flag = 1;
	while (flag) {
		menu(select, MainSort);
		if (move(&select)) { 
			switch (select) {
			case 0:
				sort_persons(mainData, ID);
				break;
			case 1:
				sort_persons(mainData, Name);
				break;
			case 2:
				sort_persons(mainData, Group);
				break;
			case 3:
				sort_persons(mainData, M1);
				break;
			case 4:
				sort_persons(mainData, M2);
				break;
			case 5:
				sort_persons(mainData, Rate);
				break;
			case 6:
				revers_persons(mainData);
				break;
			case 7:
				flag = 0;
				break;
			}
		}
	}
	is_find = 0;
	save_success = 2;
}


void sort_menu_find() { // Меню сортировки найденных данных
	int select = 0;
	int flag = 1;
	while (flag) {
		menu(select, FindSort);
		if (move(&select)) { 
			switch (select) {
			case 0:
				sort_persons(findData, ID);
				break;
			case 1:
				sort_persons(findData, Name);
				break;
			case 2:
				sort_persons(findData, Group);
				break;
			case 3:
				sort_persons(findData, M1);
				break;
			case 4:
				sort_persons(findData, M2);
				break;
			case 5:
				sort_persons(findData, Rate);
				break;
			case 6:
				revers_persons(mainData);
				break;
			case 7:
				flag = 0;
				break;
			}
		}
	}
	is_find = 0;
	save_success = 2;
}


void start_menu() { // Меню главный экран
	load_success = load_data();
	int select = 0;
	
	while (1) {
		menu(select, Start);
		if (move(&select)) { 
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


void data_menu() { // Меню опираций с данными
	int select = 0;
	int flag = 1;
	while (flag) {
		menu(select, DataOptions);
		if (move(&select)) {
			switch (select) {
			case 0:
				mainData = sum_lists(mainData, new_persons()); // Создать список студентов и добавить в mainData
				break;
			case 1:
				del_menu(); 
				break;
			case 2:
				sort_menu_main();
				break;
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


void exit_menu() { // Меню меню выхода
	int select = 0;
	while (1) {
		menu(select, Exit);
		if (move(&select)) { 
			if (select == 0) {
				break;
			}
			else {
				exit(0);
			}
		}
	}
}


void drop_menu() { // Меню сброса данных
	int select = 0;
	
	while (1) {
		menu(select, Drop);
		if (move(&select)) { 
			if (select == 0) {
				break;
			}
			else {
				drop_data(mainData);
				break;
			}
		}
	}
}


void edit_menu() { // Меню изменения данных 
	int select = 0;
	int flag = 1;
	Student* person;
	while (1) { // Получение ID и всяческие проверки
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
	findData->size = 1;
	findData->arr = person;
	while (flag) {
		menu(select, Edit);
		if(move(&select)) {
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
				save_success = save_data();
				break;
			case 7:
				flag = 0;
				break;
			}
		}
	}
	save_success = 2;
}


int move(int* select) { // Управление меню
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