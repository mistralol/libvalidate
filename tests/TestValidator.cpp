#include <libvalidate.h>

int main(int argc, char **argv) {
    Json::Value json;

    json["int"] = 5;
    json["string"] = "Value";
    json["bool"] = true;

    Validator Passes({
        new ValidateIntRange("int"),
        new ValidateIntRange("int", 0, 10),
        new ValidateOptional("int", new ValidateIntRange("int")),
        new ValidateOptional("missing", new ValidateIntRange("missing")),
        new ValidateString("string"),
        new ValidateCustom([](const Json::Value &x) {
            printf("ValidateCustom\n");
        }),
        new ValidateRegex("string", "Value"),
        new ValidateRegex("string", "value"),
        new ValidateBool("bool")
    });

    Passes.Check(json);
    Passes.Clear();

    try {
        Validator Fails({ new ValidateString("missing") });
        Fails.Check(json);
        printf("Failed to detect missing field\n");
        abort();
        Fails.Clear();
    } catch(std::exception &ex) {
        //Pass
    }

    try {
        Validator Fails({ new ValidateIntRange("string")});
        Fails.Check(json);
        abort();
        Fails.Clear();
    } catch(std::exception &ex) {
        //Pass
    }

    try {
        Validator Fails({ new ValidateBool("int")});
        Fails.Check(json);
        abort();
        Fails.Clear();
    } catch(std::exception &ex) {
        //Pass
    }

    return 0;
}