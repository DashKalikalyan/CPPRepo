#include<string>
#include "BookList.h"
#include "BookNode.h"
using namespace std;

BookList::BookList(const string name_temp,BookNode* head_temp)
{
    //create();
    name=name_temp;
    if(head==nullptr)
    {
       head=head_temp;
       tail=head_temp;
    }
    else
    {
       //tail->next=head_temp;
       tail=head_temp;
    }
}

void BookList::print()
{
    /***** Complete this function. *****/
}

/***** Complete this file. *****/
