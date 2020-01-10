

#include <memory>
#include <list>
#include <exception>
#include <functional>
#include <limits.h>

#include <json/json.h>

#include <libvalidate/IValidator.h>
#include <libvalidate/ValidateException.h>

#include <libvalidate/ValidateRegex.h>
#include <libvalidate/ValidateIntRange.h>
#include <libvalidate/ValidateString.h>
#include <libvalidate/ValidateBool.h>
#include <libvalidate/ValidateOptional.h>
#include <libvalidate/ValidateCustom.h>

class Validator {
    public:
        Validator(const std::list<IValidator *> &lst);

        void Add(IValidator *item);
        void Add(std::shared_ptr<IValidator> item);

        void Add(const std::list<IValidator *> &lst);
        void Add(const std::list<std::shared_ptr<IValidator> > &lst);

        void Check(const Json::Value &json) const;

        void Clear();

    private:
        std::list<std::shared_ptr<IValidator> > m_list;
};

