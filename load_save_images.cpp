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
stockage_images : saves the list of vector in text file  
parameters:class type and the vector
return : type void
*/
void stockage_images(int class_type, std::vector<int> image_vector)
{
	//test the type of image 
	if (class_type == 0)
	{   
		// open the file or create if it don't exist
		ofstream myfile;
		myfile.open("0.txt", std::ios_base::app);
		string j = "";
		
		//write data 
		for (int i = 0; i < image_vector.size(); i++)
		{
			j = to_string(image_vector[i]);
			j = j + "/";
			myfile << j;
		}
		myfile << "\n";

		//close the file
		myfile.close();
	}
	else
	{
		//open the file
		ofstream myfile;
		myfile.open("1.txt", std::ios_base::app);
		string j = "";
		
		//write data
		for (int i = 0; i < image_vector.size(); i++)
		{
			j = to_string(image_vector[i]);
			j = j + "/";
			myfile << j;
		}
		myfile << "\n";

		//close the file
		myfile.close();
	}
	
}



/*
explode : convert a string into an integer vector by using the delimiter ','
parameters: delimiter and the string 
return type :integer vector
*/
vector<int> explode(const string& str, const char& ch) {
	
	string next;
	vector<string> result;
	vector<int> vector_image;
	
	// For each character in the string
	for (string::const_iterator it = str.begin(); it != str.end(); it++) {
		// If we've hit the terminal character
		if (*it == ch) {
			// If we have some characters accumulated
			if (!next.empty()) {
				// Add them to the result vector
				result.push_back(next);
				next.clear();
			}
		}
		else {
			// Accumulate the next character into the sequence
			next += *it;
		}
	}
	if (!next.empty())
		result.push_back(next);
	
	//convert the vector of string to a vector of interger
	for (int i = 0; i < result.size(); i++)
	{
		vector_image.push_back(stoi(result[i]));
	}

	return vector_image;
}



/*
chargement_images: lists all files in a directory and save the in string vector
return type: string vector
parameters : number of image and the name of directory
*/
std::vector<string> chargement_images(const std::string& name,int number_images)
{
	//initailisation
	std::vector<string> images_loaded;
	std::string pattern(name);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	int number_img_occ = 0;

	//open the directory 
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		string s = data.cFileName;
		do {
			number_img_occ++;
			//ignore the 2 first files (.. and .)
			if (number_img_occ>2)
			{
				//save the file name
				images_loaded.push_back(data.cFileName);
				
			}
		} while (FindNextFile(hFind, &data) != 0 && number_img_occ<number_images+2);
		
		
		//close the directory
		FindClose(hFind);
	}
	return images_loaded;
}


/*
ouvrir_images:loads the list of images and save the in Mat vector
parameters : the list of images and path where are located in 
return type : Mat vector
*/
std::vector<Mat> ouvrir_images(std::vector<string> list_images,string path)
{
	std::vector<Mat> loaded_images;

	for (size_t i = 0; i < list_images.size(); i++)
	{
		// read the images
		Mat img_grey = imread(path+list_images[i], CV_LOAD_IMAGE_GRAYSCALE);
		// save the readed images in a vector
		loaded_images.push_back(img_grey);
	}
	return loaded_images;
}



/*
lire_fichier: reads from file the list of vectors whether empty or occupied and save them in vector 
parameters : the name of the file
returns type: string vector
*/
std::vector<string> lire_fichier(string file)
{   
	std::vector<string> loaded_image_vector;
	ifstream myReadFile;

	//open the file
	myReadFile.open(file+".txt");
	char output[1000];


	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {

			//read the vectors
			myReadFile >> output;

			//save in the vector
			loaded_image_vector.push_back(output);
		}
	}

	return loaded_image_vector;
}



