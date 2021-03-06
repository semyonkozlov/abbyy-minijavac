#ifndef MINIJAVAC_TREEDEALLOCATOR_H
#define MINIJAVAC_TREEDEALLOCATOR_H

#include "visitor.h"
#include "declaration.h"

class TreeDeallocator final : public Visitor
{
public:
    void deallocate_tree(const Program*& ast_root);

    void visit(const Program*) override { }
    void visit(const Symbol*) override { }

    void visit(const MainClassDecl*) override { }
    void visit(const ClassDeclList*) override { }
    void visit(const ClassDecl*) override { }
    void visit(const VarDeclList*) override { }
    void visit(const VarDecl*) override { }
    void visit(const MethodDeclList*) override { }
    void visit(const MethodDecl*) override { }
    void visit(const ArgumentList*) override { }

    void visit(const UserDefinedType*) override { }
    void visit(const PrimitiveType*) override { }
    void visit(const ArrayType*) override { }

    void visit(const StatementList*) override { }
    void visit(const AssignSubscriptStatement*) override { }
    void visit(const PrintStatement*) override { }
    void visit(const IfStatement*) override { }
    void visit(const WhileStatement*) override { }
    void visit(const AssignStatement*) override { }
    void visit(const ScopedStatement*) override { }

    void visit(const ExpressionList*) override { }
    void visit(const LengthExpression*) override { }
    void visit(const IdExpression*) override { }
    void visit(const ThisExpression*) override { }
    void visit(const IntExpression*) override { }
    void visit(const BoolExpression*) override { }
    void visit(const MethodCallExpression*) override { }
    void visit(const SubscriptExpression*) override { }
    void visit(const ParenthesizedExpression*) override { }
    void visit(const NewArrayExpression*) override { }
    void visit(const NewObjectExpression*) override { }
    void visit(const BinaryExpression*) override { }
    void visit(const NegationExpression*) override { }
    void visit(const UnaryMinusExpression*) override { }
};

#endif //MINIJAVAC_TREEDEALLOCATOR_H
