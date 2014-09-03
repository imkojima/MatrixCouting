#include "bitmap.h"
extern "C" {
	#include "qdbmp.h"
}
using namespace std;

#define	RECTANGLE_WIDTH		32
#define	RECTANGLE_HEIGHT	32

// Default Constructor 
BitMap::BitMap() {
	BitMap_W = 0;
	BitMap_H = 0;
	BitMap_Content = NULL;
}

// Constructor (with map size X*Y)
BitMap::BitMap(int X, int Y){
	BitMap_W = X;
	BitMap_H = Y;
	BitMap_Content = new int*[Y];
	srand (time(NULL));
	for(int i=0;i<Y;++i){
		BitMap_Content[i] = new int[X];
		for(int j=0;j<X;++j)
			BitMap_Content[i][j] = rand() % 2;
	}
}

// Constructor (with map size X*Y and the values of content)
BitMap::BitMap(int X, int Y, int** content){
	BitMap_Content = new int*[Y];
	for(int i=0;i<Y;++i)
		BitMap_Content[i] = new int[X];
}

// Display Map (visualized array elements)
void BitMap::display(){
	cout << "Map Size: " << BitMap_W << "x" << BitMap_H << "(WxH)" << endl;

	for(int i=0;i<BitMap_H;i++){
		cout << "\t";
		for(int j=0;j<BitMap_W;j++)
			cout << "[" << BitMap_Content[i][j] << "]";
		cout << endl;
	}
}

void BitMap::outputBMP(int color, string output_name){
	BMP*	output;
	UINT 	x, y;
	UCHAR 	r, g, b;

	output = BMP_Create( BitMap_W * RECTANGLE_WIDTH, BitMap_H * RECTANGLE_HEIGHT, 8 );

	switch(color){
		case 0:	// 0: White - 1: Black
			BMP_SetPaletteColor( output, 0, 255, 255, 255 );
			BMP_SetPaletteColor( output, 1, 0, 0, 0);
			break;
		case 1:	// 0: Blue - 1: Red
			BMP_SetPaletteColor( output, 0, 0, 0, 255 );
			BMP_SetPaletteColor( output, 1, 255, 0, 0);	
			break;
		default:
			BMP_SetPaletteColor( output, 0, 255, 255, 255 );
			BMP_SetPaletteColor( output, 1, 0, 0, 0);
			break;
	}

	for(int i=0;i<BitMap_H;i++){
		for(int j=0;j<BitMap_W;j++)
			for(x= j * RECTANGLE_WIDTH; x < j * RECTANGLE_WIDTH + RECTANGLE_WIDTH; ++x)
				for(y= i * RECTANGLE_HEIGHT; y < i * RECTANGLE_HEIGHT + RECTANGLE_HEIGHT; ++y)
					BMP_SetPixelIndex( output, x, y, BitMap_Content[i][j] );
	}

	/* Save output image */
	BMP_WriteFile( output, output_name.c_str() );

	/* Free output image memory */
	BMP_Free( output );
}

// Counting the number of the same as specified area
void BitMap::doCount(int size_w, int size_h, int base_x, int base_y){

	if(base_x+size_w>BitMap_W || base_y+size_h >BitMap_H)
		return;

	stringstream str;
	hash<std::string> str_hash;

	for(int i = base_y; i < (base_y+size_h) ; ++i){
		for(int j = base_x; j < (base_x+size_w) ; ++j){
			str << "[" << BitMap_Content[i][j] << "]";
		//	cout << "[" << BitMap_Content[i][j] << "]";
		}
		str << endl;
		//cout << endl;
	}

	// If the result have been calculated, then return.
	if(result.size()!= 0)
		if(std::find(result.begin(), result.end(), str_hash(str.str()))!=result.end()){
			//cout << "the result already existed" << endl;
			return ;
		}

	cout << "# "<<result.size() << endl;

	cout << "Target: " << endl;
	//cout << "# " << str_hash(str.str()) << endl;
	cout << str.str();
	result.push_back(str_hash(str.str()));

	int count = 0;
	for(int now_y = 0; now_y+size_h <= BitMap_H; ++now_y){
		for(int now_x = 0; now_x+size_w <= BitMap_W; ++now_x){
			//Comparing Block -- Start
			bool isSame = true;
			for(int i = 0; i < size_h ; ++i){
				for(int j = 0; j < size_w ; ++j)
					if(BitMap_Content[now_y+i][now_x+j] != BitMap_Content[base_y+i][base_x+j])
						isSame = false;
			}
			if(isSame==true)
				count++;
			//Comparing Block -- End
		}
	}
	cout << "count: " << count << endl;
}

// Setting specified point with the value
void BitMap::setPoint(int x, int y, int value){
	BitMap_Content[y][x] = value;
}