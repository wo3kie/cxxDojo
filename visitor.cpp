/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 visitor.cpp -o visitor
 *
 * Usage:
 *      $ ./visitor
 */

#include <iostream>

struct Human;
struct Fish;
struct Bird;

/*
 * IVisitor
 */

struct IVisitor {
  virtual void visit(Human& human) = 0;
  virtual void visit(Fish& fish) = 0;
  virtual void visit(Bird& bird) = 0;
};

/*
 * IVisitable
 */

struct IVisitable {
  virtual void accept(IVisitor& visitor) = 0;
};

/*
 * Concrete classes, Human, Fish, Bird, with no common interface 
 */

 /*
 * Human
 */

struct Human: public IVisitable {
  void accept(IVisitor& visitor) override {
    visitor.visit(*this);
  }

  void walk() {
    std::cout << "Human::walk" << std::endl;
  }
};

/*
 * Fish
 */

struct Fish: public IVisitable {
  void accept(IVisitor& visitor) override {
    visitor.visit(*this);
  }

  void swim() {
    std::cout << "Fish::swim" << std::endl;
  }
};

/*
 * Bird
 */

struct Bird: public IVisitable {
  void accept(IVisitor& visitor) override {
    visitor.visit(*this);
  }

  void fly() {
    std::cout << "Bird::fly" << std::endl;
  }
};

/*
 * GoVisitor
 */

struct GoVisitor: public IVisitor {
  void visit(Human& human) override {
    human.walk();
  }

  void visit(Fish& fish) override {
    fish.swim();
  }

  void visit(Bird& bird) override {
    bird.fly();
  }
};

/*
 * main
 */

int main() {
  GoVisitor v;

  IVisitable* h = new Human;
  IVisitable* f = new Fish;
  IVisitable* b = new Bird;

  h->accept(v); // Human::walk
  f->accept(v); // Fish::swim
  b->accept(v); // Bird::fly

  delete b;
  delete f;
  delete h;
}
