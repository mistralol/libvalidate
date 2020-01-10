
class ValidateIntRange : public IValidator {
    public:
        ValidateIntRange(const std::string &Field, int Min = INT_MIN, int Max = INT_MAX);

        void Check(const Json::Value &json) const;

    private:
        std::string m_field;
        int m_min;
        int m_max;
};
