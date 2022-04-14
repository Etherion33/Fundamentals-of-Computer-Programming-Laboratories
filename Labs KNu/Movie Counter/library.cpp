#include "library.h"
#include "Movie.h"
#include <cstring>
#include <cstdlib>


Library::Library()
{
    m_arrayOfMovies = new Movie[MAX_NO_MOVIES];
    if(m_arrayOfMovies==NULL)
    {
        std::cout<<"Allocation of memory failed!\n";
    }
    else{
        std::cout<<"Allocation of memory complete!\n";
    }
}


Library::~Library()
{
    delete[] m_arrayOfMovies;
    std::cout << "Deallocation of memory complete!";
}

Library::Insert_to_Library(int index,char* title, unsigned int year, unsigned int rating)
{
    m_arrayOfMovies[index].set_Title(title);
    m_arrayOfMovies[index].set_ProductionYear(year);
    m_arrayOfMovies[index].set_Rating(rating);
}

Library::Show_Library()
{

}
Library & Library::operator = (const Library & element)
{
    operator=(element);
    return *this;
}













