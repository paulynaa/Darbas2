#include "pagalbinesvector.h"
using namespace std;

int pasirinkimas;
int c;
int x;
int s;
int i=0;
std::vector<Pazymiai> S, P, Z;
/**
 * @brief Pagrindin� funkcija, vykdoma programos prad�ioje.
 *
 * @return int Gra�inamas nulis, nes funkcija yra tipas int.
 */



int main ()
{

    while (true){
        cout << "Pasirinkite norim� veiksm�: " << endl; // Informacija apie pasirinkimo galimybes
        cout << "1. �vesti duomenis ranka" << endl; // Galimyb� ranka �vesti duomenis
        cout << "2. Generuoti pa�ymius" << endl; // Galimyb� sugeneruoti pa�ymius
        cout << "3. Generuoti student� vardus, pavardes ir pa�ymius" << endl; // Galimyb� sugeneruoti student� duomenis
        cout << "4. Nuskaityti i� failo" << endl; // Galimyb� nuskaityti duomenis i� failo
        cout << "5. Generuoti failus" << endl; // Galimyb� sugeneruoti failus
        cout << "6. Sugeneruot� fail� skai�iavimas" << endl; // Galimyb� apskai�iuoti sugeneruot� fail� duomenis
        cout << "7. Klas�s testavimas" << endl; // Galimyb� atlikti klas�s testavim�
        cout << "8. Baigti program�" << endl; // Baigti programos darb�
        if (!(cin >> pasirinkimas)) {
            cout << "Klaida. �veskite skai�i� nuo 1 iki 7. " << endl; // Prane�imas apie klaid�, jei �vestas netinkamas skai�ius
            cin.clear(); // I�valoma klaidinga �vestis
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Praleid�iamas klaidingas �vesties srautas
        }

        switch (pasirinkimas){
            case 1:{

                // Atvejis 1: Ivesti duomenis ranka
    // �i dalis leid�ia vartotojui �vesti student� duomenis rankiniu b�du.

    // Inicializuojamas Pazymiai objektas, skirtas saugoti student� duomenis
    Pazymiai C;

    // Vartotojas kvie�iamas �vesti student� duomenis, kol �ves "4" arba "4" pavard�s lauk�
    do {
        // Skaitomi student� duomenys i� vartotojo
        std::cin >> C;

        // Tikrinama, ar �vestas "4" vienoje i� pavard�s arba vardo viet�, nurodydama duomen� �vedimo pabaig�
        if (C.getPav() == "4" || C.getVar() == "4") {
            break; // I�eiti i� ciklo, jei s�lyga pasiekta
        }

        // �traukti �vestus student� duomenis � student� vektori� (P)
        P.push_back(C);
    } while (true); // Kartoti, kol pasiekiama pabaigos s�lyga

    // Kai duomen� �vedimas baigtas, atvaizduojami �vesti student� duomenys
    rezultatai(P);

    break; // I�eiti i� switch atvejo
            }

            case 2:{

                // Atvejis 2: Generuoti pazymius
    // �i dalis leid�ia vartotojui generuoti student� duomenis su atsitiktiniais pa�ymiais.

    Pazymiai C; // Sukuriamas Pazymiai objektas skirtas saugoti vieno studento duomenims
    string xx, yy; // Laikini kintamieji vardo ir pavard�s saugojimui
    int egg; // Kintamasis saugantis egzamino rezultat�

    do  {
        double suma = 0.0; // Kintamasis saugantis pa�ymi� sum�

        // Vartotojui leid�iama �vesti vard� ir pavard�
        cout << "Iveskite " << i + 1 << " pavarde (noredami sustoti iveskite 4):   " << endl;
        cin >> xx;
        C.setPav(xx);
        if (C.getPav() == "4" || C.getVar() == "4") {
            break; // I�eiti i� ciklo, jei vartotojas nurodo duomen� �vedimo pabaig�
        }

        cout << "Iveskite " << i + 1 << " varda (noredami sustoti iveskite 4):   " << endl;
        cin >> yy;
        C.setVar(yy);
        if (C.getPav() == "4" || C.getVar() == "4") {
            break; // I�eiti i� ciklo, jei vartotojas nurodo duomen� �vedimo pabaig�
        }

        // Vartotojas pasirenka, ar nori generuoti atsitiktinius pa�ymius arba pasirinkti kiek�
        cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
        cout << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas �ved� tinkam� pasirinkim�
        while (!(cin >> x) || (x != 1 && x != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Vartotojas pasirenka atsitiktini� arba pasirinkt� pa�ymi� generavim�
        if (x == 1) {
            // Atsitiktini� pa�ymi� generavimas
            string y;
            int h = 0;
            while (y != "ne") {
                C.setOnePaz((rand() % 10) + 1); // Generuojamas atsitiktinis pa�ymys
                cout << "Pazymis " << h + 1 << " : " << C.getPazN(C.getPaz(),h) << endl;
                cout << "Ar norite testi generavima? taip arba ne: ";
                cin >> y;
                if (y != "taip" && y != "ne") {
                    cout << "Klaida. Prasome ivesti taip arba ne: ";
                    cin>>y;
                }
                suma = suma + C.getPazN(C.getPaz(),h); // Sumuojami pa�ymiai
                h++;
            }
            C.setVid(suma / h); // Apskai�iuojama pa�ymi� vidurkis
            C.setMed(mediana(h,C)); // Apskai�iuojama pa�ymi� mediana
        }

        if (x == 2) {
            // Pasirinkt� pa�ymi� generavimas
            int k;
            cout << "Iveskite pazymiu kieki: ";

            // Tikrinama, ar vartotojas �ved� tinkam� kiek� pa�ymi�
            while (!(cin >> k) || (k < 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Iveskite skaiciu nuo 1: ";
            }
            for (int l = 0; l < k; l++) {
                // Generuojamas pasirinktas pa�ymys
                C.setOnePaz((rand() % 10) + 1);
                cout << "Pazymis " << l + 1 << " : " << C.getPazN(C.getPaz(),l) << endl;
                suma = suma + C.getPazN(C.getPaz(),l); // Sumuojami pa�ymiai
            }
            C.setVid(suma / k); // Apskai�iuojama pa�ymi� vidurkis
            C.sortPaz(C); // Surikiuojami pa�ymiai did�jimo tvarka
            C.setMed(mediana(k,C)); // Apskai�iuojama pa�ymi� mediana
        }

        // Vartotojas pasirenka, ar nori atsitiktinai sugeneruoti egzamino rezultat� arba �vesti rankiniu b�du
        int w;
        cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
        cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas �ved� tinkam� pasirinkim�
        while (!(cin >> w) || (w != 1 && w != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Vartotojas pasirenka atsitiktinio arba rankinio egzamino rezultato generavim�
        if (w == 1) {
            // Atsitiktinio egzamino rezultato generavimas
            C.setEgz((rand() % 10) + 1); // Generuojamas atsitiktinis egzamino rezultatas
            cout << "Egzamino rezultatas: " << C.getEgz() << endl;
        }

        if (w == 2) {
            // Rankinio egzamino rezultato �vedimas
            cout << "Iveskite egzamino rezultata: " << endl;

            try {
                cin >> egg; // Vartotojo �vestas egzamino rezultatas
                C.setEgz(egg); // Nustatomas egzamino rezultatas

                // Tikrinama, ar vartotojo �vestas egzamino rezultatas tinkamas
                while (cin.fail() || egg < 1 || egg > 10) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                    cin >> egg; // Vartotojo �vestas egzamino rezultatas
                    C.setEgz(egg); // Nustatomas egzamino rezultatas
                }
            } catch (const std::exception& e) {
                cerr << "Exception: " << e.what() << endl; // Klaidos prane�imas, jei �vyksta klaida
            }
            cout << endl; // Tarpas ekrane
        }

        // Apskai�iuojamas galutinis balas pagal formul�
        C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));

        // �traukti studento duomenis � student� vektori� (P)
        P.push_back(C);

        i++; // Padidinti studento skai�iavimo skaitikl�
    } while (C.getPav() != "4" || C.getVar() != "4"); // Ciklas kartojamas tol, kol pasiekiamas duomen� �vedimo pabaigos s�lyga

    // Atvaizduojami �vesti student� duomenys
    rezultatai(P);

    break; // I�eiti i� switch atvejo
            }

            case 3:{
                // Atvejis 3: Generuoti ir studentu vardus, pavardes ir pazymius
    // �i dalis leid�ia automati�kai generuoti student� duomenis su atsitiktiniais pa�ymiais.

    int qq = 0; // Kintamasis nusakantis, ar reikia generuoti daugiau student�
    int egg; // Kintamasis saugantis egzamino rezultat�
    string vardai[] = {"Paulina", "Adriana", "Gitanas", "Donald", "Ugne", "Kamile", "Rugile", "Roberta", "Valdemaras", "Jurgis"}; // Vard� masyvas
    string pavardes[] = {"Podgaiska", "Obama", "Trump", "Nauseda", "Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte", "Jankauskas"}; // Pavard�i� masyvas
    string xx, yy; // Laikini kintamieji vardo ir pavard�s saugojimui

    // Ciklas kartojamas tol, kol vartotojas nenor�s baigti generuoti student� duomen�
    while (qq != 1) {
        Pazymiai C; // Sukuriamas Pazymiai objektas skirtas saugoti vieno studento duomenims

        // Atsitiktinio vardo ir pavard�s pasirinkimas i� masyv�
        xx = pavardes[rand() % 10];
        C.setPav(xx);

        yy = vardai[rand() % 10];
        C.setVar(yy);

        // Atvaizduojami studento vardas ir pavard�
        cout << "Pavarde ir vardas: " << C.getPav() << " " << C.getVar() << endl;

        // Vartotojui leid�iama pasirinkti, ar generuoti atsitiktinius ar pasirinktus pa�ymius
        cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
        cout << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas �ved� tinkam� pasirinkim�
        while (!(cin >> x) || (x != 1 && x != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Generuojami arba �vedami pa�ymiai pagal vartotojo pasirinkim�
        if (x == 1) {
            // Atsitiktiniai pa�ymiai
            string y;
            int h = 0;
            double suma = 0.0;

            while (y != "Ne") {
                C.setOnePaz((rand() % 10) + 1); // Generuojamas atsitiktinis pa�ymys
                cout << "Pazymis " << h + 1 << " : " << C.getPazN(C.getPaz(),h) << endl;
                cout << "Ar norite testi generavima? Taip arba Ne: ";
                cin >> y;
                cout << endl;
                suma = suma + C.getPazN(C.getPaz(),h); // Sumuojami pa�ymiai
                h++;
            }
            C.setVid(suma / h); // Apskai�iuojamas pa�ymi� vidurkis
            C.sortPaz(C); // Surikiuojami pa�ymiai did�jimo tvarka
            C.setMed(mediana(h,C)); // Apskai�iuojama pa�ymi� mediana
        }

        if (x == 2) {
            // Pasirinkti pa�ymiai
            double suma = 0.0;
            int k;
            cout << "Iveskite pazymiu kieki: ";

            // Tikrinama, ar vartotojas �ved� tinkam� kiek� pa�ymi�
            while (!(cin >> k) || (k < 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Iveskite skaiciu nuo 1 : ";
            }

            for (int l = 0; l < k; l++) {
                C.setOnePaz((rand() % 10) + 1); // Generuojamas pasirinktas pa�ymys
                cout << "Pazymis " << l + 1 << " : " << C.getPazN(C.getPaz(),l) << endl;
                suma = suma + C.getPazN(C.getPaz(),l); // Sumuojami pa�ymiai
            }

            C.setVid(suma / k); // Apskai�iuojamas pa�ymi� vidurkis
            C.sortPaz(C); // Surikiuojami pa�ymiai did�jimo tvarka
            C.setMed(mediana(k,C)); // Apskai�iuojama pa�ymi� mediana
        }

        // Vartotojui leid�iama pasirinkti, ar generuoti atsitiktin� ar �vest� egzamino rezultat�
        int w;
        cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
        cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas �ved� tinkam� pasirinkim�
        while (!(cin >> w) || (w != 1 && w != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Generuojamas arba �vedamas egzamino rezultatas pagal vartotojo pasirinkim�
        if (w == 1) {
            // Atsitiktinis egzamino rezultatas
            C.setEgz((rand() % 10) + 1); // Generuojamas atsitiktinis egzamino rezultatas
            cout << "Egzamino rezultatas: " << C.getEgz() << endl;
        }

        if (w == 2) {
            // �vestas egzamino rezultatas
            cout << "Iveskite egzamino rezultata: " << endl;

            try {
                cin >> egg;
                C.setEgz(egg); // Nustatomas egzamino rezultatas

                // Tikrinama, ar �vestas egzamino rezultatas tinkamas
                while (cin.fail() || egg < 1 || egg > 10) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                    cin >> egg; // Vartotojo �vestas egzamino rezultatas
                    C.setEgz(egg); // Nustatomas egzamino rezultatas
                }
            } catch (const std::exception& e) {
                cerr << "Exception: " << e.what() << endl; // Klaidos prane�imas, jei �vyksta klaida
            }
            cout << endl; // Tarpas ekrane
        }

        // Apskai�iuojamas galutinis balas pagal formul�
        C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));

        // Vartotojui leid�iama pasirinkti, ar generuoti daugiau student� duomen�
        cout << "Noredami baigti studentu generavima spauskite 1, noredami testi spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas �ved� tinkam� pasirinkim�
        while (!(cin >> qq) || (qq != 1 && qq != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // �traukiami studento duomenys � student� vektori� (P)
        P.push_back(C);
    }

    // Atvaizduojami �vesti student� duomenys
    rezultatai(P);

    break; // I�eiti i� switch atvejo
            }

            case 4:{

                // Atvejis 4: Nuskaityti duomenis i� failo

    Pazymiai C; // Sukuriamas Pazymiai objektas skirtas saugoti vieno studento duomenims

    int z; // Laikinas kintamasis skaiciui saugoti
    int o; // Vartotojo pasirinkimas, kur i�vesti rezultatus (ekranas ar failas)
    int stud; // Kiek student� duomen� nuskaityti i� failo
    string zodziai; // Laikinas kintamasis simboliams saugoti
    int xyz; // Vartotojo pasirinkimas, kaip rusiuoti studentus

    int pv = 0; // Kintamasis saugantis paskutin� egzamino rezultato stulpelio numer�
    int numeris; // Kintamasis saugantis vartotojo pasirinkt� failo numer�
    string wp; // Kintamasis saugantis failo pavadinim�

    string xx, yy; // Laikini kintamieji studento vardo ir pavard�s saugojimui
    int egg; // Laikinas kintamasis egzamino rezultatui saugoti

    // Vartotojui leid�iama pasirinkti, i� kurio failo nuskaityti duomenis
    cout << "Pasirinkite is kurio failo norite nuskaityti: " << endl;
    cout << "1. studentai10000 " << "2. studentai100000 " << "3. studentai1000000 " << "4. kursiokai5 " << endl;

    // Tikrinama, ar vartotojas �ved� tinkam� failo numer�
    while (!(cin >> numeris) || numeris < 1 || numeris > 4) {
        cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Nustatomas pasirinktas failo pavadinimas pagal vartotojo pasirinkim�
    switch (numeris) {
        case 1:
            wp = "studentai10000.txt";
            break;
        case 2:
            wp = "studentai100000.txt";
            break;
        case 3:
            wp = "studentai1000000.txt";
            break;
        case 4:
            wp = "kursiokai.txt";
            break;
        default:
            break;
    }

    // Tikrinama, ar failas egzistuoja
    ifstream file(wp);
    if (!file.is_open()) {
        cout << "Failas " << wp << " neegzistuoja!" << endl;
        break;
    }
    file.close();

    // Skaitoma failo eilu�i� skai�ius
    int lineCount = 0;
    string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    // Vartotojui leid�iama pasirinkti, kiek student� duomen� nuskaityti i� failo
    do {
        cout << "Kiek nuskaityti studentu? " << endl;

        // Tikrinama, ar vartotojas �ved� tinkam� student� kiek�
        while (!(cin >> stud) || stud <= 0 || stud > lineCount) {
            cout << "Klaida. Iveskite skaiciu nuo 1 iki " << lineCount << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (stud <= 0 || stud > lineCount);

    // Atidaromas failas nuskaitymui
    ifstream F(wp);

    auto start = chrono::steady_clock::now(); // Pradedamas laiko matavimas

    // Skaitomi student� duomenys i� failo
    while (zodziai != "Egz.") {
        F >> zodziai;
        pv++;
    }

    pv = pv - 3; // Nustatomas paskutinis pa�ymi� stulpelio numeris

    // Skaitomi duomenys i� failo ir saugomi Pazymiai objekte
    for (int l = 0; l < stud; l++) {
        double suma = 0.0;

        // Nuskaitoma studento vardo ir pavard�s informacija
        F >> xx >> yy;
        C.setPav(xx);
        C.setVar(yy);

        // Nuskaitomi studento pa�ymiai ir skai�iuojamas j� vidurkis
        for (int i = 0; i < pv; i++) {
            F >> z;
            C.setOnePaz(z);
            suma = suma + z;
        }

        // Surikiuojami pa�ymiai did�jimo tvarka
        C.sortPaz(C);

        // Apskai�iuojamas vidurkis ir pridedamas prie objekto
        C.setVid(suma / pv);

        // Nuskaitomas egzamino rezultatas ir pridedamas prie objekto
        F >> egg;
        C.setEgz(egg);

        // Apskai�iuojamas galutinis balas ir pridedamas prie objekto
        C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));

        // Apskai�iuojama mediana ir pridedama prie objekto
        C.setMed(mediana(pv,C));

        // Pridedami studento duomenys � student� vektori� (P)
        P.push_back(C);
    }

    // U�daromas failas
    F.close();

    auto end = chrono::steady_clock::now(); // Baigiamas laiko matavimas
    double laikas = chrono::duration <double> (end - start).count(); // Apskai�iuojamas laikas
    cout << "Trukme: " << laikas << " s" << endl; // Atvaizduojama laiko trukm�

    // Vartotojui leid�iama pasirinkti, kaip surikiuoti studentus
    cout << "Jeigu norite rusiuoti pagal pavarde spauskite 1: " << endl;
    cout << "Jeigu norite rusiuoti pagal varda spauskite 2: " << endl;
    cout << "Jeigu norite rusiuoti pagal galutini pazymi spauskite 3: " << endl;
    cout << "Jeigu norite rusiuoti pagal mediana spauskite 4: " << endl;

    // Tikrinama, ar vartotojas �ved� tinkam� pasirinkim�
    while (!(cin >> xyz)) {
        cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Surikiuojami studentai pagal vartotojo pasirinkim�
    if (xyz == 1) {
        sort(C.getPav().begin(), C.getPav().end());
    }
    if (xyz == 2) {
        sort(C.getVar().begin(), C.getVar().end());
    }
    if (xyz == 3) {
        sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
            return a.getGalutinis() < b.getGalutinis();
        });
    }
    if (xyz == 4) {
        sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
            return a.getMed() < b.getMed();
        });
    }

    // Vartotojui leid�iama pasirinkti, kur i�vesti surikiuotus duomenis
    cout << "Jeigu norite isvesti i ekrana- spauskite 1: " << endl;
    cout << "Jeigu norite isvesti i faila- spauskite 2: " << endl;
    cout << "Jusu pasirinkimas: ";

    // Tikrinama, ar vartotojas �ved� tinkam� pasirinkim�
    while (!(cin >> o)) {
        cout << "Klaida. Iveskite skaiciu 1 arba 2." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Atvaizduojami rezultatai pagal vartotojo pasirinkim�
    if (o == 1) {
        rezultatai(P); // Atvaizduojami rezultatai ekrane
    }
    if (o == 2) {
        rezultataifailas(P, "isvestis.txt"); // Atvaizduojami rezultatai faile
    }

    break; // Baigtas atvejis 4
            }

            case 5:{
                // Atvejis 5: Fail� generavimas su atsitiktiniais duomenimis

    Pazymiai C; // Sukuriamas Pazymiai objektas skirtas laikinai saugoti duomenims

    // Generuojami failai su atsitiktiniais duomenimis
    cout << "1k :" << endl;
    generuojam(1000, "1k.txt");
    cout << "10k :" << endl;
    generuojam(10000, "10k.txt");
    cout << "100k :" << endl;
    generuojam(100000, "100k.txt");
    cout << "1mln :" << endl;
    generuojam(1000000, "1kk.txt");
    cout << "10mln :" << endl;
    generuojam(10000000, "10kk.txt");
    cout << "Failai sugeneruoti! " << endl;
    cout << endl;

    break; // Baigtas atvejis 5
            }

            case 6:{
                // Atvejis 6: Sugeneruot� fail� skaitymas ir apdorojimas

    Pazymiai C; // Sukuriamas Pazymiai objektas skirtas laikinai saugoti duomenims

    // Vartotojui parodomas pasirinkimas strategijos
    cout << "Pasirinkite strategija 1, 2, 3, 4: ";
    int strategy;
    cin >> strategy;

    // Fail� vardai
    const vector<string> filenames = {"1k.txt", "10k.txt", "100k.txt", "1kk.txt", "10kk.txt"};
    const vector<string> lopukaiFilenames = {"lopukai1.txt", "lopukai2.txt", "lopukai3.txt", "lopukai4.txt", "lopukai5.txt"};
    const vector<string> saunuoliukaiFilenames = {"saunuoliukai1.txt", "saunuoliukai2.txt", "saunuoliukai3.txt", "saunuoliukai4.txt", "saunuoliukai5.txt"};

    // Iteruojama per visus failus
    for (size_t i = 0; i < filenames.size(); ++i) {
        cout << filenames[i] << " :" << endl;

        // Pasirinktai strategijai atliekami veiksmai su failu
        switch (strategy) {
            case 1:
                failuskaickstrategija1(filenames[i], C, S, P, Z);
                break;
            case 2:
                failuskaickstrategija2(filenames[i], C, P, Z);
                break;
            case 3:
                failuskaickstrategija3(filenames[i], C, S, P, Z);
                break;
            case 4:
                failuskaick(filenames[i], C, P, Z);
                break;
            default:
                cout << "Tokia strategija neegzistuoja!" << endl;
                break;
        }

        // Rezultat� spausdinimas � failus
        spausdintuvas(lopukaiFilenames[i], saunuoliukaiFilenames[i], P, Z);
    }

    break; // Baigtas atvejis 6
            }

            case 7:{
                // Atvejis 7: Klasi� testavimas
    testai(); // I�kvie�iamas funkcijos testai() metodas
    break; // Baigtas atvejis 7
            }
            case 8:{
                // Atvejis 8: Programos pabaiga
    cout << "Programa baigta." << endl; // Informacija apie programos pabaig�
    return 0; // Gr��inamas nulis, nurodant, kad programa s�kmingai baig� darb�
    break; // Baigtas atvejis 8 (nereikalingas, nes return funkcija baigia vykdym�)
            }
        }
    }
    return 0;
}

