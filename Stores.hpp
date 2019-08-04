//
//  Stores.hpp
//  Final Project 1
//
//  Created by Patrick Kranz on 12/4/18.
//  Copyright © 2018 Patrick Kranz. All rights reserved.
//

#ifndef Stores_hpp
#define Stores_hpp
#include <cmath>
#include <iostream>
using namespace std;

class Store{
public:
    long id;
    string name;
    string address;
    double ytd_sales;
    double ly_sales;
    char pricing;
    Store* left;
    Store* right;
    Store();
    Store(long, string, string, double, double, char, double, double);
    void print_info();
    double lon;
    double lat;
};


class Btree{
private:
    Store* root;
    void insert(Store*, Store);
    void print_inorder(Store*);
    Store* search(Store*, long);
public:
    Btree();
    Store* search(long);
    void insert(Store);
    void print_inorder();
    
};

class linkedList{
private:
    Store* head;
public:
    void insert(Store);
    linkedList();
    void print();
    void order();
};

#endif /*Stores_hpp*/




























