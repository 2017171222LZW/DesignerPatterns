
#include "Builder.h"
#include <iostream>
using namespace std;
 
 
Product::Product()
{
 
}
 
 
Product::~Product()
{
 
}
 
 
void Product::setPartA(int param)
{
	partA = param;
}
 
 
void Product::setPartB(int param)
{
	partB = param;
}
 
 
void Product::setPartC(int param)
{
	partC = param;
}
 
 
void Product::show()
{
	fprintf(stderr,"partA = %d  partB = %d  partC = %d\n",partA,partB,partC);
}
 
 
AbstractBuilder::AbstractBuilder()
{
 
}
 
 
AbstractBuilder::~AbstractBuilder()
{
 
}
 
 
Builder::Builder()
:curProduct(NULL)
{
 
}
 
 
Builder::~Builder()
{
 
}
 
 
void Builder::createProduct()
{
	cout << "����һ����Ʒ�տ�\n" << endl;
	curProduct = new Product();
}
 
 
void Builder::buildPartA(int param)
{
	cout << "���ڹ�����Ʒ��A����\n" << endl;
	curProduct->setPartA(param);
}
 
 
void Builder::buildPartB(int param)
{
	cout << "���ڹ�����Ʒ��B����\n" << endl;
	curProduct->setPartB(param);
}
 
 
void Builder::buildPartC(int param)
{
	cout << "���ڹ�����Ʒ��C����\n" << endl;
	curProduct->setPartC(param);
}
 
 
Product* Builder::getProduct()
{
	return curProduct;
}

