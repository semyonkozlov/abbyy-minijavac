#ifndef MINIJAVAC_STATEMENT_H
#define MINIJAVAC_STATEMENT_H

#include "grammar_def.h"

class StatementList : public Visitable<StatementList>
{
public:
    StatementList(const Statement* statement, const StatementList* other_statements)
        : statement_(statement), other_statements_(other_statements)
    { }

private:
    const Statement* statement_;
    const StatementList* other_statements_;
};

class Statement
{ };

class ScopedStatement : public Visitable<ScopedStatement>, public Statement
{
public:
    ScopedStatement(const StatementList* statements_in_scope)
        : statements_in_scope_(statements_in_scope)
    { }

private:
    const StatementList* statements_in_scope_;
};

class IfStatement : public Visitable<IfStatement>, public Statement
{
public:
    IfStatement(const Expression* if_condition, const Statement* statement_if_true,
        const Statement* statement_if_false)
        : if_condition_(if_condition), statement_if_true_(statement_if_true), statement_if_false_(statement_if_false)
    { }

private:
    const Expression* if_condition_;
    const Statement* statement_if_true_;
    const Statement* statement_if_false_;
};

class WhileStatement : public Visitable<WhileStatement>, public Statement
{
public:
    WhileStatement(const Expression* loop_condition, const Statement* inloop_statement)
        : loop_condition_(loop_condition), inloop_statement_(inloop_statement)
    { }

private:
    const Expression* loop_condition_;
    const Statement* inloop_statement_;
};

class PrintStatement : public Visitable<PrintStatement>, public Statement
{
public:
    PrintStatement(const Expression* expression_to_print) : expression_to_print_(expression_to_print)
    { }

private:
    const Expression* expression_to_print_;
};

class AssignStatement : public Visitable<AssignStatement>, public Statement
{
public:
    AssignStatement(const Symbol* lhs_var_id, const Expression* rhs_expression)
        : lhs_var_id_(lhs_var_id), rhs_expression_(rhs_expression)
    { }

private:
    const Symbol* lhs_var_id_;
    const Expression* rhs_expression_;
};

class AssignSubscriptStatement : public Visitable<AssignStatement>, public Statement
{
public:
    AssignSubscriptStatement(const Symbol* lhs_array_id, const Expression* subscript,
        const Expression* rhs_expression)
        : lhs_array_id_(lhs_array_id), subscript_(subscript), rhs_expression_(rhs_expression)
    { }

private:
    const Symbol* lhs_array_id_;
    const Expression* subscript_;
    const Expression* rhs_expression_;
};

#endif //MINIJAVAC_STATEMENT_H
