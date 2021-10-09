#include <iostream>
#include <Windows.h>

using namespace std;


int x;                    // x koordinatlar�
int y;                    // y koordinatlar�
int katX;                 //geni�lik
int katY;                 //y�kseklik
int catiKat;              //�at�n�n yuksekli�i

void gotoxy(int x, int y)                                             //Komut sat�r�nda istenilen koordinata gitmek i�in fonksiyonu. �u fonksiyonu kullanmak i�in Windows.h k�t�phanesi yazmam�z laz�m
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class Ev {
public:

	void koordinatlari()                             //x ve y koordinatlar� d��ar�dan alabilmek i�in
	{
		cout << "'X' Koordinat Degeri: ";
		cin >> x;
		cout << "'Y' Koordinat Degeri: ";
		cin >> y;
	}

	class Roof {
	public:

		void bilgiGir() {
			cout << "Cati Yukseklik Degeri: ";
			cin >> catiKat;
		}
		void cati() {                                                  // �at�n�n olu�turan fonksiyonu

			int bosluk = catiKat - 1;
			int kaplama = katX - bosluk * 2;

			for (int i = 0; i < catiKat; i++)
			{
				gotoxy(x + i, y);
				for (int j = 0; j < bosluk; j++)
				{
					cout << " ";
				}
				for (int j = 0; j < kaplama; j++)
				{
					cout << (char)4;
				}
				kaplama += 2;
				bosluk--;
				x--;
				y++;
			}
		};
	}cati;

	class Floor {
	public:

		void bilgiGir() {
			cout << "Genislik Degeri: ";
			cin >> katX;
			cout << "Yukseklik Degeri: ";
			cin >> katY;
		}

		void kat() {                                          //kat�n olu�turan fonsiyonu; 4 for d�ng�s�nden olu�turur, bir duvar i�in bir d�ng�

			gotoxy(x + catiKat, y);                           // catiKat de�i�keni eklendi�i i�in x koordinatlar� ile toplanmal� ki ilk duvar �at� alt�ndan ��ks�n

			for (int i = 0; i < katX; i++)
			{
				cout << (char)219;
			}

			for (int i = 0; i < katY; i++)
			{
				gotoxy(katX + x + catiKat - 1, y + i);
				cout << (char)219;
			}

			for (int i = 0; i < katY + 1; i++)
			{
				gotoxy(x + catiKat, y + i);
				cout << (char)219;
			}

			for (int i = 0; i < katX; i++)
			{
				gotoxy(katX + x + catiKat - i - 1, katY + y);
				cout << (char)219;
			}
		}
	}kat;

	class Door {
	public:

		void kapi() {                                               //kap� olu�turan fonksiyonu, geni�lik ve y�kseklik de�erlerle de�i�tirmelidir

			for (int i = 0; i < katY / 2; i++)
			{
				gotoxy((katX / 2) + (katX / 4), (katY / 2) + y + 1);          // kap�n�n durumu geni�lik ve y�kseklik de�erlerinden etkilenir.

				for (int j = 0; j < katX / 4; j++)
				{
					cout << (char)15;
				}
				y++;
				cout << endl;
			}
		}
	}kapi;
}ev;


int main() {
	//ev s�n�f�n i�erisinde bulunan nesneler ve bu nesnelerin i�erisinde bulunan fonskiyonlar �a��rmal�d�r
	ev.kat.bilgiGir();
	ev.cati.bilgiGir();
	ev.koordinatlari();

	ev.cati.cati();

	ev.kat.kat();
	ev.kapi.kapi();

	cin.get();
	cout << endl;
	system("PAUSE");
	return 0;
}