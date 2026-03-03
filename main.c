#include "Header.h"
	

/*: 
поиск / фильтры
удаление по условию
сортировка по условиям
проверки?
*/

int menu_size = 0;
us save_success = 2;
us load_success = NULL;
List* Data;

int main() {
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);


	load_success = load_data();
	start_menu();



	return 0;
}
