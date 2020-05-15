
#include "Director.h"
#include <iostream>
using namespace std;
 
 
int main()
{
	AbstractBuilder* builder = new Builder();
	Director* director = new Director(builder);
 
	director->construct();
	
	Product* product = builder->getProduct();
	product->show();
	getchar();
	return 0;
}
