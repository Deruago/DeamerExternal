#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"

deamer::external::cpp::tool::oopsyntaxrecognizer::Type::Type(TypeCategory category_,
															 const std::string& type_)
	: category(category_),
	  type(type_)
{
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::Type::SetTypeName(const std::string& type_)
{
	type = type_;
}

std::string deamer::external::cpp::tool::oopsyntaxrecognizer::Type::GetTypeName() const
{
	return type;
}

deamer::external::cpp::tool::oopsyntaxrecognizer::TypeCategory
deamer::external::cpp::tool::oopsyntaxrecognizer::Type::GetCategory() const
{
	return category;
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::Type::Print()
{
}
