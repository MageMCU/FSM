#ifndef FSM_StateMachine_h
#define FSM_StateMachine_h

#include <Arduino.h>

#include "State.h"

template <class entity_type>
class StateMachine
{
private:
    entity_type *m_pOwner;
    State<entity_type> *m_pCurrentState;
    State<entity_type> *m_pPreviousState;
    State<entity_type> *m_pGlobalState;

public:
    StateMachine(entity_type *owner) : m_pOwner(owner),
                                       m_pCurrentState(NULL),
                                       m_pPreviousState(NULL),
                                       m_pGlobalState(NULL)
    {
    }
    virtual ~StateMachine() {}
    void SetCurrentState(State<entity_type> *s) { m_pCurrentState = s; }
    void SetGlobalState(State<entity_type> *s) { m_pGlobalState = s; }
    void SetPreviousState(State<entity_type> *s) { m_pPreviousState = s; }
    void Update() const
    {
        if (m_pGlobalState)
            m_pGlobalState->Execute(m_pOwner);
        if (m_pCurrentState)
            m_pCurrentState->Execute(m_pOwner);
    }

    void ChangeState(State<entity_type> *pNewState)
    {
        if (pNewState)
        {
            Serial.println("trying to change to NULL state");
        }
        m_pPreviousState = m_pCurrentState;
        m_pCurrentState->Exit(m_pOwner);
        m_pCurrentState = pNewState;
        m_pCurrentState->Enter(m_pOwner);
    }

    void RevertToPreviousState()
    {
        ChangeState(m_pPreviousState);
    }

    int GetOwnerID()
    {
        return (int)m_pOwner;
    }
    
    bool isInState(const State<entity_type> &st) const
    {
        bool flag = true;
        // ------------------------------------------------- FIXME
        // return typeid(*m_pCurrentState) == typeid(st);
        return flag;
    }

    State<entity_type> *CurrentState() const { return m_pCurrentState; }
    State<entity_type> *GlobalState() const { return m_pGlobalState; }
    State<entity_type> *PreviousState() const { return m_pPreviousState; }
};

#endif
