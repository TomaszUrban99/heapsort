#ifndef TITLE_RATING_HH
#define TITLE_RATING_HH

#include <istream>
#include <string>
#include <iostream>
#include <fstream>

class titleRating {
    
    /* Alphanumeric unique identifier */
    std::string _tconst = NULL;

    /* Weighted average of all the individual user ratings */
    int _averageRating;

    /* Number of votes the title has received */
    int _numVotes;

    public:

    std::string& get_tconst () { return _tconst; }

    int& get_averageRating () { return _averageRating; }

    int& get_numVotes () { return _numVotes; }

};

/*!
    \brief Input operator overloading 
*/
std::istream& operator>>( std::istream& input, titleRating& newRecord );

#endif