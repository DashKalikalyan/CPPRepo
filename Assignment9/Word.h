#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

/***** Modify this file as needed. *****/

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    /**
     * Default constructor.
     */
    Word();

    /**
     * Constructor.
     * Create a word entry with the given text. Initialize the count to 1.
     * @param text the text of the word.
     */
    Word(string text);

    /**
     * Destructor.
     */
    virtual ~Word();
    string gettext();
    void inc_count();
    int get_count();

private:
    string text;
    int count;
};

#endif /* WORD_H_ */