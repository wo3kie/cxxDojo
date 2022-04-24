/*
 * Website:
 *      tttps://gittub.com/wo3kie/dojo
 *
 * Auttor:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 copy_move.cpp -o copy_move
 *
 * Usage:
 *      $ ./copy_move
 */

#include <cassert>
#include <utility>

struct S {
    static int m_copy;
    static int m_move;

    static void reset(){
        m_copy = 0;
        m_move = 0;
    }

    S(){}
    S(S const &){ ++m_copy; }
    S(S &&){ ++m_move; }
    S& operator=(S const &){ ++m_copy; return *this; }
    S& operator=(S &&){ ++m_move; return * this; }
};

int S::m_copy = 0;
int S::m_move = 0;

/*
 *
 * clang -Xclang -ast-dump -fsyntax-only -fno-color-diagnostics copy_move.cpp
 *
 */

// |-FunctionDecl 0x824208 <line:50:1, line:52:1> line:50:3 used get_S__return_S 'S (S)'
// | |-ParmVarDecl 0x824148 <col:19, col:21> col:21 used s 'S'
// | `-CompoundStmt 0x824328 <col:23, line:52:1>
// |   `-ReturnStmt 0x824318 <line:51:5, col:12>
// |     `-CXXConstructExpr 0x8242e8 <col:12> 'S' 'void (S &&)'
// |       `-ImplicitCastExpr 0x8242d0 <col:12> 'S' xvalue <NoOp>
// |         `-DeclRefExpr 0x8242b0 <col:12> 'S' lvalue ParmVar 0x824148 's' 'S'
S get_S__return_S(S s){
    return s;
}

// |-FunctionDecl 0x8243e0 <line:63:1, line:65:1> line:63:3 used get_S__return_move_S 'S (S)'
// | |-ParmVarDecl 0x824350 <col:24, col:26> col:26 used s 'S'
// | `-CompoundStmt 0x824f98 <col:28, line:65:1>
// |   `-ReturnStmt 0x824f88 <line:64:5, col:23>
// |     `-CXXConstructExpr 0x824f58 <col:12, col:23> 'S' 'void (S &&)'
// |       `-CallExpr 0x824f30 <col:12, col:23> 'typename std::remove_reference<S &>::type':'S' xvalue
// |         |-ImplicitCastExpr 0x824f18 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
// |         | `-DeclRefExpr 0x824cd8 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0x824bd8 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0x7c3a88 'move')
// |         `-DeclRefExpr 0x8244f0 <col:22> 'S' lvalue ParmVar 0x824350 's' 'S'
S get_S__return_move_S(S s){
    return std::move(s);
}

// |-FunctionDecl 0x825088 <line:74:1, line:76:1> line:74:3 used get_Srefref__return_S 'S (S &&)'
// | |-ParmVarDecl 0x824fc0 <col:25, col:30> col:30 used s 'S &&'
// | `-CompoundStmt 0x8251a8 <col:32, line:76:1>
// |   `-ReturnStmt 0x825198 <line:75:5, col:12>
// |     `-CXXConstructExpr 0x825168 <col:12> 'S' 'void (const S &)'
// |       `-ImplicitCastExpr 0x825150 <col:12> 'const S' lvalue <NoOp>
// |         `-DeclRefExpr 0x825130 <col:12> 'S' lvalue ParmVar 0x824fc0 's' 'S &&'
S get_Srefref__return_S(S && s){
    return s;
}

// |-FunctionDecl 0x825260 <line:87:1, line:89:1> line:87:3 used get_Srefref__return_move_S 'S (S &&)'
// | |-ParmVarDecl 0x8251d0 <col:30, col:35> col:35 used s 'S &&'
// | `-CompoundStmt 0x825480 <col:37, line:89:1>
// |   `-ReturnStmt 0x825470 <line:88:5, col:23>
// |     `-CXXConstructExpr 0x825440 <col:12, col:23> 'S' 'void (S &&)'
// |       `-CallExpr 0x825418 <col:12, col:23> 'typename std::remove_reference<S &>::type':'S' xvalue
// |         |-ImplicitCastExpr 0x825400 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
// |         | `-DeclRefExpr 0x8253c8 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0x824bd8 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0x7c3a88 'move')
// |         `-DeclRefExpr 0x825370 <col:22> 'S' lvalue ParmVar 0x8251d0 's' 'S &&'
S get_Srefref__return_move_S(S && s){
    return std::move(s);
}

// |-FunctionDecl 0x825568 <line:99:1, line:101:1> line:99:6 used get_Srefref__return_Srefref 'S &&(S &&)'
// | |-ParmVarDecl 0x8254a8 <col:34, col:39> col:39 used s 'S &&'
// | `-CompoundStmt 0x825758 <col:41, line:101:1>
// |   `-ReturnStmt 0x825748 <line:100:5, col:23>
// |     `-CallExpr 0x825720 <col:12, col:23> 'typename std::remove_reference<S &>::type':'S' xvalue
// |       |-ImplicitCastExpr 0x825708 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
// |       | `-DeclRefExpr 0x8256d0 <col:12, col:17> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0x824bd8 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0x7c3a88 'move')
// |       `-DeclRefExpr 0x825678 <col:22> 'S' lvalue ParmVar 0x8254a8 's' 'S &&'
S && get_Srefref__return_Srefref(S && s){
    return std::move(s);
}

int main(){
    {
        S::reset();
        S s;

        // | |-DeclStmt 0x825d00 <line:119:9, col:34>
        // | | `-VarDecl 0x825a18 <col:9, col:33> col:11 s2 'S' cinit
        // | |   `-ExprWithCleanups 0x825ce8 <col:16, col:33> 'S'
        // | |     `-CXXConstructExpr 0x825cb8 <col:16, col:33> 'S' 'void (S &&)' elidable
        // | |       `-MaterializeTemporaryExpr 0x825ca0 <col:16, col:33> 'S' xvalue
        // | |         `-CallExpr 0x825b50 <col:16, col:33> 'S'
        // | |           |-ImplicitCastExpr 0x825b38 <col:16> 'S (*)(S)' <FunctionToPointerDecay>
        // | |           | `-DeclRefExpr 0x825ae8 <col:16> 'S (S)' lvalue Function 0x824208 'get_S__return_S' 'S (S)'
        // | |           `-CXXConstructExpr 0x825b90 <col:32> 'S' 'void (const S &)'
        // | |             `-ImplicitCastExpr 0x825b78 <col:32> 'const S' lvalue <NoOp>
        // | |               `-DeclRefExpr 0x825ac8 <col:32> 'S' lvalue Var 0x825960 's' 'S'
        S s2 = get_S__return_S(s);
        assert(S::m_copy == 1);
        assert(S::m_move == 1);
    }

    {
        S::reset();
        S s;

        // | |-DeclStmt 0x826a88 <line:141:9, col:45>
        // | | `-VarDecl 0x8267b0 <col:9, col:44> col:11 s2 'S' cinit
        // | |   `-ExprWithCleanups 0x826a70 <col:16, col:44> 'S'
        // | |     `-CXXConstructExpr 0x826a40 <col:16, col:44> 'S' 'void (S &&)' elidable
        // | |       `-MaterializeTemporaryExpr 0x826a28 <col:16, col:44> 'S' xvalue
        // | |         `-CallExpr 0x8269d0 <col:16, col:44> 'S'
        // | |           |-ImplicitCastExpr 0x8269b8 <col:16> 'S (*)(S)' <FunctionToPointerDecay>
        // | |           | `-DeclRefExpr 0x826998 <col:16> 'S (S)' lvalue Function 0x824208 'get_S__return_S' 'S (S)'
        // | |           `-CXXConstructExpr 0x8269f8 <col:32, col:43> 'S' 'void (S &&)'
        // | |             `-CallExpr 0x826970 <col:32, col:43> 'typename std::remove_reference<S &>::type':'S' xvalue
        // | |               |-ImplicitCastExpr 0x826958 <col:32, col:37> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
        // | |               | `-DeclRefExpr 0x826920 <col:32, col:37> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0x824bd8 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0x7c3a88 'move')
        // | |               `-DeclRefExpr 0x8268c8 <col:42> 'S' lvalue Var 0x8266f8 's' 'S'
        S s2 = get_S__return_S(std::move(s));
        assert(S::m_copy == 0);
        assert(S::m_move == 2);
    }

    {
        S::reset();
        S s;
        // | |-DeclStmt 0x827538 <line:160:9, col:39>
        // | | `-VarDecl 0x827360 <col:9, col:38> col:11 s2 'S' cinit
        // | |   `-ExprWithCleanups 0x827520 <col:16, col:38> 'S'
        // | |     `-CXXConstructExpr 0x8274f0 <col:16, col:38> 'S' 'void (S &&)' elidable
        // | |       `-MaterializeTemporaryExpr 0x8274d8 <col:16, col:38> 'S' xvalue
        // | |         `-CallExpr 0x827468 <col:16, col:38> 'S'
        // | |           |-ImplicitCastExpr 0x827450 <col:16> 'S (*)(S)' <FunctionToPointerDecay>
        // | |           | `-DeclRefExpr 0x827430 <col:16> 'S (S)' lvalue Function 0x8243e0 'get_S__return_move_S' 'S (S)'
        // | |           `-CXXConstructExpr 0x8274a8 <col:37> 'S' 'void (const S &)'
        // | |             `-ImplicitCastExpr 0x827490 <col:37> 'const S' lvalue <NoOp>
        // | |               `-DeclRefExpr 0x827410 <col:37> 'S' lvalue Var 0x8272a8 's' 'S'
        S s2 = get_S__return_move_S(s);
        assert(S::m_copy == 1);
        assert(S::m_move == 1);
    }

    {
        S::reset();
        S s;
        // | |-DeclStmt 0x828110 <line:181:9, col:50>
        // | | `-VarDecl 0x827e10 <col:9, col:49> col:11 s2 'S' cinit
        // | |   `-ExprWithCleanups 0x8280f8 <col:16, col:49> 'S'
        // | |     `-CXXConstructExpr 0x8280c8 <col:16, col:49> 'S' 'void (S &&)' elidable
        // | |       `-MaterializeTemporaryExpr 0x8280b0 <col:16, col:49> 'S' xvalue
        // | |         `-CallExpr 0x828030 <col:16, col:49> 'S'
        // | |           |-ImplicitCastExpr 0x828018 <col:16> 'S (*)(S)' <FunctionToPointerDecay>
        // | |           | `-DeclRefExpr 0x827ff8 <col:16> 'S (S)' lvalue Function 0x8243e0 'get_S__return_move_S' 'S (S)'
        // | |           `-CXXConstructExpr 0x828080 <col:37, col:48> 'S' 'void (S &&)'
        // | |             `-CallExpr 0x827fd0 <col:37, col:48> 'typename std::remove_reference<S &>::type':'S' xvalue
        // | |               |-ImplicitCastExpr 0x827fb8 <col:37, col:42> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
        // | |               | `-DeclRefExpr 0x827f80 <col:37, col:42> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0x824bd8 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0x7c3a88 'move')
        // | |               `-DeclRefExpr 0x827f28 <col:47> 'S' lvalue Var 0x827d58 's' 'S'
        S s2 = get_S__return_move_S(std::move(s));
        assert(S::m_copy == 0);
        assert(S::m_move == 2);
    }

    {
        S::reset();
        S s;
        // | |-DeclStmt 0x828cb8 <line:201:9, col:51>
        // | | `-VarDecl 0x8289e8 <col:9, col:50> col:11 s2 'S' cinit
        // | |   `-ExprWithCleanups 0x828ca0 <col:16, col:50> 'S'
        // | |     `-CXXConstructExpr 0x828c70 <col:16, col:50> 'S' 'void (S &&)' elidable
        // | |       `-MaterializeTemporaryExpr 0x828c58 <col:16, col:50> 'S' xvalue
        // | |         `-CallExpr 0x828c30 <col:16, col:50> 'S'
        // | |           |-ImplicitCastExpr 0x828c18 <col:16> 'S (*)(S &&)' <FunctionToPointerDecay>
        // | |           | `-DeclRefExpr 0x828bd0 <col:16> 'S (S &&)' lvalue Function 0x825088 'get_Srefref__return_S' 'S (S &&)'
        // | |           `-CallExpr 0x828ba8 <col:38, col:49> 'typename std::remove_reference<S &>::type':'S' xvalue
        // | |             |-ImplicitCastExpr 0x828b90 <col:38, col:43> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
        // | |             | `-DeclRefExpr 0x828b58 <col:38, col:43> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0x824bd8 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0x7c3a88 'move')
        // | |             `-DeclRefExpr 0x828b00 <col:48> 'S' lvalue Var 0x828930 's' 'S'
        S s2 = get_Srefref__return_S(std::move(s));
        assert(S::m_copy == 1);
        assert(S::m_move == 0);
    }

    {
        S::reset();
        S s;
        // | |-DeclStmt 0x829838 <line:221:9, col:56>
        // | | `-VarDecl 0x829590 <col:9, col:55> col:11 s2 'S' cinit
        // | |   `-ExprWithCleanups 0x829820 <col:16, col:55> 'S'
        // | |     `-CXXConstructExpr 0x8297f0 <col:16, col:55> 'S' 'void (S &&)' elidable
        // | |       `-MaterializeTemporaryExpr 0x8297d8 <col:16, col:55> 'S' xvalue
        // | |         `-CallExpr 0x8297b0 <col:16, col:55> 'S'
        // | |           |-ImplicitCastExpr 0x829798 <col:16> 'S (*)(S &&)' <FunctionToPointerDecay>
        // | |           | `-DeclRefExpr 0x829778 <col:16> 'S (S &&)' lvalue Function 0x825260 'get_Srefref__return_move_S' 'S (S &&)'
        // | |           `-CallExpr 0x829750 <col:43, col:54> 'typename std::remove_reference<S &>::type':'S' xvalue
        // | |             |-ImplicitCastExpr 0x829738 <col:43, col:48> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
        // | |             | `-DeclRefExpr 0x829700 <col:43, col:48> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0x824bd8 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0x7c3a88 'move')
        // | |             `-DeclRefExpr 0x8296a8 <col:53> 'S' lvalue Var 0x8294d8 's' 'S'
        S s2 = get_Srefref__return_move_S(std::move(s));
        assert(S::m_copy == 0);
        assert(S::m_move == 1);
    }

    {
        S::reset();
        S s;
        // |-DeclStmt 0x82a3e8 <line:239:9, col:57>
        // | `-VarDecl 0x82a148 <col:9, col:56> col:11 s2 'S' cinit
        // |   `-CXXConstructExpr 0x82a3b8 <col:16, col:56> 'S' 'void (S &&)'
        // |     `-CallExpr 0x82a390 <col:16, col:56> 'S' xvalue
        // |       |-ImplicitCastExpr 0x82a378 <col:16> 'S &&(*)(S &&)' <FunctionToPointerDecay>
        // |       | `-DeclRefExpr 0x82a330 <col:16> 'S &&(S &&)' lvalue Function 0x825568 'get_Srefref__return_Srefref' 'S &&(S &&)'
        // |       `-CallExpr 0x82a308 <col:44, col:55> 'typename std::remove_reference<S &>::type':'S' xvalue
        // |         |-ImplicitCastExpr 0x82a2f0 <col:44, col:49> 'typename std::remove_reference<S &>::type &&(*)(S &) noexcept' <FunctionToPointerDecay>
        // |         | `-DeclRefExpr 0x82a2b8 <col:44, col:49> 'typename std::remove_reference<S &>::type &&(S &) noexcept' lvalue Function 0x824bd8 'move' 'typename std::remove_reference<S &>::type &&(S &) noexcept' (FunctionTemplate 0x7c3a88 'move')
        // |         `-DeclRefExpr 0x82a260 <col:54> 'S' lvalue Var 0x82a090 's' 'S'
        S s2 = get_Srefref__return_Srefref(std::move(s));
        assert(S::m_copy == 0);
        assert(S::m_move == 1);
    }
}