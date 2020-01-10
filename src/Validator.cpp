
#include <libvalidate.h>

Validator::Validator(const std::list<IValidator *> &lst) {
    Add(lst);
}

void Validator::Add(IValidator *item) {
    std::shared_ptr<IValidator> tmp(item);
    m_list.push_back(tmp);

}

void Validator::Add(std::shared_ptr<IValidator> item) {
    m_list.push_back(item);
}

void Validator::Add(const std::list<IValidator *> &lst) {
    for(const auto &it : lst) {
        std::shared_ptr<IValidator> tmp(it);
        m_list.push_back(tmp);
    }
}

void Validator::Add(const std::list<std::shared_ptr<IValidator> > &lst) {
    for(const auto &it : lst) {
        m_list.push_back(it);
    }
}

void Validator::Check(const Json::Value &json) const {
    for(const auto &it : m_list) {
        it->Check(json);
    }
}

void Validator::Clear() {
    m_list.clear();
}
