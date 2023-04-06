#include <iostream>
using namespace std;

//1.Jelaskan, mengapa suatu algoritma di butuhkan untuk meneyelesaikan suatu masalah?
//	Karena, algoritma memiliki suatu sturuktur data untuk menyelesaikan suatu masalah
//2.Dalam Algoritma, diklasifikasikan menjadi 2 data struktur. Sebutkan 2 data struktur tersebut?
//	Quadratic dan Loglinear
//3.Sebutkan faktor - faktor yang mempengaruhi efesiensi suatu program algoritma!
//	* Variabel tidak urut
//	* Kurang teliti terhadap codingan yang diketik
//	* Penggunaan dan pemanggil fungsi
//4.Dari 6 algoritma yang sudah dipelajari manakah yang paling efisien untuk mengurutkan data yang kecil, Jelaksan kenapa anda memilih itu.
//	Insertion Sort, Karena memiliki batasan panjang data
//5.Sebutkan dari algoritma yang dipelajari mana yang termasuk kedalam Quadratic dan Loglinear
//	* Bubble Sort					}	Quadratic
//	* Insection Sort				}	Quadratic
//	* Quick Sort					}	Loglinear
//	* Tipe data struct
//	



int alan[20];
int cmp_count = 0;						
int mov_count = 0;						
int n;

void input() {
	while (true)
	{
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; 1 < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> alan[1];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = alan[x];
	alan[x] = alan[y];
	alan [y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, SA;
	if (low > high)						// Langkah Algoritma no 1
		return;

	pivot = alan[low];					//Langkah ALgoritma No. 2
	i = low + 1;						//Langkah Algoritma No.3
	SA = high;							//Langkah Algoritma NO.4

	while (i <= SA)						//Langkah Algoritma No.5
	{
		//search for an element less than or equal to pivot 
		while ((alan[i] <= pivot) && (i <= high))	//Langkah Algoritma No. 6
		{
			i++;
			cmp_count++;
		}
		cmp_count++;

		//search for an element less than or equal to pivot
		while ((alan[SA] > pivot) && (SA >= low))			//Langkah Algoritma No. 7
		{
			SA--;										//Langkah Algoritma No. 8
			cmp_count++;
		}
		cmp_count++;

		// if the greater element is on the left of the element
		if (i < SA)
		{
			//swap the element at index i whit the element at index j
			swap(i, SA);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < SA)									//Langkah ALgoritma No.11
	{
		//move the pivot to its correct position in the list 
		swap(low, SA);
		mov_count++;
	}
	//sort the list on the left of pivot using quick sort
	q_short(low, SA - 1);							//Langkah ALgoritma No.12

	//sort the list on the right of pivot using quick sort 
	q_short(SA + 1, high);							//Langkah Algoritma N0.13

}

void display() {
	cout << "\n---------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << alan[i] << " ";
	}

	cout << "\n\nNumber of comparisions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n - 1);		//Sort the array using quick sort
	display();
	system("pause");

	return 0;
}
