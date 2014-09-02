#include "bitmap.h"

using namespace std;


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

int main (){

	BitMap my(10,10);
	my.display();
	for(int m=1;m<10;++m)
		for(int n=1;n<10;++n)
			for(int i=0;i<10;++i)
				for(int j=0;j<10;++j)
					my.doCount(m,n,j,i);
	return 0;
}