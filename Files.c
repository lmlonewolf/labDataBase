#include "Header.h"
#include <IO.h>

int save_data(void) {
	FILE* file = fopen("data.dat", "wb");
	int res = fwrite(Data->arr, sizeof(Student), Data->size, file);
	fclose(file);
	if (res != Data->size)
		return 1;
	return 0;
}


int load_data(void) {
	FILE* file = fopen("data.dat", "rb");
	int desk = fileno(file);
	size_t bsize = _filelength(desk);
	ui count = bsize / sizeof(Student);
	Data = calloc(1, sizeof(List));
	Data->arr = calloc(count, sizeof(Student));
	int res = fread(Data->arr, sizeof(Student), count, file);
	fclose(file);
	if ((res != count) || (count == 0)){
		Data->arr = NULL;
		Data->size = NULL;
		return 1;
	}
	Data->size = count;
	return 0;
}

