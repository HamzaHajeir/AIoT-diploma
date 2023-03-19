# Assignment 1-01

## Arithmetic operators:
Write a function to compute the volume of a cuboid and return the value:

```cpp

#include <iostream>

using namespace std;

/* 
[] getVolume([],[],[]){}
{

}
 */
int main()
{
	cout << getVolume(10,15,20) << endl;
	
	return 0;
}
```
### Sample output:
>3000


## Sort algorithm:
Write a code to separate an input array of numbers to even and odd arrays:

```cpp
#include <iostream>
#include <string>

using namespace std;

int inputArray[10] = {1,2,3,4,5,6,7,8,9,10};
int evenArray[10];
int oddArray[10];

void sortArray(){
	cout << "Sorting ..." << endl;
	// Write the algorithm here:
	
}

/* Helping function to print an array */
void printArray(string name, int array[], int size){
	cout << name << "=[";
	for (int i = 0; i < size; i++)
		cout << array[i] << ((i < size - 1) ? ", " : "]");
	cout << endl;
}

/* Helping function to print existing arrays */
void printArrays(){
	printArray("inputArray", inputArray, 10);
	printArray("evenArray", evenArray, 10);
	printArray("oddArray", oddArray, 10);
}
int main()
{
	printArrays();
	sortArray();
	printArrays();

	return 0;
}

```

### Sample output:
>inputArray=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  
>evenArray=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  
>oddArray=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  
>Sorting ...  
>inputArray=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  
>evenArray=[2, 4, 6, 8, 10, 0, 0, 0, 0, 0]  
>oddArray=[1, 3, 5, 7, 9, 0, 0, 0, 0, 0]  