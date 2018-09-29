#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <filesystem>
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <string>
using namespace std;

void stockage_images();
vector<int> explode(const string& str, const char& ch);
std::vector<string> chargement_images(const std::string& name, int number_images);
std::vector<Mat> ouvrir_images(std::vector<string> list_images ,string path);
void stockage_images(int class_type, std::vector<int> image_vector);
std::vector<string> lire_fichier(string file);