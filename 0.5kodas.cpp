#include "0.5pradzia.h"

void programa(){
     ofstream file2("Rezultatai.txt", ios::app);
     int start = clock();
     file2.fill('-');
     file2.width(71);
     file2<<" ";
     file2.fill(' ');
     file2<<" "<<endl;
     file2<<setw(8)<<right<<"Vardas"<<'\t'<<setw(8)<<left<<"Pavarde"<<'\t'<<setw(20)<<left<<"Galutinis (Vid.)"<<setw(10)<<left<<"Galutinis (Med.)"<<endl;
     file2.fill('-');
     file2.width(68);
     file2<<" ";
     file2.fill(' ');
     file2<<" "<<endl;
     cout<<"Sveiki!"<<endl;
    string eilute;
    string pradzia;
    deque<studentas> studentai;
    ifstream file("Kursiokai.txt");
    deque<string> vardas;
    char A,B;
    getline(file, pradzia);
    while (getline(file, eilute))
    {
        istringstream iss(eilute);
        studentas *naujasStudentas = new studentas();
        vector<int> pazymiai;
        sort(pazymiai.begin(), pazymiai.end());
        int pazymys;
        iss >> naujasStudentas->vardas >> naujasStudentas->pavarde;
        while (!iss.eof())
        {   iss >> pazymys;
            pazymiai.push_back(pazymys);
        }
        naujasStudentas->pazymiai = pazymiai;
        studentai.push_back(*naujasStudentas);
    };
    deque<string>::iterator iterator = vardas.begin();
	for(; iterator != vardas.end(); ++iterator)
         file2 << *iterator <<endl;
    cout<<"Pagal ka isvesti studentus i faila(M/V)? "; cin>>A;
    if(A==77|| A==109) {
    for( deque<studentas>::const_iterator i = studentai.begin(); i != studentai.end(); ++i ){
        file2<<setw(8)<<right<<i->vardas<<'\t'<<setw(4)<<right<<i->pavarde;
        file2<<setw(15)<<right<<setprecision(2)<<fixed<<"-";
        file2<<setw(15)<<right<<setprecision(2)<<fixed<<med(i->pazymiai)<<" ";
        file2<<endl;
        }; cout<<endl; cout<<"Skaiciavimas atliktas. Ziureti i rezultatai faila."<<endl;
    }  else if(A==86||A==118) { for( deque<studentas>::const_iterator i = studentai.begin(); i != studentai.end(); ++i ){
        file2<<setw(8)<<right<<i->vardas<<'\t'<<setw(4)<<right<<i->pavarde;
        file2<<setw(15)<<right<<setprecision(2)<<fixed<<galut(i->pazymiai)<<" ";
        file2<<setw(15)<<right<<"-";
        file2<<endl;
    } cout<<endl; cout<<"Skaiciavimas atliktas. Ziureti i rezultatai faila."<<endl;
              } else {cout<<"Kaida. Ar bandysite vel (T/N)? "; cin>>B;};
        if (B==84||B==116) {cout<<"Pagal ka isvesti studentus i faila(M/V)? "; cin>>A;
        if(A==77|| A==109) {
        for(deque<studentas>::const_iterator i = studentai.begin(); i != studentai.end(); ++i ){
        file2<<setw(8)<<right<<i->vardas<<'\t'<<setw(4)<<right<<i->pavarde;
        file2<<setw(15)<<right<<setprecision(2)<<fixed<<"-";
        file2<<setw(15)<<right<<setprecision(2)<<fixed<<med(i->pazymiai)<<" ";
        file2<<endl;
        }; cout<<endl;
           cout<<"Skaiciavimas atliktas. Ziureti i rezultatai faila."<<endl;
    }  else if(A==86||A==118) { for( deque<studentas>::const_iterator i = studentai.begin(); i != studentai.end(); ++i ){
        file2<<setw(8)<<right<<i->vardas<<'\t'<<setw(4)<<right<<i->pavarde;
        file2<<setw(15)<<right<<setprecision(2)<<fixed<<galut(i->pazymiai)<<" ";
        file2<<setw(15)<<right<<"-";
        file2<<endl;
        } cout<<endl;
          cout<<"Skaiciavimas atliktas. Ziureti i rezultatai faila."<<endl;}
 } else if(B==78||B==110||B<84||B>84||B>116||B<116) cout<<"Programos darbas baigtas"<<endl;
     file2.fill('-');
     file2.width(68);
     file2<<" ";
     file2.fill(' ');
     file2<<" "<<endl;
     file2<<setw(20)<<left<<""<<"Studentu saraso pabaiga"<<endl;
     file2<<" "<<endl;
     int end = clock();
    cout<<endl;
    cout<< "Programos darbo laikas "<<setprecision(4)<<((float)end - start)/CLOCKS_PER_SEC <<" sekundes." <<endl;
    file.close();
    }
