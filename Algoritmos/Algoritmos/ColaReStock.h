#pragma once
#include "Cola.h"
#include "Alimento.h"
class ReStock:public Cola<Alimento>
{
public:
	ReStock();
	~ReStock();

private:

};

ReStock::ReStock()
{
}

ReStock::~ReStock()
{
}