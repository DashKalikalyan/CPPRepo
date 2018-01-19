#include <iostream>
#include <map>
#include "WordMap.h"

/***** Complete this file. *****/

using namespace std;

WordMap::WordMap()
{
    /***** Complete this member function. *****/
}

WordMap::~WordMap()
{
    /***** Complete this member function. *****/
}

void WordMap::insert(const string text)
{
    /***** Complete this member function. *****/
   map<string, Word>::iterator it = data.find(text);
    if (it != data.end())
    {
        data[text].inc_count();
    } 
    else 
    {
        it=data.begin();
        data.insert ( std::pair<string,Word>(text,Word(text)) );
    }
}

Word WordMap::search(const string text)
{
    /***** Complete this member function. *****/
    
   map<string, Word>::iterator it = data.find(text);
    if (it != data.end())
    {
        return data[text];
    }
    
}

    int WordMap::get_size()
    {
       return data.size();
    }
    map<string,Word> WordMap::get_data()
    {
       return data;
    }