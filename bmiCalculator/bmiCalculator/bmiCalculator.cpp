
#include <iostream>
#include <iomanip>
using namespace std;
float bmi(int wagaInput, int wzrostInput)
{

    return wagaInput/(((float)wzrostInput/(float)100)*(float)wzrostInput/(float)100);
}
void skala(float &wynik)
{
    cout << "Twoj wynik Bmi to: " << wynik << endl;
    if (wynik < 18.5)
    {
        cout << "Masz niedowage, jedz wiecej " << endl;
    }
    else if (wynik >= 18.5 && wynik<=24.9)
    {
        cout << "Masz prawidlowo wage, tak trzymaj " << endl;
    }
    else if (wynik >= 25 && wynik <= 29.9)
    {
        cout << "Masz nadwage, albo to liczba miesni albo tluszcz uwazaj lepiej " << endl;
    }
    else if (wynik >= 30 && wynik <= 34.9)
    {
        cout << "Masz otylosc 1 stopnia, zrob cos z tym " << endl;
    }
    else if (wynik >= 35 && wynik <= 39.9)
    {
        cout << "Masz otylosc 2 stopnia, to powazne zrob cos " << endl;
    }
    else if (wynik >=40)
    {
        cout << "Masz otylosc 3 stopnia, zrob cos serio bo moze byc zle " << endl;
    }

}
int main()
{
    short wagaInput, wzrostInput;
    cout << "Witaj w kalkulatorze BMI dzisiaj na podstawie twoich parametrów obliczymy dla ciebie twoj współczynnik BMI" << endl;
    cout << "Najpierw podaj swój wzrost w cm: " << endl;
    cin >> wzrostInput;
    cout << "Swietnie teraz podaj swoja wage w kilogramach: " << endl;
    cin >> wagaInput;
    float wynik = round(bmi(wagaInput, wzrostInput)*10)/10;
    skala(wynik);
}

