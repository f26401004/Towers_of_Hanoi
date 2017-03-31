#include<iostream>
#include<vector>
using namespace std;

void hanoi(int, vector<int>*, vector<int>*, vector<int>*);

int main()
{

	int num;
	cin >> num;
	vector<int> peg1(0), peg2(0), peg3(0);
	for (int i = 0 ; i < num ; ++i)
		peg1.push_back(num -i);
	hanoi(num, &peg1, &peg2, &peg3);
	for (int i = 0 ; i < num ; ++i)
		cout << peg3.at(i) << " ";
	cout << endl;
	return 0;
}

void hanoi(int n, vector<int> *peg1, vector<int> *peg2, vector<int> *peg3)
{
	if(n == 1)
	{
		peg3->push_back(*(peg1->end()-1));
		peg1->erase(peg1->end()-1);
	}
	else
	{
		hanoi(n-1, peg1, peg3, peg2);
		hanoi(1, peg1, peg2, peg3);
		hanoi(n-1, peg2, peg1, peg3);
	}
}
