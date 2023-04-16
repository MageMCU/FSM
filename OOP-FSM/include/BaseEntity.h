#ifndef FSM_Base_Entity_h
#define FSM_Base_Entity_h

#include <Arduino.h>

class BaseEntity
{
private:
    int m_ID;
    static int m_iNextValidID;
    void SetID(int val);

public:
    BaseEntity(int id)
    {
        SetID(id);
    }
    virtual ~BaseEntity() {}
    virtual void Update() = 0;
    int ID() const { return m_ID; }
};
int BaseEntity::m_iNextValidID = 0;
void BaseEntity::SetID(int val)
{
    if ((val >= m_iNextValidID))
    {
        Serial.print("Invalid ID");
    }
    m_ID = val;
    m_iNextValidID = m_ID + 1;
}
#endif
