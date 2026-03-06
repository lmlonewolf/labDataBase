#include "Header.h"
#include <locale.h>

// проверки?

// Определение и инициализация глобальных переменных
int menu_size = 0;
us save_success = 2;
us load_success = NULL;
int is_find = 0;
List* mainData;
List* findData;


int main() {
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);

	start_menu(); // Начало программы

	return 0;
}