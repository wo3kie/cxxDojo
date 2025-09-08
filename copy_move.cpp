/*
 * Website:
 *      tttps://gittub.com/wo3kie/dojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 copy_move.cpp -o copy_move
 *
 * Usage:
 *      $ ./copy_move
 */

#include <cassert>
#include <utility>

struct S {
  static int m_copy;
  static int m_move;
  static int m_destroyed;

  static void reset() {
    m_copy = 0;
    m_move = 0;
    m_destroyed = 0;
  }

  ~S() {
    ++m_destroyed;
  }
  S() {
  }
  S(S const&) {
    ++m_copy;
  }
  S(S&&) {
    ++m_move;
  }
  S& operator=(S const&) {
    ++m_copy;
    return *this;
  }
  S& operator=(S&&) {
    ++m_move;
    return *this;
  }
};

int S::m_copy = 0;
int S::m_move = 0;
int S::m_destroyed = 0;

/*
 *
 * clang -Xclang -ast-dump -fsyntax-only -fno-color-diagnostics copy_move.cpp
 *
 */

// |-FunctionDecl 0xf3e378 <line:54:1, line:56:1> line:54:3 used get_S__return_S 'S (S)'
// | |-ParmVarDecl 0xf3e2b0 <col:19, col:21> col:21 used s 'S' destroyed
// | `-CompoundStmt 0xf3e498 <col:23, line:56:1>
// |   `-ReturnStmt 0xf3e488 <line:55:5, col:12>
// |     `-CXXConstructExpr 0xf3e458 <col:12> 'S' 'void (S &&)'
// |       `-ImplicitCastExpr 0xf3e440 <col:12> 'S' xvalue <NoOp>
// |         `-DeclRefExpr 0xf3e420 <col:12> 'S' lvalue ParmVar 0xf3e2b0 's' 'S'
S get_S__return_S(S s) {
  return s;
}

// |-FunctionDecl 0xf3e550 <line:67:1, line:69:1> line:67:3 used get_S__return_move_S 'S (S)'
// | |-ParmVarDecl 0xf3e4c0 <col:24, col:26> col:26 used s 'S' destroyed
// | `-CompoundStmt 0xf3f108 <col:28, line:69:1>
// |   `-ReturnStmt 0xf3f0f8 <line:68:5, col:23>
// |     `-CXXConstructExpr 0xf3f0c8 <col:12, col:23> 'S' 'void (S &&)'
// |       `-CallExpr 0xf3f0a0 <col:12, col:23> 'typename std::remove_reference<S &>::type':'S' xvalue
// |         |-ImplicitCastExpr 0xf3f088 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
// |         | `-DeclRefExpr 0xf3ee48 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0xf3ed48 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0xeddb08 'move')
// |         `-DeclRefExpr 0xf3e660 <col:22> 'S' lvalue ParmVar 0xf3e4c0 's' 'S'
S get_S__return_move_S(S s) {
  return std::move(s);
}

// |-FunctionDecl 0xf3f1f8 <line:78:1, line:80:1> line:78:3 used get_Srefref__return_S 'S (S &&)'
// | |-ParmVarDecl 0xf3f130 <col:25, col:30> col:30 used s 'S &&'
// | `-CompoundStmt 0xf3f318 <col:32, line:80:1>
// |   `-ReturnStmt 0xf3f308 <line:79:5, col:12>
// |     `-CXXConstructExpr 0xf3f2d8 <col:12> 'S' 'void (const S &)'
// |       `-ImplicitCastExpr 0xf3f2c0 <col:12> 'const S' lvalue <NoOp>
// |         `-DeclRefExpr 0xf3f2a0 <col:12> 'S' lvalue ParmVar 0xf3f130 's' 'S &&'
S get_Srefref__return_S(S&& s) {
  return s;
}

// |-FunctionDecl 0xf3f3d0 <line:91:1, line:93:1> line:91:3 used get_Srefref__return_move_S 'S (S &&)'
// | |-ParmVarDecl 0xf3f340 <col:30, col:35> col:35 used s 'S &&'
// | `-CompoundStmt 0xf3f5f0 <col:37, line:93:1>
// |   `-ReturnStmt 0xf3f5e0 <line:92:5, col:23>
// |     `-CXXConstructExpr 0xf3f5b0 <col:12, col:23> 'S' 'void (S &&)'
// |       `-CallExpr 0xf3f588 <col:12, col:23> 'typename std::remove_reference<S &>::type':'S' xvalue
// |         |-ImplicitCastExpr 0xf3f570 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
// |         | `-DeclRefExpr 0xf3f538 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0xf3ed48 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0xeddb08 'move')
// |         `-DeclRefExpr 0xf3f4e0 <col:22> 'S' lvalue ParmVar 0xf3f340 's' 'S &&'
S get_Srefref__return_move_S(S&& s) {
  return std::move(s);
}

// |-FunctionDecl 0xf3f6d8 <line:103:1, line:105:1> line:103:6 used get_Srefref__return_Srefref 'S &&(S &&)'
// | |-ParmVarDecl 0xf3f618 <col:34, col:39> col:39 used s 'S &&'
// | `-CompoundStmt 0xf3f8c8 <col:41, line:105:1>
// |   `-ReturnStmt 0xf3f8b8 <line:104:5, col:23>
// |     `-CallExpr 0xf3f890 <col:12, col:23> 'typename std::remove_reference<S &>::type':'S' xvalue
// |       |-ImplicitCastExpr 0xf3f878 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
// |       | `-DeclRefExpr 0xf3f840 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0xf3ed48 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0xeddb08 'move')
// |       `-DeclRefExpr 0xf3f7e8 <col:22> 'S' lvalue ParmVar 0xf3f618 's' 'S &&'
S&& get_Srefref__return_Srefref(S&& s) {
  return std::move(s);
}

int main() {
  {
    S::reset();
    S s;

    // | `-DeclStmt 0xf3fde0 <line:125:9, col:34>
    // |   `-VarDecl 0xf3fb88 <col:9, col:33> col:11 s2 'S' cinit destroyed
    // |     `-ExprWithCleanups 0xf3fdc8 <col:16, col:33> 'S'
    // |       `-CXXConstructExpr 0xf3fd98 <col:16, col:33> 'S' 'void (S &&)' elidable
    // |         `-MaterializeTemporaryExpr 0xf3fd80 <col:16, col:33> 'S' xvalue
    // |           `-CXXBindTemporaryExpr 0xf3fd60 <col:16, col:33> 'S' (CXXTemporary 0xf3fd60)
    // |             `-CallExpr 0xf3fcc0 <col:16, col:33> 'S'
    // |               |-ImplicitCastExpr 0xf3fca8 <col:16> 'S (*)(S)' <FunctionToPointerDecay>
    // |               | `-DeclRefExpr 0xf3fc58 <col:16> 'S (S)' lvalue Function 0xf3e378 'get_S__return_S' 'S (S)'
    // |               `-CXXBindTemporaryExpr 0xf3fd38 <col:32> 'S' (CXXTemporary 0xf3fd38)
    // |                 `-CXXConstructExpr 0xf3fd00 <col:32> 'S' 'void (const S &)'
    // |                   `-ImplicitCastExpr 0xf3fce8 <col:32> 'const S' lvalue <NoOp>
    // |                     `-DeclRefExpr 0xf3fc38 <col:32> 'S' lvalue Var 0xf3fad0 's' 'S'
    S s2 = get_S__return_S(s);
  }

  assert(S::m_copy == 1);
  assert(S::m_move == 1);
  assert(S::m_destroyed == 3);

  {
    S::reset();
    S s;

    // | `-DeclStmt 0xf40fd0 <line:151:9, col:45>
    // |   `-VarDecl 0xf40ca8 <col:9, col:44> col:11 s2 'S' cinit destroyed
    // |     `-ExprWithCleanups 0xf40fb8 <col:16, col:44> 'S'
    // |       `-CXXConstructExpr 0xf40f88 <col:16, col:44> 'S' 'void (S &&)' elidable
    // |         `-MaterializeTemporaryExpr 0xf40f70 <col:16, col:44> 'S' xvalue
    // |           `-CXXBindTemporaryExpr 0xf40f50 <col:16, col:44> 'S' (CXXTemporary 0xf40f50)
    // |             `-CallExpr 0xf40ec8 <col:16, col:44> 'S'
    // |               |-ImplicitCastExpr 0xf40eb0 <col:16> 'S (*)(S)' <FunctionToPointerDecay>
    // |               | `-DeclRefExpr 0xf40e90 <col:16> 'S (S)' lvalue Function 0xf3e378 'get_S__return_S' 'S (S)'
    // |               `-CXXBindTemporaryExpr 0xf40f28 <col:32, col:43> 'S' (CXXTemporary 0xf40f28)
    // |                 `-CXXConstructExpr 0xf40ef0 <col:32, col:43> 'S' 'void (S &&)'
    // |                   `-CallExpr 0xf40e68 <col:32, col:43> 'typename std::remove_reference<S &>::type':'S' xvalue
    // |                     |-ImplicitCastExpr 0xf40e50 <col:32, col:37> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
    // |                     | `-DeclRefExpr 0xf40e18 <col:32, col:37> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0xf3ed48 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0xeddb08 'move')
    // |                     `-DeclRefExpr 0xf40dc0 <col:42> 'S' lvalue Var 0xf40bf0 's' 'S'
    S s2 = get_S__return_S(std::move(s));
  }

  assert(S::m_copy == 0);
  assert(S::m_move == 2);
  assert(S::m_destroyed == 3);

  {
    S::reset();
    S s;
    // | `-DeclStmt 0xf41e58 <line:174:9, col:39>
    // |   `-VarDecl 0xf41c30 <col:9, col:38> col:11 s2 'S' cinit destroyed
    // |     `-ExprWithCleanups 0xf41e40 <col:16, col:38> 'S'
    // |       `-CXXConstructExpr 0xf41e10 <col:16, col:38> 'S' 'void (S &&)' elidable
    // |         `-MaterializeTemporaryExpr 0xf41df8 <col:16, col:38> 'S' xvalue
    // |           `-CXXBindTemporaryExpr 0xf41dd8 <col:16, col:38> 'S' (CXXTemporary 0xf41dd8)
    // |             `-CallExpr 0xf41d38 <col:16, col:38> 'S'
    // |               |-ImplicitCastExpr 0xf41d20 <col:16> 'S (*)(S)' <FunctionToPointerDecay>
    // |               | `-DeclRefExpr 0xf41d00 <col:16> 'S (S)' lvalue Function 0xf3e550 'get_S__return_move_S' 'S (S)'
    // |               `-CXXBindTemporaryExpr 0xf41db0 <col:37> 'S' (CXXTemporary 0xf41db0)
    // |                 `-CXXConstructExpr 0xf41d78 <col:37> 'S' 'void (const S &)'
    // |                   `-ImplicitCastExpr 0xf41d60 <col:37> 'const S' lvalue <NoOp>
    // |                     `-DeclRefExpr 0xf41ce0 <col:37> 'S' lvalue Var 0xf41b78 's' 'S'
    S s2 = get_S__return_move_S(s);
  }

  assert(S::m_copy == 1);
  assert(S::m_move == 1);
  assert(S::m_destroyed == 3);

  {
    S::reset();
    S s;
    // | `-DeclStmt 0xf42e00 <line:199:9, col:50>
    // |   `-VarDecl 0xf42ad8 <col:9, col:49> col:11 s2 'S' cinit destroyed
    // |     `-ExprWithCleanups 0xf42de8 <col:16, col:49> 'S'
    // |       `-CXXConstructExpr 0xf42db8 <col:16, col:49> 'S' 'void (S &&)' elidable
    // |         `-MaterializeTemporaryExpr 0xf42da0 <col:16, col:49> 'S' xvalue
    // |           `-CXXBindTemporaryExpr 0xf42d80 <col:16, col:49> 'S' (CXXTemporary 0xf42d80)
    // |             `-CallExpr 0xf42cf8 <col:16, col:49> 'S'
    // |               |-ImplicitCastExpr 0xf42ce0 <col:16> 'S (*)(S)' <FunctionToPointerDecay>
    // |               | `-DeclRefExpr 0xf42cc0 <col:16> 'S (S)' lvalue Function 0xf3e550 'get_S__return_move_S' 'S (S)'
    // |               `-CXXBindTemporaryExpr 0xf42d58 <col:37, col:48> 'S' (CXXTemporary 0xf42d58)
    // |                 `-CXXConstructExpr 0xf42d20 <col:37, col:48> 'S' 'void (S &&)'
    // |                   `-CallExpr 0xf42c98 <col:37, col:48> 'typename std::remove_reference<S &>::type':'S' xvalue
    // |                     |-ImplicitCastExpr 0xf42c80 <col:37, col:42> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
    // |                     | `-DeclRefExpr 0xf42c48 <col:37, col:42> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0xf3ed48 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0xeddb08 'move')
    // |                     `-DeclRefExpr 0xf42bf0 <col:47> 'S' lvalue Var 0xf42a20 's' 'S'
    S s2 = get_S__return_move_S(std::move(s));
  }

  assert(S::m_copy == 0);
  assert(S::m_move == 2);
  assert(S::m_destroyed == 3);

  {
    S::reset();
    S s;
    // | `-DeclStmt 0xf43d60 <line:222:9, col:51>
    // |   `-VarDecl 0xf43a60 <col:9, col:50> col:11 s2 'S' cinit destroyed
    // |     `-ExprWithCleanups 0xf43d48 <col:16, col:50> 'S'
    // |       `-CXXConstructExpr 0xf43d18 <col:16, col:50> 'S' 'void (S &&)' elidable
    // |         `-MaterializeTemporaryExpr 0xf43d00 <col:16, col:50> 'S' xvalue
    // |           `-CXXBindTemporaryExpr 0xf43ce0 <col:16, col:50> 'S' (CXXTemporary 0xf43ce0)
    // |             `-CallExpr 0xf43cb0 <col:16, col:50> 'S'
    // |               |-ImplicitCastExpr 0xf43c98 <col:16> 'S (*)(S &&)' <FunctionToPointerDecay>
    // |               | `-DeclRefExpr 0xf43c48 <col:16> 'S (S &&)' lvalue Function 0xf3f1f8 'get_Srefref__return_S' 'S (S &&)'
    // |               `-CallExpr 0xf43c20 <col:38, col:49> 'typename std::remove_reference<S &>::type':'S' xvalue
    // |                 |-ImplicitCastExpr 0xf43c08 <col:38, col:43> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
    // |                 | `-DeclRefExpr 0xf43bd0 <col:38, col:43> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0xf3ed48 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0xeddb08 'move')
    // |                 `-DeclRefExpr 0xf43b78 <col:48> 'S' lvalue Var 0xf439a8 's' 'S'
    S s2 = get_Srefref__return_S(std::move(s));
  }

  assert(S::m_copy == 1);
  assert(S::m_move == 0);
  assert(S::m_destroyed == 2);

  {
    S::reset();
    S s;
    // | `-DeclStmt 0xf44cb0 <line:245:9, col:56>
    // |   `-VarDecl 0xf449e0 <col:9, col:55> col:11 s2 'S' cinit destroyed
    // |     `-ExprWithCleanups 0xf44c98 <col:16, col:55> 'S'
    // |       `-CXXConstructExpr 0xf44c68 <col:16, col:55> 'S' 'void (S &&)' elidable
    // |         `-MaterializeTemporaryExpr 0xf44c50 <col:16, col:55> 'S' xvalue
    // |           `-CXXBindTemporaryExpr 0xf44c30 <col:16, col:55> 'S' (CXXTemporary 0xf44c30)
    // |             `-CallExpr 0xf44c00 <col:16, col:55> 'S'
    // |               |-ImplicitCastExpr 0xf44be8 <col:16> 'S (*)(S &&)' <FunctionToPointerDecay>
    // |               | `-DeclRefExpr 0xf44bc8 <col:16> 'S (S &&)' lvalue Function 0xf3f3d0 'get_Srefref__return_move_S' 'S (S &&)'
    // |               `-CallExpr 0xf44ba0 <col:43, col:54> 'typename std::remove_reference<S &>::type':'S' xvalue
    // |                 |-ImplicitCastExpr 0xf44b88 <col:43, col:48> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
    // |                 | `-DeclRefExpr 0xf44b50 <col:43, col:48> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0xf3ed48 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0xeddb08 'move')
    // |                 `-DeclRefExpr 0xf44af8 <col:53> 'S' lvalue Var 0xf44928 's' 'S'
    S s2 = get_Srefref__return_move_S(std::move(s));
  }

  assert(S::m_copy == 0);
  assert(S::m_move == 1);
  assert(S::m_destroyed == 2);

  {
    S::reset();
    S s;
    // | `-DeclStmt 0xf45bb8 <line:265:9, col:57>
    // |   `-VarDecl 0xf45910 <col:9, col:56> col:11 s2 'S' cinit destroyed
    // |     `-CXXConstructExpr 0xf45b88 <col:16, col:56> 'S' 'void (S &&)'
    // |       `-CallExpr 0xf45b60 <col:16, col:56> 'S' xvalue
    // |         |-ImplicitCastExpr 0xf45b48 <col:16> 'S &&(*)(S &&)' <FunctionToPointerDecay>
    // |         | `-DeclRefExpr 0xf45af8 <col:16> 'S &&(S &&)' lvalue Function 0xf3f6d8 'get_Srefref__return_Srefref' 'S &&(S &&)'
    // |         `-CallExpr 0xf45ad0 <col:44, col:55> 'typename std::remove_reference<S &>::type':'S' xvalue
    // |           |-ImplicitCastExpr 0xf45ab8 <col:44, col:49> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
    // |           | `-DeclRefExpr 0xf45a80 <col:44, col:49> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0xf3ed48 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0xeddb08 'move')
    // |           `-DeclRefExpr 0xf45a28 <col:54> 'S' lvalue Var 0xf45858 's' 'S'
    S s2 = get_Srefref__return_Srefref(std::move(s));
  }

  assert(S::m_copy == 0);
  assert(S::m_move == 1);
  assert(S::m_destroyed == 2);
}