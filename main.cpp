#include "lib/bitmap.h"

using namespace std;

int main (){
	int X = 20;
	int Y = 20;
    BitMap myBitmap(X,Y);
    
    // Display Bitmap
    myBitmap.display();

    // Output Bitmap Image
    myBitmap.outputBMP(0, "output.bmp");

    // Couting 
    for(int m=1;m<X;++m)
        for(int n=1;n<Y;++n)
            for(int i=0;i<X;++i)
                for(int j=0;j<Y;++j)
                    myBitmap.doCount(m,n,j,i);

    return 0;
}