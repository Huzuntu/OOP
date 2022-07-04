//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>

std::vector<double> StatisticalDistribution::calculate_confidence_interval(std::vector<double> random_sample, int sample_size, double t_value){
    double sum_of_elements = 0;
    for(std::vector<double>::iterator it = random_sample.begin(); it != random_sample.end(); ++it){
        sum_of_elements += *it;
    }
    double mean = sum_of_elements / random_sample.size(); //mean

    double deviation = std::inner_product(random_sample.begin(), random_sample.end(), random_sample.begin(), 0.0f);
    double standard_deviation = sqrt(deviation / random_sample.size() - (mean * mean));

    double lower_bound = mean - (t_value * (standard_deviation / std::sqrt(sample_size)));
    double upper_bound = mean + (t_value * (standard_deviation / std::sqrt(sample_size)));
    std::vector<double> confidence_interval = { lower_bound, mean, upper_bound };
    
    return confidence_interval;
};

std::vector<double> NormalDistribution::sample(int sample_size, int seed_value){
    std::vector<double> NormalDistributionSample;
    std::default_random_engine generator;
    generator.seed(seed_value);
    std::normal_distribution<double> distribution(this->getMean(), this->stddev);
    for(int i = 0; i < sample_size; i++){
        double number = distribution(generator);
        NormalDistributionSample.push_back(number);
    }
    return NormalDistributionSample;
};

std::vector<double> UniformDistribution::sample(int sample_size, int seed_value){
    std::vector<double> UniformDistributionSample;
    std::default_random_engine generator;
    generator.seed(seed_value);
    std::uniform_real_distribution<double> distribution(this->a, this->b);
    for(int i = 0; i < sample_size; i++){
        double number = distribution(generator);
        UniformDistributionSample.push_back(number);
    }
    return UniformDistributionSample;
};


std::vector<double> ExponentialDistribution::sample(int sample_size, int seed_value){
    std::vector<double> ExponentialDistributionSample;
    std::default_random_engine generator ;
    generator.seed(seed_value);
    std::exponential_distribution<double> distribution(this->lambda);
    for(int i = 0; i < sample_size; i++){
        double number = distribution(generator);
        ExponentialDistributionSample.push_back(number);
    }
    return ExponentialDistributionSample;
};