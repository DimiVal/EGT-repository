/*
 * Operations.cpp
 *
 *  Created on: 25.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Operations.h"

Operations::Operations() {
	// TODO Auto-generated constructor stub
}

Operations::~Operations() {
	// TODO Auto-generated destructor stub
}

const vector<Book*>& Operations::getStore() const {
	return store;
}

void Operations::setStore(const vector<Book*>& store) {
	this->store = store;
}

void Operations::print() const {
	for(unsigned int i = 0; i < store.size(); i++){
		store[i]->print();
		cout << endl;
	}
}

void Operations::XmlToVector(const char* b){
	pugi::xml_document doc;
	if(!doc.load_file(b)){
		cerr << "File could not be read!" << endl;
		exit(1);
	}else{
		cout << "The file is read successfully." << endl;
	}
	pugi::xml_node books = doc.child("books");
	for(pugi::xml_node article = books.first_child(); article; article = article.next_sibling()){
		Book *bookstore = new Book;
		bookstore->setTitle(article.child("title").text().as_string());
		bookstore->setLanguage(article.child("title").attribute("lang").as_string());
		bookstore->setAuthor(article.child("author").text().as_string());
		bookstore->setYearEdition(article.child("year").text().as_int());
		bookstore->setPrice(article.child("price").text().as_double());

		store.push_back(bookstore);
	}
	if (store.size() != 0){
		cout << "Vector is full.\n" << endl;
	}else{
		cout << "Vector is empty!\n" << endl;;
	}
}

const Book& Operations::TheCheapestBook() const{
	if(!store.empty()){
		double minPrice = 100.00;
		Book *books = store[0];
		for (unsigned int i = 0; i < store.size(); i++){
				if(minPrice < store[i]->getPrice()){
					minPrice = store[i]->getPrice();
					books = store[i];
			}
		}
		return *books;
	}else{
		cerr << "The vector is empty." << endl;
	}
}


const Book& Operations::TheMostExpensiveBook() const{
	if(!store.empty()){
		double maxPrice = 0.00;
		Book *books = store[0];
		for (unsigned int i = 0; i < store.size(); i++){
			if (maxPrice < store[i]->getPrice()){
				maxPrice = store[i]->getPrice();
				books = store[i];
			}
		}
		return *books;
	}else{
		cerr << "The vector is empty." << endl;
	}
}

void Operations::SearchBook(string title) {


}
