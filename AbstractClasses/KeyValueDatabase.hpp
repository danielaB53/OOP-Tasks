#pragma once

#include "Object.hpp"
#include <utility>
#include <vector>
#include <sstream>


class KeyValueDatabase : public Object
{
public:
    KeyValueDatabase(const std::string& name = "", 
        const std::string& location = "", const std::string& extension = "");

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    bool operator==(const Comparable* other) const override;
    bool operator!=(const Comparable* other) const override;

    std::string to_string() const override;
    void from_string(const std::string& serialized) override;

    std::string debug_print() const override;

    KeyValueDatabase* clone() const override;
private:
    std::vector<std::pair <std::string, int>> keyValues;
    bool containsPair(std::pair<std::string, int> keyVal) const;
    bool containsKeyValue(const std::string& keyName) const;
};