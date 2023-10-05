#include <iostream>
#include <string>  // type string
#include <map>     // dictionary library
#include <vector>  // dinamic list library
#include <fstream> // files library
#include <sstream> // "have to search for it"
#include <ctime>   // seed for random
#include <cstdlib> // random library

// using the same class for all instances
using namespace std;

// typedef
typedef struct Book
{
    string title;
    string author;
    string essay;
    int book_id;
} Book;

struct Manga
{
    string title;
    string author;
    string essay;
    int manga_id;
} manga2;

// functions
void print_book_struct(Book book);

int main()
{
    // creating new "objects"
    Book book1;
    Book book2;

    // testing it
    book1.title = "Guida do mochieleiro das galáxias";

    book2 = {
        "Diário de um banana",
        "Não lembro nome",
        "Uma belíssima história de adolecencia",
        390213,
    };

    print_book_struct(book2);

    cout << endl;

    // creating Manga without typedef
    struct Manga manga1;

    manga1 = {
        "One Piece",
        "Oda",
        "One of the best histories ever",
        321324};

    manga2 = {
        "a",
        "b",
        "c",
        12321};


    return 0;
}

void print_book_struct(Book book)
{
    cout << book.title << endl;
    cout << book.author << endl;
    cout << book.essay << endl;
    cout << book.book_id;
}
