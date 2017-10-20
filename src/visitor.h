#ifndef MINIJAVAC_VISITOR_H
#define MINIJAVAC_VISITOR_H

#include "grammar_decl.h"

struct Visitor
{
    virtual ~Visitor() = default;

    virtual void visit(const Program*) = 0;
    virtual void visit(const Symbol*) = 0;

    virtual void visit(const MainClass*) = 0;
    virtual void visit(const ClassDeclList*) = 0;
    virtual void visit(const ClassDecl*) = 0;
    virtual void visit(const VarDeclList*) = 0;
    virtual void visit(const VarDecl*) = 0;
    virtual void visit(const MethodDeclList*) = 0;
    virtual void visit(const MethodDecl*) = 0;
    virtual void visit(const ArgumentList*) = 0;

    // virtual void visit(const Type*) = 0;
    virtual void visit(const UserDefinedType*) = 0;
    virtual void visit(const PrimitiveType*) = 0;
    virtual void visit(const ArrayType*) = 0;

    // virtual void visit(const Statement*) = 0;
    virtual void visit(const StatementList*) = 0;
    virtual void visit(const AssignSubscriptStatement*) = 0;
    virtual void visit(const PrintStatement*) = 0;
    virtual void visit(const IfStatement*) = 0;
    virtual void visit(const WhileStatement*) = 0;
    virtual void visit(const AssignStatement*) = 0;
    virtual void visit(const ScopedStatement*) = 0;

    // virtual void visit(const Expression*) = 0;
    virtual void visit(const ExpressionList*) = 0;
    virtual void visit(const LengthExpression*) = 0;
    virtual void visit(const IdExpression*) = 0;
    virtual void visit(const ThisExpression*) = 0;
    virtual void visit(const IntExpression*) = 0;
    virtual void visit(const BoolExpression*) = 0;
    virtual void visit(const MethodCallExpression*) = 0;
    virtual void visit(const SubscriptExpression*) = 0;
    virtual void visit(const ParenthesizedExpression*) = 0;
    virtual void visit(const NewArrayExpression*) = 0;
    virtual void visit(const NewObjectExpression*) = 0;
    virtual void visit(const BinaryExpression*) = 0;
    virtual void visit(const NegationExpression*) = 0;
};

struct Visitable
{
    virtual ~Visitable() = default;

    virtual void accept(Visitor* visitor) const = 0;
};

#endif //MINIJAVAC_VISITOR_H
