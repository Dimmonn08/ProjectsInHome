
#include <iostream>
#include <ctime>
using namespace std;
class Gracz
{
public:
    string nazwa;
    int hp;
    int atak;
    int obrona;
        Gracz()
        {
            hp = 0;
            atak = 0;
            obrona = 0;
        }
        void displayStats()
        {
            cout << "\n=== TWOJA POSTAC ===\n";
            cout << "Nazwa: " << nazwa << endl;
            cout << "HP: " << hp << endl;
            cout << "Atak: " << atak << endl;
            cout << "Obrona: " << obrona << endl;
        }
};
class Potwor
{
public:
    string nazwa;
    int hp;
    int atak;
    int obrona;
    void displayEnemy()
    {
        cout << "\n=== TWOJ WROG ===\n";
        cout << "Nazwa: " << nazwa << endl;
        cout << "HP: " << hp << endl;
        cout << "Atak: " << atak << endl;
        cout << "Obrona: " << obrona << endl;
    }
};
void walka(Gracz& gracz1, Potwor& przeciwnik)
{
    short odp, damageZadanyPrzezGracza, damageZadanyPrzezRywala, szansa = rand() % 100 + 1;
    while (gracz1.hp > 0 && przeciwnik.hp > 0)
    {

        do
        {
            cout << "Spotykasz: " << przeciwnik.nazwa << endl << " co teraz zamierzasz zrobic?" << endl;
            cout << "1. Zaatakuj" << endl;
            cout << "2. Sprobuj uciec" << endl;
            cin >> odp;

        } while (odp != 1 && odp != 2);
        if (odp == 1)
        {
            cout << "Atakujesz !!! " << endl;
            damageZadanyPrzezGracza = gracz1.atak-przeciwnik.obrona;
            if (damageZadanyPrzezGracza < 1)
            {
                damageZadanyPrzezGracza = 1;
            }
            przeciwnik.hp -= damageZadanyPrzezGracza;
            cout << "Zadales " << damageZadanyPrzezGracza << " hp" << endl;
            cout << "potworowi zostalo: " << przeciwnik.hp << " zycia" << endl;
            if (przeciwnik.hp <= 0)
            {
                cout << "Wygrales z bestia gratulacje" << endl;
                return;
            }
            else {
            cout << "Teraz kolej besti: " << endl;
            damageZadanyPrzezRywala = przeciwnik.atak-gracz1.obrona;
            if (damageZadanyPrzezRywala < 1)
            {
                damageZadanyPrzezRywala = 1;
            }
            cout << "Potwor wylosowal: " << damageZadanyPrzezRywala << " ataku" << endl;
            gracz1.hp -= damageZadanyPrzezRywala;
            cout << "Zostalo ci : " << gracz1.hp << endl;
            }
        }
        else if (odp == 2)
        {
            szansa = rand() % 100 + 1;
            if (szansa >= 70)
            {
                cout << "Brawo udalo ci sie uciec ale nastepnym razem uwazaj na siebie" << endl;
                return;
            }
            else if (szansa < 70)
            {
                cout << "Nie udalo ci sie uciec jestes w dupie." << endl;
                cout << "Bestia zlapala cie jak probowales uciec i mocno ci rypla " << endl;
                gracz1.hp -=2;
                if (gracz1.hp <= 0)
                {
                    cout << "Przegrales koniec gry :(" << endl;
                    return;   
                }
            }
        }
    }
    if (gracz1.hp <= 0)
    {
        cout << "Przegrales koniec gry :(" << endl;
        return;
    }
    else if (przeciwnik.hp <= 0)
    {
        cout << "Wygrales z bestia gratulacje" << endl;
        return;
    }
}
int main()
{
    srand(time(NULL));
    short liczbaPuntow=10,liczbaPunktowPodanychPrzezUsera,odp;
    Gracz gracz1;
    Potwor przeciwnik;
    cout << "Witaj w naszej grze RPG" << endl;
    cout << "Podaj nazwe postaci: " << endl;
    cin >> gracz1.nazwa;
    cout << "Teraz masz 10 punktow do rozdania w hp, atak oraz obrone każdy jeden punkt w hp dodaje 10 punktow zycia" << endl;
    do
    {
        cout << "Podaj ile punktow chcesz dodac do swojego hp: " << endl;
        cin >> liczbaPunktowPodanychPrzezUsera;

    } while (liczbaPunktowPodanychPrzezUsera > liczbaPuntow || liczbaPunktowPodanychPrzezUsera < 0);
    gracz1.hp = liczbaPunktowPodanychPrzezUsera * 10;
    liczbaPuntow -= liczbaPunktowPodanychPrzezUsera;
    cout << "Zostalo ci jeszcze: " << liczbaPuntow<<endl;
    do
    {
        cout << "Podaj ile punktow chcesz dodac do swojego ataku: " << endl;
        cin >> liczbaPunktowPodanychPrzezUsera;

    } while (liczbaPunktowPodanychPrzezUsera > liczbaPuntow || liczbaPunktowPodanychPrzezUsera < 0);
    gracz1.atak = liczbaPunktowPodanychPrzezUsera;
    liczbaPuntow -= liczbaPunktowPodanychPrzezUsera;
    cout << "Zostalo ci jeszcze: " << liczbaPuntow << endl;
    do
    {
        cout << "Podaj ile punktow chcesz dodac do swojej obrony: " << endl;
        cin >> liczbaPunktowPodanychPrzezUsera;

    } while (liczbaPunktowPodanychPrzezUsera > liczbaPuntow || liczbaPunktowPodanychPrzezUsera < 0);
    gracz1.obrona = liczbaPunktowPodanychPrzezUsera;
    liczbaPuntow -= liczbaPunktowPodanychPrzezUsera;
    if (liczbaPuntow > 0)
    {
        cout << "Chcesz wykorzystac pozostale punkty czy chcesz zeby przepadly ?" << endl;
        cout << "Jesli chcesz zeby przepadly 1 jezeli nie to 0 (wtedy wstawimy ci reszte do obrony)" << endl;
        cin >> odp;
        if (odp == 0)
        {
            gracz1.obrona += liczbaPuntow;
        }

    }
    cout << "Tak prezentuja sie twoje statystyki: " <<endl;
    gracz1.displayStats();
    cout << "Swietnie co chcialbys zrobic teraz ?" << endl;
    cout << "Idz do lasu - 1" << endl;
    cout << "Wyjdz z gry - 2" << endl;
    cin >> odp;
    if (odp == 1)
    {
        short szansa = (rand()%100)+1;
        if (szansa >= 70)
        {
            przeciwnik.nazwa = "goblin";
            przeciwnik.hp = 20;
            przeciwnik.atak = 2;
            przeciwnik.obrona = 2;
        }
        else if (szansa >= 40 && szansa < 70)
        {
            przeciwnik.nazwa = "Szkielet";
            przeciwnik.hp = 15;
            przeciwnik.atak = 3;
            przeciwnik.obrona = 1;
        }
        else if (szansa >=0 && szansa < 40)
        {
            przeciwnik.nazwa = "Olbrzym";
            przeciwnik.hp = 50;
            przeciwnik.atak = 10;
            przeciwnik.obrona = 20;
        }
        przeciwnik.displayEnemy();
        walka(gracz1, przeciwnik);
        
    }
    else {
        cout << "Dziekujemy za zagranie :)" << endl;
        return 0;
    }

    
    return 0;
}

