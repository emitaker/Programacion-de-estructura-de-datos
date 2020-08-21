#include <iostream>
using namespace std;

/*
A01750202 - Abril Berenice Bautista Román
A01378948 - Emilio Campuzano Mejía
A01750192 - Carina Alemon
*/

 float prom(float s, int c)
 {
  float resultado = 0;
  resultado = s/c;
  return resultado;
 }


 int maximo(int original, float num)
 {
  int resultado = 0;
  if (original < num){
   return num;
  }
  return original;
 }


 int minimo(int original, float num)
 {
  if (original > num){
   return num;
  }
  return original;
 }


 int main()
 {
  float num;
  int c = 0;
  float suma = 0.0;
  int mayor = 0;
  int menor = 1000000;

  while (num != -1){

  cout <<"Dame un numero: ";
  cin >> num;
  if (num == -1){
   break;
  }
  mayor = maximo(mayor, num);
  menor = minimo (menor, num);
  suma += num;
  ++c;

  }
  cout <<"El numero mas grande es: " << mayor << endl;
  cout <<"El numero mas chico es: " << menor << endl;
  cout <<"El promedio es: " << prom(suma,c) << endl;

  return 0;
 }