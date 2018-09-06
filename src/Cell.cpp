#include "Cell.h"
#include "Ocean.h"
#include "Object.h"

void Cell::init(Pair p, Ocean* oc)
{
	crd = p;
	ocean = oc;
}
Object* Cell::getObject() const
{
	return obj;
}
void Cell::setObject(Object *obj) 
{
	this->obj = obj;
}

void Cell::killMe()
{
	if (obj)
	{
		ocean->deleteObject(obj);
		delete obj;
		obj = nullptr;
	}
}
