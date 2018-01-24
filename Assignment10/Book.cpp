/***** Complete this file. *****/
#include "Book.h"
#include<iostream>
#include<string>
using namespace std;

Book::Book()

{



}



Book::Book(string isbn, string last, string first, string title)



{



var_isbn=isbn;

var_last=last;

var_first=first;

var_title=title;

//var_category=category;

}



Book::~Book()

{



}



void Book::getdata()

{	cout<<"  Book{ISBN="

<<var_isbn

<<", last="

<<var_last

<<", first="

<<var_first

<<", title="

<<var_title<<"}"<<endl;



}



string Book ::getisbn()

{

return var_isbn;

}



string Book ::getlast()

{

return var_last;

}



//string Book::getcategory()

//{

//	return var_category;

//}









//// Status codes.

//enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

//

///**

// * Find the book in the catalog with the given ISBN.

// * Use a binary search.

// * @param isbn the ISBN.

// * @param catalog the vector of book records.

// * @return the vector index of the book if found, else return -1.

// */

//int find(const string isbn, const vector<Book>& catalog);

//

//const string INPUT_FILE_NAME = "commands.in";

//

///**

// * The main. Open the command input file and loop to process commands.

// */
