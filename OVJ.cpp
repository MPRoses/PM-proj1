#include <iostream>
#include <list>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int main() {

  // date initialization;

  time_t t = time(NULL);
  struct tm date;
  if (gmtime_r(&t, &date) == NULL) {
    return 1;
  }

  int Dag = date.tm_mday;
  int Maand = date.tm_mon + 1;
  int Jaar = date.tm_year + 1900;
  bool isSchrikkelJaar = (date.tm_year % 4 == 0);

  // sectie 1: geboortejaar

  int Geboortejaar;

  cout << "Geef uw geboortejaar: ";
  cin >> Geboortejaar;

  if (Geboortejaar > Jaar || Geboortejaar <= 0) {
    cout << "Ongeldige geboortejaar" << endl;
    return 1;
  }

  if ((Jaar < (Geboortejaar + 10)) || ((Geboortejaar + 101) < Jaar)) {
    cout << "Je bent of te oud of te jong voor de universiteit, jammer!"
         << endl;
    return 1;
  }

  int Geboortemaand;

  cout << "Geef uw geboortemaand: ";
  cin >> Geboortemaand;

    if (Geboortemaand > 12 || Geboortemaand <= 0) {
    cout << "Ongeldige Geboortemaand" << endl;
    return 1;
  }

  if (Geboortejaar == (Jaar - 10) || Geboortejaar == (Jaar - 101)) {
    if ((Geboortejaar == (Jaar - 10) && Geboortemaand > Maand)) {
      cout << "Je bent te jong!" << endl;
      return 1;
    }
    if ((Geboortejaar == (Jaar - 101) && Geboortemaand < Maand)) {
      cout << "Je bent te oud!" << endl;
      return 1;
    }
  }

  int Geboortedag;

  set<int> Maand31 {1, 3, 5, 7, 8, 10, 12};
  set<int> Maand30 {4, 6, 9, 11};
  set<int> Maand28 {2};

  cout << "Geef uw geboortedag: ";
  cin >> Geboortedag;

  if (Geboortedag == Dag && Geboortemaand == Maand) {
    cout << "Gefeliciteerd!" << endl;
  }


  if (Maand31.find(Maand) != Maand31.end()) {
    if (Geboortedag > 31 || Geboortedag <= 0) {
      cout << "Ongeldige Geboortedag" << endl;
      return 1;
    }
  }

   if (Maand30.find(Maand) != Maand30.end()) {
     if (Geboortedag > 30 || Geboortedag <= 0) {
      cout << "Ongeldige Geboortedag" << endl;
      return 1;
    }
  }
  if (Maand28.find(Maand) != Maand28.end()) {
    // nog checken of 28 / 29 i.v.m. schrikkeljaar
    if (isSchrikkelJaar) {
      if (Geboortedag > 29 || Geboortedag <= 0) {
        cout << "Ongeldige Geboortedag" << endl;
        return 1;
      }
    } else {
      if (Geboortedag > 28 || Geboortedag <= 0) {
        cout << "Ongeldige Geboortedag" << endl;
        return 1;
      }
    }
   
  }

  if ((Geboortejaar == (Jaar - 10) || Geboortejaar == (Jaar - 101)) &&
      Geboortemaand == Maand) {
    if (Geboortejaar == (Jaar - 10) && Geboortedag > Dag) {
      cout << "Je bent te jong!" << endl;
      return 1;
    }
    if (Geboortejaar == (Jaar - 101) && Geboortedag <= Dag) {
      cout << "Je bent te oud!" << endl;
      return 1;
    }
  }

  int LeeftijdJaren = Jaar - Geboortejaar;
  int LeeftijdMaanden = (Maand - Geboortemaand + 12) % 12;

  if (Geboortedag > Dag) {
    LeeftijdMaanden = (Maand - Geboortemaand + 11) % 12;
  }

  if (Geboortemaand > Maand || (Geboortemaand == Maand && Geboortedag >= Dag)) {
    LeeftijdJaren -= 1;
    LeeftijdMaanden = (LeeftijdMaanden + 12) % 12;
  }

  cout << "Je bent " << LeeftijdJaren << " jaar en " << LeeftijdMaanden << " maanden oud." << endl;



  // nu tijd voor sectie 2: het stellen van vragen.
  return 0;


}
