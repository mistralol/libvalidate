
#include <libvalidate.h>


ValidateBool::ValidateBool(const std::string &Field) :
    m_field(Field)
{

}

void ValidateBool::Check(const Json::Value &json) const {
    if (json.isMember(m_field) == false) {
        throw(ValidateException("Json field '%s' is required", m_field.c_str()));
    }

    if (json[m_field].isBool() == false) {
        throw(ValidateException("Json field '%s' should be type bool", m_field.c_str()));
    }
}
