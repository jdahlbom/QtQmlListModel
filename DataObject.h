#include<QString>

class DataObject {  // my custom container class
public:
  DataObject(const QString &firstName,
             const QString &lastName):
     first(firstName),
     last(lastName) {}
  QString first;
  QString last;
};
