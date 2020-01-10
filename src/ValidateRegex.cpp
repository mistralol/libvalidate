
#include <regex>

#include <libvalidate.h>

ValidateRegex::ValidateRegex(const std::string field, const std::string &regex, bool MatchCase) :
    m_field(field),
    m_regex(regex),
    m_case(MatchCase)
{

}

ValidateRegex::~ValidateRegex() {

}

void ValidateRegex::Check(const Json::Value &json) const {
    if (json.isMember(m_field) == false) {
        throw(ValidateException("Json field '%s' is required", m_field.c_str()));
    }

    if (json[m_field].isString() == false) {
        throw(ValidateException("Json field '%s' should be type string", m_field.c_str()));
    }

    std::string value = json[m_field].asString();
    std::regex ex(m_regex, m_case ? std::regex::basic : std::regex::icase);
    std::cmatch m;
    if (std::regex_match(value, ex) == false) {
        throw(ValidateException("Json field '%s' failed validation", m_field.c_str()));
    }
}
