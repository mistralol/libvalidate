
#include <libvalidate.h>


ValidateString::ValidateString(const std::string &Field) :
    m_field(Field)
{

}

void ValidateString::Check(const Json::Value &json) const {
    if (json.isMember(m_field) == false) {
        throw(ValidateException("Json field '%s' is required", m_field.c_str()));
    }

    if (json[m_field].isString() == false) {
        throw(ValidateException("Json field '%s' should be type string", m_field.c_str()));
    }
}
