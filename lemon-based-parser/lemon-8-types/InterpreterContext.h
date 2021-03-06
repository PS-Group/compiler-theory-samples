#pragma once

#include <unordered_map>
#include <memory>
#include <boost/optional.hpp>
#include "Value.h"

class CStringPool;
class CVariablesScope;
class IFunctionAst;

class CInterpreterContext
{
public:
    CInterpreterContext(std::ostream &output, std::ostream &errors, CStringPool & pool);
    ~CInterpreterContext();

    void DefineVariable(unsigned nameId, const CValue &value);
    void AssignVariable(unsigned nameId, const CValue &value);
    CValue GetVariableValue(unsigned nameId)const;

    void PushScope(std::unique_ptr<CVariablesScope> && scope);
    std::unique_ptr<CVariablesScope> PopScope();
    size_t GetScopesCount()const;

    IFunctionAst *GetFunction(unsigned nameId)const;
    void AddFunction(unsigned nameId, IFunctionAst *function);

    std::string GetStringLiteral(unsigned stringId)const;

    void SetReturnValue(const boost::optional<CValue> &valueOpt);
    boost::optional<CValue> GetReturnValue()const;

    void PrintResult(const CValue &value);
    void PrintError(std::string const& message);

private:
    CVariablesScope *FindScopeWithVariable(unsigned nameId)const;
    bool ValidateValue(const CValue &value);
    void AddBuiltin(const std::string &name, std::unique_ptr<IFunctionAst> && function);

    std::unordered_map<unsigned, IFunctionAst*> m_functions;
    CStringPool & m_pool;
    boost::optional<CValue> m_returnValueOpt;
    std::vector<std::unique_ptr<IFunctionAst>> m_builtins;
    std::vector<std::unique_ptr<CVariablesScope>> m_scopes;
    std::ostream &m_output;
    std::ostream &m_errors;
};
