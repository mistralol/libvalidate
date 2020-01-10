
#include <libvalidate.h>


ValidateIntRange::ValidateIntRange(const std::string &Field, int Min, int Max) :
    m_field(Field),
    m_min(Min),
    m_max(Max)
{

}

void ValidateIntRange::Check(const Json::Value &json) const {
    if (json.isMember(m_field) == false) {
        throw(ValidateException("Json field '%s' is required", m_field.c_str()));
    }

    if (json[m_field].isInt() == false) {
        throw(ValidateException("Json field '%s' should be type int", m_field.c_str()));
    }

    int value = json[m_field].asInt();
    if (value <= m_min || value > m_max) {
        throw(ValidateException("Json field '%s' value '%d' exceeds range min: %d max: %d", m_field.c_str(), value, m_min, m_max));
    }

}
