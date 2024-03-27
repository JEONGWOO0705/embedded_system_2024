/*
File : ProductManager.cpp
Created : 2024-03-06
Author: 황정우
*/


#include<iostream>
#include <cstring>
using namespace std;

class Product {
protected:
	string id;
	int price;
	string producer;

public:
	Product(string id, int price, string producer) {
		this->id = id;
		this->price = price;
		this->producer = producer;
	}

	void ShowProductInfo() {
		cout << "ID : " << id << "  Price : " << price << "  Producer : " << producer << endl;
	}
	string GetID() {
		return id;
	}
};

class Book :public Product {
private:
	int ISBN;
	string title;

public:
	Book(string id, int price, string producer, int ISBN, string title) :Product(id, price, producer) {
		this->ISBN = ISBN;
		this->title = title;
	}
	void ShowBookInfo() {
		ShowProductInfo();
		cout << "ISBN : " << ISBN << "  Title : " << title << endl;
	}

};

class Handphone :public Product {
private:
	string model;
	int RAM;

public:
	Handphone(string id, int price, string producer, string model, int RAM) :Product(id, price, producer) {
		this->model = model;
		this->RAM = RAM;
	}
	void ShowHandphoneInfo() {
		ShowProductInfo();
		cout << "Model : " << model << "RAM : " << RAM << endl;
	}
};

class Computer : public Product {
private:
	string model;
	int RAM;

public:
	Computer(string id, int price, string producer, string model, int RAM) :Product(id, price, producer) {
		this->model = model;
		this->RAM = RAM;
	}
	void ShowComputerInfo() {
		ShowProductInfo();
		cout << "Model : " << model << "  RAM : " << RAM << endl;
	}
};

int main(void) {
	string id;
	int price;
	string producer;
	int choice;
	int count = 0;
	int Bcount = 0;
	int Hcount = 0;
	int Ccount = 0;
	Product* product[100];
	Book* book[100];
	Handphone* handphone[100];
	Computer* computer[100];



	while (true) {
		cout << "---------상품 관리 프로그램---------" << endl;
		cout << "1. 상품 추가   2. 상품 조회   3. 상품 검색   4.종료" << endl;
		cin >> choice;

		if (choice == 1) {
			cout << " 물건의 ID(문장열)을 입력해 주세요." << endl;
			cin >> id;
			cout << " 물건의 Price를 입력해 주세요." << endl;
			cin >> price;
			cout << " 물건의 Producer를 입력해 주세요." << endl;
			cin >> producer;
			int ISBN;
			string title;
			cout << "추가할 상품을 선택해 주십시오" << endl;
			cout << "1. Book   2. Handphone   3. Computer   4. exit" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << " 책의 ISBN을 입력해 주세요." << endl;
				cin >> ISBN;

				cout << "책의 Title을 입력해 주세요." << endl;
				cin >> title;

				book[Bcount] = new Book(id, price, producer, ISBN, title);
				book[Bcount]->ShowBookInfo();
				product[count] = book[Bcount];
				Bcount += 1;
				count += 1;
			}
			else if (choice == 2) {
				string model;
				int RAM;
				cout << " 핸드폰의 Model를 입력해 주세요." << endl;
				cin >> model;
				cout << " 핸드폰의 RAM를 입력해 주세요." << endl;
				cin >> RAM;
				handphone[Hcount] = new Handphone(id, price, producer, model, RAM);
				handphone[Hcount]->ShowHandphoneInfo();
				product[count] = handphone[Hcount];
				Hcount += 1;
				count += 1;
			}
			else if (choice == 3) {
				string model;
				int RAM;
				cout << " 컴퓨터의 Model를 입력해 주세요." << endl;
				cin >> model;
				cout << " 컴퓨터의 RAM를 입력해 주세요." << endl;
				cin >> RAM;
				computer[Ccount] = new Computer(id, price, producer, model, RAM);
				computer[Ccount]->ShowComputerInfo();
				product[count] = computer[Ccount];
				Ccount += 1;
				count += 1;
			}
			else if (choice == 4) {
				exit(1);
			}
			else {
				continue;
			}
		}
		else if (choice == 2) {
			cout << "조회할 상품을 선택하세요" << endl;
			cout << "1. 책    2. 핸드폰    3. 컴퓨터" << endl;
			cin >> choice;
			if (choice == 1) {
				for (int i = 0; i < Bcount; i++) {
					book[i]->ShowBookInfo();
				}
			}
			else if (choice == 2) {
				for (int i = 0; i < Hcount; i++) {
					handphone[i]->ShowHandphoneInfo();
				}
			}
			else if (choice == 3) {
				for (int i = 0; i < Ccount; i++) {
					computer[i]->ShowComputerInfo();
				}
			}

		}
		else if (choice == 3) {
			cout << "검색할 상품을 선택하세요" << endl;
			cout << "1. 책    2. 핸드폰    3. 컴퓨터" << endl;
			cin >> choice;
			if (choice == 1) {
				string bid;
				cout << "상품의 ID를 입력해 주세요" << endl;
				cin >> bid;
				for (int i = 0; i < Bcount; i++) {
					if (book[i]->GetID() == bid) {
						book[i]->ShowBookInfo();
					}
					else {}
				}
			}
			else if (choice == 2) {
				string hid;
				cout << "상품의 ID를 입력해 주세요" << endl;
				cin >> hid;
				for (int i = 0; i < Hcount; i++) {
					if (handphone[i]->GetID() == hid) {
						handphone[i]->ShowHandphoneInfo();
					}
					else {}
				}
			}
			else if (choice == 3) {
				string cid;
				cout << "상품의 ID를 입력해 주세요" << endl;
				cin >> cid;
				for (int i = 0; i < Ccount; i++) {
					if (computer[i]->GetID() == cid) {
						computer[i]->ShowComputerInfo();
					}
					else {};
				}
			}
			else if (choice == 4) {
				exit(1);
			}
			else {
				cout << "다시 선택해 주세요" << endl;
				cout << "검색할 상품을 선택하세요" << endl;
				cout << "1. 책    2. 핸드폰    3. 컴퓨터" << endl;
				cin >> choice;
			}
		}
		else if (choice == 4) {
			exit(1);
		}
	}
	return 0;
}