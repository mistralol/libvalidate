
class IValidator {
    public:
        virtual ~IValidator() { }

        virtual void Check(const Json::Value &json) const = 0;
};
