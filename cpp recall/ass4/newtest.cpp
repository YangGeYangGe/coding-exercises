//
// Created by GeYang on 4/10/17.
//

#include <iostream>
#include "btree.h"
#include <vector>
#include <iterator>

int main(void) {
   // std::vector<int> a{1,3,5};
   // a.insert(a.begin(),3);
//    int i = 7;
//    for (auto temp = 0; temp != a.size(); ++temp) {
//        if(a[temp] > i ){
//
//            a.insert(a.begin()+temp,i);
//            break;
//        }else if (temp == 2){
//            a.push_back(i);
//        }
//
//
//    }
//
//    for(int zxc: a){
//        std::cout << zxc <<'\n';
//    }

//    btree<int> a(4);
//    auto temp_p= a.insert(2);
//
//   // a.testing();
//
//    auto temp_p1= a.insert(4);
//    auto temp_p2= a.insert(5);
//    auto temp_p3= a.insert(6);
//
//
//    auto temp_p4= a.insert(2);
//    auto temp_p5= a.insert(1);
//
//
//    //a.testing();
//
//    //std::cout <<"asd\n "<< *(temp_p.first) << "  testing/\n";
//
//   // std::cout <<"asd\n "<< *(a.begin()) << "  testing/\n";
//    //a.pRoot();
//    //a.aaa();
//
//
//    btree<int> b;
//
//    b = std::move(a);
//    auto asd = b.find(1);
//    auto zxxc = b.end();
//
//    b.pRoot();
//    std::cout <<"get here\n";
//    a.pRoot();
//    std::cout <<"get here\n";
//    //
//
//    if(asd == zxxc){
//        std::cout <<"hi\n";
//    }else{
//        std::cout <<"asd   "<< *(asd) << "  testing/\n";
//    }
//
    btree<int> b(2);
    b.insert(1);
    b.insert(3);
    b.insert(2);
    b.insert(5);
    b.insert(4);


    //b.aaa();
    //auto temptemp = ++b.begin();
//    std::cout << *(temp) << "  testing/\n";
//    std::cout << *(++temp) << "  testing/\n";

//    ++temp;
//    if(temp == b.end()){
//        std::cout <<"why not happen\n";
//    }
    auto i = b.rbegin();
    for(; i != b.rend(); ++i){

        std::cout << *(i) << "\n";
    }
    //std::cout << *(i) << "\n";
   // std::cout << *(--b.end());
//
//    std::vector<int> a{1,3,5};
//    for(auto i = a.end()-1; i >= a.begin(); --i){
//        std::cout << *i <<"\n";
//    }
}