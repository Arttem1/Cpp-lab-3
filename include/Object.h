#ifndef _OBJECT_H_
#define _OBJECT_H_

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {STONE,CORAL,PREY,PREDATOR};

class Cell;
class Object
{
protected:
	Cell *cell;
	static char name;
	static unsigned int count;
public:
	Object(Cell * = nullptr);
	virtual ~Object();
	virtual void live() = 0; // жизнь объекта
	void setCell(Cell*);
	Cell* getCell() { return cell; }
	virtual char getName();
	static unsigned int getCount();	
};

#endif