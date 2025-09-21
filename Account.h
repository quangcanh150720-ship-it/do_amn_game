#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>

// Đăng ký tài khoản mới
// Trả về true nếu thành công, false nếu username đã tồn tại
bool RegisterAccount(const std::string& username, const std::string& password);

// Đăng nhập
// Trả về true nếu username + password đúng
bool LoginAccount(const std::string& username, const std::string& password);

#endif
