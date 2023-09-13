#ifndef TITLE_RATING_COLLECTION_HH
#define TITLE_RATING_COLLECTION_HH

#include <vector>

#include "titleRating.hh"

/*!
    \brief Class titleRatingCollection representing a collection
    of pointers to object of class titleRating.
*/
class titleRatingCollection{

    std::vector<titleRating*> _titleRatingCollection;
    
    /* Number of records being stored in a collection of title ratings */
    int _recordsNumber;

    /* Total amount of fields allocated for vector _titleRatingCollection */
    int _vectorSize; 

    public:


};

#endif