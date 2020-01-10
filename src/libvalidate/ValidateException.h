
class ValidateException : public std::exception {
    public:
        ValidateException(const std::string &msg);
        ValidateException(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));

        ~ValidateException();

        virtual const char *what() const throw();

    private:
        std::string m_message;
};
