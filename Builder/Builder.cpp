
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
	cout << "创建一个产品空壳\n" << endl;
	curProduct = new Product();
}
 
 
void Builder::buildPartA(int param)
{
	cout << "正在构建产品的A部分\n" << endl;
	curProduct->setPartA(param);
}
 
 
void Builder::buildPartB(int param)
{
	cout << "正在构建产品的B部分\n" << endl;
	curProduct->setPartB(param);
}
 
 
void Builder::buildPartC(int param)
{
	cout << "正在构建产品的C部分\n" << endl;
	curProduct->setPartC(param);
}
 
 
Product* Builder::getProduct()
{
	return curProduct;
}

