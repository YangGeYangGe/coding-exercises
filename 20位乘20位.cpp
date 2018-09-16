// 20位乘20位
#include <iostream>
#include <cstdio>
// #include <stdlib>
using namespace std;

int main(){
    //freopen("1.in","r",stdin);
   	string a = "20000000000000000000";
	string b =  "30000000000000000000";

   	int result[42] = {0};
   	// int zxc = b[1]-48;
   	int start = 42;
   	int current = start;
   	for(int i = b.size()-1; i >= 0 ; --i){
   		start--;
   		current = start;
   		for(int j = a.size()-1; j >= 0 ; --j){
   			int tmp = (b[i]-48) * (a[j]-48);
   			result[current] += tmp%10;
   			result[current-1] += tmp/10;
   			if(tmp == 6){
   				cout << "first "<<current <<endl;
   			}
   			current--;
   		}
   	}
   	// cout<<(result[41]);
   	for(auto &zxzx:result){
   		cout<<zxzx<<endl;
   	}
   	int check = false;
   	int count = 0;
   	for(int m = 0; m < 42; ++m){
   		if(check == false){
   			if (result[m] != 0){

   				check = true;
   				cout<<(result[m]);
   				count++;
   			}

   		} else{
   			count++;
   			cout<<(result[m]);
   		}
   		
   	}
   	cout<<endl;

    return 0;

}