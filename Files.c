#include "Header.h"
#include <IO.h>


int save_data(void) {
	FILE* file = fopen("data.dat", "wb");
	int res = fwrite(mainData->arr, sizeof(Student), mainData->size, file);
	fclose(file);
	if (res != mainData->size)
		return 1;
	return 0;
}


int load_data(void) {
	FILE* file = fopen("data.dat", "rb");
	int desk = fileno(file);
	size_t bsize = filelength(desk);
	ui count = bsize / sizeof(Student);
	mainData = calloc(1, sizeof(List));
	mainData->arr = calloc(count, sizeof(Student));
	int res = fread(mainData->arr, sizeof(Student), count, file);
	fclose(file);
	if ((res != count) || (count == 0)){
		mainData->arr = NULL;
		mainData->size = NULL;
		return 1;
	}
	mainData->size = count;
	// инициализируем структуру найденых данных
	findData = calloc(1, sizeof(List));
	findData->arr = NULL;
	findData->size = NULL;
	return 0;
}