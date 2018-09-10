
#include "EuclideanVector.h"
#include <cmath>
namespace evec {
    //initialize EuclideanNorm
    double EuclideanNorm = 0.0;
    //constructors
    EuclideanVector::EuclideanVector(unsigned int a) {
        buffer = new double[a];
        for(unsigned int i = 0; i < a; ++i){
            buffer[i] = 0.0;
        }
        capicity = a;

    }

    EuclideanVector::EuclideanVector() {
        buffer = new double[1];
        buffer[0] = 0.0;
        capicity = 1;
    }

    EuclideanVector::EuclideanVector(unsigned int a, double b) {
        buffer = new double[a];
        for(unsigned int i = 0; i < a; ++i){
            buffer[i] = b;
        }
        capicity = a;
    }


    EuclideanVector::EuclideanVector(const std::initializer_list<double> &il) {
        capicity = std::distance(il.begin(),il.end());
        buffer = new double[capicity];
        int temp = 0;
        for(auto i = il.begin(); i != il.end(); ++i){
            buffer[temp++] = *i;
        }


    }
    //copy constructor
    EuclideanVector::EuclideanVector(const EuclideanVector &e_vector){

        capicity = e_vector.capicity;
        EuclideanNorm = e_vector.EuclideanNorm;
        buffer = new double[capicity];

        for(unsigned int i = 0; i < capicity; ++i){
            buffer[i] = e_vector.buffer[i];
        }

    }

    //move constructor
    EuclideanVector::EuclideanVector(EuclideanVector &&e_vector) {
        capicity = std::move(e_vector.capicity);
        EuclideanNorm = std::move(e_vector.EuclideanNorm);

        buffer = std::move(e_vector.buffer);

        e_vector.capicity = 0;
        e_vector.EuclideanNorm = 0;
        e_vector.buffer = nullptr;
    }


    //operations
    //copy assignment
    EuclideanVector& EuclideanVector::operator=(const EuclideanVector &e_vector) {
        if(this != &e_vector){
            delete[] buffer;
            capicity = e_vector.capicity;
            EuclideanNorm = e_vector.EuclideanNorm;
            buffer = new double[capicity];

            for(unsigned int i = 0; i < capicity; ++i){
                buffer[i] = e_vector.buffer[i];
            }
        }
        return *this;
    }

    //move assignment
    EuclideanVector& EuclideanVector::operator=(EuclideanVector &&e_vector) {
        if(this != &e_vector){

            delete[] buffer;
            capicity = std::move(e_vector.capicity);

            EuclideanNorm = std::move(e_vector.EuclideanNorm);

            buffer = std::move(e_vector.buffer);

            e_vector.capicity = 0;
            e_vector.EuclideanNorm = 0;
            e_vector.buffer = nullptr;
        }
        return *this;
    }


    unsigned int EuclideanVector::getNumDimensions() const{
        return capicity;
    }

    double EuclideanVector::get(unsigned int a) const{
        return buffer[a];
    }


    double EuclideanVector::getEuclideanNorm() const{

        if(EuclideanNorm == 0 && capicity > 0){

            double sum = 0;
            for (unsigned int temp = 0; temp < capicity; ++temp) {
                sum += buffer[temp]*buffer[temp];

            }

            EuclideanNorm = sqrt(sum);
        }

        return EuclideanNorm;
    }


    EuclideanVector EuclideanVector::createUnitVector() {
        double norm = this->getEuclideanNorm();

        EuclideanVector unit = *this;

        for(unsigned int i = 0; i < unit.getNumDimensions() ; ++i){
            unit.buffer[i] /= norm;
        }
        unit.EuclideanNorm = 0;
        return unit;
    }


    double& EuclideanVector::operator[](int a) {
        return buffer[a];
    }

    double EuclideanVector::operator[](int a) const {
        return buffer[a];
    }



    EuclideanVector& EuclideanVector::operator+=(const EuclideanVector &temp) {
        if(this->getNumDimensions() == temp.getNumDimensions()){
            for(unsigned int index = 0; index < this->getNumDimensions(); ++index){
                buffer[index] += temp[index];
            }

        }
        return *this;
    }

    EuclideanVector& EuclideanVector::operator-=(const EuclideanVector &temp) {
        if(this->getNumDimensions() == temp.getNumDimensions()){
            for(unsigned int index = 0; index < this->getNumDimensions(); ++index){
                buffer[index] -= temp[index];
            }

        }
        return *this;
    }

    EuclideanVector& EuclideanVector::operator*=(double temp) {
        for(unsigned int index = 0; index < this->getNumDimensions(); ++index){
            buffer[index] *= temp;
        }


        return *this;
    }
    EuclideanVector& EuclideanVector::operator/=(double temp) {
        for(unsigned int index = 0; index < this->getNumDimensions(); ++index){
            buffer[index] /= temp;
        }


        return *this;
    }


    EuclideanVector::operator std::vector<double>() {
        std::vector<double> temp;
        for(unsigned int i = 0; i < capicity; ++i){
            temp.push_back(buffer[i]);
        }

        return temp;
    }
    EuclideanVector::operator std::list<double>() {
        std::list<double> temp;
        for(unsigned int i = 0; i < capicity; ++i){
            temp.push_back(buffer[i]);
        }

        return temp;
    }


    //nonmember functions
    bool operator==(const EuclideanVector &a, const EuclideanVector &b) {

        if(a.getNumDimensions() == b.getNumDimensions()){
            for(unsigned int i = 0; i < a.getNumDimensions(); ++i){

                if(a[i] != b[i]){
                    return false;

                }

            }

            return true;

        }
        return false;
    }

    bool operator!=(const EuclideanVector &a, const EuclideanVector &b) {

        return !(a == b);
    }

    EuclideanVector operator+(const EuclideanVector &a, const EuclideanVector &b) {
        EuclideanVector temp(a);
        temp += b;
        return temp;
    }

    EuclideanVector operator-(const EuclideanVector &a, const EuclideanVector &b) {
        EuclideanVector temp(a);
        temp -= b;
        return temp;
    }

    double operator*(const EuclideanVector &a, const EuclideanVector &b) {
        double temp = 0;

        if(a.getNumDimensions() == b.getNumDimensions()){

            for(unsigned int index = 0; index < a.getNumDimensions(); ++index){

                temp += a[index]*b[index];

            }
        }
        return temp;
    }

    EuclideanVector operator*(const EuclideanVector &a, double b){
        EuclideanVector temp(a);
        temp *= b;

        return temp;
    }

    EuclideanVector operator*(double a, const EuclideanVector &b){
        EuclideanVector temp(b);
        temp *= a;
        return temp;

    }

    EuclideanVector operator/(const EuclideanVector &a, double b){
        EuclideanVector temp(a);
        temp /= b;
        return temp;

    }




    std::ostream& operator<<(std::ostream& os, const EuclideanVector &a){
        os << '[' ;
        unsigned int b = a.getNumDimensions();
        for(unsigned int index = 0; index < b; ++index){
            os << a[index];
            if(index != b - 1){
                os << " ";
            }

        }
        os << ']' ;
        return os;

    }

}
