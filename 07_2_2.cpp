#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* _title, const char* _isbn, int _price) :price(_price)
	{
		title = new char[strlen(_title) + 1];
		isbn = new char[strlen(_isbn) + 1];
		strcpy(title, _title);
		strcpy(isbn, _isbn);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;
public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _key)
		:Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_key) + 1];
		strcpy(DRMKey, _key);
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[]DRMKey;
	}
};

int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "bookjoa123");
	ebook.ShowEBookInfo();

	return 0;
}