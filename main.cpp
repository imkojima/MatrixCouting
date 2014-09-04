#include "lib/bitmap.h"

using namespace std;

int main (){
	int input = 1;
	int X = 10;
	int Y = 10;
	int** content;
	int color0, color1;
    
    // Inputing Width & Height
    cout << "Bitmap Width[1-20]= ";
    cin >> input;
    if (input <1 || input >20){
    	cout << "Width Range : 1 - 20" << endl;
    	return 1;
    }else
    	X = input;

    cout << "Bitmap Height[1-20]= ";
    cin >> input;
    if (input <1 || input >20){
    	cout << "Height Range : 1 - 20" << endl;
    	return 2;
    }else
    	Y = input;

    // Creating Content for Bitmap
    content = new int*[10];
    for(int i =0; i<Y; ++i)
    	content[i] = new int[10];

    // Inputing Content
    for(int i=0;i<Y;++i){
    	for(int j=0;j<X;++j){
    		cout << "(" << j << ", " << i << ")= ";
    		cin >> input;
    		if(input!=0 && input !=1){
    			cout << "Content must be 1 or 0." << endl;
    			return 3;
    		}else
    			content[i][j] = input;
    	}

    }

    // Choosing Color
    cout << "0 White / 1 Black / 2 Blue / 3 Red / 4 Green / 5 Yellow" << endl;
    cout << "What Color You want to use on [0]? ";
    cin >> input;
    if(input <0 && input >5){
    	cout << "Invalid Color" << endl;
    	return 4;
    }else
    	color0 = input;
 	cout << "What Color You want to use on [1]? ";
    cin >> input;
    if(input <0 && input >5){
    	cout << "Invalid Color" << endl;
    	return 4;
    }else
    	color1 = input;
    // Creating Bitmap
    BitMap myBitmap(X,Y,content);

    // Displaying Bitmap
    myBitmap.display();

    // Outputing Bitmap Image
    myBitmap.outputBMP(color0, color1, "output.bmp");

    // Couting 
    for(int m=1;m<X;++m)
        for(int n=1;n<Y;++n)
            for(int i=0;i<X;++i)
                for(int j=0;j<Y;++j)
                    myBitmap.doCount(m,n,j,i);
	
    return 0;
}