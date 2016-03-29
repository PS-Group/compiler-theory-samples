#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include <stack>
#include "BatchAST.h"

struct SToken;
class CInterpreterContext;

/// Wraps LEMON generated parser with Object-Oriented API.
class CBatchParser
{
public:
    CBatchParser(CInterpreterContext & context);
    ~CBatchParser();

    bool Advance(int tokenId, SToken const& tokenData);
#ifndef NDEBUG
    void StartDebugTrace(FILE *output);
#endif

    void OnError(SToken const& token);
    void OnStackOverflow();
    void OnFatalError();
    void AddStatement(IStatementASTUniquePtr &&stmt);
    void EnterBlock(CAbstractBlockAST *scope);
    void ExitBlock();

private:
#ifndef NDEBUG
    std::string m_tracePrompt;
#endif
    bool m_isFatalError = false;
    void *m_parser = nullptr;

    std::stack<CAbstractBlockAST *> m_scopes;
    CProgramAst m_program;
};
