#include <iostream>
#include <Windows.h>

using namespace std;


int x;                    // x koordinatlarý
int y;                    // y koordinatlarý
int katX;                 //geniþlik
int katY;                 //yükseklik
int catiKat;              //çatýnýn yuksekliði

void gotoxy(int x, int y)                                             //Komut satýrýnda istenilen koordinata gitmek için fonksiyonu. Þu fonksiyonu kullanmak için Windows.h kütüphanesi yazmamýz lazým
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class Ev {
public:

	void koordinatlari()                             //x ve y koordinatlarý dýþarýdan alabilmek için
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
		void cati() {                                                  // çatýnýn oluþturan fonksiyonu

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

		void kat() {                                          //katýn oluþturan fonsiyonu; 4 for döngüsünden oluþturur, bir duvar için bir döngü

			gotoxy(x + catiKat, y);                           // catiKat deðiþkeni eklendiði için x koordinatlarý ile toplanmalý ki ilk duvar çatý altýndan çýksýn

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

		void kapi() {                                               //kapý oluþturan fonksiyonu, geniþlik ve yükseklik deðerlerle deðiþtirmelidir

			for (int i = 0; i < katY / 2; i++)
			{
				gotoxy((katX / 2) + (katX / 4), (katY / 2) + y + 1);          // kapýnýn durumu geniþlik ve yükseklik deðerlerinden etkilenir.

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
	//ev sýnýfýn içerisinde bulunan nesneler ve bu nesnelerin içerisinde bulunan fonskiyonlar çaðýrmalýdýr
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