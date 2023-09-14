#include <iostream>
#include <list>
#include <set>
#include <ctime>
#include <cmath>
#include <string>


using namespace std;

int main() {

  time_t t = time(NULL);
  struct tm date;
  if (gmtime_r(&t, &date) == NULL) {
    return 1;
  }

  int Geboortejaar;
  int Geboortemaand;
  int Geboortedag;
  int Dag = date.tm_mday;
  int Maand = date.tm_mon + 1;
  int Jaar = date.tm_year + 1900;

  bool isSchrikkelJaar = (date.tm_year % 4 == 0);

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

  int LeeftijdJaren = Jaar - Geboortejaar;

  int LeeftijdMaanden = (Maand - Geboortemaand + 12) % 12;

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

  if (Geboortedag > Dag) {
    LeeftijdMaanden = (Maand - Geboortemaand + 11) % 12;
  }

  if (Geboortemaand > Maand || (Geboortemaand == Maand && Geboortedag > Dag)) {
    if (Geboortedag != Dag) {
      LeeftijdJaren -= 1;
    }
    LeeftijdMaanden = (LeeftijdMaanden + 12) % 12;
  }

  cout << "Je bent " << LeeftijdJaren << " jaar en " << LeeftijdMaanden << " maanden oud." << endl;

  int dagenInMaand[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int dagenVoorbijMaand = 0;

  for (int x = 1; x < Geboortemaand; x++) {
    dagenVoorbijMaand += dagenInMaand[x];
  }


  int AantalSchrikkeljarenVoorbij = (Geboortejaar - 1900) / 4;
  int aantalDagenVoorbijVanDeJaren = (Geboortejaar - 1900) * 365 + AantalSchrikkeljarenVoorbij;
  int aantalDagenVoorbijMaandEnDagen = dagenVoorbijMaand + Geboortedag;

  int aantalDagenVoorbijTotaal = aantalDagenVoorbijMaandEnDagen + aantalDagenVoorbijVanDeJaren;

  double dagGeboren = fmod(aantalDagenVoorbijTotaal, 7);

  string dagen[] = {"zo", "m", "d", "w", "d", "v", "za"};

  string gokDag;
  cout << "Op welke dag ben je geboren? Geef in kleine letters de eerste letter van de dag, en ook de tweede als het om za of zo gaat" << endl;
  cin >> gokDag;


  if (gokDag == dagen[static_cast<int>(round(dagGeboren))]) {
    cout << "Goed geraden haha!"<< endl;

  } else {
    cout << "Fout geraden!"
    return 1;
  }


  // nu tijd voor sectie 2: het stellen van vragen.*/

  return 0;


}
