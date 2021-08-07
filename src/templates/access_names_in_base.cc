// Effective C++, Item 43
#include <iostream>
class CompanyA {
 public:
  void sendCleartext(const std::string& msg) {}
  void sendEncrypted(const std::string& msg);
};
class CompanyB {
 public:
  void sendCleartext(const std::string& msg) {}
  void sendEncrypted(const std::string& msg) {}
};
// classes for other companies
class MsgInfo {};  // class for holding information
// used to create a message
template <typename Company>
class MsgSender {
 public:
  // ctors, dtor, etc.
  void sendClear(const MsgInfo& info) {
    std::string msg;
    // create msg from info;
    Company c;
    c.sendCleartext(msg);
  }
  void sendSecret(const MsgInfo& info)  // similar to sendClear, except
  {}                                    // calls c.sendEncrypted
};

class CompanyZ {  // this class offers no
 public:          // sendCleartext function
  void sendEncrypted(const std::string& msg) {}
};

template <>                  // a total specialization of
class MsgSender<CompanyZ> {  // MsgSender; the same as the
 public:                     // general template, except
                             // sendCleartext is omitted
  void sendSecret(const MsgInfo& info) {}
};

// This code will not compile.
// What version of MsgSender are we inheriting from?
template <typename Company>
class LoggingMsgSender : public MsgSender<Company> {
 public:
  // ctors, dtor, etc.
  void sendClearMsg(const MsgInfo& info) {
    // write "before sending" info to the log;

    // if Company == CompanyZ,
    // this function doesn't exist
    // this code will not compile!
    // sendClear(info);

    // write "after sending" info to the log;
  }
};

// Solution1: preface calls to base class functions with "this->":
template <typename Company>
class LoggingMsgSender_sol1 : public MsgSender<Company> {
 public:
  void sendClearMsg(const MsgInfo& info) {
    // write "before sending" info to the log;
    this->sendClear(info);  // okay, assumes that
    // sendClear will be inherited
    // write "after sending" info to the log;
  }
};

template <typename Company>
class LoggingMsgSender_sol2 : public MsgSender<Company> {
 public:
  using MsgSender<Company>::sendClear;  // tell compilers to assume sendClear is
                                        // in the base
  void sendClearMsg(const MsgInfo& info) {
    // write "before sending" info to the log;
    this->sendClear(info);  // okay, assumes that
    // sendClear will be inherited
    // write "after sending" info to the log;
  }
};

// This is generally the least desirable way to solve the problem, because if
// the function being called is virtual, explicit qualification turns off the
// virtual binding behavior.
template <typename Company>
class LoggingMsgSender_sol3 : public MsgSender<Company> {
 public:
  void sendClearMsg(const MsgInfo& info) {
    MsgSender<Company>::sendClear(info);  // okay, assumes that
                                          // sendClear will be
  }                                       // inherited
};

int main(int argc, char const* argv[]) {
  /* code */
  LoggingMsgSender_sol2<CompanyZ> sol1;
  MsgInfo info;
  sol1.sendClearMsg(info);
  return 0;
}
