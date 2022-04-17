#include <iostream>
#include <string>

bool check(std::string number)
{
	std::string nums = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	
	for (int i = 0; i < 10; i++)
	{
		if (number[0] == nums[i])
			return 1;
	}
	throw number;
}

void SelectSort(int*& arr, int size)
{
	int min;															//var used for minimal element

	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)								//it's value now being compared to the other elements in order to determine the smallest one
		{
			if (arr[min] > arr[j])
				min = j;												//in case of a match, the minimal element is changed
		}
		int temp = arr[i];												//swapping occures by the end of cycle iteration that puts smaller elements to the beginning
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main()
{
	int* arr = new int[1];
	std::string input;
	int size = 0;
	int pos = 0;

	std::cout << "Fill the array.\n";									//code below is simply making sure user input consists of numbers only. it's rather primitive and work in progress
	while (true) {
		std::cout << "To stop, type \"C\" character.\nInput: ";
		getline(std::cin, input);
		if (input[0] == 'c' || input[0] == 'C')
			break;
		try
		{
			check(input);
		}
		catch(std::string number)
		{
			system("cls");
			std::cout<<"Not a number!\n";
			continue;
		}
		size++;
		int* arr1 = new int[size];
		if (pos != 0)
			for (int i = 0; i < size - 1; i++)
				arr1[i] = arr[i];
		arr1[size-1] = std::stoi(input);
		delete [] arr;
		arr = arr1;
		pos++;
		system("cls");
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	SelectSort(arr, size);												//algorithm itself

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	return 0;
}