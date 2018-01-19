#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

WordVector::WordVector()
{
    /***** Complete this member function. *****/
}

WordVector::~WordVector()
{
    /***** Complete this member function. *****/
}

void WordVector::insert(const string text)
{
    bool Count_increment = false;
    vector<Word>::iterator it = data.begin();
    while ((it != data.end()) && ((*it).gettext() <= text))
    {
        if((*it).gettext() == text)
        {
            Count_increment = true;
            break;
        }
         it++;
    }
    if(Count_increment)
    {
        (*it).inc_count();
    } 
    else 
    {
        Word newWord(text);
        data.insert(it, newWord);
    }
    
    
    
}

Word WordVector::search(const string text)
{
    /***** Complete this member function. *****/
   
   for(int i=0; i<data.size(); i++)
    {
       if (data[i].gettext() == text)
       {
         return data[i];
       }
      
    }
    
}

int WordVector::get_size()
{
   return data.size();
}

vector<Word> WordVector:: get_data()
{
   return data;
}