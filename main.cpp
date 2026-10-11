//
//  main.cpp
//  
//
//  Created by Hayk Derdzyan on 27.09.26.
//

#include <iostream>
#include "vector.h"
#include "linkedlist.h"

template <typename T>
void print(const Vector<T>& list) {
    std::cout<<"----"<<std::endl;
    for (const auto& each : list){
        std::cout<<each<<std::endl;

    }
}

int main(){
    //--vector----
    Vector<int> nums;
    
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    
    print(nums);
    
    Vector<std::string> names;
    
    names.push_back("Lena");
    names.push_back("Hayk");
    names.push_back("Sargins");
    
    print(names);

    names.pop_back();
    print(names);

    //--linked list

    LinkedList<string> list;
    std::cout<<"Input count : "<<std::endl;
    int n;
    do cin>>n;while(n < 2);
    std::cout<<"Input elements : "<<std::endl;

    for (int i = 0; i < n; ++i) {
        cin>>list;
    }

    list.removeBack();

    list.printRev();
    
    return 0;
}
