#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Matrix{
private:
    double** matrix;
    int wiersze;
    int kolumny;
public:
    Matrix(int n, int m);
    Matrix(int n);
    void store(std::string filename, std::string path);
    ~Matrix() { };
    void set(int n, int m, double val);
    double get(int n, int m);
    Matrix add(Matrix& m2);
    Matrix substract(Matrix& m2);
    Matrix mutliply(Matrix& m2);  
    int cols();
    int rows();
    void print();
};

Matrix::Matrix(int n, int m){
    if(n==0 || m==0) 
        cout << "Nie mozna utworzyc macierzy" << endl;
    else {
        wiersze = n;
        kolumny = m;
        matrix = new double* [n];
        for(int i=0; i<n; i++)
           matrix[i] = new double[m];
        for (int i=0; i<n; i++) {
           for (int j=0; j<m; j++) {
               matrix[i][j] = 0;
           }
        }
    }
}

Matrix::Matrix(int n){
    if(n==0) {
        cout << "Nie mozna utworzyc macierzy" << endl;
    }
    else {
        wiersze = n;
        kolumny = n;
        matrix = new double* [n];
        for (int i = 0; i < n; i++)
            matrix[i] = new double[n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                matrix[i][j] = 0;
            }
        }
    }
}

void Matrix::store(std::string filename, std::string path) {
    std::fstream plik;
    plik.open(path + filename, std::ios::out);
    if (plik.good() == true) {
        plik << kolumny << " " << wiersze << "\n";
        for (int i = 0; i < kolumny; i++) {
            for (int j = 0; j < wiersze; j++) {
                plik << matrix[i][j] << " ";
            }
            plik << "\n";
        }
        plik.close();
    }
    else {
        cout << "Nie można otworzyć pliku";
    }   
}

void Matrix::set(int n, int m, double val) {
    if ((n > wiersze) || (m > kolumny)){
        cout << "Błędne dane" << endl;
    }
    else{
        matrix[n - 1][m - 1] = val;
    }
}

double Matrix::get(int n, int m){
    if ((n > wiersze) || (m > kolumny)){
        cout << "Błędne dane" << endl;
    }
    else{
        return matrix[n - 1][m - 1];     
    }
}

Matrix Matrix::add(Matrix& m2){
    if ((wiersze == m2.wiersze) && (kolumny == m2.kolumny)){
        Matrix suma(wiersze, kolumny);
        for (int i = 0; i < wiersze; i++){
            for (int j = 0; j < kolumny; j++){
                suma.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
            }
        }
        return suma;
    }
    else{
        cout << "Macierze nie są takich samych rozmiarów" << endl;
    }
}

Matrix Matrix::substract(Matrix& m2){
    if ((wiersze == m2.wiersze) && (kolumny == m2.kolumny)){
        Matrix wynik(wiersze, kolumny);
        for (int i = 0; i < wiersze; i++){
            for (int j = 0; j < kolumny; j++){
                wynik.matrix[i][j] = matrix[i][j] - m2.matrix[i][j];
            }
        }
        return wynik;
    }
    else{
        cout << "Macierze nie mają takich samych rozmiarów" << endl;
    }
}

Matrix Matrix::mutliply(Matrix& m2){
    if ((wiersze == m2.wiersze) && (kolumny == m2.kolumny)) {
        Matrix wynik(wiersze,kolumny);
        for (int i = 0; i < wiersze; i++) {
            for (int j = 0; j < kolumny; j++) {
                wynik.matrix[i][j] = matrix[i][j] * m2.matrix[i][j];
            }
        }
        return wynik;
    }
    else {
        cout << "Macierze nie mają takich samych rozmiarów" << endl;
    }
}

int Matrix::cols(){
    return kolumny;
}

int Matrix::rows(){
    return wiersze;
}

void Matrix::print(){
    for (int i = 0; i < wiersze; i++){
        for (int j = 0; j < kolumny; j++){
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

int main(){
    Matrix m1(5,6); // tworzenie dwoch macierzy 5x6
    Matrix m2(5,6);
    Matrix m3(3); // tworzenie macierzy kwadratowej 3x3
    m3.print();
    cout << endl;
    m1.set(1,1,5); // zmiana wartości pierwszej komórki macierzy m1 na 5
    cout << m1.get(1,1) << endl; // wyświetlanie pierwszej komórki macierzy m1
    m2.set(1,1,6); // zmiana wartości pierwszej komórki macierzy m2 na 6
    m1.mutliply(m2).print(); // mnożenie macierzy m1 oraz m2
    cout << endl;
    m1.add(m2).print(); // dodawanie macierzy m1 oraz m2
    cout << endl;
    m1.substract(m2).print(); // odejmowanie macierzy m2 od m1
    cout << endl;
    cout << m1.cols() << endl; // wyświetlanie liczby kolumn macierzy m1
    cout << m1.rows() << endl; // wyświetlanie liczby wierszy macierzy m1
    m1.store("macierz.txt","../"); // zapisywanie liczby macierzy m1 do pliku
    m1.print(); // wyświetlanie macierzy m1
}
