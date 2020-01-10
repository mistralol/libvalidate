

class ValidateBool : public IValidator {
    public:
        ValidateBool(const std::string &Field);

        void Check(const Json::Value &json) const;

    private:
        std::string m_field;
};
