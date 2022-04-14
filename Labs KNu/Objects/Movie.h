#ifndef __MOVIE_H_
#define __MOVIE_H_

#include <iostream>


class Movie{
public:
        void set_Title(std::string Title);
        void show_Title();
        void set_ProductionYear(unsigned int Year);
        void set_Rating(unsigned int Rate);
        char* get_Title();
        int* get_ProductionYear;
        int* get_Rating();

        void show_ALL();
        unsigned int swap_Rating(unsigned int Rate);
        Movie();
        Movie(char*, unsigned int, unsigned int);
        ~Movie();

private:
    char* m_Title;
    unsigned int m_ProductionYear;
    unsigned int m_Rating;

};


#endif // __MOVIE_H_
