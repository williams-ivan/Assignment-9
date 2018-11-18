#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct SnowReport { //the SnowReport structure
	string month;
	int day;
	double base;
};

void selectionSort(SnowReport arr[], int size) { //the selection sort algorithm for sorting the SnowReport array in ascending order based on each structure's base variable
	int min;
	for (int outer = 0; outer < size - 1; outer++) { //a for loop that runs size - 1 times
		min = outer; //sets value of the min variable to the value of the outer variable
		for (int inner = outer + 1; inner < size; inner++) { //a for loop that runs size/2 times
			if (arr[inner].base < arr[min].base) { //runs if the value of the base variable in arr[inner] is less than the value of the base variable in arr[min]
				min = inner; //sets value of the min variable to the value of the inner variable
			}
		}
		//swaps the structures
		SnowReport temp = arr[outer];
		arr[outer] = arr[min];
		arr[min] = temp;
	}
}

void display(SnowReport arr[], int size, string month, int startDay, int endDay) { //this displays the snow report
	cout << "Snow Report " << month << " " << startDay << "-" << endDay << endl;
	cout << "\tDate\tBase" << endl;
	for (int i = 0; i < size; i++) {
		cout << "\t" << arr[i].day << "\t" << arr[i].base << endl;
	}
}

int main() {
	//parallel arrays that hold each month's info below
	string month, months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" }; //a string variable and an array that holds all of the month names
	int startDay, endDay, numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, i; //int variables and an array that holds the number of days in each month
	SnowReport *arr = new SnowReport[7]; //a dynamic memory allocated array pointer
	bool realMonth = false; //a bool value

	cout << "Enter month: ";
	cin >> month; //retrieves the input
	while (realMonth == false) { //runs if the realMonth variable is false
		for (i = 0; i < 12; i++) { //a for loop that runs 12 times
			month[0] = toupper(month[0]); //sets the first character of the string to uppercase
			for (int j = 1; j < month.length(); j++) { //a for loop that runs as long as the length of the string
				month[j] = tolower(month[j]); //sets the specified character of the string to lowercase
			}
			if (months[i] == month) { //runs if the specified element in the array matches the input
				realMonth = true; //sets the realMonth variable to true
				break; //breaks the loop
			}
		}
		if (realMonth == false) { //runs if the realMonth variable is false
			cout << "Invalid. Re-enter month: ";
			cin >> month;
		}
	}

	cout << "Enter starting day: ";
	cin >> startDay; //retrieves the input
	while (startDay > numberOfDays[i] - 6) { //runs if the input is greater than the specified element in the numberOfDays array minus 6
		cout << "Invalid. Re-enter starting day: ";
		cin >> startDay;
	}

	/*cout << "Enter end day: ";
	cin >> endDay;
	while(endDay - startDay != 6){
		cout << "Invalid. Re-enter end day: ";
		cin >> endDay;
	}*/
	//I was going to add this above but decided not to since the code can just calculate the next 6 days for this program
	endDay = startDay + 6; //sets the endDay variable to the value of the startDay variable plus 6

	for (int i = 0; i < 7; i++) { //a for loop that runs 7 times
		arr[i].month = month;
		arr[i].day = startDay + i;
		cout << "Enter base for " << month << " " << arr[i].day << ": ";
		cin >> arr[i].base; //retrieves the input
	}

	selectionSort(arr, 7); //sorts the array in ascending order
	cout << endl << endl;
	display(arr, 7, month, startDay, endDay); //displays the snow report
}