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

bool detectection_images_test_empty(std::vector<int> image_test, int type_image_test, std::vector<int> image_class_0, std::vector<int> image_class_1);
bool detectection_images_test_occupied(std::vector<int> image_test, int type_image_test, std::vector<int> image_class_0, std::vector<int> image_class_1);