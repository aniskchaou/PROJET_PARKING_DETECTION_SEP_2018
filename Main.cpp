#include <opencv2/core.hpp>
#include "opencv2/highgui.hpp"

#include <stdint.h>
#include<windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <filesystem>
#include <algorithm>


//include all functions

#include"ldp.h"
#include "detectionr.h"
#include "distance.h"
#include"load_save_images.h"
#include"image_database.h"

using namespace std;
using namespace cv;

int main(int *argv, char **argc) {

	//initialisation
	int number_test_images = 50;
	int number_train_images = 1000;
	int average = 0;
	std::vector<int> vector_image_train_occupied;
	std::vector<int>  vector_image_train_empty;
	int occupied = 0;
	int empty = 0;



	//save images in text text files
     enregister_images_vides(number_train_images);
	enregister_images_occupe(number_train_images);
	
	
	

	 
	 //read training images  
	 std::vector<string>  images_empty_from_file = lire_fichier("0");
	 std::vector<string>  images_occupied_from_file = lire_fichier("1");

	 //read test images
	 std::vector<string> name_images_test_empty=chargement_images("images/cloudy/train/empty", number_test_images);
	 std::vector<string>  name_images_test_occupied=chargement_images("images/cloudy/train/occupied", number_test_images);
	 std::vector<Mat> loaded_images_test_empty = ouvrir_images(name_images_test_empty, "images/cloudy/test/empty/");
	 std::vector<Mat> loaded_images_test_occupied = ouvrir_images(name_images_test_occupied, "images/cloudy/test/occupied/");
	
	 


	
	 //cross test 1: train occupied ---> test empty
	 for (int i = 0; i < images_empty_from_file.size()&&i<loaded_images_test_empty.size(); i++)
	 {   
		 //transform string into vector of integer
		 vector_image_train_empty = explode(images_empty_from_file[i], '/');
		 vector_image_train_occupied = explode(images_occupied_from_file[i], '/');
			
		     //get the vector of test images
			 std::vector<int> vector_image_test_empty_vector = lbp(loaded_images_test_empty[i]);
			 
			 if (vector_image_test_empty_vector.size() > 0 && vector_image_train_occupied.size()>0)
			 {
				 //detect the type of test image
				 if (detectection_images_test_empty(vector_image_test_empty_vector, 0, vector_image_train_empty, vector_image_train_occupied))
				 {
					
					 empty++;
				 }
				 else
				 {
					 occupied++;
				 }
		 } 
	 }

	 //show result of test cross operation
	cout <<"empty :  " << empty << "\n" << endl;
	cout << "occûpied : " << occupied << "\n" << endl;
	cout << "average of true detection :  " << empty/number_train_images << "\n" << endl;
	 
	

	
	//test cross 2 :train empty -->test occupied
	for (int i = 0; i < images_occupied_from_file.size() && i<loaded_images_test_occupied.size(); i++)
	{
		//transform string into vector of integer
		vector_image_train_empty = explode(images_empty_from_file[i], '/');
		vector_image_train_occupied = explode(images_occupied_from_file[i], '/');

		//get the vector of test images
		std::vector<int> vector_image_occupied_empty_vector = lbp(loaded_images_test_occupied[i]);

		if (vector_image_occupied_empty_vector.size() > 0 && vector_image_train_occupied.size()>0)
		{
			//detect the type of test image
			if (detectection_images_test_occupied(vector_image_occupied_empty_vector, 0, vector_image_train_empty, vector_image_train_occupied))
			{

				empty++;
			}
			else
			{
				occupied++;
			}
		}
	}

	//show result of test cross operation 2
	cout << "occûpied : " << occupied << "\n" << endl;
	cout << "empty :  " << empty << "\n" << endl;
	cout << "average of true detection :  " << occupied / number_train_images << "\n" << endl;

	
	waitKey(0);
	return 0;
}