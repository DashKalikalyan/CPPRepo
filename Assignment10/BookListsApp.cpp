#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include "BookNode.h"
#include "BookList.h"
#include<vector>
using namespace std;

const string CATEGORIES_FILE_NAME = "categories.txt";

/**
 * The main. Create and print the book lists.
 */
int main()

{
   cout<<endl;
    //cout<<"here";

	enum Category { FICTION, HISTORY, TECHNICAL, NONE };
	   vector<Book> catalogScience;  // book catalog
	  vector<Book> catalogMystery;
	vector<Book> catalogChildrens;
	  vector<Book> catalogHistory;
	vector<Book> catalog;
	   vector<Book> ::iterator Iter;
	   string isbn,last,first,title;
	   string read_var1,read_var2,read_var3;
	   string isbn_to_delete;
	   bool book_presence=0;
	   bool put_in_middle=0;
	   bool book_presence_dummy=0;
	   bool put_in_middle_dummy=0;

	   char command;


	   int i=0;
	   ifstream input;
	   string command_string="";

		ifstream inputForCategory;
		inputForCategory.open("categories.txt");
		string typeString[4];
		int typeStringNo=0;
		while(typeStringNo<4)
		{
		inputForCategory>>typeString[typeStringNo];
			typeString[typeStringNo]=typeString[typeStringNo]+".txt";
			typeStringNo++;
		}

// 		for(int i=0;i<4;i++)
// 		{
// 			cout<<typeString[i]<<endl;
// 		}

		for(int bookOfCatagory=0;bookOfCatagory<4;bookOfCatagory++)
		{



	   input.open(typeString[bookOfCatagory]);
	   if (input.fail())
	   {
	       cout << "Failed to open " << typeString[bookOfCatagory] << endl;
	       return -1;
	   }

	   if(typeString[bookOfCatagory]=="science.txt")
	   {
		   while(!input.eof())
		     {
		  	   //input>>command;
		  	  // cout<<endl;
		  	   //cout<<command;

		  		   //cout<<" ";
		  		   //cout<<"Inserted at index ";
		  		   getline(input,isbn,',');
		  		   getline(input,last,',');
		  		   getline(input,first,',');
		  		   getline(input,title,'\n');
		  		   //getline(input,category,'\n');
		  		   //isbn=isbn.substr(1,isbn.length()-1);

		  		   for(int i=0;i<catalogScience.size();i++)
		  		   {
		  			   if(catalogScience[i].getisbn()==isbn)
		  			   {
		  				   //cout<<i<<": ";
		  				   //catalogScience[i].getdata();
		  				   //cout<<"*** Duplicate ISDN ***"<<endl;
		  				   book_presence=1;

		  			   }

		  		   }

		  		   if(!book_presence)
		  		   {
		  			   int size_of_vec=catalogScience.size();
		  			   for(int j=0;j<size_of_vec;j++)
		  			   {

		  				  // string demo1=((catalog[j].getisbn()).substr(4,5));
		  				  // string demo2=(isbn.substr(4,5));
		  //				   int convert1=stoi(demo1);
		  //				   int convert2=stoi(demo2);

		  				   if((catalogScience[j].getisbn())>isbn)
		  				   {
		  					   catalogScience.insert(catalogScience.begin()+j,Book(isbn,last,first,title));
		  					   //cout<<j<<": ";
		  					  // catalogScience[j].getdata();
		  					   put_in_middle=1;
		  					   i++;
		  					   break;


		  				   }


		  			   }

		  			   if(!put_in_middle)
		  			   {
		  				   catalogScience.push_back(Book(isbn,last,first,title));
		  				   //cout<<i<<": ";
		  				   //catalogScience[i].getdata();
		  				   i++;
		  			   }
		  			   put_in_middle=0;
		  		   }
		  		   book_presence=0;
		  		   
		  		   
		  		 for(int i=0;i<catalog.size();i++)
		  		 	  		   {
		  		 	  			   if(catalog[i].getisbn()==isbn)
		  		 	  			   {
		  		 	  				   //cout<<i<<": ";
		  		 	  				   //catalog[i].getdata();
		  		 	  				   //cout<<"*** Duplicate ISDN ***"<<endl;
		  		 	  				   book_presence_dummy=1;

		  		 	  			   }

		  		 	  		   }

		  		 	  		   if(!book_presence_dummy)
		  		 	  		   {
		  		 	  			   int size_of_vec=catalog.size();
		  		 	  			   for(int j=0;j<size_of_vec;j++)
		  		 	  			   {

		  		 	  				  // string demo1=((catalog[j].getisbn()).substr(4,5));
		  		 	  				  // string demo2=(isbn.substr(4,5));
		  		 	  //				   int convert1=stoi(demo1);
		  		 	  //				   int convert2=stoi(demo2);

		  		 	  				   if((catalog[j].getisbn())>isbn)
		  		 	  				   {
		  		 	  					   catalog.insert(catalog.begin()+j,Book(isbn,last,first,title));
		  		 	  					   //cout<<j<<": ";
		  		 	  					  // catalog[j].getdata();
		  		 	  					   put_in_middle_dummy=1;
		  		 	  					   i++;
		  		 	  					   break;


		  		 	  				   }


		  		 	  			   }

		  		 	  			   if(!put_in_middle_dummy)
		  		 	  			   {
		  		 	  				   catalog.push_back(Book(isbn,last,first,title));
		  		 	  				   //cout<<i<<": ";
		  		 	  				   //catalog[i].getdata();
		  		 	  				   i++;
		  		 	  			   }
		  		 	  			   put_in_middle_dummy=0;
		  		 	  		   }
		  		 	  		   book_presence_dummy=0;















		  	   }
		     {
		  		   //cout<<" ";
		  		   cout<<"Book list: science\n"<<endl;
		  		   for(int i=1;i<catalogScience.size();i++)
		  		   {
		  			   catalogScience[i].getdata();
		  		   }
		  		   cout<<"    ("<<catalogScience.size()-1<< " books)"<<endl<<endl;


		  	   }

		  	input.close();

	   }
	   else if(typeString[bookOfCatagory]=="history.txt")
	   {
		   while(!input.eof())
		     {
		  	   //input>>command;
		  	  // cout<<endl;
		  	   //cout<<command;

		  		   //cout<<" ";
		  		   //cout<<"Inserted at index ";
		  		   getline(input,isbn,',');
		  		   getline(input,last,',');
		  		   getline(input,first,',');
		  		   getline(input,title,'\n');
		  		   //getline(input,category,'\n');
		  		   //isbn=isbn.substr(1,isbn.length()-1);

		  		   for(int i=0;i<catalogHistory.size();i++)
		  		   {
		  			   if(catalogHistory[i].getisbn()==isbn)
		  			   {
		  				   //cout<<i<<": ";
		  				   //catalogHistory[i].getdata();
		  				  // cout<<"*** Duplicate ISDN ***"<<endl;
		  				   book_presence=1;

		  			   }

		  		   }

		  		   if(!book_presence)
		  		   {
		  			   int size_of_vec=catalogHistory.size();
		  			   for(int j=0;j<size_of_vec;j++)
		  			   {

		  				  // string demo1=((catalog[j].getisbn()).substr(4,5));
		  				  // string demo2=(isbn.substr(4,5));
		  //				   int convert1=stoi(demo1);
		  //				   int convert2=stoi(demo2);

		  				   if((catalogHistory[j].getisbn())>isbn)
		  				   {
		  					   catalogHistory.insert(catalogHistory.begin()+j,Book(isbn,last,first,title));
		  					  // cout<<j<<": ";
		  					   //catalogHistory[j].getdata();
		  					   put_in_middle=1;
		  					   i++;
		  					   break;


		  				   }


		  			   }

		  			   if(!put_in_middle)
		  			   {
		  				   catalogHistory.push_back(Book(isbn,last,first,title));
		  				   //cout<<i<<": ";
		  				   //catalogHistory[i].getdata();
		  				   i++;
		  			   }
		  			   put_in_middle=0;
		  		   }
		  		   book_presence=0;

		  		   
			  		 for(int i=0;i<catalog.size();i++)
			  		 	  		   {
			  		 	  			   if(catalog[i].getisbn()==isbn)
			  		 	  			   {
			  		 	  				   //cout<<i<<": ";
			  		 	  				   //catalog[i].getdata();
			  		 	  				   //cout<<"*** Duplicate ISDN ***"<<endl;
			  		 	  				   book_presence_dummy=1;

			  		 	  			   }

			  		 	  		   }

			  		 	  		   if(!book_presence_dummy)
			  		 	  		   {
			  		 	  			   int size_of_vec=catalog.size();
			  		 	  			   for(int j=0;j<size_of_vec;j++)
			  		 	  			   {

			  		 	  				  // string demo1=((catalog[j].getisbn()).substr(4,5));
			  		 	  				  // string demo2=(isbn.substr(4,5));
			  		 	  //				   int convert1=stoi(demo1);
			  		 	  //				   int convert2=stoi(demo2);

			  		 	  				   if((catalog[j].getisbn())>isbn)
			  		 	  				   {
			  		 	  					   catalog.insert(catalog.begin()+j,Book(isbn,last,first,title));
			  		 	  					   //cout<<j<<": ";
			  		 	  					  // catalog[j].getdata();
			  		 	  					   put_in_middle_dummy=1;
			  		 	  					   i++;
			  		 	  					   break;


			  		 	  				   }


			  		 	  			   }

			  		 	  			   if(!put_in_middle_dummy)
			  		 	  			   {
			  		 	  				   catalog.push_back(Book(isbn,last,first,title));
			  		 	  				   //cout<<i<<": ";
			  		 	  				   //catalog[i].getdata();
			  		 	  				   i++;
			  		 	  			   }
			  		 	  			   put_in_middle_dummy=0;
			  		 	  		   }
			  		 	  		   book_presence_dummy=0;













		  	   }
		     {
		  		   //cout<<" ";
		  		   cout<<"Book list: history\n"<<endl;
		  		   for(int i=1;i<catalogHistory.size();i++)
		  		   {
		  			   catalogHistory[i].getdata();
		  		   }
		  		   cout<<"    ("<<catalogHistory.size()-1<<" books)"<<endl<<endl;
		  	   }

		  	input.close();

	   }
	   else if(typeString[bookOfCatagory]=="mystery.txt")
	   {
		   while(!input.eof())
		     {
		  	   //input>>command;
		  	  // cout<<endl;
		  	   //cout<<command;

		  		   cout<<" ";
		  		   //cout<<"Inserted at index ";
		  		   getline(input,isbn,',');
		  		   getline(input,last,',');
		  		   getline(input,first,',');
		  		   getline(input,title,'\n');
		  		   //getline(input,category,'\n');
		  		   //isbn=isbn.substr(1,isbn.length()-1);

		  		   for(int i=0;i<catalogMystery.size();i++)
		  		   {
		  			   if(catalogMystery[i].getisbn()==isbn)
		  			   {
		  				   //cout<<i<<": ";
		  				  // catalogMystery[i].getdata();
		  				   //cout<<"*** Duplicate ISDN ***"<<endl;
		  				   book_presence=1;

		  			   }

		  		   }

		  		   if(!book_presence)
		  		   {
		  			   int size_of_vec=catalogMystery.size();
		  			   for(int j=0;j<size_of_vec;j++)
		  			   {

		  				  // string demo1=((catalog[j].getisbn()).substr(4,5));
		  				  // string demo2=(isbn.substr(4,5));
		  //				   int convert1=stoi(demo1);
		  //				   int convert2=stoi(demo2);

		  				   if((catalogMystery[j].getisbn())>isbn)
		  				   {
		  					   catalogMystery.insert(catalogMystery.begin()+j,Book(isbn,last,first,title));
		  					  // cout<<j<<": ";
		  					   //catalogMystery[j].getdata();
		  					   put_in_middle=1;
		  					   i++;
		  					   break;


		  				   }


		  			   }

		  			   if(!put_in_middle)
		  			   {
		  				   catalogMystery.push_back(Book(isbn,last,first,title));
		  				 //  cout<<i<<": ";
		  				  // catalogMystery[i].getdata();
		  				   i++;
		  			   }
		  			   put_in_middle=0;
		  		   }
		  		   book_presence=0;


		  		   
			  		 for(int i=0;i<catalog.size();i++)
			  		 	  		   {
			  		 	  			   if(catalog[i].getisbn()==isbn)
			  		 	  			   {
			  		 	  				   //cout<<i<<": ";
			  		 	  				   //catalog[i].getdata();
			  		 	  				   //cout<<"*** Duplicate ISDN ***"<<endl;
			  		 	  				   book_presence_dummy=1;

			  		 	  			   }

			  		 	  		   }

			  		 	  		   if(!book_presence_dummy)
			  		 	  		   {
			  		 	  			   int size_of_vec=catalog.size();
			  		 	  			   for(int j=0;j<size_of_vec;j++)
			  		 	  			   {

			  		 	  				  // string demo1=((catalog[j].getisbn()).substr(4,5));
			  		 	  				  // string demo2=(isbn.substr(4,5));
			  		 	  //				   int convert1=stoi(demo1);
			  		 	  //				   int convert2=stoi(demo2);

			  		 	  				   if((catalog[j].getisbn())>isbn)
			  		 	  				   {
			  		 	  					   catalog.insert(catalog.begin()+j,Book(isbn,last,first,title));
			  		 	  					   //cout<<j<<": ";
			  		 	  					  // catalog[j].getdata();
			  		 	  					   put_in_middle_dummy=1;
			  		 	  					   i++;
			  		 	  					   break;


			  		 	  				   }


			  		 	  			   }

			  		 	  			   if(!put_in_middle_dummy)
			  		 	  			   {
			  		 	  				   catalog.push_back(Book(isbn,last,first,title));
			  		 	  				   //cout<<i<<": ";
			  		 	  				   //catalog[i].getdata();
			  		 	  				   i++;
			  		 	  			   }
			  		 	  			   put_in_middle_dummy=0;
			  		 	  		   }
			  		 	  		   book_presence_dummy=0;












		  	   }
		     {
		  		   //cout<<" ";
		  		   cout<<"Book list: mystery\n"<<endl;
		  		   for(int i=1;i<catalogMystery.size();i++)
		  		   {
		  			   catalogMystery[i].getdata();
		  		   }
		  		   cout<<"    ("<<catalogMystery.size()-1<<" books)"<<endl<<endl;
		  	   }

		  	input.close();

	   }
	   else if(typeString[bookOfCatagory]=="childrens.txt")
	   {
		   while(!input.eof())
		     {
		  	   //input>>command;
		  	  // cout<<endl;
		  	   //cout<<command;

		  		   //cout<<" ";
		  		   //cout<<"Inserted at index ";
		  		   getline(input,isbn,',');
		  		   getline(input,last,',');
		  		   getline(input,first,',');
		  		   getline(input,title,'\n');
		  		   //getline(input,category,'\n');
		  		   //isbn=isbn.substr(1,isbn.length()-1);

		  		   for(int i=0;i<catalogChildrens.size();i++)
		  		   {
		  			   if(catalogChildrens[i].getisbn()==isbn)
		  			   {
		  				  // cout<<i<<": ";
		  				   //catalogChildrens[i].getdata();
		  				   //cout<<"*** Duplicate ISDN ***"<<endl;
		  				   book_presence=1;

		  			   }

		  		   }

		  		   if(!book_presence)
		  		   {
		  			   int size_of_vec=catalogChildrens.size();
		  			   for(int j=0;j<size_of_vec;j++)
		  			   {

		  				  // string demo1=((catalog[j].getisbn()).substr(4,5));
		  				  // string demo2=(isbn.substr(4,5));
		  //				   int convert1=stoi(demo1);
		  //				   int convert2=stoi(demo2);

		  				   if((catalogChildrens[j].getisbn())>isbn)
		  				   {
		  					   catalogChildrens.insert(catalogChildrens.begin()+j,Book(isbn,last,first,title));
		  					   //cout<<j<<": ";
		  					   //catalogChildrens[j].getdata();
		  					   put_in_middle=1;
		  					   i++;
		  					   break;


		  				   }


		  			   }

		  			   if(!put_in_middle)
		  			   {
		  				   catalogChildrens.push_back(Book(isbn,last,first,title));
		  				   //cout<<i<<": ";
		  				  // catalogChildrens[i].getdata();
		  				   i++;
		  			   }
		  			   put_in_middle=0;
		  		   }
		  		   book_presence=0;


		  		   
			  		 for(int i=0;i<catalog.size();i++)
			  		 	  		   {
			  		 	  			   if(catalog[i].getisbn()==isbn)
			  		 	  			   {
			  		 	  				   //cout<<i<<": ";
			  		 	  				   //catalog[i].getdata();
			  		 	  				   //cout<<"*** Duplicate ISDN ***"<<endl;
			  		 	  				   book_presence_dummy=1;

			  		 	  			   }

			  		 	  		   }

			  		 	  		   if(!book_presence_dummy)
			  		 	  		   {
			  		 	  			   int size_of_vec=catalog.size();
			  		 	  			   for(int j=0;j<size_of_vec;j++)
			  		 	  			   {

			  		 	  				  // string demo1=((catalog[j].getisbn()).substr(4,5));
			  		 	  				  // string demo2=(isbn.substr(4,5));
			  		 	  //				   int convert1=stoi(demo1);
			  		 	  //				   int convert2=stoi(demo2);

			  		 	  				   if((catalog[j].getisbn())>isbn)
			  		 	  				   {
			  		 	  					   catalog.insert(catalog.begin()+j,Book(isbn,last,first,title));
			  		 	  					   //cout<<j<<": ";
			  		 	  					  // catalog[j].getdata();
			  		 	  					   put_in_middle_dummy=1;
			  		 	  					   i++;
			  		 	  					   break;


			  		 	  				   }


			  		 	  			   }

			  		 	  			   if(!put_in_middle_dummy)
			  		 	  			   {
			  		 	  				   catalog.push_back(Book(isbn,last,first,title));
			  		 	  				   //cout<<i<<": ";
			  		 	  				   //catalog[i].getdata();
			  		 	  				   i++;
			  		 	  			   }
			  		 	  			   put_in_middle_dummy=0;
			  		 	  		   }
			  		 	  		   book_presence_dummy=0;












		  	   }
		     {
		  		   //cout<<" ";
		  		   cout<<"Book list: childrens\n"<<endl;
		  		   for(int i=1;i<catalogChildrens.size();i++)
		  		   {
		  			   catalogChildrens[i].getdata();
		  		   }
		  		   cout<<"    ("<<catalogChildrens.size()-1<<" books)"<<endl<<endl;
		  	   }

		  	input.close();

	   }
	  	}

cout<<"Book list: MERGED"<<endl<<endl;


for(int i=1;i<catalog.size();i++)
{
	catalog[i].getdata();
}

cout<<"  ("<<catalog.size()-1<<" books)"<<endl<<endl;
cout<<"Book list: AUTHORS A-M"<<endl<<endl;

int count1=0;
for(int i=1;i<catalog.size();i++)
{
	string inhand=catalog[i].getlast();
	inhand=inhand.substr(0,1);
	if(inhand=="A" || inhand=="B" || inhand=="C" || inhand=="D" || inhand=="E" || inhand=="F" || inhand=="G" || inhand=="H" ||inhand=="I" || inhand=="J" || inhand=="K" || inhand=="L" || inhand=="M")
	{

		catalog[i].getdata();
		count1++;
	   
	}
}

cout<<"  ("<<count1<<" books)"<<endl<<endl;

cout<<"Book list: AUTHORS N_Z"<<endl<<endl;

count1=0;
for(int i=1;i<catalog.size();i++)
{
	string inhand=catalog[i].getlast();
	inhand=inhand.substr(0,1);
	if(inhand=="N" || inhand=="O" || inhand=="P" || inhand=="Q" || inhand=="R" || inhand=="S" || inhand=="T" || inhand=="U" || inhand=="V" || inhand=="W" || inhand=="X" || inhand=="Y" || inhand=="Z")
	{
		catalog[i].getdata();
			count1++;
	}
}

cout<<"  ("<<count1<<" books)"<<endl<<endl;





 	    return 0;

}

/***** Complete this file. *****/
