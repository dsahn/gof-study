/* composite pattern
 * http://jdm.kr/blog/228 : 여기가 더 이해하기 편하게 설명한듯 */

/* source from https://ko.wikipedia.org/wiki/%EC%BB%B4%ED%8F%AC%EC%A7%80%ED%8A%B8_%ED%8C%A8%ED%84%B4 */
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;

class Component
{
  public:
   virtual void list() const = 0;
   virtual ~Component(){};
};

class Leaf : public Component
{
  public:
   explicit Leaf(int val) : value_(val)
   {
   }
   void list() const
   {
      cout << "   " << value_ << "\n";
   }
  private:
   int value_;
};

class Composite : public Component
{
  public:
   explicit Composite(string id) : id_(id)
   {
   }
   void add(Component *obj)
   {
      table_.push_back(obj);
   }
   void list() const
   {
      cout << id_ << ":" << "\n";
      for (vector<Component*>::const_iterator it = table_.begin();
       it != table_.end(); ++it)
      {
         (*it)->list();
      }
   }
  private:
   vector <Component*> table_;
   string id_;
};

int main()
{
   Leaf num0(0);
   Leaf num1(1);
   Leaf num2(2);
   Leaf num3(3);
   Leaf num4(4);
   Composite container1("Container 1");
   Composite container2("Container 2");

   container1.add(&num0);
   container1.add(&num1);

   container2.add(&num2);
   container2.add(&num3);
   container2.add(&num4);

   container1.add(&container2);
   container1.list();
   return 0;
}
