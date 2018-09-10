#include <iostream>
#include <random>
#include <thread>
#include <vector>

#include "BucketSort.h"

int main() {
	// std::vector<std::vector<unsigned int>> smallbuckets;
	// std::vector<unsigned int> a{1,2,3};

	// std::vector<unsigned int> b{5,6,7};

	// smallbuckets.push_back(a);
	// smallbuckets.push_back(b);
	// a.push_back(123);

	// for(auto it = smallbuckets.begin(); it != smallbuckets.end(); ++it){
	// 	for(auto it2 = it->begin(); it2 != it->end(); ++it2){
	// 		std::cout << *it2 <<"\n";
	// 	}
	// 	std::cout <<"\n";
	// }

	// double j = 10;
	// unsigned int bei = 3;

	// unsigned int s = j/bei;


	// std::cout << s <<"\n";


	// // std::vector<std::vector<unsigned int>> smallbucketsa(10, std::vector<unsigned int>());

 // //    // for(auto i = 0; i < 10; ++i){
 // //    //     smallbucketsa.push_back(std::vector<unsigned int>());
 // //    // }
 // //    std::cout << smallbucketsa[0].size() <<"\n";
 // //    smallbucketsa[0].push_back(1);
 // //    std::cout << smallbucketsa[0].size() <<"\n";
 // //    std::cout << smallbucketsa.size() <<"\n";


	// std::vector<int> myints={10,20,30,40,50,60,70};
 //  	std::vector<int> myvector;
 //  	myvector.push_back(1);

 //  	myvector.insert(myvector.end(), myints.begin(), myints.end());

 //  	std::cout << "myvector contains:";
 //  	for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
 //    	std::cout << ' ' << *it;

 //  	std::cout << '\n';
	BucketSort pbs;

	// // insert random numbers into the sort object
	pbs.numbersToSort.push_back(1);
	pbs.numbersToSort.push_back(2);
	pbs.numbersToSort.push_back(3);
	// // call sort giving the number of cores available.
    const unsigned int numCores = std::thread::hardware_concurrency();
    

    std::cout << "number of cores used: " << numCores << std::endl;
	pbs.sort(numCores);

}