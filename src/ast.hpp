#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>
#include <variant>

enum class Variant
{
    Function,
    Return,
    Constant,
    Program
};

struct AST
{
    Variant Variant;

    std::vector<AST> Children;

    int Value{};
    std::string Name{};

    void PrintAST(AST Program) const;
    void PrintVariant() const;
};

AST CreateProgram(std::vector<AST> Children);
AST CreateFunction(std::string Name, std::vector<AST> Children);
AST CreateReturn(AST Statement);
AST CreateConstant(const int N);

#endif
