#ifndef BOOK_H_
#define BOOK_H_
#include<string>
using namespace std;

/**
 * The Book class.
 */
class Book
{
    /***** Complete this class. *****/
  public:



//enum Category { FICTION, HISTORY, TECHNICAL, NONE };



    Book();



    Book(string isbn, string last, string first, string title);



    ~Book();



    void getdata();



    string getisbn();

    string getlast();

    //string getcategory();



private:





string var_isbn;

string var_last;

string var_first;

string var_title;

//string var_category;




  
};

#endif /* BOOK_H_ */
