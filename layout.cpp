/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 *
 * Usage:
 *      $ ./build/bin/struct
 */

// clang++ -cc1 -fdump-record-layouts -std=c++11 struct.cpp

/*
*** Dumping AST Record Layout
         0 | struct Struct_Empty (empty)
           | [sizeof=1, dsize=1, align=1,
           |  nvsize=1, nvalign=1]
*/
struct Struct_Empty {};

static_assert(sizeof(Struct_Empty) == 1, "");
static_assert(alignof(Struct_Empty) == 1, "");

/*
*** Dumping AST Record Layout
         0 | struct Struct_EBO
         0 |   struct Struct_Empty (base) (empty)
         0 |   int i
           | [sizeof=4, dsize=4, align=4,
           |  nvsize=4, nvalign=4]
*/
struct Struct_EBO: Struct_Empty {
  int i;
};

static_assert(sizeof(Struct_EBO) == 4, "");
static_assert(alignof(Struct_EBO) == 4, "");

/*
*** Dumping AST Record Layout
         0 | struct Struct_Base_Virtual
         0 |   (Struct_Base_Virtual vtable pointer)
         8 |   int j
           | [sizeof=16, dsize=12, align=8,
           |  nvsize=12, nvalign=8]
*/
struct Struct_Base_Virtual_1 {
  virtual ~Struct_Base_Virtual_1() {
  }

  int j;
};

static_assert(sizeof(Struct_Base_Virtual_1) == 16, "");
static_assert(alignof(Struct_Base_Virtual_1) == 8, "");

/*
*** Dumping AST Record Layout
         0 | struct Struct_Base_Virtual_2
         0 |   (Struct_Base_Virtual_2 vtable pointer)
         8 |   int k
           | [sizeof=16, dsize=12, align=8,
           |  nvsize=12, nvalign=8]
*/
struct Struct_Base_Virtual_2 {
  virtual ~Struct_Base_Virtual_2() {
  }

  int k;
};

static_assert(sizeof(Struct_Base_Virtual_2) == 16, "");
static_assert(alignof(Struct_Base_Virtual_2) == 8, "");

/*
*** Dumping AST Record Layout
         0 | struct Struct_Derived
         0 |   struct Struct_Base_Virtual (primary base)
         0 |     (Struct_Base_Virtual vtable pointer)
         8 |     int j
        12 |   int l
           | [sizeof=16, dsize=16, align=8,
           |  nvsize=16, nvalign=8]
*/
struct Struct_Derived: Struct_Base_Virtual_1 {
  int l;
};

static_assert(sizeof(Struct_Derived) == 16, "");
static_assert(alignof(Struct_Derived) == 8, "");

/*
*** Dumping AST Record Layout
         0 | struct Struct_Derived_2
         0 |   struct Struct_Base_Virtual (primary base)
         0 |     (Struct_Base_Virtual vtable pointer)
         8 |     int j
        16 |   struct Struct_Base_Virtual_2 (base)
        16 |     (Struct_Base_Virtual_2 vtable pointer)
        24 |     int k
        28 |   int m
           | [sizeof=32, dsize=32, align=8,
           |  nvsize=32, nvalign=8]
*/
struct Struct_Derived_2: Struct_Base_Virtual_1, Struct_Base_Virtual_2 {
  int m;
};

static_assert(sizeof(Struct_Derived_2) == 32, "");
static_assert(alignof(Struct_Derived_2) == 8, "");

/*
*** Dumping AST Record Layout
         0 | struct Struct_Virtual_1
         0 |   (Struct_Virtual_1 vtable pointer)
         8 |   int n
        16 |   struct Struct_Base_Virtual (virtual base)
        16 |     (Struct_Base_Virtual vtable pointer)
        24 |     int j
           | [sizeof=32, dsize=28, align=8,
           |  nvsize=12, nvalign=8]
*/
struct Struct_Virtual_1: virtual Struct_Base_Virtual_1 {
  int n;
};

static_assert(sizeof(Struct_Virtual_1) == 32, "");
static_assert(alignof(Struct_Virtual_1) == 8, "");

/*
*** Dumping AST Record Layout
         0 | struct Struct_Virtual_2
         0 |   (Struct_Virtual_2 vtable pointer)
         8 |   int o
        16 |   struct Struct_Base_Virtual (virtual base)
        16 |     (Struct_Base_Virtual vtable pointer)
        24 |     int j
           | [sizeof=32, dsize=28, align=8,
           |  nvsize=12, nvalign=8]
*/
struct Struct_Virtual_2: virtual Struct_Base_Virtual_1 {
  int o;
};

static_assert(sizeof(Struct_Virtual_2) == 32, "");
static_assert(alignof(Struct_Virtual_2) == 8, "");

/*
*** Dumping AST Record Layout
         0 | struct Struct_Diamond
         0 |   struct Struct_Virtual_1 (primary base)
         0 |     (Struct_Virtual_1 vtable pointer)
         8 |     int n
        16 |   struct Struct_Virtual_2 (base)
        16 |     (Struct_Virtual_2 vtable pointer)
        24 |     int o
        28 |   int p
        32 |   struct Struct_Base_Virtual (virtual base)
        32 |     (Struct_Base_Virtual vtable pointer)
        40 |     int j
           | [sizeof=48, dsize=44, align=8,
           |  nvsize=32, nvalign=8]
*/
struct Struct_Diamond: Struct_Virtual_1, Struct_Virtual_2 {
  int p;
};

static_assert(sizeof(Struct_Diamond) == 48, "");
static_assert(alignof(Struct_Diamond) == 8, "");

int main() {
}
