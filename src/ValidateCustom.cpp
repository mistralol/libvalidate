
#include <libvalidate.h>

ValidateCustom::ValidateCustom(std::function<void(const Json::Value)> func) :
    m_func(func)
{

}

void ValidateCustom::Check(const Json::Value &json) const {
    m_func(json);
}
