#include <stdarg.h>

#include <libvalidate.h>

ValidateException::ValidateException(const std::string &msg) {
    m_message = msg;
}

ValidateException::ValidateException(const char *fmt, ...) {
    char *tmp = 0;
    va_list ap;
    va_start(ap, fmt);
    int res = vasprintf(&tmp, fmt, ap);
    if (res < 0)
            abort();
    m_message = tmp;
    free(tmp);
    va_end(ap);
}

ValidateException::~ValidateException() {

}

const char *ValidateException::what() const throw() {
    return m_message.c_str();
}
