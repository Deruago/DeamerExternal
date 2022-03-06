#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/EnumObject.h"

deamer::external::cpp::tool::oopsyntaxrecognizer::EnumObject::EnumObject(const std::string& type_)
	: Type(TypeCategory::enumobject, type_)
{
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::EnumObject::AddMember(
	const std::string& member_)
{
	const auto iter = std::find(std::cbegin(members), std::cend(members), member_);
	if (iter == std::cend(members))
	{
		members.push_back(member_);
	}
}

std::vector<std::string>
deamer::external::cpp::tool::oopsyntaxrecognizer::EnumObject::GetMembers() const
{
	return members;
}
