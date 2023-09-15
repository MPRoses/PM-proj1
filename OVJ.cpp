#include <iostream>
#include <list>
#include <ctime>
#include <cmath>
#include <string>


using namespace std;

int main() {
  srand (time(NULL)); // seed creation
  time_t t = time(NULL); // same thing

  // lines voor initialization cTime
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

  int LeeftijdJaren;
  int LeeftijdMaanden;

  int dagenVoorbijMaand = 0; // moet gezet worden als 0
  int aantalSchrikkeljarenVoorbij;
  int aantalDagenVoorbijVanDeJaren;
  int aantalDagenVoorbijMaandEnDagen;
  int aantalDagenVoorbijTotaal;

  bool isSchrikkelJaar = (date.tm_year % 4 == 0);

  int dagenInMaand[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  string dagen[] = {"zo", "m", "d", "w", "d", "v", "za"};
  string gokDag;

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

  cout << "Geef uw geboortedag: ";
  cin >> Geboortedag;

  if (Geboortedag == Dag && Geboortemaand == Maand) {
    cout << "Gefeliciteerd!" << endl; 
  }

  if (Maand == 2 && isSchrikkelJaar) {
    if (Geboortedag > 29 || Geboortedag <= 0) {
      cout << "Ongeldige Geboortedag" << endl;
      return 1;
    }
  } else if (Geboortedag > dagenInMaand[Geboortemaand] || Geboortedag <= 0) {
    cout << "Ongeldige Geboortedag" << endl;
    return 1;
  }

  LeeftijdJaren = Jaar - Geboortejaar;
  LeeftijdMaanden = (Maand - Geboortemaand + 12) % 12;

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

  cout << "Je bent " << LeeftijdJaren << " jaar en " << LeeftijdMaanden << " maanden oud" << endl;

  for (int x = 1; x < Geboortemaand; x++) {
    dagenVoorbijMaand += dagenInMaand[x];
  }

  aantalSchrikkeljarenVoorbij = (Geboortejaar - 1900) / 4;
  aantalDagenVoorbijVanDeJaren = (Geboortejaar - 1900) * 365 + aantalSchrikkeljarenVoorbij;
  aantalDagenVoorbijMaandEnDagen = dagenVoorbijMaand + Geboortedag;
  cout << aantalDagenVoorbijMaandEnDagen << endl;

  aantalDagenVoorbijTotaal = aantalDagenVoorbijMaandEnDagen + aantalDagenVoorbijVanDeJaren;

  cout << aantalDagenVoorbijTotaal << endl;

  double dagGeboren = fmod(aantalDagenVoorbijTotaal, 7);


  cout << "Op welke dag ben je geboren? Geef in kleine letters de eerste letter van de dag, en ook de tweede als het om za of zo gaat" << endl;
  cin >> gokDag;


  if (gokDag == dagen[static_cast<int>(round(dagGeboren))]) {
    cout << "Goed geraden!"<< endl;
  } else {
    cout << "Fout geraden!" << endl;
    return 1;
  }

  // nu tijd voor sectie 2: het stellen van vragen.

 
  int getal1 = (rand() % 89) + 10; 
  int getal2 = (rand() % 89) + 10; 
  int deelGetal1 = (getal2 % 10) * getal1;
  int deelGetal2 = (getal2 / 10) * 10 * getal1;
  int antwoord = getal1*getal2;
  
  // if deelGetal1
  cout << " " << getal1 << endl << " " << getal2 << " x" << endl; 
  cout << " --" << endl << "" << deelGetal1 << endl << deelGetal2 << " +" << endl;
  cout << " ---" << endl << antwoord << endl;
  

  return 0;


}
