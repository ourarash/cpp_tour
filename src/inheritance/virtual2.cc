#include <iostream>
#include <memory>
#include <string>
class DatabaseID {};
class IPerson {
 public:
  virtual ~IPerson();
  virtual std::string name() const = 0;
  virtual std::string birthDate() const = 0;
};

class PersonInfo {
 public:
  explicit PersonInfo(DatabaseID pid);
  virtual ~PersonInfo();
  virtual const char *theName() const;
  virtual const char *theBirthDate() const;

 private:
  virtual const char *valueDelimOpen() const;   // see
  virtual const char *valueDelimClose() const;  // below
};

const char *PersonInfo::valueDelimOpen() const {
  return "[";  // default opening delimiter
}
const char *PersonInfo::valueDelimClose() const {
  return "]";  // default closing delimiter
}

#define Max_Formatted_Field_Value_Length 10
const char *PersonInfo::theName() const {
  // reserve buffer for return value; because this is
  // static, it's automatically initialized to all zeros
  static char value[Max_Formatted_Field_Value_Length];

  // write opening delimiter
  std::strcpy(value, valueDelimOpen());
  // append to the string in value this object's name field (being careful
  // to avoid buffer overruns!)

  // write closing delimiter
  std::strcat(value, valueDelimClose());
  return value;
}

class CPerson : public IPerson, private PersonInfo {  // note use of MI
 public:
  explicit CPerson(DatabaseID pid) : PersonInfo(pid) {}
  virtual std::string name() const  // implementations
  {
    return PersonInfo::theName();
  }  // of the required
  // IPerson member
  virtual std::string birthDate() const  // functions
  {
    return PersonInfo::theBirthDate();
  }

 private:                                             // redefinitions of
  const char *valueDelimOpen() const { return ""; }   // inherited virtual
  const char *valueDelimClose() const { return ""; }  // delimiter
};                                                    //

// factory function to create a Person object from a unique database ID;
// see Item 18 for why the return type isn't a raw pointer
std::unique_ptr<IPerson> makePerson(DatabaseID personIdentifier);

// function to get a database ID from the user
DatabaseID askUserForDatabaseID();

int main(int argc, char const *argv[]) {
  DatabaseID id(askUserForDatabaseID());
  std::unique_ptr<IPerson> pp(makePerson(id));  // create an object
                                                // supporting the
                                                // IPerson interface
                                                // manipulate *pp via
                                                // IPerson's member
                                                // functions
  return 0;
}
