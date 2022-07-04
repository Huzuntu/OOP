//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#ifndef __UTILS_H
#define __UTILS_H

#include "statistics.h"


StatisticalDistribution *choose_function(int);

double many_trials(StatisticalDistribution *dist, std::vector<double> random_Sample, double tValue, int trials, int sampleSize, int seedValue);

#endif