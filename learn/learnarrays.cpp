#include <iostream>
#include <string>

int main(){
    std::string cars[][3] = {{"corvette", "camaro", "Silverado"},
                       {"Mustang", "F150", "Charger"},
                       {"Civic", "Accord", "CRV"}};

    int carRows = sizeof(cars) / sizeof(cars[0]);
    int carCols = sizeof(cars[0]) / sizeof(cars[0][0]);


    for(int i = 0; i < carRows; i++){
        for(int j=0; j < carCols; j++){
            // std::cout<<cars[i][j]<< " ";
        }
        // std::cout<<std::endl;
    }
    // std::cout<<"\n\n"<<std::endl;

    std::string people[][5] ={{"Toba","Tobe","Tobi","Tobo","Tobu"},
                         {"Mark","Matthew","Madagascar","Matha","Matthias"},
                         {"Me","Myself","I"}};

    int peopleRow = sizeof(people) / sizeof(people[0]);
    int peopleCols = sizeof(people[0]) / sizeof(people[0][0]);

    for(int x = 0; x < peopleRow; x++){
        for(int y = 0; y < peopleCols; y++){
            // std::cout<<people[x][y]<< " ";
        }
        // std::cout<<std::endl;
    }

    auto FirstName = people[0][0];
    // std::cout<< &FirstName<< std::endl;

    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    p = balance;
    // output each array element's value 
    std::cout << "Array values using pointer " << std::endl; 
    for ( int i = 0; i < 5; i++ ){ 
        std::cout << "*(p + " << i << ") : ";
        std::cout << *(p + i) << std::endl;
    }
    std::cout << "Array values using balance as address " << std::endl;
    for ( int i = 0; i < 5; i++ ) {
        std::cout << "*(balance + " << i << ") : ";
        std::cout << *(balance + i) << std::endl;
    }

    return 0;
}