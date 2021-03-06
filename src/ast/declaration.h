#ifndef MINIJAVAC_DECLARATION_H
#define MINIJAVAC_DECLARATION_H

#include "visitor.h"
#include "grammardecl.h"

class Program : public Visitable
{
public:
    Program(const MainClassDecl* main_class, const ClassDeclList* other_classes) :
        main_class_(main_class), other_classes_(other_classes)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    const MainClassDecl* main_class_;
    const ClassDeclList* other_classes_;
};

class MainClassDecl : public Visitable
{
public:
    MainClassDecl(const Symbol* class_id, const Symbol* main_argv_id, const Statement* main_body)
        : class_id_(class_id), main_argv_id_(main_argv_id), main_body_(main_body)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    const Symbol* class_id_;
    const Symbol* main_argv_id_;
    const Statement* main_body_;
};

class ClassDeclList : public Visitable
{
public:
    ClassDeclList(const ClassDecl* new_class, const ClassDeclList* other_classes)
        : new_class_(new_class), other_classes_(other_classes)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    const ClassDecl* new_class_;
    const ClassDeclList* other_classes_;
};

class ClassDecl : public Visitable
{
public:
    ClassDecl(const Symbol* class_id, const Symbol* base_class_id,
        const VarDeclList* variables, const MethodDeclList* methods)
        : class_id_(class_id), base_class_id_(base_class_id), variables_(variables), methods_(methods)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    const Symbol* class_id_;
    const Symbol* base_class_id_;
    const VarDeclList* variables_;
    const MethodDeclList* methods_;
};

class VarDeclList : public Visitable
{
public:
    VarDeclList(const VarDecl* var_decl, const VarDeclList* other_var_decls)
        : var_decl_(var_decl), other_var_decls_(other_var_decls)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    const VarDecl* var_decl_;
    const VarDeclList* other_var_decls_;
};

class VarDecl : public Visitable
{
public:
    VarDecl(const Type* type, const Symbol* var_id)
        : type_(type), var_id_(var_id)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    const Type* type_;
    const Symbol* var_id_;
};

class MethodDeclList : public Visitable
{
public:
    MethodDeclList(const MethodDecl* method_decl, const MethodDeclList* other_methods_decls)
        : method_decl_(method_decl), other_methods_decls_(other_methods_decls)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    const MethodDecl* method_decl_;
    const MethodDeclList* other_methods_decls_;
};

enum class AccessMod
{
    PUBLIC,
    PRIVATE,

    ENUM_SIZE_
};

class MethodDecl : public Visitable
{
public:
    MethodDecl(AccessMod access_mod, const Type* return_type, const Symbol* method_id, const ArgumentList* arg_list,
        const VarDeclList* var_decls, const StatementList* statements, const Expression* return_expression)
        : access_mod_(access_mod), return_type_(return_type), method_id_(method_id), arg_list_(arg_list),
          var_decls_(var_decls), statements_(statements), return_expression_(return_expression)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    AccessMod access_mod_;
    const Type* return_type_;
    const Symbol* method_id_;
    const ArgumentList* arg_list_;
    const VarDeclList* var_decls_;
    const StatementList* statements_;
    const Expression* return_expression_;
};

class ArgumentList : public Visitable
{
public:
    ArgumentList(const Type* arg_type, const Symbol* arg_id, const ArgumentList* other_args)
        : arg_type_(arg_type), arg_id_(arg_id), other_args_(other_args)
    { }

    virtual void accept(Visitor* visitor) const override
    {
        visitor->visit(this);
    }

/*private:*/
    const Type* arg_type_;
    const Symbol* arg_id_;
    const ArgumentList* other_args_;
};

#endif //MINIJAVAC_DECLARATION_H
