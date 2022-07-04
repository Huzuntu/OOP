//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"

StatisticalDistribution* choose_function(int dist_type){
    if(dist_type == 0){
        StatisticalDistribution* normal_dist = new NormalDistribution();
        return normal_dist;
    }
    else if(dist_type == 1){
        StatisticalDistribution* uniform_dist = new UniformDistribution();
        return uniform_dist;
    }
    else if(dist_type == 2){
        StatisticalDistribution* exponential_dist = new ExponentialDistribution();
        return exponential_dist;
    }
    else{
        throw "Unidentified distribution function!"; 
    }
    return NULL;
};

double many_trials(StatisticalDistribution *dist, std::vector<double> random_sample, double t_value, int trials, int sample_size, int seed_value){
    int success = 0;
    int i = 0;
    while(i < trials){
        std::vector<double> random_sample = dist->sample(sample_size, seed_value);
        std::vector<double> confidence_interval = dist->calculate_confidence_interval(random_sample, sample_size, t_value);
        if(confidence_interval[0] < dist->getMean() && confidence_interval[2] > dist->getMean()){
            success++;
        }
        seed_value++;
        i++;
    }
    return (double(success) / double(trials));
};