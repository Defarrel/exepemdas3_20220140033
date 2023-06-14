#include <iostream>
#include <vector>
#include <string>
using namespace std;


class pengarang;
class buku;
class penerbit {
public: 
	string nama_penerbit;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) : nama_penerbit(pNama) {
	nama_penerbit;
	}

	void TambahPengarang(pengarang*);
	void cetakPengarang();
};

class pengarang {
public:
	string nama_pengarang;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) : nama_pengarang(pNama) {
	nama_pengarang;
	}

	void TambahPenerbit(penerbit*);
	void cetakPenerbit();
};

class buku {
public:
	string nama_buku;
	vector<pengarang*> daftar_pengarang;
	vector<penerbit*> daftar_penerbit;
	buku(string pNama) : nama_buku(pNama) {}
	void TambahPengarang();
	void Tambahbuku(buku*);	
	void cetakPengarang();
};

void penerbit::TambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakPengarang() {
	cout << "\nDaftar pengarang pada penerbit \"" << this->nama_penerbit << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama_pengarang << "\n";
	}
	cout << endl;
}

void pengarang::TambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);

}

void pengarang::cetakPenerbit() {
	cout << "\nDaftar penerbit yang diikuti \"" << this->nama_pengarang << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama_penerbit << "\n";
	}
	cout << endl;
}

void buku::Tambahbuku(buku* pBuku) {
	daftar_pengarang.push_back(pBuku);

}

void buku::cetakPengarang() {
	cout << "Daftar Buku yang dikarang oleh \"" << this->nama_buku << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama_pengarang << "\n";
	}
	cout << endl;
}


int main() {
	penerbit* VarPenerbit1 = new penerbit("Gama Press");
	penerbit* VarPenerbit2 = new penerbit("Intan Pariwara");
	pengarang* VarPengarang1 = new pengarang("Giga");
	pengarang* VarPengarang2 = new pengarang("Joko");
	pengarang* VarPengarang3 = new pengarang("Ansori");
	pengarang* Varpengarang4 = new pengarang("Lia");
	buku* varBuku1 = new buku("Matematika ");
	buku* varBuku2 = new buku("Multimedia 1");
	buku* varBuku3 = new buku("Fisika");
	buku* varBuku4 = new buku("Algoritma");
	buku* varBuku5 = new buku("Basisdata");
	buku* varBuku6 = new buku("Dasar Pemrograman");

	VarPenerbit1->TambahPengarang(VarPengarang2);
	VarPenerbit1->TambahPengarang(Varpengarang4);
	VarPenerbit1->TambahPengarang(VarPengarang1);
	VarPenerbit2->TambahPengarang(VarPengarang3);
	VarPenerbit2->TambahPengarang(VarPengarang1);
	VarPengarang1->TambahPenerbit(VarPenerbit1);
	VarPengarang1->TambahPenerbit(VarPenerbit2);

	VarPenerbit1->cetakPengarang();
	VarPenerbit2->cetakPengarang();
	VarPengarang1->cetakPenerbit();

	VarPengarang2->(varBuku3);
	VarPengarang2->(varBuku4);
	Varpengarang4->(varBuku5);
	VarPengarang3->(varBuku6);
	VarPengarang1->(varBuku1);
	VarPengarang1->(varBuku2);

	return 0;
}