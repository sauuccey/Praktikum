#include <iostream>
#include <limits>
#include <conio.h>

using namespace std;

struct node{
	string nama, nim;
	node *next;
};

node *head, *tail;

void printAll(){
	node *bantu;
	if(head == NULL){
	cout << "\nBelum ada data.\n";
	} else {
		bantu = head;
		while(bantu != NULL){
			cout << "\nNAMA \t: " << bantu -> nama << endl;
			cout << "NIM  \t: " << bantu -> nim << endl;
			bantu = bantu -> next;
		}
	}
	cout << "\nPress Any Button to Continue...";
	getch();
}


void inputDepan(){
	node *baru;
	baru = new node;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n=== PROSES MEMASUKKAN DATA ===\n\n";
	cout << "Masukkan Nama\t : "; getline(cin, baru -> nama);
	cout << "Masukkan NIM \t : "; getline(cin, baru -> nim);
	baru -> next = NULL;
	if(head == NULL){
		head = tail = baru;
		head -> next = NULL;
	} else {
		baru -> next = head; //pointer baru ke head sebelumnya
		head = baru;
	}
	cout << "\nData telah dimasukkan\n\n" << "== DATA TERBARU ==";
	printAll();
}

void inputBelakang(){
	node *baru;
	baru = new node;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n=== PROSES MEMASUKKAN DATA ===\n\n";
	cout << "Masukkan Nama\t : "; getline(cin, baru -> nama);
	cout << "Masukkan NIM \t : "; getline(cin, baru -> nim);
	baru -> next = NULL;
	if(head == NULL){
		head = baru;
	} else {
		tail -> next = baru; //ekor ke node baru
	}
	tail = baru;
	tail -> next = NULL;
	cout << "\nData telah dimasukkan\n\n" << "== DATA TERBARU ==";
	printAll();
}

void hapusDepan(){
	node *hapus;
	if (head == NULL){
		cout << "Data masih Kosong\n";
	} else {
		cout<< "\nData telah dihapus\n\n" << "== DATA TERBARU ==\n";
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
		cout << "\nData telah dihapus\n";
		hapus = head;
		head = head -> next;
		delete hapus;
	} else {
		cout<< "\nData telah dihapus\n\n" << "== DATA TERBARU ==\n";
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

int main(){
	int pil;
	do{
		system("cls");
		cout << "==================================\n"
			 <<	"      MENU UTAMA LINKED LIST\n"
			 << "==================================\n"
			 << "== 1. Input Data dari Depan     ==\n"
			 << "== 2. Input Data dari Belakang  ==\n"
			 << "== 3. Hapus Data dari Depan     ==\n"
			 << "== 4. Hapus Data dari Belakang  ==\n"
			 << "== 5. Tampilkan Semua Data      ==\n"
			 << "== 6. Keluar                    ==\n\n"
			 << "Pilih Menu \t: ";
		cin >> pil;
		switch (pil){
			case 1:{
				inputDepan();
				break;
			}
			case 2:{
				inputBelakang();
				break;
			}
			case 3:{
				hapusDepan();
				break;
			}
			case 4:{
				hapusBelakang();
				break;
			}
			case 5:{
				printAll();
				break;
			}
			case 6:{
				cout << "\nProgram Selesai";
				break;
			}
			default:{
				cout << "\nMasukan tidak valid.\n" << endl;
				cout << "\nPress Any Button to Continue...";
				getch();
			}
		}
	} while (pil != 6); 
	return 0;	 
}