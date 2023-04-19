#ifndef USERCHECK_H
#define USERCHECK_H

#include <QString>

bool registerUser(const QString& username, const QString& password);
bool authorizeUser(const QString& username, const QString& password);

#endif // USERCHECK_H
