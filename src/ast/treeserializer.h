#ifndef MINIJAVAC_TREESERIALIZER_H
#define MINIJAVAC_TREESERIALIZER_H

#include <string>
#include <array>
#include <sstream>
#include <queue>

#include "visitor.h"
#include "grammardecl.h"

class TreeSerializer final : public Visitor
{
public:
    TreeSerializer();

    std::string ast_tree_to_dot(const Program* ast_root);

    void visit(const Program*) override;
    void visit(const Symbol*) override;

    void visit(const MainClassDecl*) override;
    void visit(const ClassDeclList*) override;
    void visit(const ClassDecl*) override;
    void visit(const VarDeclList*) override;
    void visit(const VarDecl*) override;
    void visit(const MethodDeclList*) override;
    void visit(const MethodDecl*) override;
    void visit(const ArgumentList*) override;

    void visit(const UserDefinedType*) override;
    void visit(const PrimitiveType*) override;
    void visit(const ArrayType*) override;

    void visit(const StatementList*) override;
    void visit(const AssignSubscriptStatement*) override;
    void visit(const PrintStatement*) override;
    void visit(const IfStatement*) override;
    void visit(const WhileStatement*) override;
    void visit(const AssignStatement*) override;
    void visit(const ScopedStatement*) override;

    void visit(const ExpressionList*) override;
    void visit(const LengthExpression*) override;
    void visit(const IdExpression*) override;
    void visit(const ThisExpression*) override;
    void visit(const IntExpression*) override;
    void visit(const BoolExpression*) override;
    void visit(const MethodCallExpression*) override;
    void visit(const SubscriptExpression*) override;
    void visit(const ParenthesizedExpression*) override;
    void visit(const NewArrayExpression*) override;
    void visit(const NewObjectExpression*) override;
    void visit(const BinaryExpression*) override;
    void visit(const NegationExpression*) override;
    void visit(const UnaryMinusExpression*) override;

private:
    enum SyntaxType
    {
        PROGRAM,
        SYMBOL,
        MAIN_CLASS,
        CLASS_DECL_LIST,
        CLASS_DECL,
        VAR_DECL_LIST,
        VAR_DECL,
        METHOD_DECL_LIST,
        METHOD_DECL,
        ARGUMENT_LIST,
        USER_DEFINED_TYPE,
        PRIMITIVE_TYPE,
        ARRAY_TYPE,
        STATEMENT_LIST,
        ASSIGN_SUBSCRIPT_STATEMENT,
        PRINT_STATEMENT,
        IF_STATEMENT,
        WHILE_STATEMENT,
        ASSIGN_STATEMENT,
        SCOPED_STATEMENT,
        EXPRESSION_LIST,
        LENGTH_EXPRESSION,
        ID_EXPRESSION,
        THIS_EXPRESSION,
        INT_EXPRESSION,
        BOOL_EXPRESSION,
        METHOD_CALL_EXPRESSION,
        SUBSCRIPT_EXPRESSION,
        PARENTHESIZED_EXPRESSION,
        NEW_ARRAY_EXPRESSION,
        NEW_OBJECT_EXPRESSION,
        BINARY_EXPRESSION,
        NEGATION_EXPRESSION,
        UNARY_MINUS_EXPRESSION,

        ENUM_SIZE_
    };

    static const std::size_t NUM_SYNTAX_TYPES = ENUM_SIZE_;

    std::stringstream dot_stream_;
    SyntaxType parent_;
    std::array<std::size_t, NUM_SYNTAX_TYPES> syntax_counter_;
    std::array<std::string, NUM_SYNTAX_TYPES> syntax_label_;

    void add_edge_(SyntaxType from, SyntaxType to);
    void add_vertex_(SyntaxType syntax_type);
};

#endif //MINIJAVAC_TREESERIALIZER_H
