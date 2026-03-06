#include "Header.h"
#include <locale.h>

/*: 
поиск / фильтры
удаление по условию
сортировка по условиям
проверки?
*/

int menu_size = 0;
us save_success = 2;
us load_success = NULL;
int is_find = 0;
List* mainData;
List* findData;

int main() {
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);


	load_success = load_data();
	start_menu();



	return 0;
}
