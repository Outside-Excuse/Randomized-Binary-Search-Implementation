
/*
Alejandro Hidalgo Badillo A01423412
Randomized Binary Search Implementation
14 de noviembre del 2022
	*/
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

//generamos un valor random entre 0 y el tamano de nuestro arreglo de entrada
int ValorRandom(int total, int cero)
{
	//tiene una complejidad de O(n)
	srand(time(NULL));
	return (total + rand() % (cero-total+1)); //regresamos el valor random
} 



//tiene una complegidad de O(nlogn) debido a que se utiliza recursion 
int busquedaBinaria(int arr[], int l, int r, int x){
	if (r >= l){

		int media = ValorRandom(l, r); //guardamos el valor random generado

	
		if (arr[media] == x){ // si el valor aleatorio es igual deseado de encontrar se regresa el valor aleatorio
			return media;
		}
			

	//se utiliza la recursion para seguir buscando el valor deseado
		if (arr[media] > x){
			return busquedaBinaria(arr, l, media-1, x); //si el valor aleatorio es mayor entonces se le resta uno al valor y entra en la recursuo
		}
		else{
			return busquedaBinaria(arr, media+1,r, x); // si el valor aleatorio es menor se le suma y entra en la recursion
		}

		
	}


	return -100000; //si el elemento no se encuentra en el arreglo, este regresa un valor negativo
}

//inicio del main
int main(void)
{
	//almacenamos los datos de entrada
	int n;
	cin>>n;
	int cont1,cont2;
	vector<vector<string>> valArray;
	string line;
	int cont = 0;
	//contq es el contador de lineas de entrada existentes
	int largo;
	getline(cin, line);
	 while (getline(cin, line)) {
		stringstream ss(line);
		valArray.push_back(vector<string>());
		while (ss.good()) {
        string substr;
        getline(ss, substr,' ');
        valArray[cont].push_back(substr);
    }
		 cont++;
  }//guardar matriz
	int m = valArray[0].size();
	int list[m];
	for (int i=0;i<valArray[0].size();i++){
		//cout<<valArray[0][i]<<" ";
		list[i]=stoi(valArray[0][i]);
	}
	//cout<<endl;
	


	int result = busquedaBinaria(list, 0, m-1, n);

	if (result < 0){
		cout<<"Element is not in the array";
	}
	else{
		cout<<"Element is at index: "<<result;
	}
	return 0;
}
/*
el main tiene una complejidad de O(n x n) a unque por que la entrada solo es un balor y una linea no llega a a ocupar un gran tiempo, el programa podria tener una menor complejidad pero reutilize codigo

de tamano predomina la complegidad del main solo por la entrada de datos
*/
