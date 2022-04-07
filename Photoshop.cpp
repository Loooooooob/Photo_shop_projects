// Program: photoshop.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
/* Authors:  Tawfik Mohamed Khalil        id->20211024
             Badr Nasr Al-Din Al-Badri    id->20210086
             Youssef Abdullah Ahmed       id->20211117

*/
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
unsigned char temp[SIZE][SIZE];
unsigned char temp2[SIZE][SIZE/2];
unsigned char image2 [SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];


void loadImage ();
void load_img2();
void load_img();

void saveImage ();
void save_img2();

void Black_White();
void Invert_Filter ();
void flip_image(); 
void Rotate_Image();
void blur();
void merge();

int main()
{

  // choose from filters
  int num;
  cout<<"Ahlan ya user ya habibi\n";
  cout<<"1->Black_White\n2->Invert_Filter\n3->merge_filter\n4->flip_image\n5->Rotate_Image\n12->blur_filter\n0->Exit\n";
  cout<<"please choose the filter you want :  ";
  cin>>num;
  if(num==1){
      loadImage();
      Black_White();
      saveImage();
  }
  else if(num==2){
      loadImage();
      Invert_Filter ();
      saveImage();
  }
  else if(num==3){
      load_img();
      load_img2();
      merge();
      save_img2();
  }
  else if(num==4){
      loadImage();
      flip_image();
      saveImage(); 
  }
  else if(num==5){
      loadImage();
      Rotate_Image();
      saveImage();
  }  
  else if(num==12){
      load_img();
      blur();
      save_img2();
      
  }
  else if(num==0){
    cout<<"Thank you for using photoshop";
  }
  
  return 0;
}
// ________________________________________
/*load the original image*/
void load_img()
{
    char imgfilename[100];
    cout << "Enter the image file name: ";
    cin >> imgfilename;
    strcat(imgfilename, ".bmp");
    readGSBMP(imgfilename, image);

}
/*load the image you want to merge in the (merge) function*/
void load_img2()
{
    char imgfilename[100];
    cout << "Please enter the name of BMP tp merge with: ";
    cin >> imgfilename;
    strcat(imgfilename, ".bmp");
    readGSBMP(imgfilename, image2);

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
/*save in file the edited image*/
void save_img2()
{
    char imgfilename[100];
    cout << "Enter target image file name: ";
    cin >> imgfilename;
    strcat(imgfilename, ".bmp");
    writeGSBMP(imgfilename, new_image);
}
// ________________________________________
void Black_White() {
  cout << "We do Black_White image\n************************"<<endl<<endl;
  // nested loop for array two D
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

        if (image[i][j] > 127)
            image[i][j] = 255;// make pixel white 
        else
            image[i][j] = 0;//make pixel black

    }
  }
}
// _________________________________________
void Invert_Filter (){
   for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

// if the pixel is white we turn it into black
      if (image[i][j] ==255)
         image[i][j] = 0;
// if the pixel is black we turn it into white         
      else if(image[i][j] ==0)
         image[i][j] = 255;
// if not black or white we sub from 255  
      else
         image[i][j]= 255-image[i][j];      
    }
  }
}
// ________________________________________
void flip_image(){
  cout<<"we do horizon or vertical flip image\n*************************************\n\n";
  cout<<"choice 1 for horizon image\nAny other choice for vertical image\n\n";
  cout<<"Enter your choice : ";

  int c;

  cin>>c;
  cout<<endl;
  //nested loop for array two D 
  if (c==1){
    // this loop for rows 
    //size/2 because we edit rows 
    for (int i=0 ;i<SIZE/2; i++){
        for (int j=0; j<SIZE;j++){
                temp[i][j]=image[i][j];
                image[i][j]=image[255-i][j];
                image[255-i][j]=temp[i][j];//make array image = edit array (temp)
        }
    }
  }
  else {
    // this loop for column 
   //size/2 because we edit column
    for (int i=0 ;i<SIZE; i++){
        for (int j=0; j<SIZE/2;j++){
                temp2[i][j]=image[i][255-j];
                image[i][255-j]=image[i][j];
                image[i][j]=temp2[i][j];//make array image = edit array (temp2)
        }
    }
  }
}
// ________________________________________
void Rotate_Image(){
   int x;
   cout<<"1-> rotate 90\n2-> rotate 180\n3-> rotate 270\nplease enter num of rotate:";
   cin>>x;
  //  loop on every pixel in image.
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      //  Here we transpose every pixel. 
        // Rotate 90 .
          if(x==1) {
            newimage[j][255-i]= image[i][j] ; 
          }
        // Rotate 180.
          else if(x==2) {
            newimage[255-i][j]= image[i][j] ;
          }
        // Rotate 270 .
          else if(x==3) {
            newimage[255-j][i]= image[i][j] ;

          }
        }
   
  }
  // Save image in varible image.
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
       image[i][j]=newimage[i][j];
    }
  }
}
// ___________________________________

/*function that makes you choose 2 pictures to merge together and saves it*/
void merge() {

    for(int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
            new_image[i][j]=(image[i][j] + image2[i][j])/2;

}
/*function that blurs the loaded image and saves it*/
void blur()
{
    for(int i=0; i<SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] = (image[i+1][j+1]*0.12 + image[i][j+1]*0.12 + 
            image[i+1][j]*0.12 + image[i-1][j-1]*0.12 + image[i][j-1]*0.12 + 
            image[i-1][j]*0.12 + image[i-1][j+1]*0.12 + image[i+1][j-1]*0.120 + image[i][j]*0.120/9);
        }
    }
}




