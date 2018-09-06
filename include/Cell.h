#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Ocean.h"

//class Ocean;
class Object;

class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object *obj;
	Ocean *ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		crd(p),
		obj(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Pair getPair() const { return crd; }
    Ocean* getOcean() const { return ocean;  }
	Object* getObject() const;
	bool isEmpty() const { return !getObject(); }
	void setObject(Object*);
	void killMe();

};



#endif
