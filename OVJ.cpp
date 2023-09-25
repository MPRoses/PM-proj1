#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
  // Programma bepaald of gebruiker geschikt is voor universitaire studie.
  // Gecompileerd met g++

  // intro
  cout << " _________________________________________________________" << endl;
  cout << "|                Titel: Vermenigvuldiging                 |" << endl;
  cout << "|                                                         |" << endl;
  cout << "| Makers: Arthur van der Sterren en Jens van der Sloot    |" << endl;
  cout << "|                 s4097769                s4018494        |" << endl;
  cout << "|           Student Informatica     Student Informatica   |" << endl;
  cout << "| Jaar van aankomst: 2023                  2023           |" << endl;
  cout << "|                                                         |" << endl;
  cout << "|            Programma gemaakt op 25/09/2023              |" << endl;
  cout << "|                                                         |" << endl;
  cout << "| In dit programma wordt bepaald of je geschikt ben voor  |" << endl;
  cout << "| een universitaire studie. Hiervoor zul je meerdere      |" << endl;
  cout << "| vragen moeten beantwoorden, waaronder je geboortedatum, |" << endl;
  cout << "| een rekensom en een eventuele kunstvraag. Hieruit volgt |" << endl;
  cout << "| een conclusie.                                          |" << endl;
  cout << " ---------------------------------------------------------" << endl;

  // generatie van seeds
  srand (time(NULL));
  time_t t = time(NULL); 

  // initializatie cTime
  struct tm date; 
  if (gmtime_r(&t, &date) == NULL) {
    return 1;
  }
  
  // variabelen die gebruikt worden voor bijhouden en berekenen leeftijd
  int Geboortejaar;
  int Geboortemaand;
  int Geboortedag;
  int Dag = date.tm_mday;
  int Maand = date.tm_mon + 1;
  int Jaar = date.tm_year + 1900;
  int LeeftijdJaren;
  int LeeftijdMaanden;

  // variabelen die gebruikt worden voor berekenen welke dag iemand geboren is
  bool isSchrikkelJaar = (date.tm_year % 4 == 0);
  int dagenVoorbijMaand = 0; // moet gezet worden als 0
  int aantalSchrikkeljarenVoorbij;
  int aantalDagenVoorbijVanDeJaren;
  int aantalDagenVoorbijMaandEnDagen;
  int aantalDagenVoorbijTotaal;
  int dagenInMaand[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  double dagGeboren;
  char dagenLetter1ASCII[] = {122, 109, 100, 119, 100, 118, 122};
  char dagenLetter2ASCII[] = {111, 0, 105, 0, 111, 0, 97};

  // variabelen die gebruikt worden voor de vermenigvuldigingsvraag
  int getal1 = (rand() % 90) + 10; 
  int getal2 = (rand() % 90) + 10; 
  int deelGetal1 = (getal2 % 10) * getal1;
  int deelGetal2 = (getal2 / 10) * 10 * getal1;
  int antwoord = getal1*getal2;
  int getalGok = 0;
  double epsilon = 0.1;
  
  // variabelen die gebruikt worden voor meerkeuzevraag
  char gokDagLetter1;
  char gokDagLetter2;
  char meerkeuzeGok;

  // invoeren van geboortedatum en checken of deze valide is

  cout << endl << "Geef uw geboortejaar: ";
  cin >> Geboortejaar;

  if (Geboortejaar > Jaar || Geboortejaar <= 0) {
    cout << "Ongeldige geboortejaar" << endl;
    return 1;
  }

  if (Jaar < (Geboortejaar + 10)) {
    cout << "Je bent te jong voor de universiteit, jammer!" << endl;
    return 1;
  }

  if ((Geboortejaar + 101) < Jaar) {
    cout << "Je bent te oud voor de universiteit, jammer!" << endl;
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
    cout << endl << "Je bent zowel maandig als jarig, gefeliciteerd!" << endl; 
  } else if (Geboortedag == Dag) {
    cout << "Je bent maandig, gefeliciteerd!" << endl;
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

  // berekening van de leeftijd

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

  cout << endl << "Je bent " << LeeftijdJaren << " jaar en " << LeeftijdMaanden 
    << " maanden oud, dat zijn " << LeeftijdJaren * 12 + LeeftijdMaanden 
      << " maanden in totaal!" << endl << endl;

  // berekening van op welke dag iemand geboren is

  for (int x = 1; x < Geboortemaand; x++) {
    dagenVoorbijMaand += dagenInMaand[x];
  }

  aantalSchrikkeljarenVoorbij = (Geboortejaar - 1900) / 4;
  aantalDagenVoorbijVanDeJaren = (Geboortejaar - 1900) * 365 + aantalSchrikkeljarenVoorbij;
  aantalDagenVoorbijMaandEnDagen = dagenVoorbijMaand + Geboortedag;

  aantalDagenVoorbijTotaal = aantalDagenVoorbijMaandEnDagen + aantalDagenVoorbijVanDeJaren;

  dagGeboren = aantalDagenVoorbijTotaal % 7;

  cout << "Op welke dag ben je geboren? Geef in kleine letters de eerste letter van de dag." << endl;
  cin >> gokDagLetter1;

  if (gokDagLetter1 == dagenLetter1ASCII[static_cast<int>(round(dagGeboren))]) {
    if (gokDagLetter1 == 'z' || gokDagLetter1 == 'd') {
      cout << "Geef ook de tweede letter van de dag in kleine letters." << endl;
      cin >> gokDagLetter2;
      if (gokDagLetter2 != dagenLetter2ASCII[static_cast<int>(round(dagGeboren))]) {
        cout << "Fout geraden!" << endl;
        return 1;
      }
      cout << "Goed geraden!"<< endl << endl;  
    }
  } else {
    cout << "Fout geraden!" << endl;
    return 1;
  }

  // vermenigvuldigingsvraag

  cout << "   " << getal1 << endl << "   " << getal2 << " x" << endl << "   --" << endl; 

  cout << "Wat is het antwoord van de bovenstaande berekening?" << endl;
  cout << "Gok het binnen een foutmarge van " << (epsilon * 100) << "%: ";
  cin >> getalGok;

  cout << endl << "Het antwoord was:" << endl;
  cout << "   " << getal1 << endl << "   " << getal2 << " x" << endl; 

  if (deelGetal1 == 0 || deelGetal2 == 0) {
    if (antwoord >= 1000) {
      cout << "   --" << endl << " " << antwoord << endl;
    } else {
      cout << "   --" << endl << "  " << antwoord << endl;
    }
  } else {
    if (deelGetal1 < 100) {
      cout << "   --" << endl << "   " << deelGetal1 << endl;
    } else {
      cout << "  ---" << endl << "  " << deelGetal1 << endl;
    }
    if (deelGetal2 < 1000) {
      cout << "  " << deelGetal2 << " +" << endl;
    } else {
      cout << " " << deelGetal2 << " +" << endl;
    }
    if (antwoord >= 1000) {
      cout << " ----" << endl << " " << antwoord << endl;
    } else {
      cout << "  ---" << endl << "  " << antwoord << endl;
    }
  }

  // validatie vermeningvuldigingsvraag en optionele kunstvraag stellen.

  if ((getalGok >= antwoord * (1 - epsilon)) && (getalGok <= antwoord * (1 + epsilon))) {
    cout << endl << "Binnen de juiste foutmarges gegokt!" << endl;
    cout << "Je bent ofwel geschikt voor een exacte studie, gefeliciteerd!" << endl << endl;
  } else {
    cout << endl << "Buiten de juiste foutmarges gegokt!" << endl << endl;

    cout << "Misschien is een alpha-studie meer geschikt?" << endl;
    cout << "Beantwoord de volgende kunstvraag:" << endl;
    cout << "*Geef de letter van het juiste antwoord!" << endl << endl;

    if (LeeftijdJaren >= 30) {
      cout << "Welke kunststroming werd tussen 1909 en 1914 veel beoefend en staat beroemde 
        schilder Pablo Picasso bekent om?" << endl;
      cout << "A) Kubisme" << endl;
      cout << "B) Pointilisme" << endl;
      cout << "C) Realisme" << endl;
      cout << "D) Abstract Expressionisme" << endl;

      cin >> meerkeuzeGok;

      if (meerkeuzeGok == 'A' || meerkeuzeGok == 'a') {
        cout << endl << "Juist geraden! Het kubisme is te herkennen aan: geometrische vormen, 
          veelal felle kleuren en een collagestijl." << endl;
        cout << "Je bent ofwel geschikt voor een alpha-studie, gefeliciteerd!" << endl << endl;
      } else {
        cout << endl << "Fout geraden!" << endl;
        cout << "Het juiste antwoord was A: het Kubisme" << endl;
        cout << "Je bent ofwel dus niet geschikt voor een alpha of beta studie, jammer!" << endl << endl;
        return 1;
      }
    } else {
      cout << "Welke bekende straatartiest had een versnipperaar ingebouwd in een van zijn schilderijen?" << endl;
      cout << "A) Banksy" << endl;
      cout << "B) Tristan Eaton" << endl;
      cout << "C) Mark Jenkins" << endl;
      cout << "D) Blu" << endl;

      cin >> meerkeuzeGok;

      if (meerkeuzeGok == 'A' || meerkeuzeGok == 'a') {
        cout << endl << "Juist geraden! Vanwege deze stunt steeg de prijs van het schilderij 
          met 24 miljoen euro!" << endl;
        cout << "Je bent ofwel geschikt voor een alpha-studie, gefeliciteerd!" << endl << endl;
      } else {
        cout << endl << "Fout geraden!" << endl;
        cout << "Het juiste antwoord was A: Banksy" << endl;

        cout << "Je bent ofwel dus niet geschikt voor een alpha of beta studie, jammer!" << endl << endl;
        return 1;
      }
    }
  }
  return 0;
}
