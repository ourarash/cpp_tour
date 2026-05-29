class Button {};
class ListBox {};
class EntryField {};
class Message {};

class FontDialog {
 public:
  void OnMessage(Message* msg);

 private:
  Button* mOk;
  Button* mCancel;
  ListBox* mFontList;
  EntryField* mFontName;
};
