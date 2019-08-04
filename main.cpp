#include <iostream>
#include <fstream>
#include <string>
#include "Stores.hpp"
//#include "CSVReader.h"
using namespace std;
Store id_search(Btree,long);
int prompt();

int main(int argc, char** argv) {
    /*CSVReader *r = new CSVReader("stores.csv", ',');
    Btree aTree;
    linkedList aList;
    for(int i = 0;i<r->getRowsCount();i++){
        Store information =  Store(
                                   r->getCellAsInt(i,0), //author
                                   r->getCellAsString(i,1), //title
                                   r->getCellAsString(i,2), //string
                                   r->getCellAsDouble(i,3), //isbn
                                   r->getCellAsDouble(i,4), //price
                                   r->getCellAsChar(i,5),
                                   r->getCellAsDouble(i,6),
                                   r->getCellAsDouble(i,7)
                                   );
        //aTree.insert(information);
        aList.insert(information);
    }
    */
    Store store1, store2, store3, store4, home ,store5;
    home = Store(000000,"Calip Daires","200 Crossways Park Dr W, Woodbury",0,0,'Z',0,0);
    store1 = Store(123456, "Blue Deli", "329 Crooked Hill Rd, Brentwood", 3592.89, 10453.29, 'A',79,0);
    store2 = Store(478690, "red Deli", "328 Crooked Hill Rd, Brentwood", 5592.89, 20453.29, 'A',80,0);
    store3 = Store(378690, "orange Deli", "330 Crooked Hill Rd, Brentwood", 6592.89, 70453.29, 'A',95,0);
    store4 = Store(978690, "yellow Deli", "320 Crooked Hill Rd, Brentwood", 8592.89, 56453.29, 'A',7,0);
    store5 = Store(978690, "gay Deli", "320 Crooked Hill Rd, Brentwood", 8592.89, 56453.29, 'A',11,0);
    
    Btree aTree;
    linkedList aList;

    aList.insert(home);
    aList.insert(store1);
    aList.insert(store2);
    aList.insert(store3);
    aList.insert(store4);
    aList.insert(store5);
  
    int num;
    do{
        num = prompt(); //asks user to enter a number
        if(num == 1) //executes when the user enters 1
        {
            aList.order();//linked list is ordered by distance
            aList.print(); //elements in the linked list are displayed
        }
        
        else if(num == 2) //executes when the user enters 2
        {
            long Id;
            cout<<"Please Enter The Store ID Number:";
            cin>>Id; //user enters the store ID number
            
            Store store1 = id_search(aTree,Id); //creates a Store object to store information returned from the id_search function
            
            if(store1.id==-1) //executed if the id_search cannot match the user entered ID number
                cout<<"Error-> No Store with ID Number:"<<Id<<endl;
            
            //if id_search returns a store in the binary tree the pricing variable of the store object is viewed
            //to determine which pricing struture to display to the user.
            else{
                store1.print_info();
                string line; //used to print each line of the .txt file
                ifstream afile; //object used to open file for input/output purposes
                
                if(store1.pricing == 'A')
                {
                    afile.open("PricingA.txt");
                    if(afile.is_open()){
                        while(getline(afile,line))
                            cout<<line<<endl;
                        afile.close();
                    }
                    else
                        cout<<"Unable to open file\n";
                }
                
                else if(store1.pricing == 'B')
                {
                    afile.open("PricingB.txt");
                    if(afile.is_open()){
                        while(getline(afile,line))
                            cout<<line<<endl;
                        afile.close();
                    }
                    else
                        cout<<"Unable to open file\n";
                }
                
                else if(store1.pricing == 'C')
                {
                    afile.open("PricingC.txt");
                    if(afile.is_open()){
                        while(getline(afile,line))
                            cout<<line<<endl;
                        afile.close();
                    }
                    else
                        cout<<"Unable to open file\n";
                }
                
                else if(store1.pricing == 'D')
                {
                    afile.open("PricingD.txt");
                    if(afile.is_open()){
                        while(getline(afile,line))
                            cout<<line<<endl;
                        afile.close();
                    }
                    else
                        cout<<"Unable to open file\n";
                }
            }
        }
                
    }while(num!=0);
    return 0;
}

int prompt(){
    int x;
    cout<<"Delivery Route Database"<<endl;
    cout<<"Choose an option\n";
    cout<<"[1] Show Unordered Route\n";
    cout<<"[2] Display Store Pricing Structure (Given Store ID)\n";
    cin>>x; //program pauses to allow the user to enter a value
    return x;
}
Store id_search(Btree aTree,long Id){
    Store* aStore = aTree.search(Id);
    
    if(aStore!=NULL){
        return *aStore;
    }
    else{
        Store store1;
        return store1;
    }
    
}
