#include <iostream>
#include <conio.h>

using namespace std;

struct node{
	string judul, penerbit, penulis, harga, tahun;
	node *next;
};

node *head, *tail;

void enter(){
	cout << "\nPress Any Button to Continue...";
	getch();
}

void printAll(){
	node *bantu;
	if(head == NULL){
	cout << "\nBelum ada data.\n";
	} else {
		bantu = head;
		cout << " ====== DATA ======" << endl;
		cout << "================================" << endl;
		while(bantu != NULL){
			cout << "Judul        : " << bantu -> judul << endl;
			cout << "Penerbit     : " << bantu -> penerbit << endl;
			cout << "Penulis      : " << bantu -> penulis << endl;
			cout << "Harga        : Rp" << bantu -> harga << endl;
			cout << "Tahun Terbit : " << bantu -> tahun << endl;
			cout << "================================" << endl;
			bantu = bantu -> next;
		}
	}
	enter();
}


void inputDepan(){
	node *baru;
	baru = new node;
	cout << "Masukkan Judul        : "; getline(cin >> ws, baru -> judul);
	cout << "Masukkan Penerbit     : "; getline(cin >> ws, baru -> penerbit);
	cout << "Masukkan Penulis      : "; getline(cin >> ws, baru -> penulis);
	cout << "Masukkan Harga        : Rp"; getline(cin >> ws, baru -> harga);
	cout << "Masukkan Tahun Terbit : "; getline(cin >> ws, baru -> tahun);
	baru -> next = NULL;
	if(head == NULL){
		head = tail = baru;
		head -> next = NULL;
	} else {
		baru -> next = head; //pointer baru ke head sebelumnya
		head = baru;
	}
	cout << "\nData telah dimasukkan " << endl;
	cout << "==== Data Terbaru ====" << endl;
	printAll();
}

void inputBelakang(){
	node *baru;
	baru = new node;
	cout << "Masukkan Judul        : "; getline(cin >> ws, baru -> judul);
	cout << "Masukkan Penerbit     : "; getline(cin >> ws, baru -> penerbit);
	cout << "Masukkan Penulis      : "; getline(cin >> ws, baru -> penulis);
	cout << "Masukkan Harga        : Rp"; getline(cin >> ws, baru -> harga);
	cout << "Masukkan Tahun Terbit : "; getline(cin >> ws, baru -> tahun);
	baru -> next = NULL;
	if(head == NULL){
		head = baru;
	} else {
		tail -> next = baru; //ekor ke node baru
	}
	tail = baru;
	tail -> next = NULL;
	cout << "\nData telah dimasukkan " << endl;
	cout << "==== Data Terbaru ====" << endl;
	printAll();
}

void hapusDepan(){
	node *hapus;
	if (head == NULL){
		cout << "Data masih Kosong\n";
	} else {
		cout << "\nData telah dihapus " << endl;
		cout << "==== Data Terbaru ====" << endl;
		hapus = head;
		head = head -> next;
		delete hapus;
	}
	printAll();
}

void hapusBelakang(){
	node *bantu, *hapus;
	if(head == NULL){
		cout << "Data masih Kosong\n";
	} else if(head == tail){
		cout << "\nData telah dihapus " << endl;
		hapus = head;
		head = head -> next;
		delete hapus;
	} else {
		cout << "\nData telah dihapus " << endl;
		cout << "==== Data Terbaru ====" << endl;
		bantu = head;
		hapus = tail;
		while(bantu -> next != tail){
			bantu = bantu -> next;
		}
		tail = bantu;
		tail -> next = NULL;
		delete hapus;	
	}
	printAll();
}

void menu_utama(){
	cout << "================================" << endl;
	cout <<	"             MENU               " << endl;
	cout << "================================" << endl;
	cout << "== [1] Input Data             ==" << endl;
	cout << "== [2] Hapus Data             ==" << endl;
	cout << "== [3] Tampilkan Semua Data   ==" << endl;
	cout << "== [4] Keluar  		       ==" << endl;
	cout << "================================" << endl;
}
void menu_in(){
	cout << "===================================" << endl;
	cout << "             Menu Input            " << endl;
	cout << "===================================" << endl;
	cout << "== [1] Input Data dari Depan     ==" << endl;
	cout << "== [2] Input Data dari Belakang  ==" << endl;
	cout << "===================================" << endl;
}

void menu_del(){
	cout << "===================================" << endl;
	cout << "             Menu Hapus            " << endl;
	cout << "===================================" << endl;
	cout << "== [1] Hapus Data dari Depan     ==" << endl;
	cout << "== [2] Hapus Data dari Belakang  ==" << endl;
	cout << "===================================" << endl;
}

int main(){
	char pil;
	do{
		system("cls");
		menu_utama();
		cout << "Pilih Menu \t: "; pil = getch(); cout << endl;
		switch (pil){
			case '1':{
				system("cls");
				menu_in();
				cout << "Pilih : "; pil = getch(); cout << endl;
				switch (pil){
					case '1' :{
						inputDepan();
						break;
					}
					case '2' :{
						inputBelakang();
						break;
					}
					default :{
						cout << "\nPilih dengan benar!" << endl;
						enter();
					}
				}
				break;
			}
			case '2':{
				system("cls");
				menu_del();
				cout << "Pilih : "; pil = getch();
				switch (pil){
					case '1' :{
						hapusDepan();
						break;
					}
					case '2' :{
						hapusBelakang();
						break;
					}
					default :{
						cout << "\nPilih dengan benar!" << endl;
						enter();
					}
				}
				break;
			}
			case '3':{
				printAll();
				break;
			}
			case '4':{
				system("cls");
				cout << "\nProgram Selesai";
				enter();
				break;
			}
			default:{
				cout << "\nPilih dengan benar!" << endl;
				enter();
			}
		}
	} while (pil != '4'); 
	return 0;	 
}
