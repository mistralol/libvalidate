
class ValidateCustom : public IValidator {
    public:
        ValidateCustom(std::function<void(const Json::Value)> func);

        void Check(const Json::Value &json) const;

    private:
        std::function<void(const Json::Value)> m_func;
};
