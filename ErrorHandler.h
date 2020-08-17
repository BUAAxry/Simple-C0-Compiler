#pragma once
#ifndef ErrorHandler_H

#include <cstdio>
#include <vector>

using std::vector;

enum ErrorType {
    IllegalChar,                // a ok �Ƿ����Ż򲻷��ϴʷ�
    Redefine,                   // b ok �����ض���
    Undefine,                   // c ok δ���������
    ParameterNumNOTMatch,       // d ok ��������������ƥ��
    ParameterTypeNOTMatch,      // e ok �����������Ͳ�ƥ��
    IllegalTypeInCondition,     // f OK �����ж��г��ֲ��Ϸ�������
    VoidFuncWithReturn,         // g OK �޷���ֵ�ĺ������ڲ�ƥ���return���
    ReturnError,                // h ok �з���ֵ�ĺ���ȱ��return������ڲ�ƥ���return���
    SubscriptNotInt,            // i ok ����Ԫ�ص��±�ֻ�������ͱ��ʽ
    ChangeConstant,             // j OK
    SemicolonExpected,          // k OK
    RightParenthesisExpected,   // l ok
    RightBracketsExpected,      // m ok
    WhileExpected,              // n ok
    OnlyIntCharAssignConstant,  // o ok
    OtherError,
};

class ErrorHandler {
    class ErrorInfo {
    public:
        int lineAt;
        ErrorType errorType;
        ErrorInfo(int lineAt, ErrorType errorType) {
            this->lineAt = lineAt;
            this->errorType = errorType;
        }
        bool operator < (const ErrorInfo& e) const {
            return this->lineAt < e.lineAt;
        }
    };
public:
    FILE* errorFile;
    int errorLine;
    int prevSymbolLine;
    vector<ErrorInfo> infoList;

    ErrorHandler(FILE* file);
    ~ErrorHandler();
    bool isErrorOccured();
    void increaseErrorLine();
    void decreaseErrorLine();
    void error2File();
    void error2Console();
    void addErrorInfo(ErrorType errorType);
    void updatePrevSymbolLine(int lineNo);
};

#endif // !ErrorHandler_H