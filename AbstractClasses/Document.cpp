#include "Document.hpp"

Document::Document(const std::string& name, const std::string& location, const std::string& extension)
	:Object(name, location, extension), lineToBeRead(0)
{
}

void Document::write_line(const std::string& line)
{
	this->document.push_back(line);
}

std::string Document::read_line()
{
	if (lineToBeRead >= this->document.size())
	{
		throw std::out_of_range("The document has been read");
	}
	std::string currentLine = "";
	currentLine += document[lineToBeRead];
	lineToBeRead++;
	return currentLine;
}

std::string Document::read_line(const unsigned line)
{
	if (line >= this->document.size() || line < 0)
	{
		throw std::out_of_range("The document has been read");
	}
	if(line == 0)
	{
		lineToBeRead = line;
		return document[line];
	}

	lineToBeRead = line;
	return document[lineToBeRead - 1];
}

bool Document::operator==(const Comparable* other) const
{
	const Document* doc = dynamic_cast<const Document*>(other);
	if (!doc)
		return false;

	if (this->document.size() == doc->document.size())
	{
		bool areEqual = true;

		for (size_t i = 0; i < this->document.size(); i++)
		{
			if (this->document[i] != doc->document[i])
			{
				areEqual = false;
			}
		}
		return areEqual;
	}
	return false;
}

bool Document::operator!=(const Comparable* other) const
{
	return !(*this == other);
}

std::string Document::to_string() const
{
	std::string serializedString;

	serializedString = this->name + '\n' + this->location + '\n' + this->extension + '\n';

	for (size_t i = 0; i < this->document.size(); i++)
	{
		std::string currentDocumentLine = document[i] + '\n';
		serializedString += currentDocumentLine;
	}
	return serializedString;
}

void Document::from_string(const std::string& string)
{
	this->document.clear();
	this->name.clear();
	this->location.clear();
	this->extension.clear();
	
	std::stringstream stringToConvert(string);
	std::getline(stringToConvert, this->name);
	std::getline(stringToConvert, this->location);
	std::getline(stringToConvert, this->extension);

	for (size_t i = 0; i < stringToConvert.str().size(); i++)
	{
		std::string currLine;
		std::getline(stringToConvert, currLine);
		this->document.push_back(currLine);
	}

}

std::string Document::debug_print() const
{
	std::string debuggedDocument;

	for (size_t i = 0; i < this->document.size(); i++)
	{
		debuggedDocument += std::to_string(i) + ":" + document[i] + '\n';
	}
	return debuggedDocument;
}

Document* Document::clone() const
{
	return new Document(*this);
}
