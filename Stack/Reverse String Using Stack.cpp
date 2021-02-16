#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

//This function Reverses the String
string ReverseString(string arr)
{
	stack<char> S;  //Default Stack
	
	//This loops pushes each character to the stack 
	for(int i = 0;i<arr.length();i++)
	{
		S.push(arr[i]);
	}
	
	//This loop pops the the stack and overwrite string characters
	for(int i=0;i<arr.length();i++)
	{
		arr[i] = S.top();
		S.pop();
	}
   return arr;
}


int main()
{
	string arr; 
	cout<<"\nEnter the string you want to Reverse: ";
	cin>>arr;
	arr = ReverseString(arr);
	cout<<"\nString after reversal is: "<<arr;
}
