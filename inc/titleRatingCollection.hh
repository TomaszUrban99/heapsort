#ifndef TITLE_RATING_COLLECTION_HH
#define TITLE_RATING_COLLECTION_HH

#include <cstddef>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>

#include "titleRating.hh"

constexpr int initialSize = 10000;

/*!
    \brief Class titleRatingCollection representing a collection
    of pointers to object of class titleRating.
*/
class titleRatingCollection{

    titleRating** _titleRatingCollection;
    
    /* Number of records being stored in a collection of title ratings */
    int _recordsNumber = 0;

    /* Total amount of fields allocated for vector _titleRatingCollection */
    int _vectorSize = initialSize;

    int reallocate();

    public:

    titleRatingCollection() {
        _titleRatingCollection = new titleRating*[initialSize];
    }

    ~titleRatingCollection() {
        delete [] _titleRatingCollection;
    }

    /*!
        \brief Method for reading data from input file
        \par std::string &filename reference to name input file
        \retval int number of records being read
    */
    int read(char *filename );

    /*!
        \brief Method to print data stored in titleRatingCollection
        \par std::ostream &outputStream- reference to output stream
    */
    void print(std::ostream &outputStream);

};

#endif