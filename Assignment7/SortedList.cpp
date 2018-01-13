#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    /***** Complete this function. *****/
    data.push_front(Node(value));
}

void SortedList::append(const long value)
{
    /***** Complete this function. *****/
    data.push_back(Node(value));
}

void SortedList::remove(const int index)
{
    /***** Complete this function. *****/
    list<Node>::iterator it = data.begin();
    advance(it,index);
    
    data.erase(it);
}

void SortedList::insert(const long value)
{
    /***** Complete this function. *****/
    //data.push_back(Node(value));
    list<Node>::iterator it=data.begin();
  
    
   
  

 bool inserted = false;
   
   

       for(int i=0;i<data.size();i++)
       {
          if((*it).get_value() > value)
          {
      
             inserted =true;
             data.insert(it,value);
             
             break;
         }
         it++;
       }
       if(!inserted) 
       {
          data.push_back(Node(value));
       }
  
  
  
} 
       
Node SortedList::at(const int index)
{
    /***** Complete this function. *****/
    list<Node>::iterator it=data.begin();
    advance(it,index);
    return (*it);
}
