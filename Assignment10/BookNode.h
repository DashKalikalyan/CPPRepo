#ifndef BOOKNODE_H_
#define BOOKNODE_H_
#include<string>
#include "Book.h"
using namespace std;

/**
 * A book node in a linked list.
 */
class BookNode
{
public:
    /**
     * Constructor.
     * @param book this node's book.
     */
    BookNode(Book book_temp);

    /***** Complete this class. *****/

private:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};

#endif /* BOOKNODE_H_ */
