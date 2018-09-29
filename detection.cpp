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
#include "distance.h"
#include "detectionr.h"
using namespace std;
using namespace cv;


/*
detectection_images_test_empty : checks the detection between the empty test image and the training images by 
using the minimal of Euclidean distance
return type:boolean 
parameters:the empty test images,the type of image (0 or 1) ,the empty train image ,the occupied train image
*/
bool detectection_images_test_empty(std::vector<int> image_test ,int type_image_test, std::vector<int> image_class_0, std::vector<int> image_class_1)
{
	//calcul the Euclidean distance
	int distance_class_0 = distance_euclidienne(image_test, image_class_0);
	int distance_class_1 = distance_euclidienne(image_test, image_class_1);

	//calcul of the minimal distance 
	int dist_min = min(distance_class_0, distance_class_1);

	if (dist_min == distance_class_0)
	{
		return true;
	}
	else
	{
		return false;	
	}


	
}


/*
detectection_images_test_empty : checks the detection between the occupied test image and the training images by
using the minimal of Euclidean distance
return type:boolean
parameters:the empty test images,the type of image (0 or 1) ,the empty train image ,the occupied train image
*/
bool detectection_images_test_occupied(std::vector<int> image_test, int type_image_test, std::vector<int> image_class_0, std::vector<int> image_class_1)
{
	//calcul the Euclidean distance
	int distance_class_0 = distance_euclidienne(image_test, image_class_0);
	int distance_class_1 = distance_euclidienne(image_test, image_class_1);

	//calcul of the minimal distance 
	int dist_min = min(distance_class_0, distance_class_1);

	if (dist_min == distance_class_0)
	{
		return true;
	}
	else
	{
		return false;
	}



}