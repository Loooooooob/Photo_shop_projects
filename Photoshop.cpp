// Program: photoshop.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Tawfik Mohamed Khalil      id->20211024
               
// Date:    2 April 2022
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];
unsigned char arrange_photos[SIZE][SIZE];
// unsigned char ShuffleImage[4][SIZE][SIZE];

// int temp;

void loadImage ();
void saveImage ();
void Invert_Filter ();
void Rotate_Image();
void Enlarge_Image();
void Shuffle_Image();

int main()
{
  loadImage();
//   int num;
//   cout<<"2->Invert_Filter\n5->Rotate_Image\n8->Rotate_Image\n";
//   cout<<"please choose the filter you want :  ";
//   cin>>num;
//   if(num==2){
//       Invert_Filter ();
//   }
//   else if(num==5){
//       Rotate_Image();
//   }  
//   else if(num==8){
//       Enlarge_Image();
//   }
  Shuffle_Image();

  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
// ________________________________________
// void Invert_Filter (){
//    for (int i = 0; i < SIZE; i++) {
//     for (int j = 0; j< SIZE; j++) {


//       if (image[i][j] ==255)
//          image[i][j] = 0;
//       else if(image[i][j] ==0)
//          image[i][j] = 255;
//       else
//          image[i][j]= 255-image[i][j];      
//     }
//   }
// }
// // ________________________________________
// void Rotate_Image(){
//    int x;
//    cout<<"1-> rotate 90\n2-> rotate 180\n3-> rotate 270\nplease enter num of rotate:";
//    cin>>x;
//    for (int i = 0; i < SIZE; i++) {
//     for (int j = 0; j< SIZE; j++) {
   
//       if(x==1) {
//          newimage[j][255-i]= image[i][j] ; 
//       }
//       else if(x==2) {
//          newimage[255-i][j]= image[i][j] ;
//       }
//       else if(x==3) {
//          newimage[255-j][i]= image[i][j] ;

//       }
//     }
   
//    }
//    for (int i = 0; i < SIZE; i++) {
//     for (int j = 0; j< SIZE; j++) {
//        image[i][j]=newimage[i][j];
//     }
//    }
// }
// // __________________________________________
// void Enlarge_Image(){
//    int x=0,y=0,z;
//    cout<<"1->top left side\n2->down left side\n3->top right side\n4->down right side";
//    cout<<"\nplease choose the num of the side you want :";
//    cin>>z;
// // top left side 
//    if(z==1){
//       for (int i = 0; i < SIZE/2; i++) {
//          for (int j = 0; j< SIZE/2; j++) {
//             newimage[x][y]=image[i][j];

//             newimage[x] [y+1]=image[i][j];

//             newimage[x+1] [y+1]=image[i][j];

//             newimage[x+1] [y]=image[i][j];
//             y+=2;
//          }
//          x+=2;
//          y=0;
//       }
//    }
// // down left side
//    else if(z==2){
//       for (int i = 128; i < SIZE; i++) {
//          for (int j = 0; j< SIZE/2; j++) {
//             newimage[x][y]=image[i][j];

//             newimage[x] [y+1]=image[i][j];

//             newimage[x+1] [y+1]=image[i][j];

//             newimage[x+1] [y]=image[i][j];
//             y+=2;
//          }
//             x+=2;
//             y=0;
//       }
//    }
// // top right side 
//    else if(z==3){
//       for (int i = 0; i < SIZE/2; i++) {
//          for (int j = 128; j< SIZE; j++) {
//             newimage[x][y]=image[i][j];

//             newimage[x] [y+1]=image[i][j];

//             newimage[x+1] [y+1]=image[i][j];

//             newimage[x+1] [y]=image[i][j];
//             y+=2;
//          }
//             x+=2;
//             y=0;
//       }
//    }
// // down right side
//    else if(z==4){
//       for (int i = 128; i < SIZE; i++) {
//          for (int j = 128; j< SIZE; j++) {
//             newimage[x][y]=image[i][j];

//             newimage[x] [y+1]=image[i][j];

//             newimage[x+1] [y+1]=image[i][j];

//             newimage[x+1] [y]=image[i][j];
//             y+=2;
//          }
//             x+=2;
//             y=0;
//       }
//    }
//    for (int i = 0; i < SIZE; i++) {
//     for (int j = 0; j< SIZE; j++) {
//        image[i][j]=newimage[i][j];
//     }
//    }
// }
// _____________________________________________
// void Shuffle_Image(){
//    int a,b,c,d;
//    cout<<"please enter the arrange of photos :";
//    cin>>a>>b>>c>>d;
//       down left side
//       for (int i = 128; i < SIZE; i++) {
//          for (int j = 0; j< SIZE/2; j++) {
//             ShuffleImage[2][i][j]=image[i][j];

//          }
//       } 
//       // top left side 
//       for (int i = 0; i < SIZE/2; i++) {
//          for (int j = 0; j< SIZE/2; j++) {
//             ShuffleImage[0][i][j]=image[i][j];

//          }
//       }
//       // top right side 
//       for (int i = 0; i < SIZE/2; i++) {
//          for (int j = 128; j< SIZE; j++) {
//             ShuffleImage[1][i][j]=image[i][j];
//          }
//       }
//       // ____________________________________
//       int w=0,c=0;
//       for (int i = 0; i < SIZE/2; i++) {
//          for (int j = 0; j< SIZE/2; j++) {
//             image[i][j]=ShuffleImage[2][i][j];
//          }
//       }
//       for (int i = 0; i < SIZE/2; i++) {
//          for (int j = 128; j< SIZE; j++) {
//             image[i][j]=ShuffleImage[0][i][j];
//          }
//       }
//       for (int i = 128; i < SIZE; i++) {
//          for (int j = 0; j< SIZE/2; j++) {
//             image[i][j]=ShuffleImage[1][i][j];
//          }
//       }
// }


