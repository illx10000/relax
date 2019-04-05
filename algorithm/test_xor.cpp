#include "xor.h"

#include <iostream>
using namespace std;


int main(int argc,char** argv)
{
	for (int i = 0; i < 10; i++)
	{
		cout << relax::CXor::convert32(i) << "|"
			 << relax::CXor::convert32(relax::CXor::convert32(i)) << endl;
	}

}