#include "Data.h"

void x()
{
    while (opcja != '0')
    {

        string imie1, nazwisko2;
//int numer_telefonu;
        ofstream dane_rezerwacji("C:\Users\Lenovo\source\repos\danerezerwacji.txt");
        switch (opcja)
        {
            case '1':
            {
                cout << "Dodaj rezerwacje" <<
                     endl;


                cout << "Prosze podac dane osobowe: " <<
                     endl;
                cout << "Imie: " <<
                     endl;
                cin >>
                    imie1;

                if (!dane_rezerwacji.

                        is_open()

                        )
                {
                    cout << "Nie mozna otworzyc pliku" <<
                         endl;
                    return 0;
                }
                dane_rezerwacji << imie1 <<
                                endl;
                cout << "Nazwisko: " <<
                     endl;
                cin >>
                    nazwisko2;
                dane_rezerwacji << nazwisko2 <<
                                endl;
//cout << "Numer telefonu: " << endl;
//cin >> numer_telefonu;
//dane_rezerwacji << numer_telefonu;
                dane_rezerwacji.

                        close();

            }
                break;
        }
    }
}