
#include <libvalidate.h>

ValidateOptional::ValidateOptional(const std::string &field, IValidator *validator) :
    m_field(field),
    m_validator(validator)
{

}

ValidateOptional::~ValidateOptional() {

}

void ValidateOptional::Check(const Json::Value &json) const {
    if (json.isMember(m_field) == false)
        return;
    m_validator->Check(json);
}
