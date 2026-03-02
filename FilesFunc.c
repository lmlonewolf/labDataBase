#include "Header.h"
#include <IO.h>

int save_data(List* data) {
	FILE* file = fopen("data.dat", "wb");
	int res = fwrite(data->arr, sizeof(Student), data->size, file);
	fclose(file);
	if (res != data->size)
		return 1;
	return 0;
}


int load_data() {
	FILE* file = fopen("data.dat", "rb");
	int desk = fileno(file);
	size_t bsize = _filelength(desk);
	ui count = bsize / sizeof(Student);
	Data.arr = calloc(count, sizeof(Student));
	int res = fread(Data.arr, sizeof(Student), count, file);
	fclose(file);
	if (res != count)
		return 1;
	Data.size = count;
	return 0;
}

