#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0) {}
Word::Word(string text) : text(text), count(1) {}

Word::~Word() {}
string Word::gettext()
{
   return text;
}
void Word::inc_count()
{
   count++;
}
int Word::get_count()
{
   return count;
}