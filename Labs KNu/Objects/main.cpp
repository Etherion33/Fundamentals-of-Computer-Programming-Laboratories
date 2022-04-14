#include <iostream>
#include "Movie.h"
#include <string>


int main()
{
    std::string Tytul;
    unsigned Year;
    unsigned Rating;
//    Movie movie_Array[3];
//    for(int i=0;i<3;i++)
//    {
//        std::cout<<"Enter Title: ";
//        std::cin>>Tytul;
//        std::cout<<"Enter Year: ";
//        std::cin>>Year;
//        std::cout<<"Enter Rating: ";
//        std::cin>>Rating;
//        movie_Array[i].set_Title(Tytul);
//        movie_Array[i].set_ProductionYear(Year);
//        movie_Array[i].set_Rating(Rating);
//    }
//    for(int i=0;i<3;i++)
//    {
//        movie_Array[i].show_ALL();
//    }
//    movie_Array[1].swap_Rating(5);
//    for(int i=0;i<3;i++)
//    {
//        movie_Array[i].show_ALL();
    Movie* film= new Movie;
    Movie* comedy = new Movie("xd",666,5);
    film->set_Title("sfdsfd");
    film->set_ProductionYear(234);
    film->set_Rating(345);
    film->show_ALL();
    comedy->show_ALL();

    delete(film);
    delete(comedy);


    return 0;
}
