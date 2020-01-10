
class ValidateOptional : public IValidator {
    public:
        ValidateOptional(const std::string &field, IValidator *validator);
        ~ValidateOptional();

        void Check(const Json::Value &json) const;

    private:
        std::string m_field;
        std::shared_ptr<IValidator> m_validator;
};
