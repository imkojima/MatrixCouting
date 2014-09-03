#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <memory.h>

using namespace std;

class BitMap {
public:
	BitMap();
	BitMap(int X, int Y);
	BitMap(int X, int Y, int** content);

	void display();
	void outputBMP(int color, string output_name);
	void doCount(int size_w, int size_h, int base_x, int base_y);
	void setPoint(int x, int y, int value);

private:
	int BitMap_W; // Width
	int BitMap_H; // Height
	int** BitMap_Content;
	vector<size_t> result;
};