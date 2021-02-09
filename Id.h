#ifndef JO418361_PK418346_ID_H
#define JO418361_PK418346_ID_H

#include <exception>
#include <string>

class wrongIdentifierException : public std::exception {
public:
    [[nodiscard]] const char * what() const noexcept override{
        return "Invalid identifier";
    }
};

class Id {
private:
    std::string id;

    template<typename T>
    friend struct std::hash;
public:
    explicit Id(const char* name);

    bool operator< (const Id &a) const;
    bool operator== (const Id& a) const;
};

namespace std {

    template<>
    struct hash<Id>
    {
        std::size_t operator()(const Id &a) const {
            return std::hash<std::string>()(a.id);
        }
    };

} // hash for Id


#endif //JO418361_PK418346_ID_H
