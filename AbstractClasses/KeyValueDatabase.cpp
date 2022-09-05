#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, 
	const std::string& location, const std::string& extension)
	:Object(name, location, extension)
{
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	if(containsPair(entry) == true)
	{
		throw std::invalid_argument("The pair already exists!");
	}

	this->keyValues.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	if(containsKeyValue(key) == false)
	{
		throw std::invalid_argument("The pair does not exist!");
	}
	
	for (size_t i = 0; i < this->keyValues.size(); i++)
	{
		if(keyValues[i].first == key)
		{
			return keyValues[i].second;
		}
	}
}

bool KeyValueDatabase::operator==(const Comparable* other) const
{
	const KeyValueDatabase* key = dynamic_cast<const KeyValueDatabase*>(other);
	if (!key)
		return false;

	bool retValue = true;
	for (size_t i = 0; i < this->keyValues.size(); i++)
	{
		if (keyValues[i].first != key->keyValues[i].first || keyValues[i].second != key->keyValues[i].second)
			retValue = false;
	}
	return retValue;
}

bool KeyValueDatabase::operator!=(const Comparable* other) const
{
	return !(*this == other);
}

std::string KeyValueDatabase::to_string() const
{
	std::string serializedDatabase = this->name + '\n' + this->location + '\n' + this->extension + '\n';

	for (size_t i = 0; i < this->keyValues.size(); i++)
	{
		serializedDatabase += keyValues[i].first;
		serializedDatabase += ":";
		serializedDatabase += std::to_string(keyValues[i].second);
		serializedDatabase += '\n';
	}
	return serializedDatabase;
}

void KeyValueDatabase::from_string(const std::string& serialized)
{
	this->keyValues.clear();
	this->name.clear();
	this->location.clear();
	this->extension.clear();

	std::stringstream stringToConvert(serialized);
	std::getline(stringToConvert, this->name);
	std::getline(stringToConvert, this->location);
	std::getline(stringToConvert, this->extension);

	std::vector <std::string> keyNames;
	std::vector <std::string> values;

	std::string line;
	while(stringToConvert>>line)
	{
		int i = 0;
		std::string currentKey;
		std::string currentValue;
		while(line[i] != ':')
		{
			currentKey += line[i];
			i++;
		}
		i++;
		while(line[i]!='\0')
		{
			currentValue += line[i];
			i++;
		}
		std::pair <std::string, int> currentPair;
		currentPair.first += currentKey;
		std::stringstream value(currentValue);
		value >> currentPair.second;
		this->keyValues.push_back(currentPair);
	}

}

std::string KeyValueDatabase::debug_print() const
{
	std::string debuggedDocument;
	for (size_t i = 0; i < this->keyValues.size(); i++)
	{
		std::string currentLine = "{" + this->keyValues[i].first + ":" +
			std::to_string(this->keyValues[i].second) + "}" + '\n';
		debuggedDocument += currentLine;
	}
	return debuggedDocument;
}

KeyValueDatabase* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}

bool KeyValueDatabase::containsPair(std::pair<std::string, int> keyVal) const
{
	bool doesContain = false;
	for (size_t i = 0; i < this->keyValues.size(); i++)
	{
		if (this->keyValues[i].first == keyVal.first && this->keyValues[i].second == keyVal.second)
			doesContain = true;
	}
	return doesContain;
}

bool KeyValueDatabase::containsKeyValue(const std::string& keyName) const
{
	bool contains = false;
	for (size_t i = 0; i < this->keyValues.size(); i++)
	{
		if (keyValues[i].first == keyName)
			contains = true;
	}
	return contains;
}
