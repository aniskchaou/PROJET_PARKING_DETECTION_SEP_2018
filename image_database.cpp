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



#include"ldp.h"
#include "detectionr.h"
#include "distance.h"
#include"load_save_images.h"
#include"image_database.h"


using namespace std;
using namespace cv;



/*
this function performs multiple tasks:
-loading the name of all images from the directory empty
-opening the images
-transforming the images into vectors (lbp)
-saving vector in text file

return type:void
parameters : the number of images 
*/
void enregister_images_vides(int number_train_images)
{
	//load images
	std::vector<string>  images_names = chargement_images("images/cloudy/train/empty", number_train_images);
	//open images
	std::vector<Mat> loaded_images = ouvrir_images(images_names, "images/cloudy/train/empty/");

	for (size_t i = 0; i < loaded_images.size(); i++)
	{
		//invoke lbp method on every single image
		std::vector<int> image_vector = lbp(loaded_images[i]);
		//save the vector in text file
		stockage_images(0, image_vector);
	}
}




/*
this function performs multiple tasks:
-loading the name of all images from the directory occupied
-opening the images
-transforming the images into vectors (lbp)
-saving vector in text file

return type:void
parameters : the number of images
*/

void enregister_images_occupe(int number_train_images)
{   //load the images 
	std::vector<string>  images_names = chargement_images("images/cloudy/train/occupied", number_train_images);
	//open images
	std::vector<Mat> loaded_images = ouvrir_images(images_names, "images/cloudy/train/occupied/");

	for (size_t i = 0; i < loaded_images.size(); i++)
	{
		//apply the lbp method on every image
		std::vector<int> image_vector = lbp(loaded_images[i]);
		//save vector
		stockage_images(1, image_vector);
	}
}


