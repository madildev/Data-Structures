#include<iostream>
#include<stack>
#include<ctype.h>
using namespace std;

//This checks whether the character is Operand
bool IsOperand(char op)
{
	if(isdigit(op))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This checks whether the character is Operator
bool IsOperator(char op)
{
	if(op == '+' || op == '-' || op == '*' || op == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This function calculates the expresion
int CalculateExp(int op1,int op2,char ope)
{
	op1 -= 48;
	op2 -= 48;	
	if(ope == '+')
	{
		return op1 + op2; 
	}
	else if(ope == '-')
	{
		return op1 - op2;
	}
	else if(ope == '*')
	{
		return op1 * op2;
	}
	else if(ope == '/')
	{
		return op1/op2;
	}
}

//This function evaluates the postfix expression 
int CalculatePrefix(string exp)
{
	stack<int> S;
	int op1,op2;
	int result;
	int newvalue;
	for(int i = exp.length(); i>=0 ;i--)
	{
		if(IsOperand(exp[i]))
		{
			S.push(exp[i]);
		}
		else if(IsOperator(exp[i]))
		{
			op1 = S.top();
			S.pop();
			op2 = S.top();
			S.pop();
			result = CalculateExp(op1,op2,exp[i]);
			result = result + 48;    //Sends the character value to the stack
			S.push(result);
		}
	}
	return (S.top() - 48);   //Converts value into its actual value
}

int main()
{
	string exp;
	int result;
	cout<<"\nEnter the Prefix Expression: ";
	cin>>exp;
	result = CalculatePrefix(exp);
	cout<<"\nThe Result after Evaluation is: "<<result;
}
