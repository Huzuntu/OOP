//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Umut Tölek
//---Student Number: 150190724
//--------------------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <vector>

class StatisticalDistribution{
    private:
        double mean;

    public:
        StatisticalDistribution(int meanValue) : mean(meanValue) 
        {

        };
        virtual std::vector<double> sample(int, int) = 0;
        double getMean() { return this->mean; };
        std::vector<double> calculate_confidence_interval(std::vector<double>, int, double);
};

class NormalDistribution: public StatisticalDistribution{
    private:
        double stddev;
    public:
        NormalDistribution() : StatisticalDistribution(0.0), stddev(1.0)
        {
            
        };
        std::vector<double> sample(int, int);
};

class UniformDistribution: public StatisticalDistribution{
    private:
        double a, b;
    public:
        UniformDistribution() : StatisticalDistribution(0.0), a(-1.0), b(1.0)
        {

        };
        std::vector<double> sample(int, int);
};

class ExponentialDistribution : public StatisticalDistribution{
    private:
        double lambda;
    public:
        ExponentialDistribution() : StatisticalDistribution(1.0), lambda(1.0)
        {

        };
        std::vector<double> sample(int, int);
};
#endif