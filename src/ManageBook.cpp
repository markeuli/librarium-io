#include "Book.h"
#include <algorithm>
#include <vector>
#include <iostream>

//commented in case we want to add hardcoded books for demo
/*ManageBook::ManageBook()
{
    //if we had a db: books = readBooksFromFile();
    books = std::vector<Book>();
}*/

void ManageBook::addBook(const Book &book)
{
    books.push_back(book);
}

void ManageBook::addBook()
{
    Book b;
    std::string title, author, isbn, lang, cond, status;
    int tc, id;
    int d;
    
    id = books.size() + 1; //increments, so that each title has a unique id
    b.setBookId(id);
    std::cout << "Enter book title:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, title);
    b.setTitle(title);
    std::cout << "Enter book author:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, author);
    b.setAuthor(author);
    std::cout << "Enter book ISBN:\n";
    std::cin >> isbn;
    b.setISBN(isbn);
    std::cout << "Enter book publication date (Year):\n";
    std::cin >> d;
    b.setPublicationDate(d);
    std::cout << "Enter book total copies:\n";
    std::cin >> tc;
    b.setTotalCopies(tc);
    b.setCopiesAvailable(tc);
    std::cout << "Enter book language:\n";
    std::cin >> lang;
    b.setLanguage(lang);
    std::cout << "Enter book condition:\n";
    std::cin >> cond;
    b.setCondition(cond);
    std::cout << "Enter book status:\n";
    std::cin >> status;
    b.setBookStatus(status);
    books.push_back(b);
}

// Remove a book based on its ID
void ManageBook::removeBook(int bookId)
{
    books.erase(
        remove_if(books.begin(), books.end(),
                    [bookId](const Book &b)
                    {
                        return b.getBookId() == bookId;
                    }),
        books.end());
}

// TEAM: This is how we should edit any entity 
// These are meant to be used in the Menu class
void ManageBook::editBook(int bookID)
{
    //get field to change
    std::cout << "What field would you like to change?\n";
    std::cout << "1. Title\n";
    std::cout << "2. Author\n";
    std::cout << "3. ISBN\n";
    std::cout << "4. None\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    std::string newInfo;
    switch (choice)
    {
    case 1:
        std::cout << "Enter new title:\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newInfo);
        for (auto &b : books)
        {
            if (b.getBookId() == bookID)
            {
                b.setTitle(newInfo);
                return;
            }
        }
        break;

    case 2:
        std::cout << "Enter new author:\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newInfo);
        for (auto &b : books)
        {
            if (b.getBookId() == bookID)
            {
                b.setAuthor(newInfo);
                return;
            }
        }
        break;
    
    case 3:
        std::cout << "Enter new ISBN:\n";
        std::cin >> newInfo;
        for (auto &b : books)
        {
            if (b.getBookId() == bookID)
            {
                b.setISBN(newInfo);
                return;
            }
        }
        break;
    case 4:
        return;
    default:
        std::cout << "Invalid choice\n";
        editBook(bookID);
        break;
    }
}

const std::vector<Book> ManageBook::getBooks() const
{
    return books;
}

void ManageBook::viewBook(int bookID)
{
    for (auto &b : books)
    {
        if (b.getBookId() == bookID)
        {
            std::cout << "Book ID: " << b.getBookId() << std::endl;
            std::cout << "Title: " << b.getTitle() << std::endl;
            std::cout << "Author: " << b.getAuthor() << std::endl;
            std::cout << "ISBN: " << b.getISBN() << std::endl;
            std::cout << "Publication Date: " << b.getPublicationDate() << std::endl;
            std::cout << "Copies Available: " << b.getCopiesAvailable() << std::endl;
            std::cout << "Total Copies: " << b.getTotalCopies() << std::endl;
            std::cout << "Language: " << b.getLanguage() << std::endl;
            std::cout << "Condition: " << b.getCondition() << std::endl;
            std::cout << "Book Status: " << b.getBookStatus() << std::endl;
            return;
        }
    }
    std::cout << "Book not found\n";
}

void ManageBook::viewAllBooks(){
    for (auto& b : books) {
        std::cout << "Book ID: " << b.getBookId() << std::endl;
        std::cout << "Title: " << b.getTitle() << std::endl;
        std::cout << "Author: " << b.getAuthor() << std::endl;
        std::cout << "ISBN: " << b.getISBN() << std::endl;
        std::cout << "Publication Date: " << b.getPublicationDate() << std::endl;
        std::cout << "Copies Available: " << b.getCopiesAvailable() << std::endl;
        std::cout << "Total Copies: " << b.getTotalCopies() << std::endl;
        std::cout << "Language: " << b.getLanguage() << std::endl;
        std::cout << "Condition: " << b.getCondition() << std::endl;
        std::cout << "Book Status: " << b.getBookStatus() << std::endl << std::endl;
    }
}

bool ManageBook::checkOutBook(int bookId)
{
    //returns true if book was checked out successfully
    //returns false if book not found or no copies available
    for (auto &b : books)
    {
        if (b.getBookId() == bookId)
        {
            if (b.getCopiesAvailable() > 0)
            {
                b.setCopiesAvailable(b.getCopiesAvailable() - 1);
                return true;
            }
            else
            {
                std::cout << "No copies available\n";
                return false;
            }
        }
    }
    std::cout << "Book not found\n";
    return false;
}

bool ManageBook::returnBook(int bookId)
{
    //returns true if book was returned successfully
    //returns false if book not found
    for (auto &b : books)
    {
        if (b.getBookId() == bookId)
        {
            b.setCopiesAvailable(b.getCopiesAvailable() + 1);
            return true;
        }
    }
    std::cout << "Book not found\n";
    return false;
}