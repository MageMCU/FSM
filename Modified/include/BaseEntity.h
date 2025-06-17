#ifndef Base_Entity_h
#define Base_Entity_h


class BaseEntity
{
private:

  //every entity must have a unique identifying number
  int          m_ID;

  //this is the next valid ID. Each time a BaseEntity is instantiated
  //this value is updated
  static int  m_iNextValidID;

  //this must be called within the constructor to make sure the ID is set
  //correctly. It verifies that the value passed to the method is greater
  //or equal to the next valid ID, before setting the ID and incrementing
  //the next valid ID
  void SetID(int val);

public:

  BaseEntity(int id)
  {
    SetID(id);
  }

  virtual ~BaseEntity(){}

  //all entities must implement an update function
  virtual void  Update()=0;

  int           ID()const{return m_ID;}  
};

#endif


