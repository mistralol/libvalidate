
class ValidateRegex : public IValidator {
    public:
        ValidateRegex(const std::string field, const std::string &regex, bool MatchCase = false);
        ~ValidateRegex();

        void Check(const Json::Value &json) const;

    private:
        std::string m_field;
        std::string m_regex;
        bool m_case;
};
