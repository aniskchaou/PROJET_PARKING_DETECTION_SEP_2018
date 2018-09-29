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


using namespace std;
using namespace cv;

/*
fromBins: transform binary into decimal
parameter : the integer value
return type: decimal
*/
int fromBin(int n)
{
	int factor = 1;
	int total = 0;

	while (n != 0)
	{
		total += (n % 10) * factor;
		n /= 10;
		factor *= 2;
	}

	return total;
}


/*
lbp:transforms the image into an integer vector by using local binary pattern algorithm
parameter :the images must be in grey scale 
return type: interger vector
*/
std::vector<int> lbp(Mat img_grey)
{


	//initialisation 
	String vecteur_image[8];
	std::vector<int> pixel_id_vector;
	int image_id_vector[256];
	std::vector<int> img_identity;
	string byte_image_vector;
	vector<string> temp_tab;
	for (int i = 0; i < 256; i++)
	{
		image_id_vector[i] = 0;
	}



	//iterate pixel by pixel grey image
	for (int r = 1; r<img_grey.rows - 1; r++)
	{
		for (int c = 1; c<img_grey.cols - 1; c++)
		{

			//compare the central pixels ans its neighboring

			if (img_grey.at<uint8_t>(r, c)<img_grey.at<uint8_t>(r, c - 1))
			{
				pixel_id_vector.push_back(1);
			}
			else
			{
				pixel_id_vector.push_back(0);
			}

			if (img_grey.at<uint8_t>(r, c)<img_grey.at<uint8_t>(r, c + 1))
			{
				pixel_id_vector.push_back(1);
			}
			else
			{
				pixel_id_vector.push_back(0);
			}

			if (img_grey.at<uint8_t>(r, c)<img_grey.at<uint8_t>(r - 1, c))
			{
				pixel_id_vector.push_back(1);
			}
			else
			{
				pixel_id_vector.push_back(0);
			}

			if (img_grey.at<uint8_t>(r, c)<img_grey.at<uint8_t>(r + 1, c))
			{
				pixel_id_vector.push_back(1);
			}
			else
			{
				pixel_id_vector.push_back(0);
			}

			if (img_grey.at<uint8_t>(r, c)<img_grey.at<uint8_t>(r - 1, c - 1))
			{
				pixel_id_vector.push_back(1);
			}
			else
			{
				pixel_id_vector.push_back(0);
			}

			if (img_grey.at<uint8_t>(r, c)<img_grey.at<uint8_t>(r - 1, c + 1))
			{
				pixel_id_vector.push_back(1);
			}
			else
			{
				pixel_id_vector.push_back(0);
			}

			if (img_grey.at<uint8_t>(r, c)<img_grey.at<uint8_t>(r + 1, c - 1))
			{
				pixel_id_vector.push_back(1);
			}
			else
			{
				pixel_id_vector.push_back(0);
			}

			if (img_grey.at<uint8_t>(r, c)<img_grey.at<uint8_t>(r + 1, c + 1))
			{
				pixel_id_vector.push_back(1);
			}
			else
			{
				pixel_id_vector.push_back(0);
			}
		}
	}


	//process the vector of the image
	for (int i = 0; i<pixel_id_vector.size(); i++)
	{
		//build a string variable that contains all the binary sequence
		byte_image_vector.append(std::to_string(pixel_id_vector[i]));

		//if it is a byte
		if (i % 8 == 0)
		{
			//add each byte  
			temp_tab.push_back(byte_image_vector);
			byte_image_vector = "";

		}

	}

	//process each byte
	for (int i = 1; i < temp_tab.size(); i++)
	{
		//str-->int
		int val = std::stoi(temp_tab[i]);
		//binary -->decimal
		int k = fromBin(val);
		//add to histogram each value
		image_id_vector[k] = image_id_vector[k] + 1;
	}


	//show the histogram
	for (size_t i = 1; i < 256; i++)
	{
		
		img_identity.push_back(image_id_vector[i]);
		
	}

	
	return img_identity;


}


/*
lbp:transforms the image into an integer vector by using compact mean local binary pattern algorithm
parameter :the images must be in grey scale
return type: interger vector
*/
std::vector<int> compact_mean_lbp(Mat img_grey)
{
	std::vector<int> s;
	return s;
}