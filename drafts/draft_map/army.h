#ifndef ARMY_H
#define ARMY_H

class Army
{
    int strength;
    int available;
    int moving;
public:
    void reset();
    void mov(int amount);
    void add(int amount);
    void ret(int amount);
};

#endif // ARMY_H
