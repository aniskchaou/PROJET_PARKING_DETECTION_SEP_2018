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
using namespace cv;
int fromBin(int n);
std::vector<int> lbp(Mat img_grey);