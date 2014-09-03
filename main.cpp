#include "lib/bitmap.h"

using namespace std;

int main (){
    BitMap myBitmap(10,10);
    
    myBitmap.display();

    for(int m=1;m<10;++m)
        for(int n=1;n<10;++n)
            for(int i=0;i<10;++i)
                for(int j=0;j<10;++j)
                    myBitmap.doCount(m,n,j,i);
    return 0;
}