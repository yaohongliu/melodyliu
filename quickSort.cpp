// p6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <random>
#include <nmmintrin.h>

using namespace std;

struct student
{
	int id;
	string name;
	string address;
	double gpa;
	double *grades;
};

void quickSort(vector<student>&, int, int);
int partition(vector<student>&, int, int);

int main()
{	
	const int NUM_ROWS = 15;
	const int NUM_COLS = 10;

	vector<student> student_record(NUM_ROWS);

	ifstream input_file;
	input_file.open("student_1.txt", ios::in);
	string line;        
	cout << "Display the first group of student student_records and grades: \n";
	cout << " " << setw(3) << "ID"; 
	cout << " " << setw(10) << "Name"; 
	cout << " " << setw(7) << "GPA"; 
	cout << " " << setw(12) << "Address"; 
	cout << " " << setw(18) << " scores" << endl;
	
	for (int i = 0; i < NUM_ROWS; i++)
	{
		input_file >> student_record[i].id >> student_record[i].name >> student_record[i].gpa;
		getline(input_file, student_record[i].address);
	}

	input_file.close();

	double *ptr = nullptr; 
	
	input_file.open("test_score_1.txt", ios::in);

	for (int row = 0; row < NUM_ROWS; row++)
	{
		cout << " " << left << setw(8) << student_record[row].id;
		cout << " " << left << setw(8) << student_record[row].name;
		cout << " " << left << setw(6) << student_record[row].gpa;
		cout << " " << left << setw(23) << student_record[row].address;

		student_record[row].grades = new double[NUM_COLS];
		
		for(int col = 0; col < NUM_COLS; col++)
		{
			double current_grade = 0.0;
			input_file >> current_grade;
			*(student_record[row].grades + col) = current_grade;
			cout << left << setw(5) << student_record[row].grades[col]  << " ";
		}
			
		cout << endl;
	}

	input_file.close();

	quickSort(student_record, 0, NUM_ROWS - 1);

	cout << " Now play the sorted student student_record: " << endl;

	for (int row = 0; row < NUM_ROWS; row++)
	{
		cout << " " << left << setw(8) << student_record[row].id;
		cout << " " << left << setw(8) << student_record[row].name;
		cout << " " << left << setw(6) << student_record[row].gpa;
		cout << " " << left << setw(23) << student_record[row].address;

		for (int col = 0; col < NUM_COLS; col++)
		{
			cout << left << setw(5) << student_record[row].grades[col] << " ";
		}

		cout << endl;
	}
	input_file.open("student_2.txt", ios::in);
	cout << "\nDisplay the second student group of student_records and grades: \n";
	cout << " " << setw(3) << "ID";
	cout << " " << setw(10) << "Name";
	cout << " " << setw(7) << "GPA";
	cout << " " << setw(12) << "Address";
	cout << " " << setw(18) << " scores" << endl;

	for (int i = 0; i < NUM_ROWS; i++)
	{
		input_file >> student_record[i].id >> student_record[i].name >> student_record[i].gpa;
		getline(input_file, student_record[i].address);
	}

	input_file.close();

	input_file.open("test_score_2.txt", ios::in);

	for (int row = 0; row < NUM_ROWS; row++)
	{
		cout << " " << left << setw(8) << student_record[row].id;
		cout << " " << left << setw(8) << student_record[row].name;
		cout << " " << left << setw(6) << student_record[row].gpa;
		cout << " " << left << setw(23) << student_record[row].address;

		student_record[row].grades = new double[NUM_COLS];

		for (int col = 0; col < NUM_COLS; col++)
		{
			double current_grade = 0.0;
			input_file >> current_grade;
			*(student_record[row].grades + col) = current_grade;
			cout << left << setw(5) << student_record[row].grades[col] << " ";
		}

		cout << endl;
	}

	input_file.close();

	quickSort(student_record, 0, NUM_ROWS - 1);

	cout << " Now play the sorted student student_record: " << endl;

	for (int row = 0; row < NUM_ROWS; row++)
	{
		cout << " " << left << setw(8) << student_record[row].id;
		cout << " " << left << setw(8) << student_record[row].name;
		cout << " " << left << setw(6) << student_record[row].gpa;
		cout << " " << left << setw(23) << student_record[row].address;

		for (int col = 0; col < NUM_COLS; col++)
		{
			cout << left << setw(5) << student_record[row].grades[col] << " ";
		}

		cout << endl;
	}

	return EXIT_SUCCESS;
}

void quickSort(vector<student> &student_record, int low, int high)
{
	if(low < high)
	{
		int pivotIndex = partition(student_record, low, high);
		quickSort(student_record, low, pivotIndex-1);
		quickSort(student_record, pivotIndex, high);
	}
}

int partition(vector<student> &student_record, int low, int high)
{
	int pivotIndex = low + (high - low) / 2;
	int pivotValue = student_record[pivotIndex].id;
	int i = low, j = high;
	student  temp;

	while (i <= j)
	{
		while (student_record[i].id < pivotValue)
		{
			i++;
		}
		while(student_record[j].id > pivotValue)
		{
			j--;
		}
		if (i <= j)
		{
			temp = student_record[i];
			student_record[i] = student_record[j];
			student_record[j] = temp;
			i++;
			j--;
		}
	}
	return i;
}