//
//  Stores.cpp
//  Final Project 1
//
//  Created by Patrick Kranz on 12/4/18.
//  Copyright © 2018 Patrick Kranz. All rights reserved.
//

#include "Stores.hpp"

Store::Store(){
    id = -1;
    name = "";
    address = "";
    ytd_sales = -1;
    ly_sales = -1;
    pricing = 'z';
    lon = 0;
    lat = 0;
    left = NULL;
    right = NULL;
}

Store::Store(long ID, string Name, string Address, double Ytd, double Ly, char Pricing, double Lon, double Lat){
    id = ID;
    name = Name;
    address = Address;
    ytd_sales = Ytd;
    ly_sales = Ly;
    pricing = Pricing;
    lon = Lon;
    lat = Lat;
    left = NULL;
    right = NULL;
}

void Store::print_info(){
    cout<<"ID:"<<id<<endl;
    cout<<"Name:"<<name<<endl;
    cout<<"Address:"<<address<<endl;
    cout<<"------------------------------\n------------------------------\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Btree::Btree(){
    root = NULL;
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
void Btree::insert(Store key){
    if(root==NULL)
        root = &key;
    else
        insert(root,key);
}

void Btree::insert(Store* leaf, Store key){
    Store* temp = new Store(key.id,key.name,key.address,key.ytd_sales,key.ly_sales,key.pricing,key.lon,key.lat);
    
    if(key.id<leaf->id){
        if(leaf->left!=NULL)
            insert(leaf->left,key);
        else{
            leaf->left = temp;
        }
    }
    else if(key.id>leaf->id){
        if(leaf->right!=NULL)
            insert(leaf->right,key);
        else{
            leaf->right = temp;
        }
    }
    else
        return;
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
void Btree::print_inorder(){
    print_inorder(root);
    cout<<endl;
}

void Btree::print_inorder(Store* leaf){
    if(leaf!=NULL){
        print_inorder(leaf->left);
        leaf->print_info();
        print_inorder(leaf->right);
    }
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
Store* Btree::search(long Id){
    return search(root,Id);
}

Store* Btree::search(Store* leaf, long Id){
    if(leaf!=NULL){
        if(Id == leaf->id)
            return leaf;
        else if(Id<leaf->id)
            return search(leaf->left,Id);
        else
            return search(leaf->right,Id);
    }
    else
        return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
linkedList::linkedList(){
    head = NULL;
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
void linkedList::insert(Store key){
    Store* temp_store = new Store(key.id, key.name, key.address, key.ytd_sales, key.ly_sales, key.pricing,key.lon,key.lat);
    temp_store->right = head;
    Store* temp_node = head;
    
    if(head==NULL){
        temp_store->right = temp_store;
        head = temp_store;
    }
    else{
        while(temp_node->right!=head)
            temp_node = temp_node->right;
        temp_node->right = temp_store;
    }
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
void linkedList::print(){
    if(head==NULL)
        return;
    else{
        Store* temp = head;
        do{
            temp->print_info();
            temp = temp->right;
        }while(temp!=head);
    }
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
void linkedList::order()
{
    // two pointers to index nodes.
    Store* index1 = head;
    Store* index3 = head->right;
    
    // keeps track of the distances between stores
    double distance1;
    double distance2;
    
    do
    {
        // distance1 is the distance between the node pointed to by index1 and the node "next" to the node pointed to by index1
        double x1,y1,x2,y2,x3,y3;
        x1 = index1->lon;
        y1 = index1->lat;
        x2 = index1->right->lon;
        y2 = index1->right->lat;
        distance1 = sqrt((pow(x2-x1,2.0)+ pow(y2-y1,2.0)));
        
        while(index3!=head) //continues until index3 points to the head
        {
            // distance2 is the distance between the node pointed to by index1 and the node pointed to by index3
            x3 = index3->lon;
            y3 = index3->lat;
            distance2 = sqrt((pow(x3-x1,2.0)+ pow(y3-y1,2.0)));
            
            if(distance1 > distance2) //executed if the index3-store is closer to the index1-store than the store currently "next" to the index1 store
            {
                Store store = *index1->right; //used to keep the information of the store next to the index1-store
                
                //swaps the information stored with each node. does not swap the nodes themselves
                index1->right->id = index3->id;
                index1->right->name = index3->name;
                index1->right->address = index3->address;
                index1->right->ytd_sales = index3->ytd_sales;
                index1->right->ly_sales = index3->ly_sales;
                index1->right->lon = index3->lon;
                index1->right->lat = index3->lat;
                
                index3->id = store.id;
                index3->name = store.name;
                index3->address = store.address;
                index3->ytd_sales = store.ytd_sales;
                index3->ly_sales = store.ly_sales;
                index3->lon = store.lon;
                index3->lat = store.lat;
                
                //recalculates distance1 to reflect the change made in the order of the stores
                x2 = index1->right->lon;
                y2 = index1->right->lat;
                distance1 = sqrt((pow(x2-x1,2.0)+ pow(y2-y1,2.0)));
                
                //the pointer is moved to the next node
                index3 = index3->right;
            }
            else
                index3 = index3->right; //pointer is moved to the next node
        }
        index1 = index1->right; //pointer is moved to the "next" store in the list
        index3 = index1->right->right; //pointer is reset to the node 2 away from the index1-node
    }while(index1->right!=head); //loop is terminated once index1 points to the tail node and index3 points to the head node
}
