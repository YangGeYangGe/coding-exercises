#include "BucketSort.h"

#include <algorithm>
#include <cmath>
#include <mutex>
#include <iostream>
bool aLessB(const unsigned int& x, const unsigned int& y, unsigned int pow) {
    if (x == y) return false; // if the two numbers are the same then one is not less than the other
    unsigned int a = x;
    unsigned int b = y;
    // work out the digit we are currently comparing on.
    if (pow == 0) {
        while (a / 10 > 0) {
            a = a / 10;
        }
        while (b / 10 > 0) {
            b = b / 10;
        }
    } else {
        while (a / 10 >= (unsigned int) std::round(std::pow(10,pow))) {
            a = a / 10;
        }
        while (b / 10 >= (unsigned int) std::round(std::pow(10,pow))) {
            b = b / 10;
        }
    }
    if (a == b)
        return aLessB(x,y,pow + 1);  // recurse if this digit is the same
    else
        return a < b;
}

void recursiveSort(std::vector<unsigned int> &sorted ,std::vector<unsigned int> bucket, unsigned int pow){
    std::vector<std::vector<unsigned int>> innerbuckets(10, std::vector<unsigned int>());
    for(auto it = bucket.begin(); it != bucket.end(); ++it){
        std::string string_number = std::to_string(*it);
        // std::cout << string_number <<" asd\n";
        if(string_number.size() > pow){
            unsigned int index = string_number[pow] - '0';
            // std::cout << index <<" asd\n";
            innerbuckets[index].push_back(*it);
        } else {
            sorted.push_back(*it);
        }
    }
    ++pow;

    for(auto index = 0; index < innerbuckets.size(); ++index){
        if(innerbuckets[index].size() == 0){
            continue;
        }else if(innerbuckets[index].size() == 1){
            sorted.push_back(innerbuckets[index][0]);
        }else{
            recursiveSort(sorted, innerbuckets[index], pow);
        }
    }
}


// TODO: replace this with a parallel version. 
void BucketSort::sort(unsigned int numCores) {
    // std::sort(numbersToSort.begin(),numbersToSort.end(), [](const unsigned int& x, const unsigned int& y){
    //     return aLessB(x,y,0);
    // } );

    std::vector<std::vector<unsigned int>> smallbuckets(10, std::vector<unsigned int>());

    // for(auto i = 0; i < 10; ++i){
    //     smallbuckets.push_back(std::vector<unsigned int>());
    // }

    unsigned int workload = numbersToSort.size() / numCores;
    std::mutex mutex;

    std::vector<std::thread> threads;

    // auto getleftmost = [](unsigned int digit){
    //     while (digit / 10 > 0) {
    //         digit /= 10;
    //     }    
    //     return digit;
    // };

    //make buckets(thread)
    auto dividelambda = [this, &smallbuckets, &mutex](unsigned int start, unsigned int end){
        std::vector<std::vector<unsigned int>> innerbuckets(10, std::vector<unsigned int>());
        for(auto i = start; i <= end; ++i){
            auto digit = numbersToSort[i];
            unsigned int leftmost = digit;
            while (leftmost / 10 > 0) {
                leftmost /= 10;
            }             
            innerbuckets[leftmost].push_back(digit);
        }
        
        std::lock_guard<std::mutex> lock(mutex);
        for(auto i = 0; i < 10; ++i){
            smallbuckets[i].insert(smallbuckets[i].end(), innerbuckets[i].begin(), innerbuckets[i].end());
        }
    };

    for(unsigned int w = 0; w < numCores; ++w){
        if(w != numCores - 1){
            unsigned int s = w*workload;
            unsigned int e = s + workload - 1;
            threads.push_back(std::thread(dividelambda, s, e));
        } else {
            unsigned int s = w*workload;
            unsigned int e = numbersToSort.size() - 1;
            threads.push_back(std::thread(dividelambda, s, e));
        }
    }
    // std::cout << "numer of threads: "<<threads.size()<<std::endl;
    //join bucket
    for (auto &t : threads) {
        t.join();
    }


    threads.clear();

    auto sortlambda = [this,&smallbuckets,&mutex](unsigned int start, unsigned int end){

        for(auto i = start; i <= end; ++i){
            std::vector<unsigned int> sorted;
            recursiveSort(sorted,smallbuckets[i], 1);

            std::lock_guard<std::mutex> lock(mutex);
            smallbuckets[i].clear();
            smallbuckets[i] = sorted;
            // std::sort(smallbuckets[i].begin(),smallbuckets[i].end(), [](const unsigned int& x, const unsigned int& y){
            //     return aLessB(x,y,0);
            // } );
        }

    };

    // 10/numCores
    workload = smallbuckets.size()/numCores;

    for(unsigned int w = 0; w < numCores; ++w){

        unsigned int s = 0;
        unsigned int e = 0;

        if(w == 0){
            s = 0;
            e = workload;
        }else if(w != numCores - 1){
            s = 1 + w*workload;
            e = s + workload - 1;
        }else{
            s = 1 + w*workload;
            e = smallbuckets.size() - 1;
        }
        // std::cout <<s<<" "<< e<<"\n";
        threads.push_back(std::thread(sortlambda, s, e));

    }
    //join sorting
    for (auto &t : threads) {
        t.join();
    }


    // //join to original
    numbersToSort.clear();

    for(auto i = 0; i < smallbuckets.size(); ++i){
        numbersToSort.insert(numbersToSort.end(), smallbuckets[i].begin(), smallbuckets[i].end());
    }
    std::cout << "current \n";
        
}


