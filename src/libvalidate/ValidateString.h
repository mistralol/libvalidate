

class ValidateString : public IValidator {
    public:
        ValidateString(const std::string &Field);

        void Check(const Json::Value &json) const;

    private:
        std::string m_field;
};
