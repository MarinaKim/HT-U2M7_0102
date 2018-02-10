#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<locale>
#include<time.h>
#include <stdarg.h>

using namespace std;

enum type_number { possitive, negative, all };


int sluch_number(type_number tn, int start, int end)
{

	switch (tn) {
	case possitive:
		return (start + rand() % end);
		break;
	case negative:
		return (start*(-1) + rand() % end);
		break;
	case all:
		return rand();
	}
}


void massiv(int *a, int r, int start, int end, type_number tn)
{
	for (int i = 0; i < r; i++)
	{
		a[i] = sluch_number(tn, start, end);
	}

}


void print_massiv(int *a, int r)
{
	for (int i = 0; i < r; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int Lucky(int *a, int r)
{
	int s=0, s1=0;
	for (int i = 0; i < r/2; i++)
	s+=a[i];
	for (int i = 3; i < r; i++)
		s1 += a[i];

	if (s == s1)
		return 1;
	else 
		return 0;
}

void change(int *a, int r)
{
	int l1,l;
	l = a[0];
	a[0] = a[1];
	a[1] = l;
	l1 = a[2];
	a[2] = a[3];
	a[3] = l1;
}

int delete_ch(int a)
{
	int t = 0, t1 = 1;
	for (; a != 0;)
	{
		if (a % 10 != 3 && a % 10 != 6) {
			t = t + t1*(a% 10);
			t1 *= 10;
		}
		a /= 10;
	}
	return t;
	}

int same_2(int start, int finish)
{
	int s = 0;
	int i1, i2, i3;
	for (int i = start; i <= finish; i++)
	{
		i1 = i / 100;
		i2 = i % 10;
		i3 = (i % 100) / 10;
		if (i1 == i2 || i2 == i3 || i3 == i1)
		{
			s++;
		}
	}
	return s;
}

int raznie(int start, int finish)
{
	int s = 0;
	int i1, i2, i3;
	for (int i = start; i <= finish; i++)
	{
		i1 = i / 100;
		i2 = i % 10;
		i3 = (i % 100) / 10;
		if (i1 !=i2 && i2 != i3 && i3 != i1)
		{
			s++;
		}
	}
	return s;
}

int maximum(int*a,int r)
{
	int s=0,max;
	for (int i = 0; i < r; i++)
	{
		max = i;
		for (int j = i + 1; j < r; j++)
		{
			if (a[j] > a[max])
				max = j;
		}
	}
	return max;
}

void procenty(int *a, int r)
{
	int l;
	for (int i = 0; i < r; i++)
	{
		if (a[i] < 500)
			a[i] = a[i] + (a[i] * 3 / 100);
		else if (a[i] >= 500 && a[i] < 1000)
			a[i] = a[i]+(a[i] * 5 / 100);
		else if (a[i] >= 1000)
			a[i] = a[i] + (a[i] * 8 / 100);
		}
	
}