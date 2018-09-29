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

using namespace std;
using namespace cv;
/*
distance_euclidienne : performs calculation of Euclidean distance between 2 vectors
parameters : the 2 vectors
return type :the Euclidean distance
*/
int distance_euclidienne(std::vector<int> image_id_vector, std::vector<int> image_id_vector2)
{
	int image_id_vector3[256], dist = 0;
	for (int i = 0; i < image_id_vector.size(); i++)
	{
		dist += pow((image_id_vector.at(i) - image_id_vector2.at(i)), 2);
	}
	return dist;
}