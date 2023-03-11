#include<iostream>
#include <conio.h>

using namespace std;

struct node{
    int x;
    node* next;
    node* prev;
};

node *head, *tail;

void insertFirst(int data){
    node *baru;
    baru = new node;
    if(head == NULL){
        head = baru;
        baru -> prev = NULL;
        baru -> x = data;
        baru -> next = NULL;
        tail = baru;
    } else {
        baru -> next = head;
        baru -> x = data;
        baru -> prev = NULL;
        head -> prev = baru;
        head = baru;
    }
}

void insertLast(int data){
    node *baru;
    baru = new node;
    baru -> x = data;
    if(head == NULL){
        head = baru;
        baru -> prev = NULL;
        baru -> next = NULL;
        tail = baru;
    } else {
        baru -> prev = tail;
        tail -> next = baru;
        baru -> next = NULL;
        tail = baru;
    }
}

void printList(){
	cout << endl;
    node *temp;
    if(head == NULL){
	cout << "Belum ada data.";
	} else {
		temp = head;
		while(temp != NULL){
			cout << temp -> x << " -> ";
        	temp = temp -> next;
		}
	}
}

void insertAfter(int old, int data){
    node *baru;
    baru = new node;
    node *temp;
    temp = head;
    if(head == NULL){
        cout << "Tidak bisa memasukkan data." << endl;
    }
    if(head == tail){
        if(head -> x != old){
            cout << "Tidak bisa memasukkan data." << endl;
        }
        baru -> x = data;
        head -> next = baru;
        baru -> next = NULL;
        head -> prev = NULL;
        baru -> prev = head;
        tail = baru;
    }
    if(tail -> x == data){
        baru -> next = NULL;
        baru -> prev = tail;
        tail -> next = baru;
        tail = baru;
    }
    while(temp -> x != old){
        temp = temp -> next;
        if(temp == NULL){
            cout << "Tidak bisa memasukkan data." << endl;
            cout << "Tidak ada data." << endl;
        }
    }
    baru -> next = temp -> next;
    baru -> prev = temp;
    baru -> x = data;
    temp -> next -> prev = baru;
    temp -> next = baru;
}

void insertBefore(int old, int data){
    node *baru;
    baru = new node;
    node *temp;
    temp = head;
    if(head == NULL){
        cout<< "Tidak bisa memasukkan data." << endl;
    }
    if(head == tail){
        if(head -> x != old){
            cout << "Tidak bisa memasukkan data." << endl;
        }
        baru -> x = data;
        head -> next = baru;
        baru -> next = NULL;
        head -> prev = NULL;
        baru -> prev = head;
        tail = baru;
    }
    if(tail -> x == data){
        baru -> next = tail;
        baru -> prev = NULL;
        tail -> next = baru;
        tail = baru;
    }
    while(temp -> x != old){
        temp = temp -> next;
        if(temp == NULL){
            cout << "Tidak bisa memasukkan data." << endl;
            cout << "Tidak ada data." << endl;
        }
    }
    baru -> prev = temp -> prev;
    baru -> next = temp;
    baru -> x = data;
    temp -> prev -> next = baru;
    temp -> prev = baru;
}

void deleteFirst(){
    if(head == NULL){
        return;
    }
    if(head == tail){
        node *hapus;
        hapus = head;
        head = NULL;
        tail = NULL;
        delete hapus;
    } else {
        node *hapus;
        hapus = head;
        head = head -> next;
        head -> prev = NULL;
        delete hapus;
    }
}

void deleteLast(){
    if(head==NULL){
    	return;
	}
    if(head==tail){
        node *hapus;
        hapus = head;
        head = NULL;
        tail = NULL;
        delete hapus;
    } else {
        node *hapus;
        hapus = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        delete hapus;
    }
}

void deleteMid(int data){
    node *temp;
    temp = head;
    if(head == tail)
    {
        if(head -> x != data){
            cout << "Tidak dapat menghapus data." << endl;
        }
        head = NULL;
        tail = NULL;
        delete temp;
    }
    if(head -> x == data){
        head = head -> next;
        head -> prev = NULL;
        delete temp;
    } else if(tail -> x == data){
        temp = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        delete temp;
    }
    while(temp -> x != data){
        temp = temp -> next;
        if(temp == NULL){
            cout << "data not found" << endl;

        }
    }
    temp -> next -> prev = temp -> prev;
    temp -> prev -> next = temp -> next;
    delete temp;
}

int main(){
    head = NULL;
    tail = NULL;
    int baru, data, old;
    char pil;
    do{
		system("cls");
		cout << "==================================\n"
			 <<	"=     MENU UTAMA LINKED LIST     =\n"
			 << "==================================\n"
			 << "== 1. Input Data dari Depan     ==\n"
			 << "== 2. Input Data dari Belakang  ==\n"
			 << "== 3. Input Data Setelah Data   ==\n"
			 << "== 4. Input Data Sebelum Data   ==\n"
			 << "== 5. Hapus Data dari Depan     ==\n"
			 << "== 6. Hapus Data dari Belakang  ==\n"
			 << "== 7. Hapus Data dari Tengah    ==\n"
			 << "== 8. Keluar                    ==\n"
			 << "==================================\n";
			 printList();
		cout << "Pilih Menu\t: ";
		cin >> pil;
		switch (pil){
			case 1:{
	            switch(pil){
                    case 1 :{
                        cout << "\nMasukkan data : ";
                        cin >> data;
                        insertFirst(data);
                        printList();
                        getch();
                    }

                }
	            break;
            }
	        case 2:
	            cout << "\nMasukkan data : ";
	            cin >> data;
	            insertLast(data);
	            printList();
	            getch();
	            break;
	        case 3:
	        	printList();
	        	cout << endl;
	            cout << "\nMasukkan setelah   : ";
	            cin >> old;
	            cout << "Masukkan data baru : ";
	            cin >> baru;
	            insertAfter(old, baru);
	            printList();
	            getch();
	            break;
	        case 4:
	        	printList();
	        	cout << endl;
	            cout << "\nMasukkan sebelum   : ";
	            cin >> old;
	            cout << "Masukkan data baru : ";
	            cin >> baru;
	            insertBefore(old, baru);
	            printList();
	            getch();
	            break;
	        case 5:
	        	deleteFirst();
            	printList();
            	getch();
            	break;
            case 6:
            	deleteLast();
            	printList();
            	getch();
            	break;
            case 7:
            	printList();
            	cout << endl;
            	int data;
            	cout << "\nMasukkan data yang ingin dihapus: ";
   				cin >> data;
            	deleteMid(data);
            	printList();
            	getch();
            	break;
            case 8:
            	cout << "\nProgram Selesai";
				break;
			default:
				cout << "\nMasukan tidak valid.\n" << endl;
				cout << "\nPress Any Button to Continue...";
				getch();
		}
	} while (pil != 8);
	return 0;
}