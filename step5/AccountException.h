#ifndef ACCOUNT_EXCEPTION_H_
#define ACCOUNT_EXCEPTION_H_

#include <stdexcept>
#include <string>
#include "account.h" // 需要提前声明 Account

class AccountException : public std::runtime_error {
private:
    const Account* account; // 指向出错账户的指针
public:
    AccountException(const std::string& message, const Account* acc)
        : std::runtime_error(message), account(acc) {}

    const Account* getAccount() const { return account; }
};

#endif // ACCOUNT_EXCEPTION_H_