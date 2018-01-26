/**
 * A list of book nodes.
 */
 #ifndef BOOKLIST_H_
 #include<string>
 #include "BookNode.h"
 using namespace std;
 
class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name,BookNode* head_temp);

    /**
     * Print the list.
     */
    void print();
    
    /***** Complete this class. *****/

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */
