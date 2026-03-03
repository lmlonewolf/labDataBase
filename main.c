#include "Header.h"
	

/*: 
добавление студентов
сохранение в файл
считывание файла
вывод студентов
поиск / фильтры
удаление по условию
сортировка по условиям
сохранение
выход
проверки?
*/

int menu_size = 0;
List* Data;

int main() {
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);

	//Student a = {
	//125277,
	//"Александр Потапенко",
	//{"ИДБ", 25, 12}
	//};
	if (load_data())
		printf("Пока данных нет\nИли случилась ошибка при загруске данных.\n\n");
	start_menu();
	//List arr = new_persons();
	
	//printf("Нажмите Enter для перехода дальше");
	//scanf_s("%s");
	//print_students(arr);



	return 0;
}
