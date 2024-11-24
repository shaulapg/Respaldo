/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Metricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

#ifndef SORTS_H
#define SORTS_H

//Libreria
#include <vector>

/**MERGE SORT
 * 
 * Complejidad Espacial: O(n)
 * 
 * Complejidad Temporal:
 * 		Mejor: Ω(n log(n))
 * 		Promedio: Θ(n log(n))
 * 		Peor: O(n log(n))
 */

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
public:
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
	std::vector<T> mergeSort(const std::vector<T> &);
	void copyArray(std::vector<T> &, std::vector<T> &, int, int);
	void mergeArray(std::vector<T> &, std::vector<T> &, int, int, int);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++)
		A[i] = B[i];
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid)
		for (; j <= high; j++)
			B[k++] = A[j];
	else
		for (; i <= mid; i++)
			B[k++] = A[i];
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ((high - low) < 1)
		return;
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
std::vector<T> Sorts<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1);
	return v;
}

#endif