
#ifndef ASS2AAA_EUCLIDEANVECTOR_H
#define ASS2AAA_EUCLIDEANVECTOR_H
#include <iostream>
#include <vector>
#include <list>
namespace evec {

    class EuclideanVector {
    public:

        //constructor
        EuclideanVector(unsigned int a);
        EuclideanVector();
        EuclideanVector(unsigned int a, double b);
        template<class T>
        EuclideanVector(T a, T b){
            EuclideanNorm = 0.0;
            capicity = std::distance(a,b);
            buffer = new double[capicity];
            int temp = 0;
            for(auto i = a; i != b; ++i){
                buffer[temp++] = *i;

            }

        };
        EuclideanVector(const std::initializer_list<double> &il);

        //copy&move constructor
        EuclideanVector(const EuclideanVector &e_vector);
        EuclideanVector(EuclideanVector &&e_vector);
        //Destructor
        ~EuclideanVector(){
            delete[] buffer;

        };

        //operations
        //copy&move assignment
        EuclideanVector& operator=(const EuclideanVector &e_vector);
        EuclideanVector& operator=(EuclideanVector &&e_vector);

        unsigned int getNumDimensions() const;
        double get(unsigned int a) const;
        double getEuclideanNorm() const;
        EuclideanVector createUnitVector();

        double& operator[](int a);
        double operator[](int a) const;

        EuclideanVector& operator+=(const EuclideanVector &temp);
        EuclideanVector& operator-=(const EuclideanVector &temp);
        EuclideanVector& operator*=(double temp);
        EuclideanVector& operator/=(double temp);
        //type conversion
        operator std::vector<double>();
        operator std::list<double>();




    private:

        double *buffer;
        mutable double EuclideanNorm; //initialize to 0, change the value after required

        unsigned int capicity;
    };

    //nonmember functions
    bool operator ==(const EuclideanVector &a, const EuclideanVector &b);
    bool operator !=(const EuclideanVector &a, const EuclideanVector &b);
    EuclideanVector operator+(const EuclideanVector &a, const EuclideanVector &b);
    EuclideanVector operator-(const EuclideanVector &a, const EuclideanVector &b);
    double operator*(const EuclideanVector &a, const EuclideanVector &b);
    EuclideanVector operator*(const EuclideanVector &a, double b);
    EuclideanVector operator*(double a, const EuclideanVector &b);
    EuclideanVector operator/(const EuclideanVector &a, double b);
    std::ostream& operator<<(std::ostream& os, const EuclideanVector &a);
}


#endif //ASS2AAA_EUCLIDEANVECTOR_H
